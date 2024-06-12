#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <height>\n", argv[0]);

    return 1;
  }

  int height = atoi(argv[1]);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < height - i - 1; j++) {
      printf(" ");
    }

    for (int j = 0; j < 2 * i + 1; j++) {
      printf("*");
    }

    printf("\n");
  }

  return 0;
}
