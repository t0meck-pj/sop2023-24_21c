#!/bin/bash

for file in ${@}; do
	readarray -t content < ${file}
	for i in $(seq 0 1 ${#content}); do
		echo ${content[i]}
	done
done

for file in ${@}; do
	readarray -t content < ${file}
	for i in $(seq 1 1 ${#content}); do
		tmp=${content[${#content} - i]}
		line=""
		for j in $(seq ${#tmp} -1 0); do
			line+="${tmp:${j}:1}"
		done
		echo "${line}"
	done
done

