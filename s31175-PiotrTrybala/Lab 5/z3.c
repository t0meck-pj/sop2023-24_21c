#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int pid;
    int i;
    int sum = 0;
    if ((pid = fork())==0){
        for (i = 0; i <= atoi(argv[1]); i++) {
            sum+=i;
        }
        printf("Suma: %i\n",sum);
        return sum;
    }
    else{
        waitpid(-1, &pid, 0);
        for (i = 0; i <= atoi(argv[1]); i++) {
            if(i%2==1) {
                printf("%i\n",i);
            }
        }
    }
    return 0;
}