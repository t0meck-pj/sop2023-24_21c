#!/bin/bash

if [ -f "config.cfg" ]; then
./config.cfg
elif [[ $# != 0 ]]; then
./$1
else
echo "Błąd: Nie znaleziono pliku config.cfg i nie podano argumentu."
fi
