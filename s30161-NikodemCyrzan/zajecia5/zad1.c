#include <stdio.h>
#include <unistd.h>

int main()
{
    char inp;

    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    scanf("%c", &inp);

    return 0;
}
