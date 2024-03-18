Instalacja systemu operacyjnego Linux Debian bez środowiska graficznego
na maszynie wirtualnej.

Kroki:

# 1. Pobranie ISO systemu Debian12 ze strony https://www.debian.org/distrib.

# 2. W programie VirtualBox naciśnięcie przycisku "Nowa", w celu
stowrzenia obrazu nowej maszyny wirtualnej.

# 3. Wejście w tryb eksperta w celu zwiększenia ilości opcji.

# 4. Podanie w polu "Nazwa" nazwy maszyny.

Mój wybór: 
    Debian12

# 5. W polu "ISO Image" wybranie wcześniej pobranego pliku ISO systemu.

# 6. Upewnienie się, że w polu "Wersja" wybrana jest opcja "Debian (64-bit)". 

Jeśli nie:
    wybrać tą wersję

Dlaczego: 
    systemy 64-bitowe lepiej wykorzystują zasoby nowoczesnych procesorów.

Jeśli dostępne są tylko wersje 32-bit:
    prawodpodobnie (w przypadku systemu Windows) 
    na komputerze uruchomione jest HyperV, czyli oprogramowanie do wirtualizacji
    maszyn, od firmy Microsoft.

    Skutek: 
        HyperV zawłaszcza instrukcje wirtualizacyjne, przez co inne oprogramowanie
        wirtualizacyjne nie jest w stanie wykorzystywać tych instrukcji i wirtualizacja
        nie odbywa się sprzętowo, a poprzez software. W rezultacie maszyny działają wolniej.

# 7. Zaznaczenie pola "Skip Unattended Installation"

Czym jest unattended installation:
    polega to na skonfigurowaniu instalacji systemu przed uruchomieniem maszyny wirtualnej.
    VirtualBox wykona konfigurację automatycznie.

Dlaczego pominąłem:
    chciałem wykonać instalację ręcznie

# 8. Przyznanie odpowiedniej ilości pamięci RAM

Jak zdecydować jaką ilość wybrać:
    należy sprawdzić wymagania sprzętowe danego systemu operacyjnego.
    W przypadku systemu Debian12 minimalna wartość to 256 MB, 
    a rekomendowana 512 MB.

Mój wybór:
    na czas instalacji 1024 MB, aby potencjalnie przyśpieszyć ten proces.
    Po instalacji zmniejszyłem wartość na zalecane 512 MB, ponieważ system instalowany był
    jedynie w celach demonstracyjnych, więc nie było wymagane uwzględnienie wymagań sprzętowcyh
    innych serwisów, takich jak na przykład serwer HTTP.

# 9. Przydzielenie odpowiedniej ilości procesorów.

Jak zdecydować jaką ilości wybrać:
    należy zastanowić się w jakich celach wykorzystywany będzie system i czy
    wymagana będzie wielowądkowość.

Mój wybór:
    na czas instalacji 8, aby potencjalnie przyśpieszyć ten proces.
    Po instalacji zmniejszyłem wartość na 1.

# 10. Opcja EFI. // TODO

# 11. Przydzielenie odpowiedniej ilości pamięci.

Jak zdecydować jaką ilość wybrać:
    w wymaganiach sprzętowych systemu istnieje zapiska o wymaganej ilości pamięci,
    w przypadku systemu Debian12 jest to 2 GB.

Mój wybór:
    10 GB, aby zostawić sobie zapas.

# 12. Wybór typu obrazu.

Dostępne opcje:
    VDI (VirtualBox Disk Image):
        rozwiązanie firmy VirtualBox
    VHD (Virtual Hard Disk):
        rozwiązanie firmy Microsoft, wykorzystywane w HyperV i Azure
    VMDK (Virtual Machine Disk):
        rozwiązanie firmy VMware, wykorzystywane na przykład w VMwate Server
    HDD (równoległy dysk twardy):
        fizyczny dysk, wykorzystywane w celu uzyskania największej możliwej wydajności
    QCOW (QEMU Copy-On-Write):
        format z opcją Copy-On-Write wykorzystywany przez emulator QEMU
    QED (QEMU enhanced disk):
        format wykorzystywany przez emulator QEMU

Mój wybór:
    VDI, ponieważ jest formatem wykorzystywanym przez VirtualBox,
    a więc jest w pełni wspierany.

# 13. Zaznaczenie opcji "Pre-allocate Full Size"

Co to oznacza:
    jeśli opcja jest zaznaczona, obraz zostanie zaalokowany w pełni podczas jego tworzenia.
    Jeśli nie jest, dodatkowa potrzebna przestrzeń będzie alokowana automatycznie w trakcie
    działania systemu.

Kiedy wybrać:
    Jeśli często będą alokowane nowe dane, a wymagana będzie najwyższa wydajność.

Mój wybór:
    Wyłączone, ponieważ nie było to potrzebne.