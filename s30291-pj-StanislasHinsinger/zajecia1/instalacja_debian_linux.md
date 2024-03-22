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
| Wlacz I/O APIC | Opcja ta pozwala na emulowanie bardziej zaawansowanego kontrolera przerwan (Input/Output Advanced Programmable Interrupt Controller), ktory bedzie w bardziej wydaje sposob zarzadzal przekazywanie przerwan miedzy roznymi wirtualnymi sprzetami danego srodowiska (karty sieciowe, kontrolery dyskow, itd.). <br>***W tym procesie instalacji: `opcja ta ma byc zaznaczona`*** (I/O APIC jest nowszym i bardziej rozbudowany kontrolerem przerwan, co dla srodowiska serwerowego moze byc przydatne) |
| Enable Hardware Clock in UTC Time | Opcja ta pozwala na ustawienie zegaru sprzetowego tak, aby dzialal on dla strefy UTC niezaleznie od strefy czasowej hosta. Jego wylaczenie bedzie wykorzystywalo czas systemowy hosta. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona`*** (ze wzgledow na wykorzystanie serwerowe instalowanego systemu, bardzo przydatne bedzie posiadanie tego samego czasu zegara systemowego co host, ze wzgledow na zapis i odczyt ewentualnych "logow") |
| Wlacz EFI | Opcja ta pozwala na wlaczenie EFI (Extensible Firmware Interface), dokladnie zostalo wyjasnione czym to jest w sekcji kreatora. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona`*** |
| Enable Secure Boot | Opcja ta pozwala na wlaczenie mechanizmu bezpieczenstwa Secure Boot podczas uruchamiania systemu. Ma on na celu zapobieganie ladowania nieautoryzowanego oprogramowania podczas uruchamiania systemu. Potrzebe wlaczenia tej opcji znajdziemy podczas korzystania z systemow Windows 8, 10, 11 czy Windows Server do zwiekszenia bezpieczenstwa uzytkowania. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona`*** (system Debian od wersji 10 wspiera Secure Boot, ale dla tego srodowiska serwerowego nie ma takiej potrzeby) |
| Reset Keys to Default | Opcja ta pozwala na zresetowanie kluczy wykorzystywanych przez Secure Boot do tych podstawowych (cofnie to wszystkie zmiany kluczy dokonanych przez uzytkownika). <br>***W tym procesie instalacji: `nie nalezy dokonywac zmian`*** |

### System - Procesor
| Opcja | Opis |
| --- | --- |
| Processors | Tutaj mozna zmienic ilosc przydzielonych watkow procesora. (jezeli chcemy uzyskac wieksza wydajnosc mozna zwiekszyc ilosc wykorzysytwanych CPU) <br>***W tym procesie instalacji: `nalezey ustawic na 2 CPU`.*** |
| Wykorzystanie Procesora | Tutaj mozna ustawic w ilu procentach maksymalnie moze byc obciazony jeden CPU, zmniejszenie tej wartosci moze byc przydatne, gdy maszynie wirtualnej zostana przydzielone wszystkie dostepne CPU hosta i podczas pelnego obciazenia maszyny nie bedzie to calkowicie spowalnialo pracy hosta. <br>***W tym procesie instalacji: `nalezy ustawic na 100% lub na 70% jezeli przydzielone zostaly wszystkie dostepne CPU hosta`.*** |
| Wlacz PAE/NX | Opcja ta pozwala na wlaczenie PAE/NX. <br>**PAE - Physical Address Extension** pozwala na korzystanie z wiecej niz 4 GB RAM, jego aktywacja jest wymagana w przypadku przydzielenia wiekszej ilosci pamiecie RAM do wirtualnej maszyny niz 4 GB. <br>**NX - No Execute** zabezpiecza system przed wykonaniem sie nieautoryzowanego kodu umieszonego w obszarach pamieci (chroni przed `code injection`) <br>***W tym procesie instalacji: `opcja ta ma byc zaznaczona`.*** (zwiekszy to bezpieczenstwo systemu i pozwoli na ewentualne zwiekszenie pamieci RAM maszyny wirtualnej w przyszlosci) |
| Wlacz zagniezdzone VT-x/AMD-V | Opcja ta pozwala na zagniezdzone wirtualizacje, gdy tworzymy wirtualne srodowisko w wirtualnym srodowisku. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona jezeli system hosta nie jest systemem wirtualnym`.***  |

