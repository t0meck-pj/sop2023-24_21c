#!/bin/bash

if [ $(ls | wc -l) -gt 5 ]; then
    echo "W bieżącym katalogu jest więcej niż 5 plików"
else 
    echo "W bieżącym katalogu jest 5 lub mniej plików"
fi