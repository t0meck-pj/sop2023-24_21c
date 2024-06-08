#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;

    for (int i = 0; i < 100; i++) {
        child_pid = fork();

        if (child_pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            printf("Potomek %d (PID: %d), rodzic: %d\n", i+1, getpid(), getppid());
            exit(EXIT_SUCCESS);
        }
    }

    while (waitpid(-1, &status, 0) > 0) {
        if (WIFEXITED(status)) {
            printf("Proces potomny o PID %d zakończony sukcesem.\n", WEXITSTATUS(status));
        } else {
            printf("Proces potomny zakończony niepowodzeniem.\n");
        }
    }

    return 0;
}
