#!/bin/bash

function color {
    case "$2" in
        "red")
            color_code="\033[0;31m" ;;
        "green")
            color_code="\033[0;32m" ;;
        "yellow")
            color_code="\033[0;33m" ;;
        "blue")
            color_code="\033[0;34m" ;;
        "magenta")
            color_code="\033[0;35m" ;;
        "cyan")
            color_code="\033[0;36m" ;;
        *)
            echo "Bash nie obsługuje takiego koloru"
            return ;;
    esac

    local text="$1"
    echo -e "${color_code}${text}\033[0m"

}

# Text kolor
color $"$1" $"$2"
