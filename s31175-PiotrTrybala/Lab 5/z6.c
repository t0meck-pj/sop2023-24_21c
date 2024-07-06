#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp;
    char *my_row = (char*)malloc(sizeof(char)*128);
    char *row = (char*)malloc(sizeof(char)*128);
    char *rowcom = (char*)malloc(sizeof(char)*128);
    char *pid = (char*)malloc(sizeof(char)*32);
    char exi[] = "exit";
    int sep;
    int my_pid = getpid();
    char *nickname = (char*)malloc(sizeof(char)*32);
    char *your_nickname = (char*)malloc(sizeof(char)*32);

    printf("Podaj swój nickname: ");
    scanf("%s", your_nickname);
    

    if ((sep=fork())==0){
        while(0 == kill(getppid(), 0)) {
            fp = fopen("/tmp/chat", "a+");
            if(fp==NULL)
                printf("nie dziala");
            fgets( row, 128, fp);
            fgets( nickname, 32, fp);
            fgets( pid, 32, fp);
            if (atoi(pid) != my_pid && strcmp(rowcom,row) != 0) {
                printf("%s(%s): %s", nickname, pid, row);
                strcpy(rowcom, row);
            }
            fclose(fp);
    }
    return 0;
    }
    
    fgets(my_row, 128, stdin);
    while(1) {
        fgets(my_row, 128, stdin);
        if(strcmp(row,exi) != 0)
            return 0;
        printf("%s(Ty:%i): %s\n", your_nickname, my_pid, my_row);
        remove("/tmp/chat");
        fp = fopen("/tmp/chat", "a+");
        fprintf(fp, "%s", my_row);
        fprintf(fp, "%s\n", your_nickname);
        fprintf(fp, "%i", my_pid);
        fclose(fp);
    }
    return 0;
}