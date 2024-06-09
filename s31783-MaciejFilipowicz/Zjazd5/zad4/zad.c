#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100

void create_child_process(int process_number, int max_processes) {
    if (process_number >= max_processes) {
        return;
    }

    pid_t pid = fork();
    if (pid == 0) { 
        printf("Child %d created by parent %d\n", getpid(), getppid());
        create_child_process(process_number + 1, max_processes);
        exit(0);
    } else if (pid > 0) { 
        wait(NULL);
        printf("Parent %d waited for child %d to finish\n", getpid(), pid);
    } else { 
        perror("Fork failed");
        exit(1);
    }
}

int main() {
    create_child_process(1, MAX_PROCESSES);
    return 0;
}