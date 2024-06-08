#!/bin/bash

kolorowy_tekst() {
	local tekst="$1"
	local kolor="$2"

case "$kolor" in
        "czerwony")	printf "\e[31m$tekst\e[0m\n" ;;
        "pomaranczowy")  printf "\e[38;5;208m$tekst\e[0m\n" ;;
        "zielony") printf "\e[32m$tekst\e[0m\n" ;;
        "fioletowy") printf "\e[35m$tekst\e[0m\n" ;;
    esac
}

kolorowy_tekst "czerwony" "czerwony"
kolorowy_tekst "pomaranczowy" "pomaranczowy"
kolorowy_tekst "zielony" "zielony"
kolorowy_tekst "fioletowy" "fioletowy"
