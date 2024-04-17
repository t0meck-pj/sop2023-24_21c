#!/bin/bash

imie="$1"
imie_short=${imie:0:${#imie}-1}

if [[ ${imie:${#imie}-1:1} == "a" ]]; then
	echo "$imie ma kota, a kot ma ${imie_short}ę"
else 
	echo "$imie ma kota, a kot ma ${imie}a"
fi
