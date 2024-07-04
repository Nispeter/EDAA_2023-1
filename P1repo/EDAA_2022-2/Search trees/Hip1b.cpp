#include <vector>
#include <iostream>
#include <chrono>
#include "AVLTree.h"
#include "RedBlackTree.h"
#include "splayTree.h"
#include "functions.cpp"


using namespace std;

int main(int argc, char *argv[]){
	int size = atoi(argv[1]);
	int rep = atoi(argv[2]);
	double valsIBT[rep], valsIAVL[rep], valsIRBT[rep], valsIST[rep],
	valsSBT[rep], valsSAVL[rep], valsSRBT[rep], valsSST[rep];
	chrono::duration<double> diff;
	chrono::time_point<chrono::high_resolution_clock> start, end;

	//insercion y busqueda AVL
	for (int i = 0; i < rep; ++i)
	{
		AVLTree t;
		start = chrono::high_resolution_clock::now();
		for (int j = 0; j < size; ++j)t.insert(j);
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		valsIAVL[i] = diff.count();
		start = chrono::high_resolution_clock::now();
		for (int j = 0; j < size; ++j)t.search(rand()%size);
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		valsSAVL[i] = diff.count();
	}

	//insercion y busqueda RBT
	for (int i = 0; i < rep; ++i)
	{
		RedBlackTree t;
		start = chrono::high_resolution_clock::now();
		for (int j = 0; j < size; ++j)t.insert(j);
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		valsIRBT[i] = diff.count();
		start = chrono::high_resolution_clock::now();
		for (int j = 0; j < size; ++j)t.search(rand()%size);
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		valsSRBT[i] = diff.count();
	}

	//insercion y busqueda ST
	for (int i = 0; i < rep; ++i)
	{
		SplayTree t;
		start = chrono::high_resolution_clock::now();
		for (int j = 0; j < size; ++j)t.insert(j);
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		valsIST[i] = diff.count();
		start = chrono::high_resolution_clock::now();
		for (int j = 0; j < size; ++j)t.search(rand()%size);
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		valsSST[i] = diff.count();
	}




	//imprimimos resultado
	double medIAVL = 0, medIRBT = 0, medIST = 0, varIAVL = 0, varIRBT = 0, varIST = 0,
	medSAVL = 0, medSRBT = 0, medSST = 0, varSAVL = 0, varSRBT = 0, varSST = 0;

	//media
	for (int i = 0; i < rep; ++i){
		medIAVL += valsIAVL[i];
		medIRBT += valsIRBT[i];
		medIST += valsIST[i];
		medSAVL += valsSAVL[i];
		medSRBT += valsSRBT[i];
		medSST += valsSST[i];
	}
	medIAVL = medIAVL*1000/rep;
	medIRBT = medIRBT*1000/rep;
	medIST = medIST*1000/rep;
	medSAVL  = medSAVL *1000/rep;
	medSRBT = medSRBT*1000/rep;
	medSST = medSST*1000/rep;
	//varianza
	varIAVL = variance(valsIAVL, rep, medIAVL);
	varIRBT = variance(valsIRBT, rep, medIRBT);
	varIST = variance(valsIST, rep, medIST);
	varSAVL = variance(valsSAVL, rep, medSAVL);
	varSRBT = variance(valsSRBT, rep, medSRBT);
	varSST = variance(valsSST, rep, medSST);

	cout<<size<<";"<<medIAVL<<";"<<medIRBT <<";"<<medIST<<";"<<medSAVL <<";"<<medSRBT<<";"<<medSST<<";"<<
	varIAVL<<";"<<varIRBT<<";"<<varIST<<";"<<varSAVL<<";"<<varSRBT<<";"<<varSST<<endl;

	return 0;
}