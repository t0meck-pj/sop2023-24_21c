#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *numbers;
    int i=0;
    int sum=0;
    scanf("%d", &n);

    numbers = malloc(n * sizeof(*numbers));

    for (i=0; i<n; i++){
        scanf("%d", &numbers[i]);
        sum+=numbers[i];
    }
    sum=sum/i;
    return sum;
}