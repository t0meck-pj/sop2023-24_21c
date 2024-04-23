files=($(ls))

for (( i = 0; i < $(ls -1 | wc -l); i++ )); do
    echo "Patrzcie Państwo, oto plik: " ${files[$i]}
done
