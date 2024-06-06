#include <stdio.h>

int fibonacci(int index)
{
    if (index <= 0)
        return 0;
    if (index == 1)
        return 1;

    return fibonacci(index - 2) + fibonacci(index - 1);
}

int main(int argc, char **argv)
{
    int i;
    for (i = 0; i < 10; i++)
        printf("%d\n", fibonacci(i));

    return 0;
}
