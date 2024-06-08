#include <stdio.h>

int (*functions[3])(int, int);

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int sum(int a, int b) {
    return a + b;
}

int main() {
    functions[0] = max;
    functions[1] = min;
    functions[2] = sum;

    int functionId, elementCount;
    printf("Podaj indeks funkcji (0 - max, 1 - min, 2 - sum): ");
    scanf("%d", &functionId);
    printf("Podaj liczbe elementow ciagu: ");
    scanf("%d", &elementCount);

    if (functionId < 0 || functionId > 2) {
        printf("Bledny indeks funkcji.\n");
        return 1;
    }

    if (elementCount <= 0) {
        printf("Liczba elementow ciagu musi byc dodatnia.\n");
        return 1;
    }

    int numbers[elementCount];
    printf("Podaj %d liczb:\n", elementCount);
    for (int i = 0; i < elementCount; i++) {
        scanf("%d", &numbers[i]);
    }

    int v = numbers[0];

    for (int i = 1; i < elementCount; i++) {
        v = functions[functionId](v, numbers[i]);
    }

    printf("Wynik funkcji: %d\n", v);
    return 0;
}
