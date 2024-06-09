#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int h = 0;
    int i;

    if (argc < 2 || atoi(argv[1]) < 2){
        printf("Bledny argument");
        return -1;
    }
    h = atoi(argv[1]);
    
    for (i = 0; i < h; i++){
        int j;
        for (j = 0; j < h - i - 1; j++){
            printf(" ");
        }
        for (j = 0; j < 2 * i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
