#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define LOG_FILE "server.log"

/*TODO
- problem naruszenia pamieci
- dodać logi
*/

int socketFileDescriptor;

void shutDownServer(int sig) {
    printf("\nZamykanie serwera...\n");
    close(socketFileDescriptor);
    exit(EXIT_SUCCESS);
}

void send_file(int acceptFileDescriptor, char *filename){
    FILE *file = fopen(filename, "r");
    int file_size = ftell(file);
    char buffer[BUFFER_SIZE];
    int bytes_read;
   
    if (file == NULL){
        int file_size = -1;
        send(acceptFileDescriptor, &file_size, sizeof(file_size), 0);
        perror("Nie można otworzyć pliku");
        return;
    }

    fseek(file, 0, SEEK_END);
    fseek(file, 0, SEEK_SET);
    send(acceptFileDescriptor, &file_size, sizeof(file_size), 0);

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0){
        send(acceptFileDescriptor, buffer, bytes_read, 0);
    }
    fclose(file);
}

int main() {
    struct sockaddr_in serv_addr, cli_addr;
    
    char buffer[BUFFER_SIZE];

    int acceptFileDescriptor;
    
    socklen_t client_addr_len = sizeof(cli_addr);

    signal(SIGINT, shutDownServer);

    if ((socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Socket is opened\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socketFileDescriptor, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        close(socketFileDescriptor);
        exit(EXIT_FAILURE);
    }

    printf("Server bound to socket\n");

    if (listen(socketFileDescriptor, 5) < 0) {
        perror("listen failed");
        close(socketFileDescriptor);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening\n");

    while (1) {
        acceptFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&cli_addr, (socklen_t *)&client_addr_len);
        printf("Server got incoming connection\n");
        
        read(acceptFileDescriptor, buffer, BUFFER_SIZE);
        send_file(acceptFileDescriptor, buffer);
        close(acceptFileDescriptor);
    }

    return 0;
}
