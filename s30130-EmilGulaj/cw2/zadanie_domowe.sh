#!/bin/bash

file=`cat $1`

echo -e "${file//Emil/"\e[31mEmil\e[0m"}"
