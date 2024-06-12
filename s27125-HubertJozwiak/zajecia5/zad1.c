/*
Napisz program, który
przedstawi swój numer PID, oraz PPID
po wypisaniu, będzie czekał na standardowym wejściu na dane od użytkownika.
Uruchom program - nic nie podawaj na wejściu (program powinien czekać w
nieskończoność).Uruchom nowy terminal. W nim za pomocą komendy kill zamknij ten
program korzystając z PID wypisanego przez niego na początku.
*/

#include <stdio.h>

int main() {
  printf("PID: %d\n", getpid());
  printf("PPID: %d\n", getppid());
  getchar();

  return 0;
}
