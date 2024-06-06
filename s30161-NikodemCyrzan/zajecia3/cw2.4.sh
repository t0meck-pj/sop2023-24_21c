#!/bin/bash
for i in $(ls -1); do
    if [[ "${i:(-2)}" = ".c" ]]; then
        $(cc "$i" -o "${i:0:-2}")
    fi
done
