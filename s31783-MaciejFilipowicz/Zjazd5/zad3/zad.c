#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void parent_process(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i;
    }
    printf("Suma liczb od 0 do %d wynosi: %d\n", n, sum);
}

void child_process(int n) {
    printf("Liczby nieparzyste od 1 do %d to:\n", n);
    for (int i = 1; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Użycie: %s <liczba>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    pid_t pid = fork();

    if (pid == -1) {
        perror("Błąd funkcji fork()");
        return 1;
    } else if (pid == 0) { 
        child_process(n);
    } else { 
        wait(NULL); 
        parent_process(n);
    }

    return 0;
}
