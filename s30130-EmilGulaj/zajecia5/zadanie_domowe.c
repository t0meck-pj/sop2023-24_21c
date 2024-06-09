#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_process_tree(int depth, int max_depth) {
    pid_t pid1, pid2;
    if (depth > max_depth) {
        return;
    }
    pid1 = fork();
    if (pid1 == 0) {
        create_process_tree(depth + 1, max_depth);
    }
    pid2 = fork();
    if (pid2 == 0) {
        create_process_tree(depth + 1, max_depth);
    }
}

int main() {
    int nothing;
    create_process_tree(0, 1);
    if (getpid() == getppid()){
        wait(NULL);
    }
    scanf("%d", &nothing);
    return 0;
}
