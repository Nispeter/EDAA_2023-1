#!/bin/bash
echo "size for secuential search" > reps.txt
echo "100;1000;10000;100000;1000000;10000000;10000000;100000000;1000000000;" >> reps.txt
./m -n -s >> reps.txt
echo "position for secuential search" >> reps.txt
echo "1/6;2/6;3/6;4/6;5/6;6/6;" >> reps.txt
./m -p -s >> reps.txt
echo "size for binary search" >> reps.txt
echo "100;1000;10000;100000;1000000;10000000;10000000;100000000;1000000000;" >> reps.txt
./m -n -b >> reps.txt
echo "position for binary search" >> reps.txt
echo "1/6;2/6;3/6;4/6;5/6;6/6;" >> reps.txt
./m -p -b >> reps.txt
echo "size for exponential search" >> reps.txt
echo "100;1000;10000;100000;1000000;10000000;10000000;100000000;1000000000;" >> reps.txt
./m -n -g >> reps.txt
echo "position for exponential search" >> reps.txt
echo "1/6;2/6;3/6;4/6;5/6;6/6" >> reps.txt
./m -p -g >> reps.txt


