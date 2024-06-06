#include <stdio.h>

int main(){
    int sum = 0, num = 0;
    while (num != 0){
        scanf("%d", &num);
        sum += num;
    }
    return sum;
}
