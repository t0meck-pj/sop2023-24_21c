#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>

int sum(int);
void printOdd(int);

int main() {
    int arg = 0;
    scanf("%i", &arg);

    if(fork() > 0) {
        int result = sum(arg);
        wait(NULL);
        printf("%i\n", result);
    }
    else {
        printOdd(arg);
        printf("\n");
    }

    return 0;
}

int sum(int n) {
    int i; 
    int sum = 0;
    for(i = 0; i < n; i++) {
        sum += i;
    }

    return sum;
}

void printOdd(int n) {
    int i;

    for(i = 0; i < n; i++) {
        if(i % 2 == 1) printf("%i ", i);
    }
}



