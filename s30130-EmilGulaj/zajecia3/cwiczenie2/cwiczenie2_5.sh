#!/bin/bash

for file in "$@"; do
    lines=()
    while IFS= read -r line; do
        lines+=("$line")
        echo $line
    done < $file

    echo -e '\n------odwrotność------\n'
    
    for (( line=${#lines[@]}-1; line >= 0; line-- )); do
        echo "${lines[$line]}"
    done < $file

    echo ''
done