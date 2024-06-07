#!/bin/bash
TABLICA=()
for i in "$@"; do
	TABLICA+=("$i")
done
echo "Zawartość Tablicy:"

T=${#TABLICA[@]}
for ((i = 0; i < "$T" ; i++)); do
	ZAWARTOSC=$(<"${TABLICA[i]}")
	echo -n "$ZAWARTOSC "
done
echo
for ((i = T - 1; i >= 0 ; i--)); do
	ZAWARTOSC=$(<"${TABLICA[i]}")
	DLUGOSC=${#ZAWARTOSC}
	for ((j = DLUGOSC - 1; j >= 0; j--)); do
	echo -n "${ZAWARTOSC:j:1}"	
done
	echo -n " "
done

#echo "${TABLICA[@]}"
#for i in ${TABLICA[@]}; do
#	cat "$i"
#	echo -n " "
#done

#for i in "${TABLICA[@]}"; do
#	tac "$i" | rev
#done

