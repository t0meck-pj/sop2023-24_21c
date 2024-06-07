#!/bin/bash

#fileCount=$(ls -1 | grep -c '^') #| wc -l)
fileCount=$(find . -maxdepth 1 -type f | wc -l)
if (( "$fileCount" > 5 )); then
echo "W bieżącym katalogu jest  ponad 5 plików."
else
echo ":("
fi
