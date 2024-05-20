#include<stdio.h>
#include<stdlib.h>

#define SPACING "   "

/* 
    param1 = plik do odczytu;
    param2 = grupowanie po X elementow (def = 16);  
*/
int main(int argc, char **argv) {
    int i, offset, buffor_size;
    unsigned char *buffor;
    size_t bytes;
    FILE *file;

    if(argc < 2) {
        printf("Nie wprowadzono pliku do wyswietlenia!");
        return 0;
    }

    if(argc > 2) buffor_size = atoi(argv[2]);
    else buffor_size = 16;

    buffor = calloc(buffor_size, sizeof(unsigned char)); /* buffor o danej wielkosci grupowania */
    file = fopen(argv[1], "rb"); /* tryb odczytu bytow */

    printf("Loading file: %s\n", argv[1]);

    while ((bytes = fread(buffor, 1, buffor_size, file)) > 0) {
        printf("%08X", offset); /* wypisanie offsetu z uzupelnieniem zer (do 8 cyfr) */
        printf(SPACING);

        for(i = 0; i < bytes; i++) {
            printf("%02X", buffor[i]); /* wypisanie wartosci jako hexadecymalnej z uzuplenieniem zer (do 2 cyfr) */
            
            if (i != buffor_size - 1) printf(" ");
        }

        for (i = bytes; i < buffor_size; i++) {
            printf("  "); /* dopisanie spacji jezeli koniec pliku nie jest podzielny przez wielkosc */
            
            if (i != buffor_size - 1) printf(" ");
        }

        printf(SPACING);

        for(i = 0; i < bytes; i++) {
            /* znaki czytalne w zakresie 32-126 */
            if(buffor[i] >= 32 && buffor[i] <= 126) printf("%c", buffor[i]); 
            else printf(".");
        }

        offset += buffor_size;
        printf("\n");
    }

    free(buffor);
    return 0;
}






