#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pid;
    if ((pid=fork())==0){
        printf("%u\t%u\n",getpid(),getppid());
    }
    else{
        printf("%u\n", getpid());
        return 0;
    }
    printf("%u\n", getpid());
    return 0;
}