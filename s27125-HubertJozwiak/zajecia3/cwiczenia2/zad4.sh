#!/bin/bash

for file in $(ls | grep -E '\.c$'); do
    cc $file -o $(echo "${file%.c}")
done