#!/bin/bash

IFS=$'\n'

for plik in $(ls -a); do
    echo "Patrzcie Państwo, oto plik: $plik"
done
