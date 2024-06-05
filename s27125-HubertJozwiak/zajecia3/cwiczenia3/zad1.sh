#!/bin/bash

function print_colored_text {
    if [ -z "$1" ] || [ -z "$2" ]; then
        echo "Usage: $0 <text> <color> (red, green, yellow, blue, magenta, cyan)"
        return
    fi

    case $2 in
        red)
            echo -e "\e[31m$1\e[0m"
            ;;
        green)
            echo -e "\e[32m$1\e[0m"
            ;;
        yellow)
            echo -e "\e[33m$1\e[0m"
            ;;
        blue)
            echo -e "\e[34m$1\e[0m"
            ;;
        magenta)
            echo -e "\e[35m$1\e[0m"
            ;;
        cyan)
            echo -e "\e[36m$1\e[0m"
            ;;
        *)
            echo "Usage: $0 <text> <color> (red, green, yellow, blue, magenta, cyan)"
            ;;
    esac
}

print_colored_text $1 $2