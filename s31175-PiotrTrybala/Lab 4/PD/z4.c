#include <stdio.h>
#include <stdlib.h>


int main() {

    int i;
    int n;

    int a = 0;
    int b = 1;
    int c = 1;

    printf("Podaj liczbe elementow ciagu: ");
    scanf("%d", &n);
    if(n==0) {
        printf("0");
        return 0;
    }
    else if (n==1) {
        printf("0, 1");
    }
    printf("0, 1");

    for (i = 3; i <= n; ++i) {
        printf(", %d", c);
        a = b;
        b = c;
        c = a + b;
    }
    return 0;
}