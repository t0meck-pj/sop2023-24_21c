#!/bin/bash
function fibonacci {
    if [[ $1 -le 0 ]]; then
        return 0
    elif [[ $1 == 1 ]]; then
        return 1
    else
        fibonacci $(( $1 - 1 ))
        local a="$?"
        fibonacci $(( $1 - 2 ))
        local b="$?"

        return $(( a + b ))
    fi
}

fibonacci "$1"
echo "$?"
