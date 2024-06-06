#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define FILE_PATH "/tmp/chat.txt"
#define BUFFER_SIZE 256

void write_messages(const char *nickname) {
    FILE *file;
    char buffer[BUFFER_SIZE];

    
    file = fopen(FILE_PATH, "a");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    printf("Wpisz wiadomość (exit, aby zakończyć):\n");

    while (1) {
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);

        
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        
        if (fprintf(file, "%s: %s\n", nickname, buffer) < 0) {
            perror("fprintf");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        fflush(file); 
    }

    fclose(file);
}

void read_messages() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long current_position = 0;

    while (1) {
        
        file = fopen(FILE_PATH, "r");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

       
        fseek(file, current_position, SEEK_SET);

       
        while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
            printf("%s", buffer);
            current_position = ftell(file);
        }

        fclose(file);
        sleep(1);
    }
}

int main() {
    pid_t pid;
    char nickname[50];

    printf("Podaj swój nick: ");
    fgets(nickname, 50, stdin);

    
    nickname[strcspn(nickname, "\n")] = 0;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        
        read_messages();
        exit(EXIT_SUCCESS);
    } else {
        
        write_messages(nickname);
        wait(NULL); 
        printf("Czat zakończony.\n");
    }

    return 0;
}
