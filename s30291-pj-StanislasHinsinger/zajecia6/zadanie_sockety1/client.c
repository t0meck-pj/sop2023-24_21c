#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

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

void init(char *host, char *port);

void info(char *msg);
void error(char *msg);
void logtext(char *prefix, char *msg);

int main(int argc, char **argv) {
    if(argc < 3) {
        error("Nie podano hosta i portu!");
    }

    init(argv[1], argv[2]);
    return 0;
}

void init(char *host, char *port) {
    int cliSockFile;
    int srvInfoSockFile;

    struct sockaddr_in srvAddr;
    struct addrinfo *srvAddrInfo;
    struct addrinfo hints;

    info("Laczenie z serwerem!");

    cliSockFile = socket(AF_INET, SOCK_STREAM, 0);
    if (cliSockFile < 0) {
        error("Nie mozna bylo otwrzyc socketu do serwera!");
    }

    bzero(&hints, sizeof(struct addrinfo));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;

    srvInfoSockFile = getaddrinfo(host, port, &hints, &srvAddrInfo);

    if (srvInfoSockFile != 0){
        error("Nie udalo sie uzyskac adresu docelowego serwera!");
        freeaddrinfo(srvAddrInfo);
        close(cliSockFile);
        exit(1);
    }

    bzero((char *) &srvAddr, sizeof(srvAddr));

    srvAddr.sin_family = AF_INET;
    srvAddr.sin_port = htons(atoi(port));

    if(connect(cliSockFile, (struct sockaddr *) &srvAddr, sizeof(srvAddr)) < 0) {
        error("Nie udalo sie polaczyc z serwerem!");
        freeaddrinfo(srvAddrInfo);
        close(cliSockFile);
        exit(1);
    }

    //char *filename = calloc(255, sizeof(char));
    char *filename = "test";

    if(filename == NULL) { // calloc check
        error("WYSTAPIL BLAD Z ALOKACJA!");
        freeaddrinfo(srvAddrInfo);
        close(cliSockFile);
        return;
    }
    
    //scanf("%s", filename);

    if(write(cliSockFile, (void *) strlen(filename), sizeof(size_t)) < 0) {
        error("Error sending size!");
    }

    close(cliSockFile);

    freeaddrinfo(srvAddrInfo);
    free(filename);
}

void info(char *msg) {
    logtext("INFO", msg);
}

void error(char *msg) {
    logtext("ERROR", msg);
}

void logtext(char *prefix, char *msg) {
    printf("%s: %s\n", prefix, msg);
}