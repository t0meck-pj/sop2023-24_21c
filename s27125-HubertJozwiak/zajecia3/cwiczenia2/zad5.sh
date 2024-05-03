#!/bin/bash

for i in $@
do
    echo "Plik: $i"
    echo "Od początku:"
    cat $i
    echo

    echo "Od końca:"
    tac $i
    echo
done