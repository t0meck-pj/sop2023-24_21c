#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define FILENAME_BUFFER_SIZE 256
#define FILENAME_LENGTH_STR_SIZE 10

#define FILE_SIZE_AS_STR_SIZE 10

static int socketFd;

static void handler(int sig) {
  if (sig == SIGINT) {
    printf("\nReceived SIGINT\n");
    printf("Closing socket...\n");

    close(socketFd);

    exit(0);
  }
}

static void errorFatal(char* msg) {
  perror(msg);
  printf("Closing socket...\n");

  close(socketFd);

  exit(1);
}

static void setupSignalHandler() {
  struct sigaction sa;
  sa.sa_handler = handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  if (sigaction(SIGINT, &sa, NULL) == -1) {
    errorFatal("[ERROR] sigaction");
  }
}

int main(int argc, char* argv[]) {
  size_t bytesWritten = 0, bytesRead = 0;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  char* hostname = argv[1];
  char* port = argv[2];

  setupSignalHandler();

  struct addrinfo hints, *res = NULL;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  if (getaddrinfo(hostname, port, &hints, &res) != 0) {
    errorFatal("[ERROR] getaddrinfo");
  }

  socketFd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (socketFd < 0) {
    errorFatal("[ERROR] socket");
  }

  printf("Connecting to %s:%s...\n", hostname, port);

  if (connect(socketFd, res->ai_addr, res->ai_addrlen) < 0) {
    errorFatal("[ERROR] connect");
  }

  freeaddrinfo(res);

  printf("Successfully connected to %s:%s\n", hostname, port);

  printf("Select a file: ");

  char filenameBuffer[FILENAME_BUFFER_SIZE];
  fgets(filenameBuffer, FILENAME_BUFFER_SIZE, stdin);

  /* Remove trailing newline */
  filenameBuffer[strcspn(filenameBuffer, "\n")] = 0;

  /* Send filename length ----------------------------------------------- */
  size_t filenameLength = strlen(filenameBuffer);

  char filenameLengthAsStr[FILENAME_LENGTH_STR_SIZE] = {0};
  sprintf(filenameLengthAsStr, "%ld", filenameLength);

  printf("Sending filename length: %s\n", filenameLengthAsStr);
  bytesWritten =
      send(socketFd, filenameLengthAsStr, FILENAME_LENGTH_STR_SIZE, 0);
  if (bytesWritten < 0) {
    errorFatal("[ERROR] write");
  }
  /* -------------------------------------------------------------------- */

  /* Send filename ------------------------------------------------------ */
  printf("Sending filename: %s\n", filenameBuffer);
  bytesWritten = send(socketFd, filenameBuffer, filenameLength, 0);
  if (bytesWritten < 0) {
    errorFatal("[ERROR] write");
  }
  /* -------------------------------------------------------------------- */

  /* Receive size of incoming file -------------------------------------- */
  char incomingFileSizeAsStr[FILE_SIZE_AS_STR_SIZE] = {0};
  bytesRead = recv(socketFd, &incomingFileSizeAsStr, FILE_SIZE_AS_STR_SIZE, 0);
  if (bytesRead < 0) {
    errorFatal("[ERROR] read");
  }

  int incomingFileSize = atoi(incomingFileSizeAsStr);

  if (incomingFileSize == -1) {
    printf("File not found\n");

    close(socketFd);

    return 0;
  }

  printf("Incoming file size: %d\n", incomingFileSize);
  /* -------------------------------------------------------------------- */

  printf("Allocating %d bytes for incoming file...\n", incomingFileSize);
  size_t dataLeftToReceive = incomingFileSize;
  char* incomingDataBuffer = malloc(incomingFileSize);

  /* Receive file ------------------------------------------------------- */
  while (dataLeftToReceive > 0) {
    bytesRead = recv(
        socketFd, incomingDataBuffer + (incomingFileSize - dataLeftToReceive),
        dataLeftToReceive, 0);

    printf("Received %ld bytes\n", bytesRead);

    dataLeftToReceive -= bytesRead;
  }
  /* -------------------------------------------------------------------- */

  printf("%s\n", incomingDataBuffer);

  printf("Closing socket and freeing memory...\n");
  close(socketFd);
  free(incomingDataBuffer);

  return 0;
}