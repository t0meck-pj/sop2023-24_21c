#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Numer PID: %d\n", getpid());
    printf("Numer PPID: %d\n", getppid());
    while(1){
        getchar();
    }

    return 0;
}