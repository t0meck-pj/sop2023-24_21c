#!/bin/bash

arg=$1

echo ${arg:0:1}
echo ${arg:(-1)}
echo -e ${arg//"SOP"/"\e[32mSOP\e[0m"}
