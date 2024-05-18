#!/bin/bash

files=$(ls -l | grep ".c$" | awk '{print $9}')

for file in $files; do
	cc $file -o ${file:0:${#file}-2}
done

