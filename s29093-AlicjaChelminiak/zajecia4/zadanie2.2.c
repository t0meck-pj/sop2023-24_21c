#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file = stdin;

    if (argc > 1) {
        file = fopen(argv[1], "r"); 
        if (file == NULL) {
            perror("Nie można otworzyć pliku");
            return 1;
        }
    }

    int number;
    while (fscanf(file, "%d", &number) == 1) {
        printf("Odczytano liczbę: %d\n", number);
    }

    if (file != stdin) {
        fclose(file);
    }

    return 0;
}