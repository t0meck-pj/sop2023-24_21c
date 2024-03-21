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
> **W tym konkretnym procesie instalacyjnym zostanie wykorzystana wersja obrazu instalatora `Small Installation Image`,** poniewaz bedziemy instalowali system z dostepem do internetu i taka wersja bedzie szybsza do pobrania przez hosta.

### Name and Operating System
| Opcja |  Opis |
| --- | --- |
| Nazwa | Tutaj wprowadzamy nazwe naszego systemu operacyjnego do rozpozniania wirtualnych maszyn. <br>***Dla tego procesu instalacyjnego wykorzystamy: `Debian 12 - Server`.*** |
| Folder | Tutaj wybieramy folder gdzie ma zostac zainstalowany nasz system i wszystkie jego pliki powiazane z maszyna wirtualna i srodowiskiem VirutalBox. <br>***Dla tego procesu instalacyjnego wykorzystamy: `.../.../VirtualBox/Systemy`.*** |
| ISO Image | Tutaj wybieramy obraz systemu w postaci pliku **.iso** (moze to byc obraz gotowego systemu lub instalatora) <br>***Dla tego procesu instalacyjnego wykorzystamy: `wczesniej pobrany obraz instalatora systemu Debian 12`.*** |
| Typ  | Tutaj wybieramy rodzine wykorzystywanego systemu operacyjnego, jezeli jest to dystrybucja z rodziny Windows to wybieramy Microsoft Windows, jezeli jest to dystrybucja z rodziny Mac OS to wybieramy Mac Os X [warto podkreslic, ze formalnie powinno sie instalowac systemy z rodziny Mac OS X tylko na systemie hosta Mac OS), jezeli jest to dystrybucja z rodziny Linux (Ubuntu, Debian, Fedora itd.) to wybieramy Linux. <br>***Dla tego procesu instalacyjnego wybieramy: `Linux (poniewaz Debian nalezy do tej rodziny systemow)`.*** |
| Wersja | Tutaj nalezy wprowadzic wersje systemu jaka bedzie wykorzystywana. (np. Typ = Microsoft Windows, Wersja = Windows 10) <br>***Dla tego procesu instalacyjnego wybieramy: `Debian (64-bit)`.*** |
| Skip Unattended Installation | Opcja ta pozwala na pominiecie automatycznego wykonania procesow instalacyjnych przez VirtualBox. <br>***Dla tego procesu instalacyjnego: `opcja ta ma byc zaznaczona`.*** |
> [!WARNING]
> *Warto podkreslic, ze jezeli na liscie wersji systemow nie znajduja sie opcje 64-bitowych systemow, to oznacza, ze system hosta jest systemem 32-bitowym lub jest uruchomiona dodatkowa wirtualizacja jak np. HyperV, ktora wplywa na to srodowisko wirtualizacyjne.*
### Unattended Install

| Opcja |  Opis |
| --- | --- |
| Username and Password | Tutaj wprowadzamy dane konta uzytkownika jakie ma zostac utworzone. (bedzie sie go stosowac do zalogowania do systemu) |
| Additional Options | Tutaj znajduja sie dodatkowe opcje, ktore beda wykonane podczas automatycznej instalacji. <br> `Hostname:` nazwa komputera w sieci <br> `Domain Name:` nazwa domeny sieci do ktorej ten system bedzie podpiety |

> [!CAUTION]
> **Dla tego rodzaju instalacji systemu nie bedziemy korzystac z zadnych z opcji w kategorii `Unattended Install`,** poniewaz proces instalacji zostanie wykonany manualnie, z wyborem spacjalnych ustawien, aby system ten byl odpowiednio przygotowany pod wykorzystanie serwerowe.

### Hardware

| Opcja |  Opis |
| --- | --- |
| RAM | Tutaj wprowadzamy ilosc ramu jaka chcemy przydzielic wirtualnemy systemowi. (Nie powinno sie przydzielac wszystkich dostepnych zasobow hosta) [nalezy takze dokonac rozsadnego przydzialu zasobow, ktorych rzeczywiscie ewentualna maszyna moze wykorzystac] <br>***Dla tego procesu instalacyjnego ustawimy: `2048 MB`.*** |
| Processors | Tutaj wybiramy ile dostepnych watkow hosta chcemy przydzielic wirutalnej maszynie. (Nie powinno sie przydzielac wszystkich dostepnych watkow hosta) <br>***Dla tego procesu instalacyjnego ustawimy: `2 CPU`*** ( dzieki temu srodowisko serwerowe bedzie moglo w pelni wykorzystac potencjal ewentualnych podstawowych aplikacji wielowatkowych, a sam proces instalacji bedzie szybszy ) |
| Enable EFI | Opcja ta sluzy do obslugi `Extensible Firmware Interface`, ktory zastepuje standardowy interfejs firmware'u komputera `BIOS`. Posiada on lepsze wsparcie i wykorzystanie nowszego sprzetu i dodatkowe rozszerzenia np. podpisow cyfrowych umozliwiajacych korzystanie z **Secure Boot** i weryfikacji podpisow cyfrowych systemu i sterownikow. Opcje ta zaznacza sie glownie w przypadku korzystania z wirtualnej maszyny w sposob Desktopowy, gdzie instalujemy systemy pokroju Windows 10/11, czy Mac OS. Dla systemow instalowanych z mysla o serwerowym wykorzystaniu jak Ubuntu czy Debian nie bedzie to raczej w pelni wykorzystywane.  <br>***Dla tego procesu instalacyjnego: `opcja ta ma byc odznaczona`.***  |

> [!TIP]
> *Minimalne zasoby potrzebne dla danego systemu zawsze mozna znalezc na stronie dystrybutora. W przypadku rodziny systemow `Debian` te minimalne wymagania mozna znalezc na [oficjalnej stronie Debian.org](https://www.debian.org/releases/stable/i386/ch03s04.en.html)*











