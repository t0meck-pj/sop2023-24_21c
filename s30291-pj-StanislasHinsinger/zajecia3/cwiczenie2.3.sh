#!/bin/bash

files=$(ls -l | grep "^-" | awk '{print $9}')
directories=$(ls -l | grep "^d" | awk '{print $9}')

for file in $files; do
	echo "Patrzcie Państwo, oto plik: $file"
done

for directory in $directories; do
	echo $directory
done

