#include <stdio.h>

int main() {
    int wysokosc;

    printf("Podaj wysokosc choinki: ");
    scanf("%d", &wysokosc);

    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j < wysokosc - i - 1; j++) {
            printf(" ");
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
