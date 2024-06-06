#define _POSIX_SOURCE
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#define LOCK_PATH "/tmp/s30291-sop-signals-2.lock"

bool close_triggered = false;

void init_lock();
void init_signal();

void create_lock();
void read_lock(FILE *file) ;

void signal_handler(int signalnum);

int main() {
    init_lock();
    init_signal();

    while(!close_triggered) {
        sleep(1);
    }

    remove(LOCK_PATH);

    return 0;
}

void init_lock() {
    FILE *file = fopen(LOCK_PATH, "r");

    if(file == NULL) {
        create_lock();
        return;
    }
    
    read_lock(file);
}

void create_lock() {
    FILE *file = fopen(LOCK_PATH, "w");

    if(file == NULL) {
        printf("WYSTAPIL BLAD Z TWORZENIEM PLIKU!");
        exit(1);
    }

    fprintf(file, "%d", getpid());
    fclose(file);
}

void read_lock(FILE *file) {
    pid_t pid = 0;

    fscanf(file, "%d", &pid);
    fclose(file);

    kill(pid, SIGUSR1);

    printf("Zostala już uruchomiona instancja tego programu!\n");
    exit(1);
}

void init_signal() {
    struct sigaction act;
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    
    sigemptyset(&act.sa_mask);

    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGINT, &act, NULL);
}

void signal_handler(int signalnum) {
    if(signalnum == SIGUSR1) {
        printf("Wykryto probe uruchomienia drugiej instancji programu!\n");
        fflush(stdout);
    }
    if(signalnum == SIGINT) {
        printf("Rozpoczęto procedurę zamykania programu!\n");
        fflush(stdout);
        close_triggered = true; 
    }
} 


