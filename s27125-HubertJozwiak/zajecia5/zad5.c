/*
Napisz program, który uruchomi 100 procesów potomnych w taki sposób, że będzie jeden rodzic i 100 potomków.
Proces główny niech oczekuje na zakończenie wszystkich procesów potomnych.
*/

#include <stdio.h>

int main() {
    int n = 100;
    int i;

    for (i = 0; i < n; i++) {
        int pid = fork();
        if (pid == 0) {
            sleep(5);
            return 0;
        }
    }

    for (i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}