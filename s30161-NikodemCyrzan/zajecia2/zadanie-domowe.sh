tekst=$(cat $1)
echo -e "${tekst//Nikodem/"\e[31mNikodem\e[0m"}"
