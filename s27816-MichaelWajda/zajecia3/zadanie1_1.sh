#!/bin/bash

if (( "$#" > 0 )); then
	echo "Pierwszy parametr: $1"
else
	echo "Nie podano parametrów."
fi
