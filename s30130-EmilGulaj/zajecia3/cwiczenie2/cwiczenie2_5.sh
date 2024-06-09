#!/bin/bash

for file in "$@"; do
    lines=()
    while IFS= read -r line; do
        lines+=("$line")
        echo $line
    done < $file

    echo -e '\n------odwrotność------\n'
    
    for ((line=${#lines[@]}-1; line >= 0; line--)); do
        reversed_line=""
        for ((letter=${#lines[line]}-1; letter >= 0; letter--)); do
            reversed_line="${reversed_line}${lines[line]:letter:1}"
        done
        echo "$reversed_line"
    done < $file

    echo ''
done
