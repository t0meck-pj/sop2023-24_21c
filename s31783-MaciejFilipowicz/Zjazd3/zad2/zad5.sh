#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "Nie podano żadnych plików."
    exit 1
fi

echo "Zawartość plików od początku do końca:"
for a in "$@"; do
    echo "Zawartość pliku $a:"
    while IFS= read -r b; do
        echo "$b"
    done < "$a"
    echo ""
done

echo "Zawartość plików od końca do początku:"
for a in "$@"; do
    b=$(wc -l < "$a")
    for (( i=b; i>=1; i-- )); do
        sed "${i}q;d" "$a"
    done
    echo ""
done