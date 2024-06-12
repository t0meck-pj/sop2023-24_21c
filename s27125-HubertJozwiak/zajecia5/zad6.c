#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHAT_FILE "/tmp/chat"
#define BUFFER_SIZE 256

void error_exit(const char* message) {
  perror(message);

  exit(EXIT_FAILURE);
}

void write_to_chat_file() {
  char buffer[FILENAME_BUFFER_SIZE];
  FILE* file = NULL;

  file = fopen(CHAT_FILE, "w");
  if (file == NULL) {
    error_exit("fopen");
  }

  while (1) {
    printf("You: ");
    fgets(buffer, FILENAME_BUFFER_SIZE, stdin);
    if (fwrite(buffer, sizeof(char), strlen(buffer), file) < strlen(buffer)) {
      error_exit("fwrite");
    }
    fflush(file);
    sleep(1);
  }

  fclose(file);
}

void read_from_chat_file() {
  char buffer[FILENAME_BUFFER_SIZE];
  FILE* file = NULL;

  file = fopen(CHAT_FILE, "r");
  if (file == NULL) {
    error_exit("fopen");
  }

  while (1) {
    while (fgets(buffer, FILENAME_BUFFER_SIZE, file) != NULL) {
      printf("Friend: %s", buffer);
    }
    clearerr(file);
  }

  fclose(file);
}

int main() {
  int pid = 0;
  pid = fork();

  if (pid < 0) {
    error_exit("fork");
  } else if (pid == 0) {
    read_from_chat_file();
  } else {
    write_to_chat_file();
  }

  return 0;
}
