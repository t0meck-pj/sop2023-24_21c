#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
        
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    if (n < 0){
        printf("n cannot be smaller than 0");
        return 0;
    }
    
    printf("%d", fibonacci(n));

    return 0;
}
