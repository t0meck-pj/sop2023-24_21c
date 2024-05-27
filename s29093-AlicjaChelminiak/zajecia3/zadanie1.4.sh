#!/bin/bash

ILOSC_PLIKOW=$(ls -1 | wc -l)

if [[ "$ILOSC_PLIKOW" -gt 5 ]]; then
	echo "Jest wiecej niz 5 plikow"
fi
