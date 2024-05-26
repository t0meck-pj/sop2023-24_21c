#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sendMessage(char *nick, char *message)
{
    FILE *tmp = tmpfile();

    fprintf(tmp, "[%s]%s\n", nick, message);
    printf("[%s]%s\n", nick, message);

    fclose(tmp);
}

void receiveMessages()
{
    FILE *tmp = tmpfile();
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, NULL, tmp)) != -1)
        printf("%s", line);

    fclose(tmp);
    if (line)
        free(line);
}

int main()
{
    char nick[20], command[8], arg1[20], message[256];
    int argInt;

    printf("Podaj swoj nick: ");
    scanf("%s", nick);

    while (1)
    {
        printf("\nWybiez jedna z komend:\n\tsend <wiadomosc>\n\treceive\n\n");

        printf("%s: ", nick);
        scanf("%7s", command);

        if (!strcmp(command, "send"))
        {
            fgets(message, 256, stdin);
            sendMessage(nick, message);
            continue;
        }

        if (!strcmp(command, "receive"))
        {
            receiveMessages();
            continue;
        }
    }
}
