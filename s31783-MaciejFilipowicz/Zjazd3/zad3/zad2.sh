#!/bin/bash

fibonacci() {
    local a="$1"

    if (( a <= 1 )); then
        echo "$a"
        return
    fi

    local fib1=$(fibonacci $(( a - 1 )))
    local fib2=$(fibonacci $(( a - 2 )))
    echo $(( fib1 + fib2 ))
}

echo "Podaj liczbe: "
read a

wynik=$(fibonacci "$a")
echo "Wynik: $wynik"
