#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


void signal_handler(int sig){
    exit(EXIT_SUCCESS);
}

int main()
{
    printf("%d\n", getpid());

    while (1){
        signal (SIGUSR1, signal_handler);
    }
    
    return 0;
}
