#!/bin/bash

IFS=$'\n'

for a in $(ls); do
    echo "Patrzcie Państwo, oto plik: $a"
done