#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("[CHILD] PID: %i\n", getpid());
        printf("[CHILD] PPID: %i\n", getppid());
    }
    else {
        printf("[PARENT] PID: %i\n", getpid());
        printf("[PARENT] PPID: %i\n", getppid());
    }

    if(pid > 0) {
        wait(NULL);
    }

    return 0;
}



