#!/bin/bash

if  test -f ./config.cfg; then
	sh config.cfg
elif (( $# > 0 )); then
	sh "$1"
else
	echo "Error"
fi