### System - Akceleracja
| Opcja | Opis |
| --- | --- |
| Interfejs Parawirtualizacji | Opcja ta pozwala na wybor interfejsu wirtualizacyjnego wykorzystywanego do stworzenia wirtualnego srodowiska dla maszyny wirtualnej. <br>***W tym procesie instalacji: `nalezy zostawic domyslna opcje`.*** |
| Wlacz zagniezdzone stronnicowanie | Opcja ta pozwala na bezposrednie wykorzsytywanie zasob pamieci fizycznej, bez potrzeby przelaczania sie miedzy kontekstami wirutalnego srodowiska a fizycznego. Jego aktywacja zwieksza wydajnosc szczegolnie, gdy maszyna wirtualna jest uruchamiana w innej maszynie wirtualnej. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona jezeli system hsota nie jest systemem wirtualnym`.*** |

### Ekran - Ekran
| Opcja | Opis |
| --- | --- |
| Pamiec Wideo | Opcja ta pozwala na ustawienie ile pamieci wideo ma byc przeznaczone dla wirtualnej maszyny. ( przykladowo do wyswietlenia jednej klatki na ekranie (YxZ)px bedziemy potrzebowali Y*Z bajtow) Jezeli korzystamy z bardziej rozbudowanego srodowiska graficznego, np. Windows 10, zalecane byloby zwiekszenie ilosci tej pamieci do 128MB<br>***W tym procesie instalacji: `nalezy ustawic 16MB`.*** (serwerowe wykorzystanie praktycznie wogole nie bedzie wykorzystywalo tej pamieci) |
| Ilosc Monitorow | Mozna ustawic ile monitorow bedzie podpietych do wirtualnego srodowiska. <br>***W tym procesie instalacji: `nalezy ustawic na 1`.*** |
| Scale Factor | Pozwala na ustawienie skali danego monitora.  <br>***W tym procesie instalacji: `nie nalezy dokonywac zmian`.*** |
| Kontroler Grafiki | Opcja ta pozwala na wyboru emulowanego kontrolera grafiki.  <br>***W tym procesie instalacji: `nalezy wybrac VMSVGA`*** |
| Wlacz akceleracje 3D | Opcja ta pozwala na aktywowanie akceleracji sprzetowej 3D hosta do poprawy wydajnosci renderowania grafiki. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona`.*** (nie ma potrzeby aktywacji akceleracji 3D w srodowisku serwerowym) |

> [!NOTE]
> **Typy kontrolerow grafiki i ich opis:** <br>* `VBoxVGA` - jest to starszy kontroler grafiki VirtualBox, jest on kompatybilny z wieloma systemami operacyjnymi ale moze nie zapewniac najlepsze wydajnosci. <br>* `VMSVGA` - jest to ulepszony kontroler grafiki VirtualBox, posiada czesciowa akceleracje sprzetowa 3D i jest zalecany dla nowszych systemow operacyjnych. <br>* `VBoxSVGA` - jest to najnowszy kontroler grafiki VirtualBox, posiada wieksze wsparcie akceleracji sprzetowej niz VMSVGA, co sprawia, ze jest zalecany do wymagajacych zastosowan maszyny wirtualnej zwiazanych z renderowanie grafiki. <br>* `Brak` - do maszyny wirtualnie nie zostaje podpiety jakiekolwiek adapter grafiki, co sprawi, ze maszyna wirutalana nie bedzie renderowac obrazu, a dostep do niej bedzie moglo odbyc sie tylko poprzez ssh.

### Ekran - Zdalny Pulpit
| Opcja | Opis |
| --- | --- |
| Wlacz serwer | Opcja ta pozwala na uruchamianie sie serwera zdalnego pulpitu podczas wlaczania systemu, co daje dostep do podlaczenia sie do niego bezposrednio poprzez wykorzystanie aplikacji zadlanego laczenie sie na innym komputerze. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona`.*** (zdalny dostep do maszyny wirtualnej bedzie odbywal sie przez ssh) |
| Port Serwera | Port na ktorym ma zostac podpiety serwer zdalnego laczenia sie. [podstawowy to 3389] |
| Metoda uwierzytelniania | Pozwala na wybor w jakii sposob bedzie uzytkownik otrzymywal dostep do pulpitu maszyny wirtualnej. |
| Limit czasu uwierzytelniania | Limit czasu na przeprowadzenie procesu autoryzacji uzytkownika (podany w milisekudnach). | 
| Pozwol na wielokrotne polaczenia | Opcja ta pozwala na lacznenie sie wielu uzytkownikow w tym samym czasie z wirutualna maszyna. |

> [!WARNING]
> Dzialanie zdalnego pulpitu bedzie dostepne dopiero po zainstalowaniu `VirtualBox Extension Pack`, z podstawy VirtualBox nie posiada wsparcia.

### Ekran - Nagrywanie
| Opcja | Opis |
| --- | --- |
| Wlacz Nagrywanie | Opcja ta pozwala na nagrywanie aktywnosci maszyny wirtualnej odrazy po jej uruchomieniu i przerwaniu po jej wylaczeniu. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona`.*** (nie ma potrzeby nagrywania srodowiska serwerowego) |
| ... | Reszta opcji sluzy do konfiguracji jakosci i rozdzielczosci nagrywanego obrazu, w przypadku instalowania systemu dokladne wyjasnienie tych opcji nie jest konieczne |

