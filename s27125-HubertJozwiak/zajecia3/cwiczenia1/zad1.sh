#!/bin/bash

if [ $# -ge 1 ]; then
    echo "Pierwszy parametr: $1"
elif [ $# -eq 0 ]; then
    echo "Nie podano parametrów"
fi
