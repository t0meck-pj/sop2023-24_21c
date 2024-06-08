TABLICA=(element1 "element 2" element\ 3)

echo ${TABLICA[1]} # pierwszy element

echo ${TABLICA[*]} # wszystkie elementy [jako jeden string]

echo ${TABLICA[@]} # wszystkie elementy [kady element traktowany oddzielnie]

echo "${!TABLICA[@]}  ${!TABLICA[*]}"

echo ${#TABLICA[@]}

echo ${#TABLICA[0]}

