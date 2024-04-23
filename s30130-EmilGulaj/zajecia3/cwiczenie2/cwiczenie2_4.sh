files=($(ls))

for (( i = 0; i < $(ls -1 | wc -l); i++ )); do
    if [[ ${files[$i]} == *.c ]]; then
        file_without_extension="${files[$i]##*/}"
        cc ${files[$i]} -o $file_without_extension
    fi
done