### Pamiec
W tej sekcji mozna ustawiac kontrolery pamieci masowej i przydzielac do nich odpowiednie nosnik danych. W tym tworzyc takze emulowane nosniki zawierajace dane z folderow z komputera hosta. Dostepnych kontrolerow jest wiele, ale kluczowymi sa kontrolery IDE i SATA, ktore sa juz domyslnie ustawione. Ponizej znajduje sie informacja odnosnie kazdego dostepnego kontrolera.

* *Dla tego procesu instalacyjnego w kontrolerze IDE powinnien sie znalezc obraz instalatora `.iso`, a w kontrolerze SATA dysk `.vhd`, ktory zostal utworzony wraz z wirtualna maszyna.*

| Kontroler | Opis |
| --- | --- |
| PIIX4/PIIX3/ICH6 (IDE)| `Integrated Drive Electornics` - sa emulowane chipsety kontrolerow I/O pozwalajacych na montowanie nosnikow danych. Posiadaja one najwieksza kompatybilnosc z systemami operacyjnymi. <br> ***Maksymalna ilosc montowalnych nosinkow:** `4` |
| AHCI (SATA) | `Serial Advanced Technology Attachment` - kontroler ten posiada wieksza przepustownosc w porownaniu do IDE. Ponadto oferuje mozliwosc `Hot Swappingu` pozwalajacego na wymiane dysku podczas pracy systemu operacyjnego bez jego resetowania. (jest to jedyny kontroler oferujacy taka mozliwosc w VirtualBox) <br> ***Maksymalna ilosc montowalnych nosinkow:*** `30`*** |
| LsiLogic (SCSI) | `Small Computer System Interface` - jest to kontroler, ktory bedzie oferowal wieksza kompatybilnosc z systemami w porownaniu do SATA ale nie posiada w VirtualBoxie opcji Hot Swappingu. <br> ***Maksymalna ilosc montowalnych nosinkow: `15`*** |
| Floppy | Jest to kontroler pozwalajacy na emulowanie dyskietek. <br> ***Maksymalna ilosc montowalnych nosinkow: `2`*** |
| LsiLogic SAS | `Serial Attached SCSI` - jest to kontroler obslugujacy dyski SAS, ktore sa bardzie zaawansowane i zapewniaja wieksza wydajnosc i niezawodnosc w porownaniu do dyskow SATA. Interfejs ten obsluguje spinanie dyskow w macierz RAID i zarzadzanie matryca dyskow. Posiada mozliwosc podpiecia duzej ilosci dyskow co jest preferowanym kontrolerem dla systemow serwerowych. | <br> ***Maksymalna ilosc montowalnych nosinkow: `255`*** |
| VirtIO | Jest to kontroler stworzony specjalnie z mysla o wirtualizacji do wydajnej i optymalnej pracy z hostem. Obsluguje on dyski roznego typu, ale wymagac bedzie instalacji dodatkowych sterownikow na maszynie wirtualnej do uzyskania pelnego wsparcia.  | <br> ***Maksymalna ilosc montowalnych nosinkow: `255`*** |
| USB | `Universal Serial Bus` - jest to kontroler, ktory pozwala na montowanie i bezposrednia komunikacje urzadzen hosta z wirtualnym srodowiskiem, tak jakby byly one podpiete bezposrednio z wirtualnym systemem. <br> ***Maksymalna ilosc montowalnych nosinkow: `8`*** |

