#!/bin/bash
INFO="W bieżącym katalogu znajduje się więcej niż 5 plików" 

# metoda 1
if [[ $(ls -1 | wc -l) -gt 5 ]]; then
    echo "$INFO" 
fi

# metoda 2
if [[ $(ls -1 | grep -c ^) -gt 5 ]]; then
    echo "$INFO" 
fi

# metoda 3
if [[ $(find -type f | wc -l) -gt 5 ]]; then
    echo "$INFO" 
fi
