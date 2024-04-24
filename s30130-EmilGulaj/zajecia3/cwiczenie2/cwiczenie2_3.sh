#!/bin/bash

ls -1 | while IFS= read -r file; do
    echo "Patrzcie Państwo, oto plik: $file"
done
