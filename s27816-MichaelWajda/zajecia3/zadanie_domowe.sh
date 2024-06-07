#!/bin/bash
n="$1"
imie="^[A-ZĄĘÓŃŁŚĆŻŹ][a-ząęóńłśćżź]*"
kod="^\d||\d$"
email="^[a-zA-Z0-9._%+-]+\@[a-zA-Z]+\.[a-zA-Z]{2,}"

function coto {
if [[ $n =~ $imie ]]; then
	echo "imię"
elif [[ $n =~ $kod ]]; then
	echo "kod pocztowy"
elif [[ $n =~ $email ]]; then
	echo "email"
else
	echo "idk ¯\_(ツ)_/¯"
fi
}
coto
