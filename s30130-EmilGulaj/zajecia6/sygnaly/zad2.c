#define _POSIX_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <wait.h>
#include <fcntl.h>

#define FILE_PATH "/tmp/lock8"

void sigHandler(int sig){
    printf("Wyrkyto probe uruchomienia drugiej instancji programu.\n");
}


void ctrlcHandler(int sig){
    if (remove(FILE_PATH) == 0)
        printf("\nsuccess\n");
    exit(EXIT_SUCCESS);
}

int main()
{
    FILE *file = NULL;
    pid_t pid;
    struct sigaction new_action, old_action;
    
    file = fopen(FILE_PATH, "r");
    

    if (file == NULL) { /*Plik nie istnieje*/
        pid = getpid();
        file = fopen(FILE_PATH, "w");
        fprintf(file, "%d\n", pid);
        fclose(file);

        new_action.sa_handler = sigHandler;
        sigemptyset(&new_action.sa_mask);
        new_action.sa_flags = 0;
        sigaction(SIGUSR1, &new_action, NULL);
        

        old_action.sa_handler = ctrlcHandler;
        sigemptyset(&old_action.sa_mask);
        old_action.sa_flags = 0;
        sigaction(SIGINT, &old_action, NULL);
    
        while (1){
            sleep(1);
        }
    }
    else { /*Plik istnieje*/
        fscanf(file, "%d", &pid);
        kill(pid, SIGUSR1);
    }

    return 0;
}
