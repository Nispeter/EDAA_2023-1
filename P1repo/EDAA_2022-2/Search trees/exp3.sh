g++ Hip1v2.cpp AVLTree.cpp RedBlackTree.cpp -o m
echo "n,ms_Isercion_AVL,ms_Isercion_RBT,ms_Isercion_ST,ms_search_AVL,ms_search_RBT,ms_search_ST,ms^2_Isercion_AVL,ms^2_Isercion_RBT,ms^2_Isercion_ST,ms^2_search_AVL,ms^2_search_RBT,ms^2_search_ST" >  Hip1v2.csv
echo -ne '\n'>> Hip1v2.csv
for i in {10000..100000..10000}
do
	./m $i 50 >> Hip1v2.csv
done