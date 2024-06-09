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

    if (elementCount <= 0)
        return 0;

    nums = (int*)malloc(elementCount * sizeof(int));

    if (nums == NULL){
        printf("Blad alokacji pamieci");
        return -1;
    }

    for (i = 0; i < elementCount; i++){
        scanf("%d", &nums[i]);
    }

    v = nums[0];
    for (i = 1; i < elementCount; i++){
        v = f[functionId](v, nums[i]);
        printf("%d", v);
    }

    free(nums);

    return 0;
}
