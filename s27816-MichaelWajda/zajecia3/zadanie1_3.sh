#!/bin/bash

NAZWA=$0
extension=".sh"

if [[ $NAZWA == *.sh ]]; then
echo "Rozszerzenie pliku to .sh"
else	
	
NAZWA2=$(echo "$NAZWA" | sed 's/\..*$//')"$extension"
#NAZWA2="${NAZWA%.*}"
mv "$NAZWA" "$NAZWA2"
fi
