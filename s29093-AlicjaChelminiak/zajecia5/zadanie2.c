#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        printf("Proces potomny - PID: %d, PPID: %d\n", getpid(), getppid());
        exit(EXIT_SUCCESS);
    } 
    else {
        printf("Proces rodzica - PID: %d, PPID: %d\n", getpid(), getppid());
        wait(NULL);
    }

    return 0;
}
