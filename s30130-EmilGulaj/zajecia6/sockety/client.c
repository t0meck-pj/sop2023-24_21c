#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void receive_file(int socketFileDescriptor, char *filename){
    FILE *file = fopen(filename, "r");
    int file_size = ftell(file);
    char buffer[BUFFER_SIZE];
    int bytes_received;

    recv(socketFileDescriptor, &file_size, sizeof(file_size), 0);

    if (file_size == -1) {
        printf("Nie można otworzyć pliku na serwerze\n");
        return;
    }

    if (file == NULL) {
        perror("Nie można utworzyć pliku");
        return;
    }

    while (file_size > 0 && (bytes_received = recv(socketFileDescriptor, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
        file_size -= bytes_received;
    }
    fclose(file);
}


int main() {
    int socketFileDescriptor = 0;
    char filename[BUFFER_SIZE];
    struct sockaddr_in serv_addr;

    if ((socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    if (connect(socketFileDescriptor, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    printf("Podaj nazwę pliku do pobrania: ");
    scanf("%s", filename);
    send(socketFileDescriptor, filename, strlen(filename), 0);

    receive_file(socketFileDescriptor, filename);

    close(socketFileDescriptor);
    return 0;
}
