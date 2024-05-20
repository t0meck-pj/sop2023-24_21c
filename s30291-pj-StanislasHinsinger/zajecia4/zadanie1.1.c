/*
    Pierwotna wersja zadania, skrocona wersja jako zadanie1b.c
*/

#include<stdio.h>

#define MAX_NUMBER_COUNT 3 

int sum(int*, int);

int main() {
    int values[MAX_NUMBER_COUNT];
    
    int i = 0;

    for(; i < MAX_NUMBER_COUNT; i++) {
        values[i] = 0;
    }
    
    for(i = 0; i < MAX_NUMBER_COUNT; i++) {
        scanf("%i", &values[i]);
    }
    
    printf("%d\n", sum(values, MAX_NUMBER_COUNT));
    return 0;
}

int sum(int* table, int size) {
    int sum = 0;
    int i = 0;
    for(; i < size; i++) {
        sum += table[i];
    }

    return sum;
}







