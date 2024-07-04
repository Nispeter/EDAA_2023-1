
#!/bin/bash
echo "size for secuential search" > reps.txt
echo "150000000;300000000;450000000;600000000;750000000;900000000;" >> reps.txt
for(( i = 0; i<=30; i++))
do
   ./m -n -s >> reps.txt
done
echo "position for secuential search" >> reps.txt
echo "1/6;2/6;3/6;4/6;5/6;6/6;" >> reps.txt
for(( i = 0; i<=30; i++))
do
   ./m -p -s >> reps.txt
done
j=100
echo "size for binary search" >> reps.txt
echo "150000000;300000000;450000000;600000000;750000000;900000000;" >> reps.txt
for(( i = 0; i<=100; i++))
do
   ./m -n -b >> reps.txt
done
echo "position for binary search" >> reps.txt
echo "1/6;2/6;3/6;4/6;5/6;6/6;" >> reps.txt
for(( i = 0; i<=100; i++))
do
   ./m -p -b >> reps.txt
done
echo "size for exponential search" >> reps.txt
echo "150000000;300000000;450000000;600000000;750000000;900000000;" >> reps.txt
for(( i = 0; i<=100; i++))
do
   ./m -n -g >> reps.txt
done
echo "position for exponential search" >> reps.txt
echo "1/6;2/6;3/6;4/6;5/6;6/6" >> reps.txt
for(( i = 0; i<=100; i++))
do
   ./m -p -g >> reps.txt
done



