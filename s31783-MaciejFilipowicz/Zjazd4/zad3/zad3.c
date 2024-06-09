#include <stdio.h>

int max(int a, int b);
int min(int a, int b);
int suma(int a, int b);

int main() {
    int (*funkcje[3])(int, int) = {max, min, suma};

    int id, ilosc;
    scanf("%d %d", &id, &ilosc);
    int v;
    scanf("%d", &v);

    for (int i = 1; i < ilosc; i++) {
        int liczba;
        scanf("%d", &liczba);
        v = funkcje[id](v, liczba);
    }

    printf("%d\n", v);

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int suma(int a, int b) {
    return a + b;
}
