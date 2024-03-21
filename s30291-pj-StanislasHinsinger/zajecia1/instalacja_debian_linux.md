# Instalacja Systemu Debian 12 (do wykorzystania serwerowego)

**Autorstwa:** `Stanislas Hinsinger - s30291`

## Tworzenie wirtualnej maszyny
1. Nalezy uruchomic aplikacje `VirtualBox`. W przypadku jej braku na systemie, mozna ja pobrac [z oficjalnej strony VirtualBox](https://www.virtualbox.org) 
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
| Folder | Tutaj wybieramy folder gdzie ma zostac zainstalowany nasz system i wszystkie jego pliki powiazane z maszyna wirtualna i srodowiskiem VirutalBox. <br>***Dla tego procesu instalacyjnego wykorzystamy: `...\...\VirtualBox\Systemy`.*** |
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
> **Dla tego rodzaju instalacji systemu nie bedziemy korzystac z zadnych z opcji w kategorii `Unattended Install`,** poniewaz proces instalacji zostanie wykonany manualnie, z wyborem specjalnych ustawien, aby system ten byl odpowiednio przygotowany pod wykorzystanie serwerowe.

### Hardware

| Opcja |  Opis |
| --- | --- |
| RAM | Tutaj wprowadzamy ilosc ramu jaka chcemy przydzielic wirtualnemy systemowi. (Nie powinno sie przydzielac wszystkich dostepnych zasobow hosta) [nalezy takze dokonac rozsadnego przydzialu zasobow, ktorych rzeczywiscie ewentualna maszyna moze wykorzystac] <br>***Dla tego procesu instalacyjnego ustawimy: `2048 MB`.*** |
| Processors | Tutaj wybiramy ile dostepnych watkow hosta chcemy przydzielic wirutalnej maszynie. (Nie powinno sie przydzielac wszystkich dostepnych watkow hosta) <br>***Dla tego procesu instalacyjnego ustawimy: `2 CPU`*** ( dzieki temu srodowisko serwerowe bedzie moglo w pelni wykorzystac potencjal ewentualnych podstawowych aplikacji wielowatkowych, a sam proces instalacji bedzie szybszy ) |
| Enable EFI | Opcja ta sluzy do obslugi `Extensible Firmware Interface`, ktory zastepuje standardowy interfejs firmware'u komputera `BIOS`. Posiada on lepsze wsparcie i wykorzystanie nowszego sprzetu i dodatkowe rozszerzenia np. podpisow cyfrowych umozliwiajacych korzystanie z **Secure Boot** i weryfikacji podpisow cyfrowych systemu i sterownikow. Opcje ta zaznacza sie glownie w przypadku korzystania z wirtualnej maszyny w sposob Desktopowy, gdzie instalujemy systemy pokroju Windows 10/11, czy Mac OS. Dla systemow instalowanych z mysla o serwerowym wykorzystaniu jak Ubuntu czy Debian nie bedzie to raczej w pelni wykorzystywane.  <br>***Dla tego procesu instalacyjnego: `opcja ta ma byc odznaczona`.***  |

> [!TIP]
> *Minimalne zasoby potrzebne dla danego systemu zawsze mozna znalezc na stronie dystrybutora. W przypadku rodziny systemow `Debian` te minimalne wymagania mozna znalezc na [oficjalnej stronie Debian.org](https://www.debian.org/releases/stable/i386/ch03s04.en.html)*


### Hard Disk

**W tej zakladce do wyboru sa 3 opcje:**
* **Create a Virutal Hard Disk Now:** `pozwala na stworzenie i podpiecie wirtualnego dysku twardego do tej wirtualnej maszyny wirtualnej` 
<br>( **TA OPCJE WYBIERZEMY DLA INSTALACJI SYSTEMU** )

| Opcja |  Opis |
| --- | --- |
| Location and Size | Tutaj wprowadzamy lokalizacje w ktorej chcemy aby nasz wirtualny dysk sie znalazl. <br>***Dla tego procesu instalacyjnego wybieramy: `...\...\VirtualBox\Systemy\Debian 12 - Server\Debian 12 - Server.vdi`.*** |
| Suwak Pamieci | Za pomoca tego suwaka mozemy ustawic ilosc przestrzeni dyskowej dostepnej dla danego systemu operacyjnego. <br>***Dla tego procesu instalacyjnego ustawimy: `40 GB`.*** (bedzie to przestrzen wystaczajaca na zapotrzebowania systemu i ewentualnych podstawowych uzytkownikow serwera) |
| Type and Variant | Tutaj ustawiamy jakiego typu chcemy aby ten wirtualny dysk byl. Opis kazdego rodzaju znalezc bedzie mozna w komentarzach nizej. <br>***Dla tego procesu instalacyjnego wybieramy: `VDI (VirtualBox Disk Image)`*** (poniewaz bedzie on najbardziej optymalna opcja dla naszego zastosowania tego systemu)|
| Pre-allocate Full Size | Opcja ta pozwala na bezposrednia alokacje przestrzeni dyskowej (do tej ktora zostala ustawiona). Moze to byc przydatne w przypadku, gdy chcemy zminimalizowac czas zapisu, ktory bedzie ewentualnie spowalaniany przez dynamiczne alokowanie przestrzeni przez srodowisko VirtualBox. <br>***Dla tego procesu instalacyjnego: `opcja ta ma byc odznaczona` (dynamiczne alokowanie przestrzeni nie powinno miec znaczacego wplywu na optymalne dzialanie systemu dla wykorzystania serwerowego).***|
| Split into 2GB parts | Opcja ta pozwala na podzielenie dysku na 2GB czesci. Co mogloby byc wymaganiem w przypadku korzystania z systemu plikow FAT (w ktorym maksymalna wielkosc pliku to 4GB), lub tez chcielibysmy w latwiejszy sposob przesylac mniejsze pliki dysku przez siec zamiast jednego duzego. <br>***Dla tego procesu instalacyjnego: `opcja ta ma byc odznaczona`*** |

* **Use an Exsiting Virtual Hard Disk File:** `pozwala na wybranie juz istniejacego wirtualnego dysk twardego [gdy chcemy wykorzystac juz stworzyny i zapisany system operacyjny]`
* **Do Not Add a Virtual Disk:** `nie podpina zadnego wirtualnego dysku do tej maszyny, w zamian mozna wykorzystac podczas uruchamiania sam naped optyczny, dyskietke lub usb`

> [!NOTE]
> **Typy dyskow i ich opis:** <br>* VDI - <br>* VHD - <br>* VMDK - <br>* HDD - <br>* QCOW - <br>* QED -

> [!TIP]
> *Minimalna przestrzen wymagana przez dany system zawsze mozna znalezc na stronie dystrybutora. W przypadku rodziny systemow `Debian` te minimalne wymagania mozna znalezc na [oficjalnej stronie Debian.org](https://www.debian.org/releases/stable/i386/ch03s04.en.html)*


## Dalsze kroki
4. Po prawidlowym ustawieniu wszystkich opcji w kreatorze wybieramy przycisk `Zakoncz`.
5. Do VirtualBoxa zostanie dodana skonfigurowana maszyna o wprowadzonej nazwie. `Debian 12 - Server`. Przed jej uruchomieniem nalezy jeszcze skonfigorowac pare dodatkowych opcji w ustawieniach.
6. Wchodzimy w opcje `Ustawienia` w zakladce wyboru akcji danej maszyny wirtualnej (u gory okna).

## Ustawienia
### Ogolne - Podstawowe
| Opcja | Opis |
| --- | --- |
| Nazwa | Tutaj mozna zmienic nazwe maszyny wirtualnej. <br>***W tym procesie instalacji: `nie nalezy dokonywac zmian`.*** |
| Typ | Tutaj mozna zmienic typ maszyny wirtualnej. <br>**W tym procesie instalacji: `nie nalezy dokonywac zmian`.*** |
| Wersja | Tutaj mozna zmienic wersje maszyny wirtualnej. <br>***W tym procesie instalacji: `nie nalezy dokonywac zmian`.*** |

### Ogolne - Zaawansowane
| Opcja | Opis |
| --- | --- |
| Folder Migawek (Snapshots) | Tutaj mozna ustawicc folder w ktorym beda umieszczane Snapshoty (zapisy kontrolne systemu). Zapisy te pozwalaj na przywracanie maszyny wirtualnej do poprzedniego zapisanego stanu. <br>***W tym procesie instalacji: `nie nalezy dokonywac zmian`.*** |
| Wspoldzielony schowek | Tutaj mozna ustawic czy schowek systemu hosta ma byc wpoldzielony ze schowkiem wirutalnej maszyny. <br>***W tym procesie instalacji: `opcja ta powinna byc wylaczona`*** (nie ma koniecznosci posiadania wspoldzielonego schowka, w szczegolnosci gdy logowanie bedzie sie odbywalo tylko przez ssh) |
| Przeciaganie i upuszczanie | Tutaj mozna ustawic czy przeciaganie plikow i ich upuszczanie z systemu hosta na system wirtualnej maszyny bedzie wspierane. <br>***W tym procesie instalacji: `opcja ta powinna byc wylaczona`*** (szczegolnie ze wzgledow na fakt, ze system bedzie wykorzystywany serwerowo, gdzie interakcje beda mogly odbywac sie tylko przez klawiature) |

### Ogolne - Szyfrowanie dysku:
| Opcja | Opis |
| --- | --- |
| Wlacz szyfrowanie dysku | Opcja ta wlacza szyfrowanie na dysku. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona`.*** (nie ma wymogow szyfrowania dla tego konkretnego wykorzystania maszyny wirtualnej) |
| Szyfr | Tutaj mozna wybrac szyfr jaki bedzie wykorzysytywany do procesu szyforwania i odszyfrowywania tresci z dyskow systemowych maszyny wirtualnej. Z podstawy do wyboru sa dwa szyfry, ktore roznia sie dlugoscia. |
| Haslo | W tej sekcji mozna ustawic haslo wykorzystywane do procesu szyfrowania i odszyfrowywania. [warto podkreslic, ze dokonywania zmian hasla moze doprowadzic do nieprawidlowego odszyfrowania juz zapisanej tresci] |

> [!WARNING]
> Proces szyfrowania i odszyfrowywania tresci na dysku dodatkowo obciaza system podczas kazdego wykonywania odczytu/zapisu, co moze spowolnic calosciowe dzialanie maszyny wirtualnej.

### System - Plyta Glowna
| Opcja | Opis |
| --- | --- |
| RAM | Tutaj mozna ustawic ilosc przydzielonej pamiec RAM do maszyny wirtualnej.  <br>***W tym procesie instalacji: `nie nalezy dokonywac zmian`.*** |
| Kolejnosc bootowania | Tutaj mozna ustawic kolejnosc w jakiej wirtualna maszyna bedzie uruchamiac dane urzadzenia i ewentualnie probwac uruchomic z nich system operacyjny. <br>***W tym procesie instalacji: `Powinnismy miec zaznaczone tylko "Naped optyczny" i "Dysk Twardy"`*** (gdzie naped optyczny bedzie wykorzystany tylko do procesu instalacji systemu, potem ta opcje bedzie nalezalo odznaczyc, reszta opcji jest nie potrzebna dla tego rodzaju wykorzystania systemu) |
| Chipset | Tutaj mozna dokonac wyboru chipsetu wirtualnej plyty glownej jaki bedzie wykorzystywany. PIIX3 jest podstawowym rodzajem chipsetu, ktory bedzie mial wsparcie dla wiekszosci instalowanych systemow jednak posiada mniejsze mozliwosci niz chipset ICH9, ktory jest eksperymentalnym chipsetem oferujacym lepsze wsparcie dla takich systemow jak Mac OS X, ale nie bedzie on wszedzie wspierany i nie jest zalecany jezeli jezeli jego posiadania nie jest wymogiem sposobu wykorzystania maszyny. <br>***W tym procesie instalacji: `wybierzemy PIIX3`.*** |
| TPM | Opcja pozwalana na wybor wersji symulowanego modulu Trusted Platform Module, ktory moze byc wykorzysytwany do uruchamiania systemu z Secure Boot, przechowywania kluczy szyfrowania, czy tez weryfikowania podpisow cyfrowych. Symulowanie takiego modulu bedzie wymagane w przypadku korzystania z takiego systemu jak Windows 11. <br>***W tym procesie instalacji: `nalezy wybrac brak`.*** (system Debian nie posiada takiego wymogu i nie bedzie wykorzystania zadnych elementow TPM w zastosowaniu serwerowym wirtualnej maszyny) |
| Urzadzenie Wskazujace | Tutaj mozna wybrac rodzaj symulacji urzadzenia wskazujacego, gdy bedziemy jezdzic po ekranie wirtualnej maszyny kursorem hosta. <br>***W tym procesie instalacji: `wybierzemy Mysz PS/2`.*** (poniewaz nie bedziemy korzystac z kursora w srodowisku serwerowym) |
| Wlacz I/O APIC | ... |
| Enable Hardware Clock in UTC Time | ... |
| Wlacz EFI | ... |
| Enable Secure Boot | ... |
| Reset Keys to Default | ... |







