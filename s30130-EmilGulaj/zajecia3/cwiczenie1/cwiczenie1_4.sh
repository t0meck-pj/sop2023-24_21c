#!/bin/bash

# Rozwiązanie 1
if (( $(ls *.* | wc -l) < 5 )); then
    echo  "check1"
fi

# Rozwiązanie 2
if (( $(ls -l . | grep -c '^-') < 5 )); then
    echo "check2"
fi

# Rozwiązanie 3
if (( $(find -type f | wc -l) < 5 )); then
    echo "check3"
fi
