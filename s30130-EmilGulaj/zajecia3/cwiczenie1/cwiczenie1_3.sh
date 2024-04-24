#!bin/bash

# Rozwiązanie 1
if [[ $0 =~ .sh$ ]]; then
	echo "check"
else
	mv "$0" "$0.sh"
fi

# Rozwiązanie 2
if [[ "${0: -3}" == ".sh" ]]; then 
	echo "check2"
else
	mv "$0" "$0.sh"
fi

# Rozwiązanie 3
if [[ "$0" == *.sh ]]; then
	echo "check3"
else
	mv "$0" "$0.sh"
fi
