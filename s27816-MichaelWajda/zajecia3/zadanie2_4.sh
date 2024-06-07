#!/bin/bash
for file in *.c; do
if [ -e "$file" ]; then
	filename="${file%.c}"
	cc "$file" -o "$filename"
	echo "Nastąpiła kompilacja i utworzenie pliku wykonywalnego $filename"
fi
done

