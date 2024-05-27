#!/bin/bash

if [ "$#" -gt 1 ]; then
    echo "$1"
else
    echo "Nie podano więcej niż 2 parametry"
fi
