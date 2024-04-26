#!/bin/bash
if [ -a "config.cfg" ]; then
    bash "./config.cfg"
elif [ "$#" -gt 0 ]; then
    bash "$1"
else
    echo "Plik config.cfg nie istnieje i nie został podany żaden inny"
fi
