#!/bin/bash
if [[ $1 =~ ^[A-ZĄĆĘŁÓŚŹŻ][a-ząćęłóśźż]+$ ]]; then
    echo "imię"
elif [[ $1 =~ ^[0-9]{2}-[0-9]{3}$ ]]; then
    echo "kod pocztowy"
elif [[ $1 =~ ^[A-Za-z0-9!#$%\&\'*+\-\/=?^_\`{|}~.]*@[A-za-z0-9.-]+\.[A-za-z0-9.-]+$ ]]; then
    echo "email"
else
    echo "nie rozpoznano"
fi
