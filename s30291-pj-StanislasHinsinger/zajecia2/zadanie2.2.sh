#!/bin/bash

#
# x=Tekst dluzszy
#
# echo $x
#
# Ten zestaw polecen zwroci blad, poniewaz tekst dzielony spacja zostanie zle
# zinterpretowany przez interpreter skryptu. Aby to zadzialalo prawidlowo
# nalezy umieszczac tekst w "" albo ''.

x="Tekst dluzszy"
echo $x
