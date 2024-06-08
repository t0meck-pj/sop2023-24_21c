#!/bin/bash

for plik in "$@"; do
    echo "$plik"
    cat "$plik"
done

for plik in "$@"; do
    echo "$plik"
    tac "$plik"
done
