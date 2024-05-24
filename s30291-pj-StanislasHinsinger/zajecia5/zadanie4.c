#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define COUNT 100

int counter = 0;

int main() {
    pid_t fork_pid;

    do {
        counter++;
        fork_pid = fork();

        if(fork_pid > 0) {
            waitpid(fork_pid, NULL, 0);
        }
    } while (fork_pid == 0 && counter < COUNT);

    if (fork_pid == 0 && counter == COUNT){
        int result = 0;
        scanf("%i", &result);
    }

    return 0;
}


















