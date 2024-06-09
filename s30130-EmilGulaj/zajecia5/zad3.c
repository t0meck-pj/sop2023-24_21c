#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t p;
    int num, sum, i, status;
    scanf("%d", &num);

    p = fork();
    
    
    if(p == 0){
        printf("Liczby: ");
        for (i = 0; i <= num; i++){
            if (i % 2 == 1){
                printf("%d ", i);
            }
        }
    }
    else{
        waitpid(p, &status, 0);
        printf("\nSuma: ");
        for (i = 1; i <= num; i++){
            sum += i;
        }
        printf("%d\n", sum);
    }
              
    return 0;
}
