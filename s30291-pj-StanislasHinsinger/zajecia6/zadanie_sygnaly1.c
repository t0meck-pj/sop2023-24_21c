#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdbool.h>
#include<sys/types.h>

bool triggered = false;

void handler(int signum) {
    if(signum == SIGUSR1) {
        triggered = true;
        printf("Otrzymano sygnal USR1,\n");
    }
}

int main() {
    printf("PID programu: %d\n", getpid());
    signal(SIGUSR1, handler);

    while(!triggered) {}

    return 0;
}









