#!/bin/bash

echo $(ls -l) # Wypisze wartosci z "wyczyszczonymi" znakami nowych lini i tabulacji.

echo "$(ls -l)" # Wypisze wartosci z pozostawionym formatowanie (nie zadziala dla zmiennych)