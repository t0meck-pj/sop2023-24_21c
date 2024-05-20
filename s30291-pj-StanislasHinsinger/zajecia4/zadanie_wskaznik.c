#include<stdlib.h>
#include<stdio.h>

int sum(int, int);
int min(int, int);
int max(int, int);

int main(int argc, char **argv) {
    int (*functions[])(int, int) = { sum, min, max };
    int i, v, current, functionId, elementCount;

    scanf("%i", &functionId);
    scanf("%i", &elementCount);

    /* nie mozna bylo uzyc if, wiec uzylem for aby sprawdzic 
    czy ma byc podany pierwszy element (elementCount > 0)*/

    for(i = 0; (elementCount > 0 && i < 1); i++) { 
        scanf("%i", &current);
        v = current;
    }

    for(i = 1; i < elementCount; i++) {
        scanf("%i", &current);
        v = functions[functionId](v, current);
    }

    printf("v = %i\n", v);

    return 0;
}

int sum(int a, int b) {
    return a + b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}




