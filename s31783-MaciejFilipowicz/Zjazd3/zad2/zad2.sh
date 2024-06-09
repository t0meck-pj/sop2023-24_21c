#!/bin/bash

# Wyświetlanie każdego argumentu w cudzysłowie
for argu in "$@"; do
    echo "\"$argu\""
done