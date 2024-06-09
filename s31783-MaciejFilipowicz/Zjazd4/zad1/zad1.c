#include <stdio.h>
#include <stdlib.h>

void read_numbers(FILE *file) {
    int count;

    if (fscanf(file, "%d", &count) != 1) {
        fprintf(stderr, "Błąd: nie można odczytać liczby elementów.\n");
        return;
    }

    int *numbers = (int *)malloc(count * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Błąd: nie można zaalokować pamięci.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (fscanf(file, "%d", &numbers[i]) != 1) {
            fprintf(stderr, "Błąd: nie można odczytać liczby.\n");
            free(numbers);
            return;
        }
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc == 1) {

        file = stdin;
    } else if (argc == 2) {
        // Wczytywanie z pliku
        file = fopen(argv[1], "r");
        if (file == NULL) {
            fprintf(stderr, "Błąd: nie można otworzyć pliku %s.\n", argv[1]);
            return 1;
        }
    } else {
        fprintf(stderr, "Błąd: niepoprawna liczba argumentów.\n");
        return 1;
    }

    read_numbers(file);

    if (argc == 2) {
        fclose(file);
    }

    return 0;
}
