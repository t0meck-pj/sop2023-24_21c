if [[ $1 == "" ]]; then
	echo "Nie wprowadzono nazwy pliku z ktorego nalezy pobrac tekst!"
	exit
fi

imie="Stanislas"
tekst=$( cat ${1} )

echo -e "${tekst//${imie}/"\e[31m${imie}\e[0m"}"

# Tekst do pracy domowej w pliku: tekst_do_pracy_domowej.txt