#!/bin/bash
X=$*
echo -e "\e[31m$1\e[0m"
echo -e "$(sed -E "s#$X#\\\e[31m$X\\\e[0m#" $X)"
