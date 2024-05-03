#include <stdio.h>
#include <stdlib.h>

typedef int (*f)(int, int);

int maksimum(int a, int b) {
  return a > b ? a : b;
}

int minimum(int a, int b) {
  return a < b ? a : b;
}

int suma(int a, int b) {
  return a + b;
}

int main() {
  f funkcje[3] = {maksimum, minimum, suma};

  int functionId = 0;
  int elementCount = 0;
  int i = 0;

  int* numbers = NULL;
  int v = 0;

  printf("Function ID: ");
  scanf("%d", &functionId);
  if (functionId < 0 || functionId > 2) {
    printf("Invalid function id\n");

    return 1;
  }

  printf("Element count: ");
  scanf("%d", &elementCount);
  if (elementCount < 1) {
    printf("Element count must be at least 1\n");

    return 2;
  }

  numbers = (int*)malloc(elementCount * sizeof(int));

  for (i = 0; i < elementCount; i++) {
    printf("Number %d: ", i + 1);
    scanf("%d", &numbers[i]);
  }

  v = numbers[0];
  for (i = 1; i < elementCount; i++) {
    v = funkcje[functionId](v, numbers[i]);
  }

  printf("%d\n", v);

  free(numbers);

  return 0;
}
