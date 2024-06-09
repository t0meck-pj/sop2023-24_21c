#!/bin/bash

for argu in "$@"; do
    printf "\"%s\"\n" "$argu"
done