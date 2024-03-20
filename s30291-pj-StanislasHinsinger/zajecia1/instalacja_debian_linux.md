# Instalacja Systemu Debian 12 (do wykorzystania serwerowego)

## Tworzenie wirtualnej maszyny
1. Nalezy uruchomic aplikacje `VirtualBox`. W przypadku jej braku na systemie, mozna ja pobrac ze strony https://www.virtualbox.org 
2. Do stworzenia nowej maszyny wirtualnej wybieramy opcje `Maszyna` [znajdujaca sie na gornym pasku] i tam wybieramy opcje `Nowa`.
3. Na ekranie wyswietli sie okno `Utworz wirtualna maszyne`. 

> [!TIP]
> W przypadku pierwszego tworzenia maszyny wirtualnej, kreator bedzie ustawiony w trybie "Przewodnika", ze wzgledu na latwieszy dostep do wyboru opcji, nalezy przelaczyc sie na tryb "Eksperta" (przycisk na dole okna).

> [!NOTE]
> Do kolejnych etapow potrzebne bedzie posiadanie na komputerze pliku obrazu instalatora systemu Debian 12. Plik ten mozna pobrac bezposrednio z [oficjalnej strony](https://www.debian.org/distrib/). <br>
> <br> *Jezeli posiadamy dostep do internetu na wirutalnej maszynie to wybieramy `Small Installation Image` w przeciwnym wypadku powinnismy pobrac `Complete Installation Image` (zawiera on wszystkie potrzebne pakiety instalacyjne, bez potrzeby dodatkowego klonowania z innego serwera podczas instalacji) <br><br> Nalezy takze wybrac odpowiedni rodzaj pliku instalacyjnego, w przypadku wirtualnej maszyny, bedziemy instalowali system na 64-bitowej architekturze `amd64`.*

## Kategorie kreatora
> [!IMPORTANT]
> W tym konkretnym procesie instalacyjnym zostanie wykorzystana wersja obrazu instalatora `Small Installation Image`, poniewaz bedziemy instalowali system z dostepem do internetu i taka wersja bedzie szybsza do pobrania przez hosta.

| Opcja |  Name and Operating System |
| --- | --- |
| Nazwa | Tutaj wprowadzamy nazwe naszego systemu operacyjnego do rozpozniania wirtualnych maszyn. <br>***Dla tego procesu instalacyjnego wykorzystamy: `Debian 12 - Server`.*** |
| Folder | Tutaj wybieramy folder gdzie ma zostac zainstalowany nasz system i wszystkie jego pliki powiazane z maszyna wirtualna i srodowiskiem VirutalBox. <br>***Dla tego procesu instalacyjnego wykorzystamy: `.../.../VirtualBox/Systemy`.*** |
| ISO Image | Tutaj wybieramy obraz systemu w postaci pliku **.iso** (moze to byc obraz gotowego systemu lub instalatora) <br>***Dla tego procesu instalacyjnego wykorzystamy: `wczesniej pobrany obraz instalatora systemu Debian 12`.*** |
| Typ  | Tutaj wybieramy rodzine wykorzystywanego systemu operacyjnego, jezeli jest to dystrybucja z rodziny Windows to wybieramy Microsoft Windows, jezeli jest to dystrybucja z rodziny Mac OS to wybieramy Mac Os X [warto podkreslic, ze formalnie powinno sie instalowac systemy z rodziny Mac OS X tylko na systemie hosta Mac OS), jezeli jest to dystrybucja z rodziny Linux (Ubuntu, Debian, Fedora itd.) to wybieramy Linux. <br>***Dla tego procesu instalacyjnego wybieramy: `Linux (poniewaz Debian nalezy do tej rodziny systemow)`.*** |
| Wersja | Tutaj nalezy wprowadzic wersje systemu jaka bedzie wykorzystywana. (np. Typ = Microsoft Windows, Wersja = Windows 10) <br>***Dla tego procesu instalacyjnego wybieramy: `Debian (64-bit)`.*** |

> [!WARNING]
> *Warto podkreslic, ze jezeli na liscie wersji systemow nie znajduja sie opcje 64-bitowych systemow, to oznacza, ze system hosta jest systemem 32-bitowym lub jest uruchomiona dodatkowa wirtualizacja jak np. HyperV, ktora wplywa na to srodowisko wirtualizacyjne.*
