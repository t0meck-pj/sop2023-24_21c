#!/bin/bash

if [[ -a "config.cfg" ]]; then
    bash "config.cfg"
elif [[ $# > 0 && -a $1 ]]; then
    bash $1
else
    echo "Nie udalo sie uruchomic zadnego pliku!"
fi

