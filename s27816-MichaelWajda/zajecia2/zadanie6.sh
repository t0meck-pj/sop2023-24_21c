#!/bin/bash
A=Stefan && echo $A ma kota, a kot ma ${A} | sed s/a$/ę/g | sed 's/\([^ę]\)$/\1a/g'