**Dodatkowe opcje, ktore mozna znalezc w tej kategorii:**
| Opcja | Opis |
| --- | --- |
| Live CD/DVD | Opcja ta daje mozliwosc uruchomienia systemu bezposrednio z nosnika bez jego instalacji na dysk. Gdzie ewentualnie dane ustawione podczas korzystania z systemu zostana utracone. (lub nie, jezeli zostanie dokonana ich kopia na inny nosnik) |
| Nazwa | Pozwala ustawic nazwe danego kontrolera. |
| Typ | Pozwala ustawic rodzaj danego kontrolera. |
| Ilosc Portow | Pozwala ustawic ilosc obslugiwanych portow na danym kontrolerze. |
| Dysk SSD | Opcja ta sprawia, ze montowany dysk bedzie traktowany jak dysk SSD (opcja ta powinna byc aktywowana tylko gdy mamy doczynienia z fizycznym dyskiem SSD) |
| Hot-pluggable | Opcja ta daje mozliwosc odlaczania i ponowego laczenia dysku podczas pracy systemu operacyjnego, bez potrzeby jego resetowania. |


### Dzwiek
| Opcja | Opis |
| --- | --- |
| Wlacz dzwiek | Opcja ta pozwala na aktywowanie przechwytywania dzwieku z wirtualnej maszyny poprzez sterownik dzwieku. <br>***W tym procesie instalacji: `opcja ta ma byc odznaczona`.*** (nie ma zapotrzebowania na wykorzystanie dzwieku w srodowisku serwerowym) |
| Sterownik dzwieku gospodarza | W tej opcji mozna wybrac poprzez jaki sterownik bedzie przekazywany dzwiek z wirtualnej maszyny do systemu hosta. |
| Kontroler audio | Opcja ta pozwala na wybor kontrolera audio wirtualnej maszyny. `ICH AC97` jest najstarzym kontrolerem i bedzie zapewniac kompatyblinosc dla starszy systemow. `SoundBlaster16` takze jest kontrolerem starszej generacji. `Intel HD Audio` jest to najnowszy standard dzwieku oferujacy lepsza jakosc i szereg dodatkowych funkcji.|
| Wlacz wyjscie dzwieku | Opcja ta aktywuje przekazywanie dzwieku z wirtualnej maszyny do hosta. |
| Wlacz wejscie dzwieku | Opcja ta aktywuje przekazywanie dzwieku z urzadzen hosta do wirtualnej maszyny. (o ile zostaly wczesniej prawidlowo podlaczone i skonfigurowane). |


### Siec
W tej sekcji mozna skonfigurowac karty sieciowe maszyny wirtualnej (maksymalnie do 4).

* **Dla tego procesu instalacji wykorzystamy 1 karte sieciowa i skonfigurujemy ja jako mostkowana karta sieciowa, tak aby maszyna byla oddzielnie zarejestrowana w sieci hosta (gdzie w nazwie bedzie trzeba ustawic karte sieciowa uzywana przez hosta).** 

| Typ Sieci | Opis |
| --- | --- |
| NAT | `Network Address Translation` - jest to siec umozliwiajaca maszynom wirtualnym na dostep do internetu poprzez hosta, gdzie host bedzie dzialac jako router a maszyny beda posiadac swoje prywatne adresy IP, ktore beda tlumaczone na publiczny adres hosta. |
| Siec Mostkowa | Siec ta pozwala wirtualnej maszynie dzialac jak pelnoprawne urzadzenie w sieci fizycznej. Kazda maszyna dostaje swoj wlasny adres w sieci fizycznej, co pozwala jej na komunikacje z lokalnymi urzadzeniami w sieci.
| Siec Wewnetrzna | Laczy maszyny wirtualne wewnatrz srodowiska wirtualnego, ale bez dostepu do hosta i sieci zewnetrznej. Przydatne, gdy nalezy stworzyc siec komunikujacych ze soba maszyn wirtualnych np. cluster baz danych. |
| Siec Hosta | Pozwala na komunikacje tylko miedzy maszyna wirtualna a hostem. (brak mozliwosci laczenia sie z sieciami zewnetrznymi)
| Rodzajowy Sterownik | Pozwala na ustawienie niestandardowego sterownika sieciowego dla danej maszyny wirtualnej. Wykorzystywane, gdy potrzebne jest dostosowanie sie do specjalnych sterownikow lub wymagan sprzetowych. |
| Siec NAT | Pozwala na tworzenie wielu sieci NAT w ktorej kazda z nich bedzie dzialac niezaleznie. |
| Cloud Network | Pozwala na laczenie sie infrastruktura dostawcow uslug chmury takich jak AWS, AZURE czy GCP.


