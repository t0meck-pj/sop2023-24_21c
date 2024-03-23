# Instalacja Systemu Debian 12 (do wykorzystania serwerowego)

**Autorstwa:** `Stanislas Hinsinger - s30291`

## Tworzenie wirtualnej maszyny
1. Należy uruchomić aplikacje `VirtualBox`. W przypadku jej braku na systemie, można ja pobrać [z oficjalnej strony VirtualBox](https://www.virtualbox.org) 
2. Do stworzenia nowej maszyny wirtualnej wybieramy opcje `Maszyna` [znajdująca się na górnym pasku] i tam wybieramy opcje `Nowa`.
3. Na ekranie wyświetli się okno `Utwórz wirtualna maszynę`. 

> [!TIP]
> W przypadku pierwszego tworzenia maszyny wirtualnej, kreator będzie ustawiony w trybie "Przewodnika", ze względu na łatwiejszy dostęp do wyboru opcji, należy przełączyć się na tryb "Eksperta" (przycisk na dole okna).

> [!NOTE]
> Do kolejnych etapów potrzebne będzie posiadanie na komputerze pliku obrazu instalatora systemu Debian 12. Plik ten można pobrać bezpośrednio z [oficjalnej strony](https://www.debian.org/distrib/). <br>
> <br> *Jeżeli posiadamy dostęp do Internetu na wirtualnej maszynie to wybieramy `Small Installation Image` w przeciwnym wypadku powinniśmy pobrać `Complete Installation Image` (zawiera on wszystkie potrzebne pakiety instalacyjne, bez potrzeby dodatkowego klonowania z innego serwera podczas instalacji) <br><br> Należy także wybrać odpowiedni rodzaj pliku instalacyjnego, w przypadku wirtualnej maszyny, będziemy instalowali system na 64-bitowej architekturze `amd64`.*

## Kategorie kreatora
> [!IMPORTANT]
> **W tym konkretnym procesie instalacyjnym zostanie wykorzystana wersja obrazu instalatora `Small Installation Image`,** ponieważ będziemy instalowali system z dostępem do Internetu i taka wersja będzie szybsza do pobrania przez hosta.

### Name and Operating System
| Opcja |  Opis |
| --- | --- |
| Nazwa | Tutaj wprowadzamy nazwę naszego systemu operacyjnego do rozpoznania wirtualnych maszyn. <br>***Dla tego procesu instalacyjnego wykorzystamy: `Debian 12 - Server`.*** |
| Folder | Tutaj wybieramy folder gdzie ma zostać zainstalowany nasz system i wszystkie jego pliki powiązane z maszyna wirtualna i środowiskiem VirutalBox. <br>***Dla tego procesu instalacyjnego wykorzystamy: `...\...\VirtualBox\Systemy`.*** |
| ISO Image | Tutaj wybieramy obraz systemu w postaci pliku **.iso** (może to być obraz gotowego systemu lub instalatora) <br>***Dla tego procesu instalacyjnego wykorzystamy: `wcześniej pobrany obraz instalatora systemu Debian 12`.*** |
| Typ  | Tutaj wybieramy rodzinne wykorzystywanego systemu operacyjnego, jeżeli jest to dystrybucja z rodziny Windows to wybieramy Microsoft Windows, jeżeli jest to dystrybucja z rodziny Mac OS to wybieramy Mac Os X [warto podkreślić, ze formalnie powinno się instalować systemy z rodziny Mac OS X tylko na systemie hosta Mac OS), jeżeli jest to dystrybucja z rodziny Linux (Ubuntu, Debian, Fedora itd.) to wybieramy Linux. <br>***Dla tego procesu instalacyjnego wybieramy: `Linux (ponieważ Debian należy do tej rodziny systemów)`.*** |
| Wersja | Tutaj należy wprowadzić wersje systemu jaka będzie wykorzystywana. (np. Typ = Microsoft Windows, Wersja = Windows 10) <br>***Dla tego procesu instalacyjnego wybieramy: `Debian (64-bit)`.*** |
| Skip Unattended Installation | Opcja ta pozwala na pominiecie automatycznego wykonania procesów instalacyjnych przez VirtualBox. <br>***Dla tego procesu instalacyjnego: `opcja ta ma być zaznaczona`.*** |
> [!WARNING]
> *Warto podkreślić, ze jeżeli na liście wersji systemów nie znajdują się opcje 64-bitowych systemów, to oznacza, ze system hosta jest systemem 32-bitowym lub jest uruchomiona dodatkowa wirtualizacja jak np. HyperV, która wpływa na to środowisko wirtualizacyjne.*
### Unattended Install

| Opcja |  Opis |
| --- | --- |
| Username and Password | Tutaj wprowadzamy dane konta użytkownika jakie ma zostać utworzone. (będzie się go stosować do zalogowania do systemu) |
| Additional Options | Tutaj znajdują się dodatkowe opcje, które Beda wykonane podczas automatycznej instalacji. <br> `Hostname:` nazwa komputera w sieci <br> `Domain Name:` nazwa domeny sieci do której ten system będzie podpięty |

> [!CAUTION]
> **Dla tego rodzaju instalacji systemu nie będziemy korzystać z żadnych z opcji w kategorii `Unattended Install`,** ponieważ proces instalacji zostanie wykonany manualnie, z wyborem specjalnych ustawień, aby system ten był odpowiednio przygotowany pod wykorzystanie serwerowe.

### Hardware

| Opcja |  Opis |
| --- | --- |
| RAM | Tutaj wprowadzamy ilość pamięci ram jaką chcemy przydzielić wirtualnemu systemowi. (Nie powinno się przydzielać wszystkich dostępnych zasobów hosta) [należy także dokonać rozsądnego przydziału zasobów, których rzeczywiście ewentualna maszyna może wykorzystać] <br>***Dla tego procesu instalacyjnego ustawimy: `2048 MB`.*** |
| Processors | Tutaj wybieramy ile dostępnych wątków hosta chcemy przydzielić wirtualnej maszynie. (Nie powinno się przydzielać wszystkich dostępnych wątków hosta) <br>***Dla tego procesu instalacyjnego ustawimy: `2 CPU`*** ( dzięki temu środowisko serwerowe będzie mogło w pełni wykorzystać potencjał ewentualnych podstawowych aplikacji wielowątkowych, a sam proces instalacji będzie szybszy ) |
| Enable EFI | Opcja ta śluzy do obsługi `Extensible Firmware Interface`, który zastępuje standardowy interfejs firmware'u komputera `BIOS`. Posiada on lepsze wsparcie i wykorzystanie nowszego sprzętu i dodatkowe rozszerzenia np. podpisów cyfrowych umożliwiających korzystanie z **Secure Boot** i weryfikacji podpisów cyfrowych systemu i sterowników. Opcje ta zaznacza się głownie w przypadku korzystania z wirtualnej maszyny w sposób Desktopowy, gdzie instalujemy systemy pokroju Windows 10/11, czy Mac OS. Dla systemów instalowanych z myślą o serwerowym wykorzystaniu jak Ubuntu czy Debian nie będzie to raczej w pełni wykorzystywane.  <br>***Dla tego procesu instalacyjnego: `opcja ta ma być odznaczona`.***  |

> [!TIP]
> *Minimalne zasoby potrzebne dla danego systemu zawsze można znaleźć na stronie dystrybutora. W przypadku rodziny systemów `Debian` te minimalne wymagania można znaleźć na [oficjalnej stronie Debian.org](https://www.debian.org/releases/stable/i386/ch03s04.en.html)*


### Hard Disk

**W tej zakładce do wyboru są 3 opcje:**
* **Create a Virutal Hard Disk Now:** `pozwala na stworzenie i podpięcie wirtualnego dysku twardego do tej wirtualnej maszyny wirtualnej` 
<br>( **TA OPCJE WYBIERZEMY DLA INSTALACJI SYSTEMU** )

| Opcja |  Opis |
| --- | --- |
| Location and Size | Tutaj wprowadzamy lokalizacje w której chcemy aby nasz wirtualny dysk się znalazł. <br>***Dla tego procesu instalacyjnego wybieramy: `...\...\VirtualBox\Systemy\Debian 12 - Server\Debian 12 - Server.vdi`.*** |
| Suwak Pamieci | Za pomocą tego suwaka możemy ustawić ilość przestrzeni dyskowej dostępnej dla danego systemu operacyjnego. <br>***Dla tego procesu instalacyjnego ustawimy: `40 GB`.*** (będzie to przestrzeń wystarczająca na zapotrzebowania systemu i ewentualnych podstawowych użytkowników serwera) |
| Type and Variant | Tutaj ustawiamy jakiego typu chcemy aby ten wirtualny dysk był. Opis każdego rodzaju znaleźć będzie można w komentarzach niżej. <br>***Dla tego procesu instalacyjnego wybieramy: `VDI (VirtualBox Disk Image)`*** (ponieważ będzie on najbardziej optymalna opcja dla naszego zastosowania tego systemu)|
| Pre-allocate Full Size | Opcja ta pozwala na bezpośrednia alokacje przestrzeni dyskowej (do tej która została ustawiona). Może to być przydatne w przypadku, gdy chcemy zminimalizować czas zapisu, który będzie ewentualnie spowalniany przez dynamiczne alokowanie przestrzeni przez środowisko VirtualBox. <br>***Dla tego procesu instalacyjnego: `opcja ta ma być odznaczona` (dynamiczne alokowanie przestrzeni nie powinno mieć znaczącego wpływu na optymalne działanie systemu dla wykorzystania serwerowego).***|
| Split into 2GB parts | Opcja ta pozwala na podzielenie dysku na 2GB części. Co mogłoby być wymaganiem w przypadku korzystania z systemu plików FAT (w którym maksymalna wielkość pliku to 4GB), lub tez chcielibyśmy w łatwiejszy sposób przesyłać mniejsze pliki dysku przez siec zamiast jednego dużego. <br>***Dla tego procesu instalacyjnego: `opcja ta ma być odznaczona`*** |

* **Use an Exsiting Virtual Hard Disk File:** `pozwala na wybranie już istniejącego wirtualnego dysk twardego [gdy chcemy wykorzystać już stworzony i zapisany system operacyjny]`
* **Do Not Add a Virtual Disk:** `nie podpina żadnego wirtualnego dysku do tej maszyny, w zamian można wykorzystać podczas uruchamiania sam napęd optyczny, dyskietkę lub USB`

| Typ dysku | Opis dysku |
| --- | --- |
| VDI | Format dysku wirtualnego używany przez VirtualBox. Jest to domyślny format dla nowo tworzonych maszyn wirtualnych. |
| VHD | Format dysku wirtualnego, który jest szeroko stosowany i obsługiwany przez różne platformy wirtualizacyjne, w tym przez VirtualBox. |
| VMDK | Format dysku wirtualnego używany przez VMware, ale obsługiwany także przez VirtualBox. |
| HDD | Ogólna kategoria dysków twardych, obejmująca różne formaty używane przez różne platformy wirtualizacyjne. |
| QCOW | Format dysku wirtualnego używany przez QEMU, który może być również obsługiwany przez VirtualBox. |
| QED | Format dysku wirtualnego zastosowany w QEMU, który może być również używany w VirtualBox. |

> [!TIP]
> *Minimalna przestrzeń wymagana przez dany system zawsze można znaleźć na stronie dystrybutora. W przypadku rodziny systemów `Debian` te minimalne wymagania można znaleźć na [oficjalnej stronie Debian.org](https://www.debian.org/releases/stable/i386/ch03s04.en.html)*


## Dalsze kroki
4. Po prawidłowym ustawieniu wszystkich opcji w kreatorze wybieramy przycisk `Zakończ`.
5. Do VirtualBoxa zostanie dodana skonfigurowana maszyna o wprowadzonej nazwie. `Debian 12 - Server`. Przed jej uruchomieniem należy jeszcze skonfigurować parę dodatkowych opcji w ustawieniach.
6. Wchodzimy w opcje `Ustawienia` w zakładce wyboru akcji danej maszyny wirtualnej (u góry okna).

## Ustawienia
### Ogólne - Podstawowe
| Opcja | Opis |
| --- | --- |
| Nazwa | Tutaj można zmienić nazwę maszyny wirtualnej. <br>***W tym procesie instalacji: `nie należy dokonywać zmian`.*** |
| Typ | Tutaj można zmienić typ maszyny wirtualnej. <br>***W tym procesie instalacji: `nie należy dokonywać zmian`.*** |
| Wersja | Tutaj można zmienić wersje maszyny wirtualnej. <br>***W tym procesie instalacji: `nie należy dokonywać zmian`.*** |

### Ogólne - Zaawansowane
| Opcja | Opis |
| --- | --- |
| Folder Migawek (Snapshots) | Tutaj można ustawić folder w którym Beda umieszczane Snapshoty (zapisy kontrolne systemu). Zapisy te pozwalaj na przywracanie maszyny wirtualnej do poprzedniego zapisanego stanu. <br>***W tym procesie instalacji: `nie należy dokonywać zmian`.*** |
| Współdzielony schowek | Tutaj można ustawić czy schowek systemu hosta ma być współdzielony ze schowkiem wirtualnej maszyny. <br>***W tym procesie instalacji: `opcja ta powinna być wyłączona`*** (nie ma konieczności posiadania współdzielonego schowka, w szczególności gdy logowanie będzie się odbywało tylko przez SSH) |
| Przeciąganie i upuszczanie | Tutaj można ustawić czy przeciąganie plików i ich upuszczanie z systemu hosta na system wirtualnej maszyny będzie wspierane. <br>***W tym procesie instalacji: `opcja ta powinna być wyłączona`*** (szczególnie ze względów na fakt, ze system będzie wykorzystywany serwerowo, gdzie interakcje będą mogły odbywać się tylko przez klawiaturę) |

### Ogólne - Szyfrowanie dysku:
| Opcja | Opis |
| --- | --- |
| Włącz szyfrowanie dysku | Opcja ta włącza szyfrowanie na dysku. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona`.*** (nie ma wymogów szyfrowania dla tego konkretnego wykorzystania maszyny wirtualnej) |
| Szyfr | Tutaj można wybrać szyfr jaki będzie wykorzystywany do procesu szyfrowania i odszyfrowywania treści z dysków systemowych maszyny wirtualnej. Z podstawy do wyboru sa dwa szyfry, które różnią się długością. |
| Hasło | W tej sekcji można ustawić hasło wykorzystywane do procesu szyfrowania i odszyfrowywania. [warto podkreślić, ze dokonywania zmian hasła może doprowadzić do nieprawidłowego odszyfrowania już zapisanej treści] |

> [!WARNING]
> Proces szyfrowania i odszyfrowywania treści na dysku dodatkowo obciąża system podczas każdego wykonywania odczytu/zapisu, co może spowolnić całościowe działanie maszyny wirtualnej.

### System - Płyta Główna
| Opcja | Opis |
| --- | --- |
| RAM | Tutaj można ustawić ilość przydzielonej pamięć RAM do maszyny wirtualnej.  <br>***W tym procesie instalacji: `nie należy dokonywać zmian`.*** |
| Kolejność bootowania | Tutaj można ustawić kolejność w jakiej wirtualna maszyna będzie uruchamiać dane urządzenia i ewentualnie próbować uruchomić z nich system operacyjny. <br>***W tym procesie instalacji: `Powinniśmy mieć zaznaczone tylko "Napęd optyczny" i "Dysk Twardy"`*** (gdzie napęd optyczny będzie wykorzystany tylko do procesu instalacji systemu, potem, ta opcje będzie należało potem odznaczyć, reszta opcji jest nie potrzebna dla tego rodzaju wykorzystania systemu) |
| Chipset | Tutaj można dokonać wyboru chipsetu wirtualnej płyty głównej jaki będzie wykorzystywany. PIIX3 jest podstawowym rodzajem chipsetu, który będzie miał wsparcie dla większości instalowanych systemów jednak posiada mniejsze możliwości niż chipset ICH9, który jest eksperymentalnym chipsetem oferującym lepsze wsparcie dla takich systemów jak Mac OS X, ale nie będzie on wszędzie wspierany i nie jest zalecany jeżeli jego posiadania nie jest wymogiem sposobu wykorzystania maszyny. <br>***W tym procesie instalacji: `wybierzemy PIIX3`.*** |
| TPM | Opcja pozwalana na wybór wersji symulowanego modułu `Trusted Platform Module`, który może być wykorzystywany do uruchamiania systemu z Secure Boot, przechowywania kluczy szyfrowania, czy tez weryfikowania podpisów cyfrowych. Symulowanie takiego modułu będzie wymagane w przypadku korzystania z takiego systemu jak Windows 11. <br>***W tym procesie instalacji: `należy wybrać brak`.*** (system Debian nie posiada takiego wymogu i nie będzie wykorzystania żadnych elementów TPM w zastosowaniu serwerowym wirtualnej maszyny) |
| Urządzenie Wskazujące | Tutaj można wybrać rodzaj symulacji urządzenia wskazującego, gdy będziemy jeździć po ekranie wirtualnej maszyny kursorem hosta. <br>***W tym procesie instalacji: `wybierzemy Mysz PS/2`.*** (ponieważ nie będziemy korzystać z kursora w środowisku serwerowym) |
| Włącz I/O APIC | Opcja ta pozwala na emulowanie bardziej zaawansowanego kontrolera przerwań (Input/Output Advanced Programmable Interrupt Controller), który będzie w bardziej wydaje sposób zarządzał przekazywaniem przerwań miedzy rożnymi wirtualnymi sprzętami danego środowiska (karty sieciowe, kontrolery dysków, itd.). <br>***W tym procesie instalacji: `opcja ta ma być zaznaczona`*** (I/O APIC jest nowszym i bardziej rozbudowany kontrolerem przerwań, co dla środowiska serwerowego może być przydatne) |
| Enable Hardware Clock in UTC Time | Opcja ta pozwala na ustawienie zegar sprzętowego tak, aby działał on dla strefy UTC niezależnie od strefy czasowej hosta. Jego wyłączenie będzie wykorzystywało czas systemowy hosta. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona`*** (ze względów na wykorzystanie serwerowe instalowanego systemu, bardzo przydatne będzie posiadanie tego samego czasu zegara systemowego co host, ze względów na zapis i odczyt ewentualnych "logów") |
| Włącz EFI | Opcja ta pozwala na włączenie EFI (Extensible Firmware Interface),  dokładnie zostało wyjaśnione czym to jest w sekcji kreatora. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona`*** |
| Enable Secure Boot | Opcja ta pozwala na włączenie mechanizmu bezpieczeństwa Secure Boot podczas uruchamiania systemu. Ma on na celu zapobieganie lądowania nieautoryzowanego oprogramowania podczas uruchamiania systemu. Potrzebę włączenia tej opcji znajdziemy podczas korzystania z systemów Windows 8, 10, 11 czy Windows Server do zwiększenia bezpieczeństwa użytkowania. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona`*** (system Debian od wersji 10 wspiera Secure Boot, ale dla tego środowiska serwerowego nie ma takiej potrzeby) |
| Reset Keys to Default | Opcja ta pozwala na zresetowanie kluczy wykorzystywanych przez Secure Boot do tych podstawowych (cofnie to wszystkie zmiany kluczy dokonanych przez użytkownika). <br>***W tym procesie instalacji: `nie należy dokonywać zmian`*** |

### System - Procesor
| Opcja | Opis |
| --- | --- |
| Processors | Tutaj można zmienić ilość przydzielonych wątków procesora. (jeżeli chcemy uzyskać większa wydajność można zwiększyć ilość wykorzystywanych CPU) <br>***W tym procesie instalacji: `należy ustawić na 2 CPU`.*** |
| Wykorzystanie Procesora | Tutaj można ustawić w ilu procentach maksymalnie może być obciążony jeden CPU, zmniejszenie tej wartości może być przydatne, gdy maszynie wirtualnej zostaną przydzielone wszystkie dostępne CPU hosta i podczas pełnego obciążenia maszyny nie będzie to całkowicie spowalniało pracy hosta. <br>***W tym procesie instalacji: `należy ustawić na 100% lub na 70% jeżeli przydzielone zostały wszystkie dostępne CPU hosta`.*** |
| Włącz PAE/NX | Opcja ta pozwala na włączenie PAE/NX. <br>**PAE - Physical Address Extension** pozwala na korzystanie z więcej niż 4 GB RAM, jego aktywacja jest wymagana w przypadku przydzielenia większej ilości pamięci RAM do wirtualnej maszyny niż 4 GB. <br>**NX - No Execute** zabezpiecza system przed wykonaniem się nieautoryzowanego kodu umieszonego w obszarach pamięci (chroni przed `code injection`) <br>***W tym procesie instalacji: `opcja ta ma być zaznaczona`.*** (zwiększy to bezpieczeństwo systemu i pozwoli na ewentualne zwiększenie pamięci RAM maszyny wirtualnej w przyszłości) |
| Włącz zagnieżdżone VT-x/AMD-V | Opcja ta pozwala na zagnieżdżone wirtualizacje, gdy tworzymy wirtualne środowisko w wirtualnym środowisku. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona jeżeli system hosta nie jest systemem wirtualnym`.***  |

### System - Akceleracja
| Opcja | Opis |
| --- | --- |
| Interfejs Parawirtualizacji | Opcja ta pozwala na wybór interfejsu witalizacyjnego wykorzystywanego do stworzenia wirtualnego środowiska dla maszyny wirtualnej. <br>***W tym procesie instalacji: `należy zostawić domyślna opcje`.*** |
| Włącz zagnieżdżone stronnicowanie | Opcja ta pozwala na bezpośrednie wykorzystywanie zasób pamięci fizycznej, bez potrzeby przełączania się miedzy kontekstami wirtualnego środowiska a fizycznego. Jego aktywacja zwiększa wydajność szczególnie, gdy maszyna wirtualna jest uruchamiana w innej maszynie wirtualnej. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona jeżeli system hosta nie jest systemem wirtualnym`.*** |

### Ekran - Ekran
| Opcja | Opis |
| --- | --- |
| Pamięć Wideo | Opcja ta pozwala na ustawienie ile pamięci wideo ma być przeznaczone dla wirtualnej maszyny. ( przykładowo do wyświetlenia jednej klatki na ekranie (YxZ)px będziemy potrzebowali Y*Z bajtów) Jeżeli korzystamy z bardziej rozbudowanego środowiska graficznego, np. Windows 10, zalecane byłoby zwiększenie ilości tej pamięci do 128MB<br>***W tym procesie instalacji: `należy ustawić 16MB`.*** (serwerowe wykorzystanie praktycznie nie będzie wykorzystywało tej pamięci) |
| Ilość Monitorów | Można ustawić ile monitorów będzie podpiętych do wirtualnego środowiska. <br>***W tym procesie instalacji: `należy ustawić na 1`.*** |
| Scale Factor | Pozwala na ustawienie skali danego monitora.  <br>***W tym procesie instalacji: `nie należy dokonywać zmian`.*** |
| Kontroler Grafiki | Opcja ta pozwala na wyboru emulowanego kontrolera grafiki.  <br>***W tym procesie instalacji: `należy wybrać VMSVGA`*** |
| Włącz akceleracje 3D | Opcja ta pozwala na aktywowanie akceleracji sprzętowej 3D hosta do poprawy wydajności renderowania grafiki. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona`.*** (nie ma potrzeby aktywacji akceleracji 3D w środowisku serwerowym) |

| Kontroler Grafiki | Opis kontrolera |
| --- | --- |
| VBoxVGA | Starszy kontroler grafiki oferujący kompatybilność wsteczną z starszymi wersjami VirtualBox. |
| VMSVGA | Aktualny kontroler grafiki, zapewniający lepszą wydajność i obsługę nowszych funkcji graficznych. |
| VBoxSVGA | Kontroler grafiki zaprojektowany specjalnie dla systemów operacyjnych obsługujących akcelerację sprzętową 3D. |
| Brak | Kontroler grafiki nie jest przypisany do maszyny wirtualnej, co powoduje brak wyświetlanego obrazu. Dostęp do maszyny może odbywać się jedynie poprzez SSH lub inną formę zdalnego dostępu. Ta opcja jest przydatna w przypadku maszyn serwerowych, gdzie interfejs graficzny nie jest wymagany, co minimalizuje zużycie zasobów systemowych. |

### Ekran - Zdalny Pulpit
| Opcja | Opis |
| --- | --- |
| Włącz serwer | Opcja ta pozwala na uruchamianie się serwera zdalnego pulpitu podczas włączania systemu, co daje dostęp do podłączenia się do niego bezpośrednio poprzez wykorzystanie aplikacji zdalnego leczenie się na innym komputerze. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona`.*** (zdalny dostęp do maszyny wirtualnej będzie odbywał się przez SSH) |
| Port Serwera | Port na którym ma zostać podpięty serwer zdalnego leczenia się. [podstawowy to 3389] |
| Metoda uwierzytelniania | Pozwala na wybór w jaki sposób będzie użytkownik otrzymywał dostęp do pulpitu maszyny wirtualnej. |
| Limit czasu uwierzytelniania | Limit czasu na przeprowadzenie procesu autoryzacji użytkownika (podany w milisekudnach). | 
| Pozwól na wielokrotne polaczenia | Opcja ta pozwala na leczenie się wielu użytkowników w tym samym czasie z wirtualna maszyna. |

> [!WARNING]
> Działanie zdalnego pulpitu będzie dostępne dopiero po zainstalowaniu `VirtualBox Extension Pack`, z podstawy VirtualBox nie posiada wsparcia.

### Ekran - Nagrywanie
| Opcja | Opis |
| --- | --- |
| Włącz Nagrywanie | Opcja ta pozwala na nagrywanie aktywności maszyny wirtualnej odrazy po jej uruchomieniu i przerwaniu po jej wyłączeniu. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona`.*** (nie ma potrzeby nagrywania środowiska serwerowego) |
| ... | Reszta opcji służy do konfiguracji jakości i rozdzielczości nagrywanego obrazu, w przypadku instalowania systemu dokładne wyjaśnienie tych opcji nie jest konieczne |

### Pamięć
W tej sekcji można ustawiać kontrolery pamięci masowej i przydzielać do nich odpowiednie nośnik danych. W tym tworzyć także emulowane nośniki zawierające dane z folderów z komputera hosta. Dostępnych kontrolerów jest wiele, ale kluczowymi są kontrolery IDE i SATA, które są już domyślnie ustawione. Poniżej znajduje się informacja odnośnie każdego dostępnego kontrolera.

* *Dla tego procesu instalacyjnego w kontrolerze IDE powinien się znaleźć obraz instalatora `.iso`, a w kontrolerze SATA dysk `.vhd`, który został utworzony wraz z wirtualna maszyna.*

| Kontroler | Opis |
| --- | --- |
| PIIX4/PIIX3/ICH6 (IDE)| `Integrated Drive Electornics` - są emulowane chipsety kontrolerów I/O pozwalających na montowanie nośników danych. Posiadają one największa kompatybilność z systemami operacyjnymi. <br> ***Maksymalna ilość montowalnych nosików:** `4` |
| AHCI (SATA) | `Serial Advanced Technology Attachment` - kontroler ten posiada większa przepustowość w porównaniu do IDE. Ponadto oferuje możliwość `Hot Swappingu` pozwalającego na wymianę dysku podczas pracy systemu operacyjnego bez jego resetowania. (jest to jedyny kontroler oferujący taka możliwość w VirtualBox) <br> ***Maksymalna ilość montowalnych nosików:*** `30`*** |
| LsiLogic (SCSI) | `Small Computer System Interface` - jest to kontroler, który będzie oferował większa kompatybilność z systemami w porównaniu do SATA ale nie posiada w VirtualBoxie opcji Hot Swappingu. <br> ***Maksymalna ilość montowalnych nosików: `15`*** |
| Floppy | Jest to kontroler pozwalający na emulowanie dyskietek. <br> ***Maksymalna ilość montowalnych nosików: `2`*** |
| LsiLogic SAS | `Serial Attached SCSI` - jest to kontroler obsługujący dyski SAS, które są bardzie zaawansowane i zapewniają większa wydajność i niezawodność w porównaniu do dysków SATA. Interfejs ten obsługuje spinanie dysków w macierz RAID i zarzadzanie matryca dysków. Posiada możliwość podpięcia dużej ilości dysków co jest preferowanym kontrolerem dla systemów serwerowych. | <br> ***Maksymalna ilość montowalnych nosików: `255`*** |
| VirtIO | Jest to kontroler stworzony specjalnie z myślą o wirtualizacji do wydajnej i optymalnej pracy z hostem. Obsługuje on dyski rożnego typu, ale wymagać będzie instalacji dodatkowych sterowników na maszynie wirtualnej do uzyskania pełnego wsparcia.  | <br> ***Maksymalna ilość montowalnych nosików: `255`*** |
| USB | `Universal Serial Bus` - jest to kontroler, który pozwala na montowanie i bezpośrednia komunikacje urządzeń hosta z wirtualnym środowiskiem, tak jakby były one podpięte bezpośrednio z wirtualnym systemem. <br> ***Maksymalna ilość montowalnych nosików: `8`*** |

**Dodatkowe opcje, które można znaleźć w tej kategorii:**
| Opcja | Opis |
| --- | --- |
| Live CD/DVD | Opcja ta daje możliwość uruchomienia systemu bezpośrednio z nośnika bez jego instalacji na dysk. Gdzie ewentualnie dane ustawione podczas korzystania z systemu zostaną utracone. (lub nie, jeżeli zostanie dokonana ich kopia na inny nośnik) |
| Nazwa | Pozwala ustawić nazwę danego kontrolera. |
| Typ | Pozwala ustawić rodzaj danego kontrolera. |
| Ilość Portów | Pozwala ustawić ilość obsługiwanych portów na danym kontrolerze. |
| Dysk SSD | Opcja ta sprawia, ze montowany dysk będzie traktowany jak dysk SSD (opcja ta powinna byc aktywowana tylko gdy mamy odczynienia z fizycznym dyskiem SSD) |
| Hot-pluggable | Opcja ta daje możliwość odłączania i pionowego podłączenia dysku podczas pracy systemu operacyjnego, bez potrzeby jego resetowania. |


### Dźwięk
| Opcja | Opis |
| --- | --- |
| Włącz dźwięk | Opcja ta pozwala na aktywowanie przechwytywania dźwięku z wirtualnej maszyny poprzez sterownik dźwięku. <br>***W tym procesie instalacji: `opcja ta ma być odznaczona`.*** (nie ma zapotrzebowania na wykorzystanie dźwięku w środowisku serwerowym) |
| Sterownik dźwięku gospodarza | W tej opcji można wybrać poprzez jaki sterownik będzie przekazywany dźwięk z wirtualnej maszyny do systemu hosta. |
| Kontroler audio | Opcja ta pozwala na wybór kontrolera audio wirtualnej maszyny. `ICH AC97` jest najstarszym kontrolerem i będzie zapewniać kompatybilność dla starszy systemów. `SoundBlaster16` także jest kontrolerem starszej generacji. `Intel HD Audio` jest to najnowszy standard dźwięku oferujący lepsza jakość i szereg dodatkowych funkcji.|
| Włącz wyjście dźwięku | Opcja ta aktywuje przekazywanie dźwięku z wirtualnej maszyny do hosta. |
| Włącz wejście dźwięku | Opcja ta aktywuje przekazywanie dźwięku z urządzeń hosta do wirtualnej maszyny. (o ile zostały wcześniej prawidłowo podłączone i skonfigurowane). |


### Sieć
W tej sekcji można skonfigurować karty sieciowe maszyny wirtualnej (maksymalnie do 4).

* **Dla tego procesu instalacji wykorzystamy `1 kartę sieciowa` i skonfigurujemy ja jako `mostkowaną kartę sieciową`, tak aby maszyna była oddzielnie zarejestrowana w sieci hosta (gdzie w nazwie będzie trzeba ustawić kartę sieciowa używana przez hosta podłączoną do internetu).** 

| Typ Sieci | Opis |
| --- | --- |
| NAT | `Network Address Translation` - jest to siec umożliwiająca maszynom wirtualnym na dostęp do Internetu poprzez hosta, gdzie host będzie działać jako router a maszyny będą posiadać swoje prywatne adresy IP, które będą tłumaczone na publiczny adres hosta. |
| Siec Mostkowa | Siec ta pozwala wirtualnej maszynie działać jak pełnoprawne urządzenie w sieci fizycznej. Każda maszyna dostaje swój własny adres w sieci fizycznej, co pozwala jej na komunikacje z lokalnymi urządzeniami w sieci.
| Siec Wewnętrzna | Lachy maszyny wirtualne wewnątrz środowiska wirtualnego, ale bez dostępu do hosta i sieci zewnętrznej. Przydatne, gdy należy stworzyć siec komunikujących ze sobą maszyn wirtualnych np. cluster baz danych. |
| Siec Hosta | Pozwala na komunikacje tylko miedzy maszyna wirtualna a hostem. (brak możliwości leczenia się z sieciami zewnętrznymi)
| Rodzajowy Sterownik | Pozwala na ustawienie niestandardowego sterownika sieciowego dla danej maszyny wirtualnej. Wykorzystywane, gdy potrzebne jest dostosowanie sie do specjalnych sterowników lub wymagań sprzętowych. |
| Siec NAT | Pozwala na tworzenie wielu sieci NAT w której każda z nich będzie działać niezależnie. |
| Cloud Network | Pozwala na leczenie się infrastruktura dostawców usług chmury takich jak AWS, AZURE czy GCP.


**Dodatkowe opcje, które można znaleźć w tej kategorii:**
| Opcja | Opis |
| --- | --- |
| Typ karty | Tutaj można ustawić typ emulowanej karty sieciowej. Każda z nich będzie w pełni działała dla podstawowego wykorzystania przez maszynę wirtualna, jedna do bardziej zaawansowanych konfiguracji karty sieciowej przez maszynę wirtualna, może być zalecane wykorzystanie edycji `SERVER` zamiast `DESKTOP`. <br>***W tym procesie instalacji: `wystarczy wybranie opcji Intel PRO/100 MT Desktop`.*** |
| Tryb nasłuchiwania | Ustawienie to pozwala na aktywowanie nasłuchiwania całego ruchu ramek sieciowych, nawet tych które nie są adresowane do maszyny wirtualnej. Tryb ten może być aktywowany w momencie, gdy chcemy monitorować cały ruch w danej sieci. Ze względów bezpieczeństwa i na przepływ potencjalnie wrażliwych danych nie jest to zalecane. <br>***W tym procesie instalacji: `należy wybrać Odmawiaj`.*** |
| Adres MAC | Tutaj znajduje się adres MAC karty sieciowej maszyny wirtualnej. Z podstawy kazdy adres MAC maszyny wirtualnej VirtualBox będzie zaczynał się od `080027`. Adres ten można ponownie zregenerować wybierając przycisk regeneracji po prawej stronie. <br>***W tym procesie instalacji: `nie należy dokonywać zmian`.*** |
| Kabel Podłączony | Opcja ta pozwala na ustawienie, czy karta sieciowa będzie podłączona do sieci czy tez nie. Przydatne gdy chcemy odłączyć maszynę od danej sieci, ale nie chcemy całkowicie odłączać karty sieciowej. |

### Porty Szeregowe
Sekcja ta zostanie pominięta, ze względów na całkowity brak wykorzystania portów szeregowych w tym procesie instalacyjnym i ewentualnym użytkowaniu systemu operacyjnego, ponadto bardzo rzadko takie porty są instalowane na maszynach wirtualnych użytku codziennego czy serwerowego. Większość urządzeń wykorzystuje standard komunikacji USB. Ewentualne zastosowanie, będzie można odnaleźć podczas instalacji o wiele starszych systemów operacyjnych.

### USB
Sekcja ta pozwala na bezpośrednie podłączenie urządzeń USB hosta z maszyna wirtualna. Można wybrać miedzy standardami USB 1.1, USB 2.0 i USB 3.0. Urządzenia można dodawać poprzez przycisk `+` w prawym panelu. Można także dodać filtry, dzięki którym w łatwy sposób można ustawić automatyczne instalowanie urządzeń.

### Udostępniane foldery
Sekcja ta pozwala na udostepnienie folderów hosta maszynie wirtualnej, dzięki czemu w łatwy sposób można ustanowić komunikacje miedzy nimi. Folder można udostępnić klikając na przycisk `+` w prawym panelu. Na potrzeby tego procesu instalacyjnego nie będzie wykorzystania udostępniania folderów, dlatego w tej sekcji nie zostanie wprowadzona jakakolwiek zmiana.

| Opcja | Opis |
| --- | --- |
| Ścieżka do folderu | Lokalizacja folderu u hosta, który będzie się udostępniało. |
| Nazwa Folderu | Nazwa tego folderu. |
| Punkt Montowania | Lokalizacja na maszynie wirtualnej w jakiej zostanie ten folder zamontowany. |
| Tylko do odczytu | Opcja ta blokuje możliwość zapisu przez maszynę wirtualna w tym folderze. Przydatne, gdy nie chcemy w jakikolwiek sposób dawać dostęp do modyfikacji systemu hosta maszyny wirtualnej. |
| Automatyczne Montowanie | Opcja ta sprawi, ze VirtualBox będzie automatycznie montował ten folder do systemu przy każdy uruchomieniu wirtualnej maszyny.

> [!WARNING]
> Dla niektórych systemów operacyjnych wirtualnej maszyny będzie wymagane zainstalowanie i konfiguracja `VirtualBox Guest Additions` do prawidłowego automatycznego montowania udostępnianych folderów.

### Interfejs Użytkownika
Sekcja ta śluzy tylko do konfigurowania interfejsu okna wirtualnej maszyny. Opcje te maja aspekt czysto wizualny dla użytkownika korzystający z VirtualBox'a i nie maja jakiegokolwiek wpływu na proces instalacyjny systemu czy tez jego prawidłowe działanie, dlatego tez sekcja ta zostanie pominięta.

## Finalny proces instalacji
7. Po prawidłowym skonfigurowaniu wszystkich opcji w ustawieniach, należy kliknąć na przycisk `OK`.
8. Teraz wszystko jest już gotowe i można przejść do finalnego procesu instalacji systemu operacyjnego. W tym celu należy uruchomić maszynę przyciskiem `Uruchom`. 
9. Po uruchomieniu się systemu wybieramy opcje `Install`. (*nie Graphical Install, ponieważ chcemy mieć jak najbardziej wydajny proces instalacji*). Do wyboru są dostępne także inne opcje, takie jak instalowanie systemu z syntezatorem mowy, instalowanie systemu z wysokim kontrastem (dla osób niedowidzących), a także menu `Help` z informacjami pomocniczymi.
10. Na ekranie pojawi się opcja z wyborem jeżyka. Należy wybrać `English`, ze względów na łatwiejsze wykonanie procesu instalacji czy tez odnajdowanie pomocy w Internecie w razie ewentualnych komplikacji.
11. W kolejnym oknie, należy podać kraj z którego instalujemy system operacyjny, będzie to kluczowe w celu ustawienia prawidłowej strefy czasowej i pobierania plików z najbliższego serwera. Należy odszukać `Poland`, jeżeli nie znajduje się on na liście to należy wybrać `other`, następnie `Europe` i `Poland` (łatwiej można odnaleźć klikając na przycisk P).
12. Następnie konfigurator instalacji poprosi o wybranie finalnych ustawień językowych i system kodowania tekstu, w tym celu należy wybrać `United States`.
13. Kolejnym krokiem jest wybranie mapowania klawiatury, z racji tego ze klawiatura wykorzystywana w Polsce to klawiatura z mapowaniem programistycznym, to tutaj także wybierzemy mapowanie `American English`.
14. Następnie będzie należało dokonać konfiguracji sieciowej. Na początku będzie trzeba wprowadzić `Hostname`, czyli identyfikator systemu w sieci, w tym procesie instalacyjnym użyjemy `debian12-server`. Po ustawieniu nazwy, konfigurator poprosi o wprowadzenie stosowanej domeny sieci.  Jeżeli system ten jest instalowany na lokalnej sieci domowej, to nie ma potrzeby wprowadzac specjalnej nazwy (należy pozostawić puste), jednak jeżeli instalacje dokonujemy w sieci roboczej, np. szkolnej to należy ta domenę wprowadzić. (dla PJATK będzie to `pjwstk.edu.pl`).
15. W kolejnym kroku należy skonfigurować konto super administratora (root), który bedzie miał wszystkie potrzebne uprawnienia do pełnego zarzadzania maszyna. Aby je skonfigurować będzie trzeba wprowadzić, a potem w kolejnym oknie je powtórzyć.

> [!CAUTION]
> Jeżeli osoba nieautoryzowana otrzyma dostęp do konta root, to otrzymuje pełna kontrole nad maszyna. Aby zabezpieczyć się przed ewentualnymi atakami brutforce zalecane jest wprowadzenie odpowiednio silnego hasła lub przyszłościowego ustawienia dostępu tylko poprzez klucz SSH.

16. Po skonfigurowaniu konta super administratora, konfigurator będzie wymagał wprowadzenie danych do konta normalnego użytkownika (nie posiadającego wszystkich uprawnień), z którego korzystanie jest zalecane dla większości codziennych wykonywanych działań. Na początku będzie należało wprowadzić pełna nazwę użytkownika (może to być imię i nazwisko), następnie login (jedno wyrazowy wykorzystywany do logowania), a na końcu hasło tego użytkownika i jego powtórzenie.  

17. Kolejnym bardzo kluczowym krokiem jest partycjonowanie dysków, w którym należy wybrać opcje `Manual`. (Dla tego procesu instalacyjnego nie będziemy dokonywać bardzo zaawansowanego podziału na partycji, ponieważ korzystamy tylko z jednego dysku, a także to środowisko serwerowe nie będzie tego wymagało.)

18. Na ekranie powinny się pojawić opcje `Guided partitioning`, `Configure iSCSI volumes` i `SCSI (0, 0, 0) (sda) ...`. Ostatnia opcja to dysk, na którym chcemy dokonać podziału na partycje, należy go wybrać i kliknąć `enter`. Po tym pojawi się pytanie, czy chcemy stworzyć nowa pusta tabele partycji na tym dysku (wybieramy `Yes`). Po tym zostanie utworzona partycja pusta `pri/log` z maksymalna dostępna ilością pamięci i tagiem `FREE SPACE`. Cala tą przestrzeń będzie należało rozdzielić na inne partycje.

19. Tworzenie partycji `SWAP (Pamięci Wymiany)`. Partycja ta jest bardzo kluczowa do prawidłowego działania systemu i wykonywania się procesów. Do pamięci SWAP są tymczasowo zapisywane dane procesu, tak aby nie wypełniać pamięci RAM w trakcie zmiany kontekstu, a po powrocie do kontekstu oryginalnego zostaje to powrotem wczytane do pamięci RAM. Aby utworzyć ta partycje przechodzimy do opcji zawierająca tag `FREE SPACE` i klikamy enter. Wyskoczy komunikat z kilkoma opcjami, gdzie będzie należało wybrać opcje `Create a new partition`. Następnie będzie należało podać ilość pamięci, która zostanie przeznaczona dla SWAPu. Z racji tego, ze przydzielone zostało do tej maszyny 2GB RAM, to do SWAP'u będzie trzeba przydzielić 4 GB i wybrać `Continue`. Następnie będzie trzeba wybrać czy partycja ta ma być `Primary` czy `Logical`. (dla `Primary` można przydzielić tylko 3 partycje,  a dla `Logical` o wiele więcej ] w zależności od wybranego kontrolera dysków]), w tym przypadku dla SWAP zostanie utworzona partycja logiczna. W kolejnym oknie będzie trzeba wybrać czy partycja ma być stworzona na początku czy na końcu. W ogólnym kontekście nie ma to już wielkiego znaczenia w tych czasach, a wiec zostanie wybrana opcja `Beginning`. W kolejnym oknie do wyboru będą opcje konfiguracyjne tej konkretnej partycji. Dla SWAP'u do zmiany będzie tylko opcja pierwsza `Use as`, do której należy wejść i tam wybrać opcje `swap area`. Dla konfiguracji pamięci wymiany to by było tyle, wiec teraz należy wybrać opcje `Done setting up the partition`, aby zakończyć proces tworzenia tej partycji. Po prawidłowym ustawieniu, w liście utworzonych partycji powinna pojawić się stworzona partycja o numerze `#5`, z przydzielonymi `4GB` przestrzeni w postaci `swap`.

> [!NOTE]
> Zalecane jest przydzielenie do SWAPu tyle pamięci: <br> - **[GDY RAM DO 2 GB]** -> SWAP = 2 * (ILOSC RAM) <br> - **[GDY RAM > 2 GB]** -> SWAP = (ILOSC RAM) + 2 GB

**Wyjaśnienie reszty dostępnych opcji wykorzystania danej partycji (Use as):**
| Opcja | Opis |
| --- | --- |
| Ext4 journaling | System plików Ext4 z mechanizmem dziennikowania, zapewniający stabilność danych i wysoką wydajność. |
| Ext3 journaling | Poprzednia wersja systemu plików Ext z mechanizmem dziennikowania, oferująca podobne cechy do Ext4, ale z mniejszymi możliwościami optymalizacji. |
| Ext2 | Starsza wersja systemu plików Ext bez mechanizmu dziennikowania, oferująca podstawową funkcjonalność bez dodatkowych zabezpieczeń. |
| btrfs journaling | System plików Btrfs z mechanizmem dziennikowania, charakteryzujący się elastycznością, obsługą kopiowania migawkowego i replikacji. |
| JFS | System plików JFS (Journaling File System), zapewniający szybki dostęp do danych i wysoką niezawodność. |
| XFS | System plików XFS, zapewniający wysoką wydajność i skalowalność, szczególnie przy obsłudze dużych plików i woluminów. |
| FAT16 | System plików FAT16, obsługujący małe partycje i pliki o ograniczonym rozmiarze. |
| FAT32 | System plików FAT32, obsługujący większe partycje i pliki w porównaniu do FAT16. |
| Swap Area | Specjalna partycja używana jako przestrzeń wymiany, służąca do przechowywania danych wykorzystywanych przez system, gdy brakuje pamięci RAM. |
| physical volume for encryption | Partycja przeznaczona do szyfrowania danych, wykorzystywana w technologiach szyfrowania dysków. |
| physical volume for RAID | Partycja przeznaczona do wykorzystania w macierzach RAID, służąca do zwiększenia niezawodności i wydajności przechowywanych danych. |
| physical volume for LVM | Partycja przeznaczona do wykorzystania w systemie zarządzania logicznymi woluminami (LVM), umożliwiającym elastyczne zarządzanie przestrzenią dyskową. |
| do not use the partition | Opcja wyboru, aby nie wykorzystywać danej partycji, pozostawiając ją niewykorzystaną w systemie. |

**Wyjaśnienie dostępnych opcji ustawień montowania danej partycji (Mount Options):**
| Opcja | Opis |
| --- | --- |
| discard | Opcja umożliwiająca natychmiastowe usuwanie danych (TRIM) dla urządzeń SSD, co może poprawić wydajność i trwałość dysku. |
| noatime | Opcja wyłączająca aktualizację czasu dostępu do plików, co może zwiększyć wydajność systemu poprzez ograniczenie operacji zapisu na dysku. |
| nodiratime | Opcja podobna do noatime, ale dotyczy tylko katalogów, pomijając aktualizację czasu dostępu tylko dla nich. |
| realtime | Opcja umożliwiająca oznaczenie partycji jako obszar czasu rzeczywistego, co jest przydatne w systemach wymagających precyzyjnej synchronizacji czasu. |
| nodesv | Opcja blokująca tworzenie specjalnych plików urządzeń (np. /dev/null, /dev/random) na danej partycji, co może zwiększyć bezpieczeństwo systemu. |
| nosuid | Opcja blokująca wykonanie plików z ustawionym bitem suid, co może ograniczyć potencjalne luki bezpieczeństwa w systemie. |
| noexec | Opcja blokująca wykonywanie plików wykonywalnych na danej partycji, co może zapobiec wykonaniu złośliwego kodu. |
| ro | Opcja montowania partycji jako tylko do odczytu (read-only), uniemożliwiająca zapisywanie na niej danych. |
| sync | Opcja wymuszająca synchroniczne operacje zapisu na danej partycji, co może zwiększyć niezawodność systemu kosztem wydajności. |
| userquota | Opcja umożliwiająca obsługę limitów dyskowych dla użytkowników na danej partycji. |
| grpquota | Opcja umożliwiająca obsługę limitów dyskowych dla grup użytkowników na danej partycji. |
| user_xattr | Opcja umożliwiająca obsługę rozszerzonych atrybutów użytkownika na danej partycji, co pozwala na przechowywanie dodatkowych metadanych plików. |
20. Tworzenie partycji `Home`. W partycji tej zostanie uwzględniony katalog domowy użytkowników. Zalecane jest jego oddzielenie, ze względów na fakt, ze jeżeli pamięć tej partycji zostanie wypełniona, to nie będzie to miało wpływu na prawidłowe funkcjonowanie systemu. W celu utworzenia tej partycji należy ponownie wybrać opcje z tagiem `FREE SPACE`, tam wybrać opcje `Create a new partition` i tutaj ustawić przestrzeń jaka zostanie przydzielona dla użytkowników. Dla tego procesu instalacyjnego przeznaczone zostanie 26GB (reszta wolnej przestrzeni przeznaczona będzie dla systemu i reszty katalogów). Partycja ta będzie także ustawiona jako partycja logiczna na początku wolnej przestrzeni. W konfiguracji tej partycji pozostawiony zostanie system plików `Ext4 journaling`, ze względów na wystarczająca wydajność i niezawodność, która dla systemu serwerowego jest kluczowa. Dodatkowo w konfiguracji należy zmienić `Mount point`, w którym ustawić trzeba `/home`. Reszta ustawień konfiguracyjnych ma być niezmieniona. Gdy wszystko zostanie ustawione, należy wybrać zapisać konfiguracje tej partycji wybierając `Done setting up the partition`.

21. Tworzenie partycji ogólnej `/` (root). Partycja ta będzie partycja ogólna, w której znajdować się będą wszystkie innego katalogi systemowe i do której zostanie przydzielona reszta wolnej przestrzeni dyskowej. Ponownie należy wybrać opcje z tagiem `FREE SPACE`. W ilości przydzielanej pamięć należy wprowadzić cala wolna przestrzeń, czyli `10 GB`. Zamiast wybierać partycje logiczna należy tym razem wybrać partycje `Primary` (ze względów na to, ze przestrzeń ta będzie ogólna dla systemu). Tutaj także pozostawiony zostanie podstawowy system plików `Ext4 journaling`. Mount point ma wskazywać na `/`. A reszta ustawień ma pozostać bez zmian. Po prawidłowym ustawieniu należy zapisać ta partycje wybierając `Done setting up the partition`.

> [!NOTE]
> W procesie konfiguracji wirtualnej maszyny został stworzony dysk o pojemności 40GB. 4GB zostały przeznaczone dla przestrzeni wymiany, a dla reszty systemu według [minimalnych zalecen](https://www.debian.org/releases/stable/i386/ch03s04.en.html) w wersji `No Dektop`, czyli tej która jest instalowana, potrzebne jest minimum 4GB przestrzeni. Dla bezawaryjnego korzystania i pozostawienia wolnej przestrzeni dodano dodatkowo 6GB dla przyszłych aplikacji, zaokrąglając wymagana przestrzeń ogólna `/` do 10GB dla systemu, z tego względu na katalog `Home` można było przeznaczyć `26GB`.


22. I właśnie w taki sposób prawidłowo została podzielona i skonfigurowana cala przestrzeń dyskowa. Aby zakończyć ten proces należy wybrać opcje `Finish partitioning and write changes to disk` a następnie `Yes`. Po tym zostanie rozpoczęty proces instalacji podstawy systemu.

23. Po zainstalowaniu się podstawy systemu, na ekranie powinno wyskoczyć powiadomienie `Configure the package manager`, w którym mamy opcje zeskanować inne nośniki, które mogłyby zostać użyte na potrzeby `package manager'a`. W tym procesie instalacyjnym dodatkowe nośniki nie zostały wprowadzone, wiec należy wybrać opcje `No`. Po czym zostanie wyświetlone okno wyboru kraju z którego zostanie dokonany klon pobieranych plików systemu do finalnego procesu instalacyjnego. W tym przypadku należy wybrać `Poland`. Wyświetlone zostaną dostępne serwery archiwów systemowych, gdzie optymalnie należy wybrać serwer znajdujący się najbliżej lokalizacji instalowanego systemu. W przypadku Trójmiasta zalecane jest wybranie opcji `ftp.task.gda.pl`, jeżeli podczas instalacji wyskoczy błąd z informacja, ze serwer ten jest niedostępny lub  że nie można pobrać plików instalacyjnych, to w takim przypadku należy wybrać innych serwer dostępny z listy. Po wybraniu serwera, instalator zapyta o informacje czy do uzyskania dostępu do Internetu wykorzystany ma być serwer `Proxy`. Jeżeli sieć, w której instalowany jest system nie posiada ograniczaj dostępowych to należy zostawić tą przestrzeń pustą, w innym przypadku należy uzupełnić to pole danymi serwera Proxy.

24. W trakcie pobierania plików instalacyjnych prawdopodobnie wyświetli się informacja odnośnie `ankiety popularnościowej`, w której nie trzeba brać udziału, dlatego tez w tym przypadku należy wybrać opcje `No`.

25. W trakcie instalacji, wyskoczy okno z wyborem Software'u do zainstalowania. Opcje te można zaznaczać i odznaczać korzystając ze spacji. Na potrzeby tego procesu instalacyjnego systemu serwerowego zaznaczone powinny być tylko opcje `SSH server` i `Standard system utilities`.  Po wybraniu należy przejść do dalszego etapu instalacji poprzez przycisk `Continue`.

| Opcja | Opis dostępnych opcji |
| --- | --- |
| Debian desktop environment | Opcja instalowania podstawowych aplikacji i narzędzi dla systemu z wykorzystaniem domowym. |
| GNOME | Środowisko graficzne zapewniające intuicyjny interfejs użytkownika oraz obsługę aplikacji. |
| Xfce | Lekkie środowisko graficzne, charakteryzujące się niskim zużyciem zasobów systemowych. |
| GNOME Flashback | Wersja GNOME o uproszczonym interfejsie, przypominająca starsze wersje GNOME. |
| KDE Plasma | Środowisko graficzne oferujące bogate funkcje i elastyczność w dostosowaniu wyglądu. |
| Cinnamon | Środowisko graficzne o interfejsie zbliżonym do tradycyjnych systemów operacyjnych. |
| MATE | Lekkie i prostsze w obsłudze środowisko graficzne, bazujące na starszych wersjach GNOME. |
| LXDE | Bardzo lekkie środowisko graficzne, zapewniające minimalne zużycie zasobów systemowych. |
| LXQt | Nowoczesne, lekkie środowisko graficzne zbudowane na Qt, oferujące niskie zużycie zasobów. |
| Web Server | Opcja instalująca serwer WWW, umożliwiający udostępnianie stron internetowych. |
| SSH Server | Instalacja serwera SSH, umożliwiającego zdalne logowanie i zarządzanie systemem przez SSH. |
| Standard system utilities | Podstawowe narzędzia systemowe niezbędne do prawidłowego funkcjonowania systemu operacyjnego. |

26. Po zainstalowaniu się systemu wyskoczy okno konfiguracyjne `GRUB boot loader'a`, który zajmuje się startowanie systemu z dysku. W oknie konfiguracyjny wyświetlona zostanie informacja, że system ten jest jedynym zainstalowanym na tym komputerze i czy ma skonfigurować automatycznie bootloadera dla tego systemu. Z racji tego, że na środowisku serwerowym operować będzie tylko jeden system, to należy wybrać opcje `Yes`, a w kolejnej sekcji wybrać dysk na który jest zainstalowany system, czyli `dev/sda`.

27. Po finalnej konfiguracji systemu i zakończeniu się instalacji wyskoczy komunikat z informacja, ze proces ten zakończył się pomyślnie. Teraz wystarczy zresetować system, wybierając `Continue`.

28. Na samym końcu warto by było jeszcze zamknąć maszynę i w ustawieniach tej wirtualnej maszyny w sekcji `System - Płyta Główna odznaczyć `Napęd Optyczny`, ponieważ nie będzie on już potrzebny, a w sekcji `Pamięć` należy usunąć kontroler `IDE`, ponieważ system jest prawidłowy zainstalowany ma dysku.

## Słowa na koniec

> [!TIP]
> *System serwerowy można uruchomić w tle używając bezgłowego startu.*

> [!TIP]
> *Aby połączyć się z maszyna poprzez SSH należy rozpoznać pod jakim prywatnym adresem IP w tej sieci jest ten system podpięty. Aby uzyskać taką informacje należy użyć polecenia `hostname -I`. A potem wykorzystać ten adres w procesie łączenia się.*

**To by było na tyle z procesu instalacji systemu operacyjnego.** Ćwiczenie to wymagało dogłębnego zaznajomienia się z każdą opcją w systemie, gdzie trzeba było poświęcić większą ilość czasu niż początkową przewidywałem, ale z pewnością moja wiedza na temat samych maszyn wirtualnych i działania fundamentalnych elementów systemów operacyjnych się znacznie poszerzyła. (wcześniej tylko potrafiłem odpalić automatyczną instalacje bez głębszego przemyślenia, teraz dokładnie rozumiem cały proces instalacji i jak wiele możliwości otwiera na lepszą konfiguracje środowiska wirtualnej maszyny i samego systemu)
