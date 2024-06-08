#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int liczba;
    int *liczby = NULL;
    int liczby_w_ciagu = 0;
    FILE *plik;

    if (argc == 1) {
        plik = stdin;
    } else if (argc == 2) {
        plik = fopen(argv[1], "r");
        if (plik == NULL) {
            printf("BLAD. Nie udalo sie poprawnie otworzyc pliku.\n");
            return 1;
        }
    } else {
        printf("Uzycie: %s [plik]\n", argv[0]);
        return 1;
    }

    if (fscanf(plik, "%d", &liczby_w_ciagu) != 1) {
        printf("BLAD. Nie udalo sie wczytac liczby elementow.\n");
        if (plik != stdin) fclose(plik);
        return 1;
    }

    liczby = (int *)malloc(liczby_w_ciagu * sizeof(int));
    if (liczby == NULL) {
        printf("BLAD. Nie udalo sie zaalokowac pamieci.\n");
        if (plik != stdin) fclose(plik);
        return 1;
    }

    for (int i = 0; i < liczby_w_ciagu; i++) {
        if (fscanf(plik, "%d", &liczba) != 1) {
            printf("BLAD. Nie udalo sie wczytac liczby.\n");
            free(liczby);
            if (plik != stdin) fclose(plik);
            return 1;
        }
        liczby[i] = liczba;
    }

    if (plik != stdin) fclose(plik);

    for (int i = liczby_w_ciagu - 1; i >= 0; i--) {
        printf("%d\n", liczby[i]);
    }

    free(liczby);

    return 0;
}
