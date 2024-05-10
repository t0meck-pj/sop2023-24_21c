#include <stdio.h>
#include <stdlib.h>

int maksimum(int num1, int num2){
    return (num1 > num2) ? num1 : num2;
}

int minimum(int num1, int num2){
    return (num1 < num2) ? num1 : num2;
}

int suma(int num1, int num2){
    return num1 + num2;
}

int main(){

    int (*f[3])(int, int) = {maksimum, minimum, suma};
    int functionId, elementCount, v, i;
    int *nums;

    scanf("%d", &functionId);

    scanf("%d", &elementCount);

    nums = (int*)malloc(elementCount * sizeof(int));

    for (i = 0; i < elementCount; i++){
        scanf("%d", &nums[i]);
    }

    v = nums[0];
    for (i = 1; i < elementCount; i++){
        v = f[functionId](v, nums[i]);
        printf("%d", v);
    }

    return 0;
}