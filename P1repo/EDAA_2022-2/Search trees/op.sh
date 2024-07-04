#!/bin/bash
#g++ Hip1.cpp AVLTree.cpp RedBlackTree.cpp -o m
#echo "n,ms Isercion AVL,ms Isercion RBT,ms Isercion ST,ms search AVL,ms search RBT,ms search ST, ms^2 Isercion AVL,ms^2 Isercion RBT,ms^2 Isercion ST, ms^2 search AVL,ms^2 search RBT,ms^2 search ST" >  hip1-2.csv
#echo -ne '\n'>> hip1-2.csv
#for i in {10000..100000..10000}
#do
#	./m $i 100 >> hip1-2.csv
#done
#g++ hip3v2.cpp AVLTree.cpp RedBlackTree.cpp -o m
#echo "n,ms_search_AVL,ms_search_RBT,ms_search_ST,ms^2_search_AVL,ms^2_search_RBT,ms^2_search_ST" >  hip3v2.csv
#for (( i=1, i<=5000, i+=500))
#do
#	echo "iter $i"
#	./m  $i 50 >> hip3v2.csv
#done

g++ Hip1v2.cpp AVLTree.cpp RedBlackTree.cpp -o m
echo "n,ms_Isercion_AVL,ms_Isercion_RBT,ms_Isercion_ST,ms_search_AVL,ms_search_RBT,ms_search_ST,ms^2_Isercion_AVL,ms^2_Isercion_RBT,ms^2_Isercion_ST,ms^2_search_AVL,ms^2_search_RBT,ms^2_search_ST" >  Hip1v2.csv
echo -ne '\n'>> Hip1v2.csv
for i in {10000..100000..10000}
do
	./m $i 50 >> Hip1v2.csv
done
