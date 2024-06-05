#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    int i, nothing, p = 0;
    for(i = 0; i < 10; i++){
        if (p == 0){
            fork();
        }
        else{
            wait(NULL);
        }
    }

    scanf("%d", &nothing);

    return 0;
}
