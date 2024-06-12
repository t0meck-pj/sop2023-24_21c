#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LOCKFILE "/tmp/lock"

static void handler(int sig) {
  if (sig == SIGUSR1) {
    printf("Wyrkyto probe uruchomienia drugiej instancji programu.\n");
  } else if (sig == SIGINT) {
    remove(LOCKFILE);
    exit(0);
  } else {
    printf("Got signal: %d\n", sig);
  }
}

int main() {
  if (access(LOCKFILE, F_OK) == 0) {
    /* Plik istnieje */
    FILE* file = NULL;
    int pid = 0;

    printf("Another instance is already running\n");

    file = fopen(LOCKFILE, "r");
    if (file == NULL) {
      perror("fopen");
      return 1;
    }

    fscanf(file, "%d", &pid);

    kill(pid, SIGUSR1);

    fclose(file);
  } else {
    /* Plik nie istnieje */
    FILE* file = NULL;
    int pid = getpid();

    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handler;
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);

    printf("PID: %d\n", pid);

    /* Zapisujemy PID obecnego procesu */
    file = fopen(LOCKFILE, "w");
    if (file == NULL) {
      perror("fopen");
      return 1;
    }

    fprintf(file, "%d\n", pid);
    fclose(file);

    while (1) {
      sleep(0);
    }

    remove(LOCKFILE);
  }

  return 0;
}