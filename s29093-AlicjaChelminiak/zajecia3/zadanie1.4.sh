#!/bin/bash

# Zliczanie tylko plików w bieżącym katalogu
ILOSC_PLIKOW=$(find . -maxdepth 1 -type f | wc -l)

if [[ "$ILOSC_PLIKOW" -gt 5 ]]; then
    echo "Jest więcej niż 5 plików"
fi
