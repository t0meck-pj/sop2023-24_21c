#!/bin/bash

IMIE=$1

NOWE_IMIE=$(echo "$IMIE" | sed 's/a$/e/g')

echo "$IMIE ma kota, a kot ma $NOWE_IMIE"
