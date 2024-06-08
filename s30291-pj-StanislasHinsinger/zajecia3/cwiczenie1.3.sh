#!/bin/bash

file=${0##*/}

if [[ ${file##*.} != "sh" ]]; then
	mv $file "${file%.*}.sh" 
else
	echo "Plik konczy sie .sh"
fi

