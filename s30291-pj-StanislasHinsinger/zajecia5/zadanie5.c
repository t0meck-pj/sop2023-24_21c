#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define COUNT 100

pid_t tab[COUNT];

int main() {
    int i;
    pid_t fork_pid = 1;

    for(i = 0; fork_pid > 0 && i < COUNT; i++) {
        fork_pid = fork();

        if(fork_pid == 0) {
            sleep(5);
        }
        else {
            tab[i] = fork_pid;
        }
    }

    for(i = 0; fork_pid > 0 && i < COUNT; i++) {
        waitpid(tab[i], NULL, 0);
    }

    return 0;
}


















