#!/bin/bash

for item in *; do
if [ -f "$item" ]; then
echo "Patrzcie Państwo, oto plik: $item"
elif [ -d "$item" ]; then
echo $item
fi
done
