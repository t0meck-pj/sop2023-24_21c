#!/bin/bash
function autocomplete {
    if [[ "${#COMP_WORDS[@]}" != 2 ]]; then
        return
    fi

    local commands="add commit switch checkout"

    local completions=($(compgen -W "${commands}" -- "${COMP_WORDS[1]}"))

    if [[ "${#completions[@]}" == 1 ]]; then
        case "$completions" in
            add) COMPREPLY="add ." ;;
            commit) COMPREPLY="commit -m" ;;
            switch) COMPREPLY="switch" ;;
            checkout) COMPREPLY="checkout" ;;
            *) COMPREPLY="" ;;
        esac
    else
        COMPREPLY=("${completions[@]}")
    fi
}

complete -F autocomplete git
