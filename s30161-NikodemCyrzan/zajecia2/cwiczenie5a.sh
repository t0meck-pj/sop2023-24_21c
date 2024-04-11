if [[ ${1: -1} == "a" ]]; then
    echo "$1 ma kota, kot ma ${1:0:-1}ę"
else
    echo "$1 ma kota, kot ma ${1}a"
fi
