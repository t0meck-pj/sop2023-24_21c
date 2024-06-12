/*
Napisz program, który uruchomi 100 procesów w taki sposób, że każdy kolejny
potomek stworzy potomka. Niech każdy proces poczeka na zakończenie procesu
potomka. Możesz korzystać z oczekiwania na wejście lub z komendy sleep i zobacz
czy drzewko procesów jest takie jak się spodziewasz (możesz w tym celu
ograniczyć liczbę procesów do 10)
*/

#include <stdio.h>

void spawn(int n) {
  if (n == 0) {
    getchar();
    return;
  }

  int pid = fork();
  if (pid == 0) {
    spawn(n - 1);
    return;
  }

  wait(NULL);
}

int main() {
  int n = 100;

  spawn(n);

  return 0;
}
