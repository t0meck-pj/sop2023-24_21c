#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  FILE* file = NULL;

  if (argc != 2) {
    printf("Usage %s <file>\n", argv[0]);

    return 1;
  }

  printf("Loading file: %s\n", argv[1]);

  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Cannot open file %s\n", argv[1]);

    return 2;
  }

  while (!feof(file)) {
    unsigned char buffer[16];
    int i = 0;

    for (i = 0; i < 16; i++) {
      buffer[i] = 0;
    }

    printf("%08X | ", ftell(file));

    fread(buffer, 1, 16, file);

    for (i = 0; i < 16; i++) {
      printf("%02X ", buffer[i]);
    }

    printf("| ");

    for (i = 0; i < 16; i++) {
      if (buffer[i] >= 32 && buffer[i] <= 126) {
        printf("%c", buffer[i]);
      } else {
        printf("\u2592");
      }
    }

    printf("\n");
  }

  printf("Closing file: %s\n", argv[1]);

  fclose(file);

  return 0;
}