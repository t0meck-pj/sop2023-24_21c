#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    char *path = argv[1];
    int count, i;
    int *values;

    FILE *file = fopen(path, "r");

    if(file == NULL) {
        printf("Nie mozna bylo otworzyc pliku!\n");
        return 0;
    }

    fscanf(file, "%i", &count);

    values = calloc(count, sizeof(int));

    if(values == NULL) {
        prinft("Blad z alokacja!");
        exit(1);
    }

    for(i = 0; i < count; i++) {
        fscanf(file, "%i", &values[i]);
        printf("%i\n", values[i]);
    }

    fclose(file);
    free(values);

    return 0;
}



