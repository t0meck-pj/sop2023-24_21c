#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pid = fork();
    int i;

    for(i=0;i<10;i++)
    {
        if(pid == 0)
        {
            pid = fork();
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
        }
        else {
            sleep(10);
            exit(0);
        }

    }
    return 0;
}