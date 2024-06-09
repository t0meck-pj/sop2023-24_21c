#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    int num1 = 0, num2 = 1, next_num, i;
    

    if (n < 0){
        printf("n cannot be smaller than 0");
        return 0;
    }
    else if (n == 0){
        printf("0");
        return 0;
    }
    else if (n == 1){
        printf("1");
        return 0;
    }
    else{
        for(i = 0; i <= n; i++){
            printf("%d\n", num1);
            next_num = num1 + num2;
            num1 = num2;
            num2 = next_num;
        }
    }

    return 0;
}
