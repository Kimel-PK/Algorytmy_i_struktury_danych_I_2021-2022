for VALUE in {0..200000..5000}
do
printf "%s" "$VALUE" >> wstawiane.txt
./Generator.x $VALUE 1000000 | ./BubbleSort.x >> wstawiane.txt
done