#!/bin/bash

print_color_text() {
    local text="$1"
    local color="$2"

    case "$color" in
        "Red")
            echo -e "\033[0;31m$text\033[0m"
            ;;
        "Magenta")
            echo -e "\033[0;95m$text\033[0m"
            ;;
        "Yellow")
            echo -e "\033[0;93m$text\033[0m"
            ;;
        "Cyan")
            echo -e "\033[0;36m$text\033[0m"
            ;;
        "Gray")
            echo -e "\033[0;90m$text\033[0m"
            ;;
        *)
            echo "Nieobsługiwany kolor: $color"
            ;;
    esac
}
echo "podaj tekst do wyswietlenia: "
read input_text

echo "podaj kolor tekstu: "
read input_color

print_color_text "$input_text" "$input_color"