# for i in {1..$#}; do
#     echo $i;
# done
# 
# echo ''

for i in $(seq 1 1 $#); do
    echo $i;
done

echo ''

for (( i = 1; i <= $#; i++ )); do
    echo $i;
done