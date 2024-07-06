#include <stdio.h>
#include <stdlib.h>

typedef int(*f)(int, int);

int min(int a,int b) {
    if (a < b) return a;
    else return b;
}

int max(int a ,int b) {
    if (a > b) return a;
    else return b;
}

int sum(int a,int b) {
    return a + b;
}

int func(int *a, int b, f typ) {
    int i;
    int temp;
    temp=a[0];
    for(i=1; i<b;i++) {
        temp = typ(temp, a[i]);
    }
    return temp;
}

int main(int argc, char* argv[]) {
    int a=1;
    int b=2;
    int i;
    int functionId;
    int *tablica;
    int elementCount;
    f functions[3]={min,max,sum};
    
    printf("Podaj nazwę funkcji (min - 0, max - 1, sum - 2): ");
    scanf("%i", &functionId);

    printf("Podaj ilosc liczb: ");
    scanf("%i", &elementCount);

    tablica = malloc(sizeof(int) * elementCount);

    for(i=0; i<elementCount;i++) {
        printf("Podaj element %i:", i);
        scanf("%i", &tablica[i]);
    }
    printf("%i", func(tablica, elementCount, functions[functionId]));

    return 0;
}