#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Użycie: %s <wartość>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int value = atoi(argv[1]);

    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        printf("Liczby nieparzyste: ");
        for (int i = 1; i <= value; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        wait(NULL);
        printf("Suma liczb od 0 do %d: %d\n", value, value * (value + 1) / 2);
    }

    return 0;
}
