#!/bin/bash

file_count=$(find . -maxdepth 1 -type f | wc -l)

if [ "$file_count" -gt 5 ]; then
    echo "W obecnym katalogu jest więcej niż 5 plików."
elif [ "$file_count" -eq 5 ]; then
    echo "W obecnym katalogu jest 5 plików."
else
    echo "W obecnym katalogu jest mniej niż 5 plików."
fi