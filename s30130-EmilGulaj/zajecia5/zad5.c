#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(){
    int i, status,p = 0, processes = 10, nothing;
    for(i = 0; i < processes; i++){
        p = fork();
        if (p == 0){
            break;
        }
    }

    if (p != 0){
        for(i = 0; i < processes; i++){
            wait(NULL);
        }

        scanf("%d", &nothing);
    }
    

    return 0;
}
