#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

/*
    DO OSOBY SPRAWDZAJACEJ:

    Pomysl:
    - dwa procesy dzici (sync_loop i input_loop)
    - sync_loop = petla, ktora bedzie otwierac plik, czytac jego zawartosc,
      sprawdzac ilosc lini czy jest wieksza od ostatniej zczytanej ilosci,
      jezeli tak, to wypisac wszystkie linie przekraczajace ostatni zakres,
      wyswietlic na ekranie, zamknac plik
    - input_loop = petla, ktora bedzie w nieskonczonosc czekac na input
      uzytkownika gdzie za kazdym razem jest prefix "nazwa_klienta: ",
      gdy go dostanie to otwiera plik ("a+"), dodaje wprowadzony tekst,
      zapisuje go, dokonuje ++ na ostatnie zczytanej ilosci lini.

    Problemy:
    - gdy dokona sie printf zostanie za kazdy razem dodane w linijce przed tekst
      ktory mial byc z prefixu od sync_loop "nazwa_klienta: ", jezeli nawet
      nie wprowadzac tego prefixu to wtedy i tak wyswietli text z wprowadzonego buffora.
    - petla sync_loop i petla input_loop moga sie ze soba klocic jezeli chodzi o dostep do pliku
      (trzeba delay zrobic, (usleep) nie wykrywalo mi, a sleep daje tylko sekundy co nie
      rozwiazuje jakkolwiek sensownie problemu)
    - mozna by bylo zrobic jakas glebsza logike powiazana z dzialaniem socketow (nie dokonca),
      tylko ze na pliku, ze clienci dokonuja ciaglego "streamingu" tego co sie dzieje, taki
      jakby live-update.

    Zadanie jest nie wykonane, ze wzgledu na brak wystraczajacej wiedzy. (wielokrotnie scrapowalem ten plik)
    Prosilbym o nakierowanie jakbym mogl te problemy ewentualnie rozwiazac, albo jaka inna droge moge obrac?

    Pozdrawiam,

    Udanego Dnia!
*/

const char* FILE_PATH = "/tmp/sop_chat_app.tmp";
char *client;

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Nie wprowadzono nazwy uzytkownika!\n");
        return 0;
    }

    client = argv[1];
}

void init_input_thread_loop() {
    pid_t fork_pid = fork();

    while(fork_pid == 0 && 1) { input_thread_loop(); }
}

void init_sync_thread_loop() {
    pid_t fork_pid = fork();

    while (fork_pid == 0 && 1) { syncthread_loop(); }
}

void input_thread_loop() {

}

void sync_thread_loop() {

}







