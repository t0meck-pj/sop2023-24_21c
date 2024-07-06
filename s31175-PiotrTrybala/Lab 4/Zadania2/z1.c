#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char filename[64];
    FILE* fp;
    int i=0;
    int j;
    int *numbers;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            scanf("%s", filename);
            fp = fopen(filename, "r");
        }
    }
    else {
        scanf("%s", filename);
        fp = fopen(filename, "r");
    }


    fscanf(fp, "%i\n", &i);
    numbers = malloc(sizeof(int) * i);

    for (j=0; j<i; j++) {
        fscanf(fp, "%i\n", &numbers[j]);
        printf("%i\n",numbers[j]);
    }
    
    printf("Tera odwrotnie:\n");
    
    for (j=i-1; j>=0; j--) {
        printf("%i\n",numbers[j]);
    }

    fclose(fp);
    free(numbers);
    return 0;
}