#!/bin/bash
function textColor {
    local color=
    case "$2" in
        "black")
            color="\033[0;30m"
            ;;
        "red")
            color="\033[0;31m"
            ;;
        "green")
            color="\033[0;32m"
            ;;
        "brown")
            color="\033[0;33m"
            ;;
        "blue")
            color="\033[0;34m"
            ;;
        "magenta")
            color="\033[0;35m"
            ;;
        "cyan")
            color="\033[0;36m"
            ;;
        "white")
            color="\033[0;37m"
            ;;
        *)
            color="\033[38;5;${2}m"
    esac

    echo -e "${color}${1}\033[0m"
}

textColor $"Magenta" $"magenta"
textColor $"Z 255-bitowej palety" $"22"
