#include <stdio.h>
#include <stdlib.h>

int forAll(int *nums, int elementCount, int (*f)(int, int)){
    int v, i;

    v = nums[0];
    for (i = 1; i < elementCount; i++){
        v = f(v, nums[i]);
    }

    return v;
}

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
    int tablica[] = {1,6,3,4,5};
    int liczbaElementow = sizeof(tablica) / sizeof(tablica[0]);

    int wynik = forAll(tablica, liczbaElementow, maksimum);

    printf("%d", wynik);

    return 0;
}
