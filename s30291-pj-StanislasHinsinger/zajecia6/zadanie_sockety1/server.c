#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <netinet/in.h>

#define MAX_CONNECTION 5
#define FILES_PATH "files/"

/* 
    Starłem się, niestety jest to temat narazie dla mnie
    niewystarczająco zagłebiony, abym był w stanie samodzielnie
    stworzyć serwer socketowy.

    Fundamentalnie wiem mniej wiecej co wszystko w tym kodzie robi,
    tylko nie jestem w stanie zrozumieć, dlaczego to w nie jest w 
    stanie prawidlowo działać. Na cliencie write zwraca ujemne wartosc,
    co sugeruje błąd z wysłaniem, a tutaj read niewiadomo czemu odrazu
    odczytuje, gdy nawet nie zostalo wykonane jeszcze przez clienta write.

    Połaczenie jest utworzone, to akurat działa. Chociaż sposob zamykania
    programu zostawia wiele do życzenia, bo wymagane jest połaczenie jakiekolwiek,
    aby można bylo wyjść z (accept()) i przejść przez pętle.

    Całościowo program do reworku totalnego, potrzebowałbym wiecej czasu,
    aby się z tym zaznajomić, niestety nie miałem go na tyle w tym tygodniu,
    ale do kolejnych zajęć powinienem być w stanie nadrobić to zadanie,
    ponownie wielokrotnie oglądając materiały z zajęć. 

    A teraz kombinować na szybko też nie ma sensu, bo nie będę w stanie
    zaimplementować obsługi takiej która jest wymagana w kolejnych zadaniach.

 */

bool running = true;

void start(char *port);
void stop(int signum);

void info(char *msg);
void error(char *msg);
void logtext(char *prefix, char *msg);

int main(int argc, char **argv) {
    if(argc < 2) {
        error("Nie wprowadzono port na ktorym nalezy uruchomic serwer!");
        exit(1);
    }

    signal(SIGINT, stop);
    start(argv[1]);

    return 0;
}

void stop(int signum) {
    running = false;
}

void start(char *port) {
    int srvSockFile; /* Server Socket File Descriptor */
    int cliSockFile; /* Client Socket File Descriptor */

    struct sockaddr_in srvAddr, cliAddr; /* Server and Client address structures */

    if(atoi(port) < 1024 || atoi(port) > 65535) {
        error("Wprowadzony port jest ze zlego zakresu! (1024 <= port <= 65535)");
        exit(1);
    } 

    srvSockFile = socket(AF_INET, SOCK_STREAM, 0);

    if(srvSockFile < 0) {
        error("Nie mozna bylo otworzy socketu! Juz istnieje!");
        close(srvSockFile);
        exit(1);
    }

    info("Pomyslnie stworzono socket!");

    bzero((char *) &srvAddr, sizeof(srvAddr));

    srvAddr.sin_family = AF_INET;
    srvAddr.sin_port = htons(atoi(port));
    srvAddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(srvSockFile, (struct sockaddr *) &srvAddr, sizeof(srvAddr))) {
        error("Nie mozna bylo utworzyc polaczenia z socketem!");
        close(srvSockFile);
        exit(1);
    }

    info("Pomyslnie polaczono z socketem!");

    listen(srvSockFile, MAX_CONNECTION);
    info("Nasluchiwanie na przychodzace polaczenia!");

    while(running) {
        cliSockFile = accept(srvSockFile, (struct sockaddr *) &cliAddr, (socklen_t *) sizeof(cliAddr));

        info("Otrzymano nowe polaczanie!");
        {
            //size_t *fileNameLength = malloc(sizeof(size_t));

            size_t fileNameLength = 0L;

            if(fileNameLength == NULL) {
                error("WYSTAPIL BLAD Z ALOKACJA!");
                close(cliSockFile);
                continue;
            }

            read(cliSockFile, fileNameLength, sizeof(size_t));

            printf("dlugosc otrzymana: %d \n", fileNameLength);
        }

        info("Zakonczono wykonywanie odbierania!");

        close(cliSockFile);

        info("Zamknieto polaczenie!");
    }

    info("Zamykanie serwera!");
    close(srvSockFile);
}

void info(char *msg) {
    logtext("INFO", msg);
}

void error(char *msg) {
    logtext("ERROR", msg);
}

void logtext(char *prefix, char *msg) {
    printf("%s: %s \n", prefix, msg);
}







