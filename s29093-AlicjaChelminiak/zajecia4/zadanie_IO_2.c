#include <stdio.h>

#define ROZMIAR_BUFORA 16

void heksadecymalne(FILE *plik) {
    unsigned char bufor[ROZMIAR_BUFORA];
    int przeczytane;

    while ((przeczytane = fread(bufor, sizeof(unsigned char), ROZMIAR_BUFORA, plik)) > 0) {
        for (int i = 0; i < przeczytane; i++) {
            printf("%02X ", bufor[i]);
            if ((i + 1) % 4 == 0) {
                printf(" ");
            }
        }

        for (int i = przeczytane; i < ROZMIAR_BUFORA; i++) {
            printf("   ");
            if ((i + 1) % 4 == 0) {
                printf(" ");
            }
        }

        printf(" ");

        for (int i = 0; i < przeczytane; i++) {
            if (bufor[i] >= 32 && bufor[i] <= 126) {
                printf("%c", bufor[i]);
            } else {
                printf(".");
            }
        }

        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uzycie: %s [plik]\n", argv[0]);
        return 1;
    }

    FILE *plik = fopen(argv[1], "rb");
    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        return 1;
    }

    wypisz_heksadecymalne(plik);

    fclose(plik);

    return 0;
}
