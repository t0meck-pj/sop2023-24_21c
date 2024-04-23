#!/bin/bash


if (( $(ls -1 | wc -l) < 5 )); then
    echo  "check1"
fi


if (( $(ls -l . | grep -c '^-') < 5 )); then
    echo "check2"
fi


if (( $(find -type f | wc -l) < 5 )); then
    echo "check3"
fi

