#!/bin/bash

x="test"
echo $x
bash
echo $x

exit

# Pierwsze wykonanie echo X, wyswietlilo prawidlowo tekst, natomiast
# drugie wykonanie wyswietlilo pusty tekst, co oznacza, ze do tej
# zmiennej nie zostala przypisana jakakolwiek wartosc. 

# W tej konkretnej sytuacji jest to spowodowane wywolaniem 'bash', ktory
# uruchamia nowa powloke i wszystkie kolejne polecenia po tej komendzie,
# beda wykonywane wlasnie na tej nowej powloce, w ktorej zmienna X nie
# zostala przypisana ani wyeksportowana.


