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
		echo ${content[${#content} - i]}
	done
done

