#!/bin/bash

for file in "$@"; do
    while IFS= read -r line; do
        echo $line
    done < $file

    echo ''

    for (( line=$(wc -l); line > 0; line-- )); do
        echo "$line"
    done < $file

    echo ''
done