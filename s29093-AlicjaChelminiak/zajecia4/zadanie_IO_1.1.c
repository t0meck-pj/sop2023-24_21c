#include <stdio.h>
#include <stdlib.h>

int main() {
	int liczba;
	int i;
	int liczby_w_ciagu;

    FILE *PLIK = fopen("plik.txt", "r");

    if (PLIK == NULL) {
        printf("BLAD. Nie udalo sie poprawnie otworzyc pliku.\n");
        return 1;
    }


    fscanf(PLIK, "%d", &liczby_w_ciagu);

    for (i = 0; i < liczby_w_ciagu; i++) {
        fscanf(PLIK, "%d", &liczba);
        printf("%d\n", liczba);
    }

    fclose(PLIK);

    return 0;
}
