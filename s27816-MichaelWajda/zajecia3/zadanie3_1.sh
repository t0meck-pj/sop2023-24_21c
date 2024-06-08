#!/bin/bash
function text_color {
text="$1"
color="$2"

case $color in
	black) color_code='\e[0;30m' ;;
	red) color_code='\e[0;31m' ;;
	green) color_code='\e[0;32m' ;;
	yellow) color_code='\e[0;33m' ;;
	blue) color_code='\e[0;34m' ;;
	magenta) color_code='\e[0;35m' ;;
	cyan) color_code='\e[0;36m' ;;
	white) color_code='\e[0;37m' ;;
esac

echo -e "${color_code}${text}\e[0m"
return 0
}
