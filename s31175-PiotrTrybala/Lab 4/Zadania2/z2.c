#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {

    char filename[64];
    FILE* fp;
    int i;
    int row=0;
    char *numbers = malloc(sizeof(char) * 16);

    if (argc > 1) {
        fp = fopen(argv[1], "rb");
        if (fp == NULL) {
            printf("Enter file name: ");
            scanf("%s", filename);
            fp = fopen(filename, "rb");
            printf("Reading file: %s\n", filename);
        }
        else
            printf("Reading file: %s\n", argv[1]);
    }
    else {
        printf("Enter file name: ");
        scanf("%s", filename);
        fp = fopen(filename, "rb");
    printf("Reading file: %s\n", filename);
    }

    printf("adres_w_pliku\tkolejne_16_bajtów_w_formie_hexadecymalnej\t\tbajty_jako_tekst\n");

    while(!feof(fp)) 
    {
        printf("%08x\t", row);
        row+=16;

        memset(numbers, 0, sizeof(char) * 16);
        fread(numbers,sizeof(char),16,fp);

        for(i=0;i<16;i++)
            printf("%02X ", numbers[i]);

        printf("\t");

        for(i=0;i<16;i++)
            if (isspace(numbers[i]))
                printf(" ");
            else
                printf("%c", numbers[i]);
        printf("\n");
    }
    printf("Closing file: %s%s\n", filename, argv[1]);
    free(numbers);
    fclose(fp);
    return 0;
}