#!/bin/bash

if [ -f config.cfg ]; then
    ./config.cfg
elif [ $# -ge 1 ]; then
    ./$1
else
    echo "Nie podano parametrów"
fi
