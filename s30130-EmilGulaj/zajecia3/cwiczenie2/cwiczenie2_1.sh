#!/bin/bash

# Rozwiązanie 1
for ((i = 10; i > 0; i -= 2)); do
    echo $i;
done

echo ''

# Rozwiązanie 2
for i in {10..1..-2}; do
    echo $i;
done

echo ''

# Rozwiązanie 3
for i in $(seq 10 -2 1); do
    echo $i;
done