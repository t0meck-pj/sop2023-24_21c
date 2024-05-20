#!/bin/bash

function echo_colorized_text {
	text=$1
	color=$2

	echo -e "\e[${color}m${text}\e[0m"
}

echo_colorized_text "${1}" "${2}"

