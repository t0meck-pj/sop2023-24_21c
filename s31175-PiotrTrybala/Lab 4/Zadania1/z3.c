#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i;
    int j;
    int h = atoi(argv[1]);

    for (i=0; i<=h; i++) {
        for(j=1;j<=h-i; j++)
        {
            printf(" ");
        }

        for(j=1; j<=2*i-1; j++)
        {
            printf(".");
        }
        printf("\n");
    }

    for (i=0; i<h;i++) {
        if (i==h-2)
            printf("|||");
        else
        printf(" ");
    }
    printf("\n");
    return 0;
}