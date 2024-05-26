#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    int id = 1, i;
    for (i = 0; i < 100; i++)
    {
        if (id != 0)
            id = fork();

        if (id == 0)
            exit(0);
    }

    while (wait(NULL) > 0)
    {
    }

    return 0;
}
