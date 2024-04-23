#!bin/bash

if [[ $0 =~ .sh$ ]]; then
	echo "check"
else
	mv "$0" "$0.sh"
fi


if [[ "${0: -3}" == ".sh" ]]; then 
	echo "check2"
else
	mv "$0" "$0.sh"
fi


if [[ "$0" == *.sh ]]; then
	echo "check3"
else
	mv "$0" "$0.sh"
fi
