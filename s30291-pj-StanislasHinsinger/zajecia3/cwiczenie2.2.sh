#!/bin/bash

for i in $(seq 1 1 $#); do
	eval arg="\$$i"
	echo $arg
done

