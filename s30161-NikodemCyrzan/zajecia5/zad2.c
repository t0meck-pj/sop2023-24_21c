#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    int id = fork(), status;
    if (id != 0)
        waitpid(id, &status, 0);

    if (id != 0)
        printf("Rodzic:\n");
    else
        printf("Dziecko:\n");

    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());

    return 0;
}
