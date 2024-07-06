#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pid;
    int i;

    for(i=0;i<10;i++)
    {
        if(pid = fork() == 0)
        {
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
            sleep(5);
            exit(0);
        }
        sleep(1);
    }

    for(i=0;i<10;i++) {
        wait(0);
        printf("Another one!\n");
    }

    return 0;
}