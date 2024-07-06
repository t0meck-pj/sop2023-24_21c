#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Received SIGUSR1!\n");
        exit(1);
    }
}

int main() {
    signal(SIGINT, SIG_IGN);
    signal(SIGUSR1, handler);

    printf("Moj PID: %i\n", getpid());

    while(1) {
        printf("Czekam na sygnal\n");
        sleep(5);
    }

    return 0;
}