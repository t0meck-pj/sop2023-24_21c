#!/bin/bash

function fib {
    local n=$1

    if (($n <= 0)); then
    	return 0
    elif (($n == 1)); then
    	return 1
    else
    	fib $((n - 1))
    	local v1=${?}

    	fib $((n - 2))
    	local v2=${?}

   		return $((v1 + v2))
    fi 
}

fib $1
exit ${?} # Mozna zwrocic maksymalnie wartosci do 255, wiec do 13 elementu ciagu (233)

