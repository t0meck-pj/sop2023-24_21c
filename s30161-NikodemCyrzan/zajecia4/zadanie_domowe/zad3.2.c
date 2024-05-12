#include <stdio.h>

struct
{
    int a;
    int b;
} fibonacci = {0, 0};

int fibonacciNext()
{
    int v = fibonacci.a + fibonacci.b;
    fibonacci.a = fibonacci.b;
    fibonacci.b = v;

    if (fibonacci.b == 0)
        fibonacci.a = 1;
    return v;
}

int main(int argc, char **argv)
{
    int i;
    for (i = 0; i < 10; i++)
        printf("%d\n", fibonacciNext());

    return 0;
}
