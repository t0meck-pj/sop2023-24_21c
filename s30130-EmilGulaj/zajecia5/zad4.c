#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    int i, nothing, p = 0;
    for(i = 0; i < 10 && p != 0; i++){
        fork();
    }

    if (p != 0){
        for(i = 0; i < processes; i++){
            wait(NULL);
        }

        scanf("%d", &nothing);
    }

    return 0;
}
