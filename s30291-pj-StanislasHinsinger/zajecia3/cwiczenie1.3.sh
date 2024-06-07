#!/bin/bash

file=$0
length=${#0}
ending="${file:${length}-2:2}"

if [[ $ending != "sh" ]]; then
	for i in $(seq $(($length - 1)) -1 0); do
		if [[ ${file:${i}:1} == "." ]]; then
			mv $file "${file:0:$i}.sh"
			echo "Zmieniono zakonczenie pliku!"
			break
		fi
	done
else
	echo "Plik konczy sie .sh"
fi

