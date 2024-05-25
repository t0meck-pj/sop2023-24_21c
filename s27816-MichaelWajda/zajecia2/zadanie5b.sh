#!/bin/bash

X="SOP! SOP w imieniu prawa! SOP w imieniu prawa!"
echo ${X:0:1}
Y=$#-1
echo ${X:Y:1}
echo -e ${X//SOP/"\e[32mSOP\e[0m"}
