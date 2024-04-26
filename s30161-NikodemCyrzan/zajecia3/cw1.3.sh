#!/bin/bash
echo ${0:(-3)}

# metoda 1
if [[ ${0##*.} != "sh" ]]; then
    mv "$0" "$0.sh"
fi

# metoda 2
if [[ $0 =~ .*[^.sh]$ ]]; then
    mv "$0" "$0.sh"
fi

# metoda 3
if [[ ${0:(-3)} ]]; then
    mv "$0" "$0.sh"
fi
