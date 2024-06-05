/*
Napisz program, który uruchomi podproces za pomocą komendy fork. Niech proces rodzica oczekuje na proces potomka. Oba procesy powinny wypisać swój PID oraz PPID.
*/

#include <stdio.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("In child: PID: %d\n", getpid());
        printf("In child: PPID: %d\n", getppid());
    } else {
        printf("In parent: PID: %d\n", getpid());
        printf("In parent: PPID: %d\n", getppid());
        wait(NULL);
    }
    
    
    
    return 0;
}