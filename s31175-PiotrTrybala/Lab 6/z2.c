#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Wyrkyto probe uruchomienia drugiej instancji programu.\n");
    }
    else if (signum == SIGINT)
    {
        remove("/tmp/lock");
        exit(0);
    }
}

int main() {
    FILE* fp;
    char row[6];
    int pid = getpid();
    signal(SIGINT, handler);
    signal(SIGUSR1, handler);
    
    if (access("/tmp/lock", F_OK) == 0) {
        fp = fopen("/tmp/lock", "r");
        fgets( row, 6, fp);
        kill(atoi(row), SIGUSR1);
        printf("row pid: %s, my pid: %i", row, pid);
        fclose(fp);
        return 0;
    }
    else {
        printf("mojpid: %i", pid);
        fp = fopen("/tmp/lock", "w");
        fprintf(fp, "%i", pid);
        fclose(fp);
    }
    

    while(1) {
        printf("Czekam na sygnal\n");
        sleep(5);
    }

    return 0;
}