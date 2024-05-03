#!/bin/bash

if [[ $0 =~ \.sh$ ]]; then
    echo "Nazwa pliku kończy się na .sh"
else
    mv $0 $0.sh
    echo "Zmieniono nazwę pliku na $0.sh"
fi