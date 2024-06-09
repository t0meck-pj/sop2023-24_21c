#!/bin/bash

function fibonacci {
    if (( $1 == 0 )); then
        return 0
    elif (( $1 == 1 )); then
        return 1
    else
        fibonacci $(( $1 - 1 ))
        local fib1=$?
        fibonacci $(( $1 - 2 ))
        local fib2=$?
        
        return $(( fib1 + fib2 ))
    fi
}


fibonacci $1
# Dla liczb większych od 13 ( czyli takich które zwracają liczbę powyżej 255 )
# zwracana jest reszta z dzielenia: podana liczba % 256.
# Takie działanie jest spowodowane tym, że bash może zwracać liczby tylko
# z zakresu 0 - 255

echo $?
