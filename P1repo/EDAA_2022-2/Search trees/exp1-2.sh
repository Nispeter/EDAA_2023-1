!/bin/bash
g++ Hip1.cpp AVLTree.cpp RedBlackTree.cpp -o m
echo "n,ms Isercion AVL,ms Isercion RBT,ms Isercion ST,ms search AVL,ms search RBT,ms search ST, ms^2 Isercion AVL,ms^2 Isercion RBT,ms^2 Isercion ST, ms^2 search AVL,ms^2 search RBT,ms^2 search ST" >  hip1-2.csv
echo -ne '\n'>> hip1-2.csv
for i in {10000..100000..10000}
do
	./m $i 100 >> hip1-2.csv
done
