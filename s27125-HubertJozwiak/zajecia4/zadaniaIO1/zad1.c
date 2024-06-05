#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = NULL;
  int dlugoscCiagu = 0;
  int* ciag = NULL;
  int i = 0;

  file = fopen("plik", "r");
  if (file == NULL) {
    printf("Nie udało się otworzyć pliku\n");

    return 1;
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
  fclose(file);

  return 0;
}
