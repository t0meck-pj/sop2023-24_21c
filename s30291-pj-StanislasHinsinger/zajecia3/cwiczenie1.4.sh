#!/bin/bash

file_count=$(ls -l | grep "^-" | wc -l)

if [[ $file_count > 5 ]]; then
	echo "W katalogu jest wiecej niz 5 plikow!"
else
	echo "W katalogu jest mniej niz 5 plikow!"
fi

