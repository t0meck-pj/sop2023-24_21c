#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    int status, p = fork();

    waitpid(p, &status, 0);

    if (p == 0){
        printf("Dziecko: \n");
    }
    else{
        printf("Rodzic: \n");
    }

    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    
    

    return 0;
}
