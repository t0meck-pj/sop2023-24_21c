#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    int id = 0, i, status;
    for (i = 0; i < 100; i++)
    {
        if (id == 0)
            id = fork();
        if (id != 0)
        {
            waitpid(id, &status, 0);
            break;
        }
    }

    return 0;
}
