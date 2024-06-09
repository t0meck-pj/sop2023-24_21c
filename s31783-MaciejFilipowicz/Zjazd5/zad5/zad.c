#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;
    
    for (int i = 0; i < 100; ++i) {
        child_pid = fork();
        
        if (child_pid == 0) { 
            printf("Proces potomny nr %d uruchomiony\n", i+1);
            exit(0);
        } else if (child_pid < 0) { 
            perror("fork");
            exit(1);
        }
    }
    
    for (int i = 0; i < 100; ++i) {
        pid_t terminated_pid = waitpid(-1, &status, 0);
        if (terminated_pid > 0) {
            printf("Proces potomny o PID: %d zakończony\n", terminated_pid);
        }
    }
    
    printf("Wszystkie procesy potomne zakończone.\n");
    
    return 0;
}