**Dodatkowe opcje, ktore mozna znalezc w tej kategorii:**
| Opcja | Opis |
| --- | --- |
| Typ karty | Tutaj mozna ustawic typ emulowanej karty sieciowej. Kazda z nich bedzie w pelni dzialala dla podstawowego wykorzystania przez maszyne wirtualna, jedna do bardziej zaawansowanych konfiguracji karty sieciowej przez maszyne wirtualna, moze byc zalecane wykorzystanie edycji `SERVER` zamiast `DESKTOP`. <br>***W tym procesie instalacji: `wystarczy wybranie opcji Intel PRO/100 MT Desktop`.*** |
| Tryb nasluchiwania | Ustawienie to pozwala na aktywowanie nasluchiwania calego ruchu ramek sieciowych, nawet tych ktore nie sa adresowane do maszyny wirtualnej. Tryb ten moze byc aktywowany w momencie, gdy chcemy monitorowac caly ruch w danej sieci. Ze wzgledow bezpieczenstwa i na przeplyw potencjalnie wrazliwych danych nie jest to zalecane. <br>***W tym procesie instalacji: `nalezy wybrac "Odmawiaj"`.*** |
| Adres MAC | Tutaj znajduje sie adres MAC karty sieciowej maszyny wirtualnej. Z podstawy kazdy adres MAC maszyny wirtualnej VirtualBox bedzie zaczynal sie od `080027`. Adres ten mozna ponownie zregenerowac wybierajac przycisk regenerajci po prawej stronie. <br>***W tym procesie instalacji: `nie nalezy dokonywac zmian`.*** |
| Kabel Podlaczony | Opcja ta pozwala na ustawienie, czy karta sieciowa bedzie podlaczona do sieci czy tez nie. Przydatne gdy chcemy odlaczyc maszyne od danej sieci, ale nie chcemy calkowicie odlaczac karty sieciowej. |

### Porty Szeregowe
Sekcja ta zostanie pominieta, ze wzgledow na calkowity brak wykorzystania tej portow szeregowych w tym procesie instalacyjnym i ewentualnym uzytkowaniu systemu operacyjnego, ponadto bardzo rzadko takie porty sa instalowane na maszynach wirtualnych uzytku codziennego czy serwerowego. Wiekszosc urzadzen wykorzystuje standart komunikacji USB.

### USB
Sekcja ta pozwala na bezposrednie podlaczenie urzadzen USB hosta z maszyna wirtualna. Mozna wybrac miedzy standardami USB 1.1, USB 2.0 i USB 3.0. Urzadzenia mozna dodawac poprzez przycisk `+` w prawym panelu. Mozna takze dodwac filty, dzieki ktorym w latwy sposb mozna ustawic automatyczne instalowanie urzadzen.

### Udostepniane foldery
Sekcja ta pozwala na udostepnienie folderow hosta maszynie wirtualnej, dzieki czemu w latwy sposob mozna ustanowic komunikacje miedzy nimi. Folder mozna udostepnic klikajac na przycisk `+` w prawym panelu. Na potrzeby tego procesu instalacyjnego nie bedzie wykorzystania udostepniania folderow, dlatego w tej sekcji nie zostanie wprowadzona jakakolwiek zmiana.

| Opcja | Opis |
| --- | --- |
| Sciezka do folderu | Lokalizacja folderu u hosta, ktory bedzie sie udostepnialo. |
| Nazwa Folderu | Nazwa tego folderu. |
| Punkt Montowania | Lokalizacja na maszynie wirtualnej w jakiej zostanie ten folder zamontowany. |
| Tylko do odczytu | Opcja ta blokuje mozliwosc zapisu przez maszyne wirtualna w tym folderze. Przydatne, gdy nie chcemy w jakikolwiek sposob dawac dostep do systemu hosta maszynie wirtualnej. |
| Automatyczne Montowanie | Opcja ta sprawi, ze VirtualBox bedzie automatycznie montowal ten folder do systemu przy kazdy uruchomieniu wirtualnej maszyny.

> [!WARNING]
> Dla niektorych systemow operacyjnych wirtualnej maszyny bedzie wymagane zainstalowanie i konfiguracja `VirtualBox Guest Additions` do prawidlowego automatycznego montowania udostepnianych folderow.

### Interfejs Uzytkownika
Sekcja tak sluzy tylko do konfigurowania interfejsu okna wirtualnej maszyny. Opcje te maja aspekt czysto wizualny dla uzytkownika korzystajacy z VirtualBox'a i nie maja jakiegokolwiek wplywu na proces instalacyjny systemu czy tez jego prawidlowe dzialanie, dlatego tez sekcja ta zostanie pominieta.

 













