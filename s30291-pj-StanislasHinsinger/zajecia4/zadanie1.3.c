#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    int height, x, y;

    if(argc < 2) {
        printf("Do programu należy wprowadzić parametr wysokości!\n");
        return 0;
    }

    x = 0;
    y = 0;
    height = 0;

    height = atoi(argv[1]);

    for(; y < height; y++) {
        for(; x < (height * 2) - 1; x++) {
            if((y == height - 1 && x == (height - 1)) || (y != height - 1 && x >= height - y - 1 && x <= height + y - 1)) 
                printf("*");
            else printf(" ");
        }
        x = 0;
        printf("\n");
    }

    return 0;
}

