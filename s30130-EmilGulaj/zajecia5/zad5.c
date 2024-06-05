#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(){
    int i, status,p = 0, processes = 10, nothing;
    for(i = 0; i < processes; i++){
        if (p == 0){
            p = fork();
        }
    }

    for(i = 0; i < processes; i++){
        waitpid(p,&status, 0);
    }

    scanf("%d", &nothing);

    return 0;
}
