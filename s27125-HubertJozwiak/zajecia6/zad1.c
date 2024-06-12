#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

static void handler(int sig) {
  printf("Got signal: %d\n", sig);
}

int main() {
  struct sigaction sa;
  int pid = getpid();

  printf("PID: %d\n", pid);

  sa.sa_handler = handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  sigaction(SIGUSR1, &sa, NULL);

  while (1) {
    if (pause() == -1) {
      break;
    }
  }

  return 0;
}
