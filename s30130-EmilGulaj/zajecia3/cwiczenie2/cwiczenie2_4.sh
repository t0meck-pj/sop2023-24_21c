#!/bin/bash

ls *.c | while IFS= read -r file; do
    file_without_extension=$(basename "$file" .c)
    cc "$file" -o "$file_without_extension"
done