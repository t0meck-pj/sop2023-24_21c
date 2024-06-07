#!/bin/bash
function fib {
	local n=$1
if (( n == 0 )); then
	return 0
elif (( n == 1 )); then
	return 1
else
	fib $(( n - 1 ))
	local fib1=$?
	fib $(( n - 2 ))
	local fib2=$?
	return $(( fib1 + fib2 ))
fi
}
fib $1
echo $?
