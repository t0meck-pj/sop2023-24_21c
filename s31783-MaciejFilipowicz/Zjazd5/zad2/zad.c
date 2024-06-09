#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Błąd podczas tworzenia procesu potomnego\n");
        return 1;
    } else if (pid == 0) {
        printf("Proces potomny - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        printf("Proces rodzica - PID: %d, PPID: %d\n", getpid(), getppid());
        wait(NULL); // Czekaj na zakończenie procesu potomnego
    }

    return 0;
}