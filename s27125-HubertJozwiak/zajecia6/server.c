#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CONNECTIONS 5
#define MAX_PACKET_SIZE 512

#define FILENAME_LENGTH_STR_SIZE 10
#define FILENAME_SIZE 128

#define FILE_SIZE_AS_STR_SIZE 10

static int listeningSocketFd, connectionSocketFd;

static void handler(int sig) {
  if (sig == SIGINT) {
    printf("\nReceived SIGINT\n");
    printf("Closing sockets...\n");

    close(connectionSocketFd);
    close(listeningSocketFd);

    exit(0);
  }
}

static void error(char* msg) {
  perror(msg);
}

static void errorFatal(char* msg) {
  perror(msg);
  printf("Closing sockets...\n");

  close(connectionSocketFd);
  close(listeningSocketFd);

  exit(1);
}

static void logMessage(const char* fmt, ...) {
  FILE* logFile = fopen("server.log", "a");
  if (logFile == NULL) {
    errorFatal("[ERROR] fopen");
  }

  va_list fprintfArgs, printfArgs;
  va_start(fprintfArgs, fmt);
  va_copy(printfArgs, fprintfArgs);

  vfprintf(logFile, fmt, fprintfArgs);
  vprintf(fmt, printfArgs);

  va_end(fprintfArgs);
  va_end(printfArgs);

  fclose(logFile);
}

static void handleConnection(int connectionSocketFd) {
  size_t bytesRead = 0, bytesSent = 0;

  struct sockaddr_in clientAddress;
  socklen_t clientAddressLength = sizeof(clientAddress);
  getpeername(connectionSocketFd, (struct sockaddr*)&clientAddress,
              &clientAddressLength);
  logMessage("[%s:%d]:\n", inet_ntoa(clientAddress.sin_addr),
             ntohs(clientAddress.sin_port));

  /* Receive filename length ----------------------------------------------- */
  char filenameLengthStr[FILENAME_LENGTH_STR_SIZE] = {0};
  bytesRead =
      recv(connectionSocketFd, filenameLengthStr, FILENAME_LENGTH_STR_SIZE, 0);
  if (bytesRead < 0) {
    error("[ERROR] read");
  }

  if (bytesRead == 0) {
    logMessage("Client disconnected\n");

    return;
  }

  printf("Received filename length: %s \n", filenameLengthStr);
  /* ------------------------------------------------------------------------ */

  int filenameLength = atoi(filenameLengthStr);
  char* filenameBuffer = malloc(filenameLength + 1);

  /* Receive filename ------------------------------------------------------ */
  bytesRead = recv(connectionSocketFd, filenameBuffer, filenameLength, 0);
  if (bytesRead < 0) {
    error("[ERROR] read");
  }

  filenameBuffer[filenameLength] = '\0';

  logMessage("Received file name: %s\n", filenameBuffer);
  /* ------------------------------------------------------------------------ */

  FILE* fileToSend = fopen(filenameBuffer, "r");
  if (fileToSend == NULL) {
    error("[ERROR] fopen");

    /* Send file not found */
    bytesSent = send(connectionSocketFd, "-1", 2, 0);
    if (bytesSent < 0) {
      error("[ERROR] write");
    }

    return;
  }

  /* Send file size -------------------------------------------------------- */
  fseek(fileToSend, 0, SEEK_END);
  size_t fileSize = ftell(fileToSend);
  fseek(fileToSend, 0, SEEK_SET);

  char fileSizeAsStr[FILE_SIZE_AS_STR_SIZE] = {0};
  sprintf(fileSizeAsStr, "%ld", fileSize + 1);  // +1 for NULL byte

  printf("Sending file size: %s\n", fileSizeAsStr);
  bytesSent = send(connectionSocketFd, fileSizeAsStr, FILE_SIZE_AS_STR_SIZE, 0);
  if (bytesSent < 0) {
    error("[ERROR] write");
  }
  /* ------------------------------------------------------------------------ */

  /* Send file ------------------------------------------------------------- */
  size_t dataLeftToSend = fileSize;
  char* fileBuffer = malloc(fileSize);

  while (dataLeftToSend > 0) {
    bytesRead = fread(fileBuffer, 1, MAX_PACKET_SIZE, fileToSend);

    printf("Sending %ld bytes\n", bytesRead);
    bytesSent = send(connectionSocketFd, fileBuffer, bytesRead, 0);
    if (bytesSent < 0) {
      error("[ERROR] write");
    }

    dataLeftToSend -= bytesRead;
  }

  /* Send NULl byte */
  printf("Sending NULL byte\n");
  bytesSent = send(connectionSocketFd, "\0", 1, 0);
  if (bytesSent < 0) {
    error("[ERROR] write");
  }

  /* ------------------------------------------------------------------------ */

  printf("File sent\n");

  fclose(fileToSend);
  free(filenameBuffer);
  free(fileBuffer);
}

static void setupSignalHandler() {
  struct sigaction sa;
  sa.sa_handler = handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);

  if (sigaction(SIGINT, &sa, NULL) == -1) {
    errorFatal("[ERROR] sigaction");
  }
}

static int setupListeningSocket(char* port) {
  struct addrinfo hints, *res = NULL;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if (getaddrinfo(NULL, port, &hints, &res) != 0) {
    errorFatal("[ERROR] getaddrinfo");
  }

  int listeningSocketFd =
      socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (listeningSocketFd < 0) {
    errorFatal("[ERROR] socket");
  }

  if (bind(listeningSocketFd, res->ai_addr, res->ai_addrlen) != 0) {
    errorFatal("[ERROR] bind");
  }

  freeaddrinfo(res);

  return listeningSocketFd;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  setupSignalHandler();

  char* port = argv[1];
  listeningSocketFd = setupListeningSocket(port);

  printf("Server is listening on port %s\n", port);

  if (listen(listeningSocketFd, MAX_CONNECTIONS) != 0) {
    errorFatal("[ERROR] listen");
  }

  while (1) {
    struct sockaddr_in clientAddress;
    size_t clientAddressLength = sizeof(clientAddress);

    connectionSocketFd =
        accept(listeningSocketFd, (struct sockaddr*)&clientAddress,
               (socklen_t*)&clientAddressLength);
    if (connectionSocketFd < 0) {
      errorFatal("[ERROR] accept");
    }

    printf("Connection established\n");

    int pid = fork();
    if (pid < 0) {
      errorFatal("[ERROR] fork");
    }

    if (pid == 0) {
      /* Child doesn't need the listener */
      close(listeningSocketFd);

      handleConnection(connectionSocketFd);

      exit(0);
    } else {
      /* Parent doesn't need the connection */
      close(connectionSocketFd);
    }
  }

  printf("Closing sockets...\n");

  close(connectionSocketFd);
  close(listeningSocketFd);

  return 0;
}