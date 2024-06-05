#!/bin/bash

# ograniczenie: literał return może zwracać tylko wartości z zakresu 0-255
function fibonacci {
    if [ $1 -eq 0 ]; then
        return 0
    elif [ $1 -eq 1 ]; then
        return 1
    else
        fibonacci $(( $1 - 1 ))
        local a=$?
        fibonacci $(( $1 - 2 ))
        local b=$?

        return $(( $a + $b ))
    fi
}

if [ $# -ne 1 ]; then
    echo "Usage: $0 <n>"
    exit 1
fi

fibonacci "$1"
echo $?