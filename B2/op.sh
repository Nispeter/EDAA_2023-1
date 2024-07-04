
#!/bin/bash
g++ m.cpp -o m
echo "Binomial push" > outE.txt
echo "100000;200000;300000;400000;500000;600000;700000;800000;900000;1000000;" >> outE.txt
echo "Binary push" > outB.txt
echo "100000;200000;300000;400000;500000;600000;700000;800000;900000;1000000;" >> outB.txt
./m -ps
echo -ne '\n\n\n\n\n'>> outE.txt
echo -ne '\n\n\n\n\n'>> outB.txt

echo "Binomial pop" >> outE.txt
echo "100000;200000;300000;400000;500000;600000;700000;800000;900000;1000000;" >> outE.txt
echo "Binary pop" >> outB.txt
echo "100000;200000;300000;400000;500000;600000;700000;800000;900000;1000000;" >> outB.txt
./m -pp
echo -ne '\n\n\n\n\n'>> outE.txt
echo -ne '\n\n\n\n\n'>> outB.txt

echo "Binomial union" >> outE.txt
echo "100000;200000;300000;400000;500000;600000;700000;800000;900000;1000000;" >> outE.txt
echo "Binary union" >> outB.txt
echo "100000;200000;300000;400000;500000;600000;700000;800000;900000;1000000;" >> outB.txt
./m -un
echo -ne '\n\n\n\n\n'>> outE.txt
echo -ne '\n\n\n\n\n'>> outB.txt

