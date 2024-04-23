#!/bin/bash

for ((i = 10; i > 0; i -= 2)); do
    echo $i;
done

echo ''

for i in {10..1..-2}; do
    echo $i;
done

echo ''

for i in $(seq 10 -2 1); do
    echo $i;
done