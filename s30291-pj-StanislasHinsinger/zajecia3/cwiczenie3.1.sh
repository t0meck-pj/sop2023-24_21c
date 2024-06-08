#!/bin/bash

declare -A colors

colors['czarny']=30
colors['czerwony']=31
colors['zielony']=32
colors['brazowy']=33
colors['niebieski']=34 
colors['fioletowy']=35 
colors['turkusowy']=36 
colors['bialy']=37 

function echo_colorized_text {
	text=$1
	color=$2

	echo -e "\e[${color}m${text}\e[0m"
}

if [[ ${#2} == 0 ]]; then
	echo "Wprowadz kolor: ${!colors[@]}"
	exit 1
fi

if [[ ${#colors[$2]} == 0 ]]; then
	echo "Wprowadzono bledny kolor! (Dostepne: ${!colors[@]})"
	exit 1
fi


echo_colorized_text "${1}" "${colors[$2]}"

