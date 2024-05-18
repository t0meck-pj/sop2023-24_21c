#!/bin/bash

if [[ $# > 1 ]]; then # ma byc wiecej niz jeden, czyli przy jednym parametrze ma to nie dzialac
    echo "$1"
else
    echo "Nie podano parametrow!"
fi

