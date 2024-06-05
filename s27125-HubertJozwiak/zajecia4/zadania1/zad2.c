#include <stdio.h>

int main() {
    int n;
    int sum = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }

        sum += n;
    }

    return sum;
}

/* Zwróconą wartośc możemy wyświetlić za pomocą `echo $?` */