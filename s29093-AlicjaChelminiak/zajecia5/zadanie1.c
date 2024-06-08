#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("Numer PID: %d\n", pid);
    printf("Numer PPID: %d\n", ppid);

    getchar();

    return 0;
}
