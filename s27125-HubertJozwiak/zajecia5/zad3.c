/*
Napisz program, który będzie pobierał jeden argument z wiersza poleceń  i będzie
obliczał w 2 procesach: Proces rodzica: Wartość sumy liczb od 0 do wartości
zadanej jako pierwszy argument wykonania programu. Proces potomny: Wypisujący
liczby nieparzyste od 1 do wartości zadanej jako pierwszy argument wykonania
programu. Program powinien wypisać wyniki w kolejności takiej, że najpierw
wypisze wynik proces potomny, a następnie proces rodzica. Nie korzystaj z
komendy sleep.
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <n>\n", argv[0]);

    return 1;
  }

  int n = atoi(argv[1]);
  int pid = fork();
  int i;

  /* child */
  if (pid == 0) {
    for (i = 1; i <= n; i += 2) {
      printf("%d ", i);
    }
    printf("\n");
  } else {
    int sum = 0;
    for (i = 0; i <= n; i++) {
      sum += i;
    }
    wait(NULL);
    printf("Sum: %d\n", sum);
  }

  return 0;
}
