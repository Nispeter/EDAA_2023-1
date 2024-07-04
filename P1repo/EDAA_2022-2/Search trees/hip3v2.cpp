#include <vector>
#include <iostream>
#include <chrono>
#include "AVLTree.h"
#include "RedBlackTree.h"
#include "splayTree.h"
#include "functions.cpp"
#include <time.h>
#include <cstdlib>
#include <set>

using namespace std;

int main(int argc, char *argv[]){
	
	int searchSize = atoi(argv[1]);
	int rep = atoi(argv[2]);
	int size = 20'000;
	double valsSBT[rep], valsSAVL[rep], valsSRBT[rep], valsSST[rep];
	chrono::duration<double> diff;
	chrono::time_point<chrono::high_resolution_clock> start, end;
	srand(time(0));
	for (int i = 0; i < rep; ++i)
	{
		AVLTree avl;
		RedBlackTree rbt;
		SplayTree st;
		set<int> values, searchVals;
		vector<int> searchElements;
		searchElements.reserve(size);
		while(values.size() != size)values.insert(rand());

		set<int>::iterator itr;
		if(searchSize == size)searchVals = values;
		else{
			while(searchVals.size() != searchSize){
				itr = begin(values);
				advance(itr,rand() % values.size());
				searchVals.insert(*itr);
			}
		}
		for (int j = 0; j < size; ++j)
		{
			itr = begin(searchVals);
			advance(itr,rand() % searchVals.size());
			searchElements.push_back(*itr);
		}
		for(itr = values.begin(); itr != values.end(); itr++){
			avl.insert(*itr);
			rbt.insert(*itr);
			st.insert(*itr);
		}
		//AVL
		start = chrono::high_resolution_clock::now();
		for (int j = 0; j < size; ++j)avl.search(searchElements[j]);
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		valsSAVL[i] = diff.count();
		//RBT
		start = chrono::high_resolution_clock::now();
		for (int j = 0; j < size; ++j)rbt.search(searchElements[j]);
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		valsSRBT[i] = diff.count();
		//ST
		start = chrono::high_resolution_clock::now();
		for (int j = 0; j < size; ++j)st .search(searchElements[j]);
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		valsSST[i] = diff.count();
	}
	//imprimimos resultado
	double medSAVL = 0, medSRBT = 0, medSST = 0, varSAVL = 0, varSRBT = 0, varSST = 0;

	//media
	for (int i = 0; i < rep; ++i){
		medSAVL += valsSAVL[i];
		medSRBT += valsSRBT[i];
		medSST += valsSST[i];
	}
	medSAVL  = medSAVL *1000/rep;
	medSRBT = medSRBT*1000/rep;
	medSST = medSST*1000/rep;
	//varianza
	varSAVL = variance(valsSAVL, rep, medSAVL);
	varSRBT = variance(valsSRBT, rep, medSRBT);
	varSST = variance(valsSST, rep, medSST);

	cout<<searchSize<<","<<medSAVL <<","<<medSRBT<<","<<medSST<<","<<varSAVL<<","<<varSRBT<<","<<varSST<<endl;

	return 0;
}