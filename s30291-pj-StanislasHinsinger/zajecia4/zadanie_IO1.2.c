#include<stdio.h>
#include<stdlib.h>

/* extended table with size and values pointer; */
struct Table 
{
    int size;
    int *values;
};

int fileRead(char *path, struct Table *table);
void consoleRead(struct Table *table);

int main(int argc, char **argv) {
    int i = 0;
    struct Table table;

    if(argc > 1) {
        if(!fileRead(argv[1], &table)) /* jezeli plik nie znaleziony zwraca 0 (false); */
            return 1; 
    }
    else consoleRead(&table);

    for (i = table.size - 1; i >= 0 ; i--) {
        printf("%i\n", table.values[i]); 
    }

    free(table.values);

    return 0;
}

int fileRead(char *path, struct Table *table) {
    int i = 0;
    FILE *file = fopen(path, "r");

    if(file == NULL) {
        printf("Nie mozna bylo otworzyc pliku: %s\n", path);
        return 0;
    }

    fscanf(file, "%i", &table->size); /* pobieranie ilosc elementow; */

    table->values = calloc(table->size, sizeof(int)); /* alokacja pamieci; */

    for (; i < table->size; i++) {
        fscanf(file, "%i", &table->values[i]); /* zapis wartosci; */
    }

    fclose(file);

    return 1;
}

void consoleRead(struct Table *table) {
    int i = 0;
    scanf("%i", &table->size); /* pobieranie ilosc elementow; */

    table->values = calloc(table->size, sizeof(int)); /* alokacja pamieci; */

    for (; i < table->size; i++) {
        scanf("%i", &table->values[i]); /* zapis wartosci; */
    }
}



