#include <stdio.h>

int main(){
    int num = 0;
    int sum = 0;
    while ( num != 0 ){
        scanf("Enter number different than 0: %d", &num);
        sum += num;
        printf("This is the sum: %d\n", sum);
    }
    
    return 0;
}