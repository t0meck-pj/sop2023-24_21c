#!/bin/bash

TEKST=$1
echo "${TEKST:0:l}"
echo "${TEKST: -1}"
NOWY_TEKST=$(echo "$TEKST" | sed 's/SOP/\\e[32mSOP\\e[0m/g')
echo -e "$NOWY_TEKST"
