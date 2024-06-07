#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    int test = 0;
    pid_t pid = getpid();
    pid_t ppid = getppid();
    
    printf("PID: %i, PPID: %i", pid, ppid);
    scanf("%i", &test);

    return 0;
}









