#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 100; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            printf("Potomek %d (PID: %d), rodzic: %d\n", i+1, getpid(), getppid());
            exit(EXIT_SUCCESS);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
