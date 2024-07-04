g++ hip3v2.cpp AVLTree.cpp RedBlackTree.cpp -o m
echo "n,ms_search_AVL,ms_search_RBT,ms_search_ST,ms^2_search_AVL,ms^2_search_RBT,ms^2_search_ST" >  hip3v2.csv
for (( i=1, i<=5000, i+=500))
do
	echo "iter $i"
	./m  $i 50 >> hip3v2.csv
done