#!/bin/bash

if [ -f "config.cfg" ]; then
    bash config.cfg
    exit 0
fi

if [ "$#" -eq 1 ] && [ -f "$1" ]; then
    bash "$1"
    exit 0
fi

echo "BLAD"
exit 1
