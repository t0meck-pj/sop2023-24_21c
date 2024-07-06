#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    char i;
    printf("%ld\n%ld\n", (long)getpid(), (long)getppid());
    while(i!='z') {
        printf("Podaj wartosc (z aby zakonczyc program): ");
        scanf("%c",&i);
    }
    printf("koniec\n");
    return 0;
}