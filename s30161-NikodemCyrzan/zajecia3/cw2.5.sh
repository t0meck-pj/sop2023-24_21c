#!/bin/bash
IFS=" " read -r -a files <<< "$@"

echo -e "\nOd początku\n-----------\n"

allLines=()

for file in "${files[@]}"; do
    while IFS= read -r line; do
        allLines+=("$line")
        echo "$line"
    done < "$file"
done

echo -e "\nOd końca\n--------\n"

LEN=${#allLines[@]}
for (( i=$LEN-1; i >= 0; i-- )); do
    echo "${allLines[$i]}"
done
