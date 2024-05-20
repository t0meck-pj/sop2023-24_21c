#include<stdio.h>

int main() {
    int last;
    int sum = 0;

    do {
        scanf("%i", &last);
        sum += last;
    } while(last != 0);

    printf("%i\n", sum);
    return 0;
}






