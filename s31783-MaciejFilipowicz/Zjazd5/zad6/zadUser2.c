#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    char buf[BUFSIZ];

    fd = open("/tmp/chat_fifo", O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Wpisz wiadomość (lub 'exit' aby zakończyć):\n");

    while (1) {
        fgets(buf, BUFSIZ, stdin);

        if (strncmp(buf, "exit", 4) == 0) {
            break;
        }

        ssize_t nbytes = write(fd, buf, strlen(buf) + 1);
        if (nbytes == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    close(fd);

    return 0;
}