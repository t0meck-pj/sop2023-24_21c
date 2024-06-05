#!/bin/bash

function coto {
    if [[ $1 =~ ^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$ ]]; then
        echo "email"
    elif [[ $1 =~ ^[A-Z][a-z]+$ ]]; then
        echo "Imię"
    elif [[ $1 =~ ^[0-9]{2}\-[0-9]{3}$ ]]; then
        echo "kod pocztowy"
    else
        echo "Nie umiem tego rozpoznać"
    fi
}

coto $1
