#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  FILE* file = NULL;
  int dlugoscCiagu = 0;
  int* ciag = NULL;
  int i = 0;

  if (argc == 1) {
    file = stdin;
  } else {
    file = fopen(argv[1], "r");
    if (file == NULL) {
      printf("Nie udało się otworzyć pliku\n");

      return 1;
    }
  }

  fscanf(file, "%d", &dlugoscCiagu);

  ciag = (int*)malloc(dlugoscCiagu * sizeof(int));

  for (i = 0; i < dlugoscCiagu; i++) {
    fscanf(file, "%d", &ciag[i]);
  }

  for (i = 0; i < dlugoscCiagu; i++) {
    printf("%d ", ciag[i]);
  }

  printf("\n");

  free(ciag);
  if (argc == 2) {
    fclose(file);
  }

  return 0;
}