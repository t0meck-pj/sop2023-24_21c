#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void execution_of_A();
void execution_of_B_AND_C();

int main() {
    execution_of_A();

    return 0;
}

void execution_of_A() {
    int i;
    pid_t fork_pid;

    for(i = 0; fork_pid > 0 && i < 2; i++) {
        fork_pid = fork();

        if(fork_pid == 0) execution_of_B_AND_C();
    }
    wait(NULL);
}

void execution_of_B_AND_C() {
    int i;
    pid_t fork_pid;

    for(i = 0; fork_pid > 0 && i < 2; i++) {
        fork_pid = fork();
    }
    sleep(5);
}




