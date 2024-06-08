#include <stdio.h>

int main() {
    int liczba1;
    int liczba2;
    int suma;

    printf("Podaj pierwsza liczbe: ");
    scanf("%d", &liczba1);

    printf("Podaj druga liczbe: ");
    scanf("%d", &liczba2);

    suma = liczba1 + liczba2;
    printf("Suma ma wartosc: %d\n", suma);

    return suma % 256;
}
