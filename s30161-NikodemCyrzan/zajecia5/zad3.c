#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int sum, i, id, status;
    for (i = 1; i < atoi(argv[1]); i++)
        sum += i;

    id = fork();
    if (id == 0)
    {
        printf("Dziecko:\n");
        for (i = 1; i < atoi(argv[1]); i++)
            if (i % 2 != 0)
                printf("%d\n", i);
    }

    waitpid(id, &status, 0);

    if (id != 0)
        printf("Rodzic: %d", sum);
    return 0;
}
