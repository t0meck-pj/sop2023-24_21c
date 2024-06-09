#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    char buf[BUFSIZ];

    mkfifo("/tmp/chat_fifo", 0666);

    // Otwieranie potoku do odczytu
    fd = open("/tmp/chat_fifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Czekanie na wiadomość...\n");

    while (1) {
        ssize_t nbytes = read(fd, buf, BUFSIZ);
        if (nbytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        if (nbytes == 0) {
            printf("Klient zamknął połączenie.\n");
            break;
        }
        printf("Otrzymano: %s", buf);
    }

    close(fd);
    unlink("/tmp/chat_fifo");

    return 0;
}