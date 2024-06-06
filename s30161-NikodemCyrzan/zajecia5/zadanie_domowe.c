#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void createTree(int i, int depth)
{
    int j;
    pid_t pid;

    if (i > depth)
        return;

    for (j = 0; j < 2; j++)
    {
        if (pid == 0)
            createTree(i + 1, depth);
        else
            return;
    }
}

int main()
{
    int input;

    createTree(0, 1);
    wait(NULL);

    scanf("%d", &input);
    return 0;
}
