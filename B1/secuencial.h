#include <iostream>
#include <vector>

using namespace std;

int secuencial(const vector<int> &v,int size,  int n){
	for (int i = 0; i < size; ++i)
	{
		if(v[i] == n){
			return i; 
		}
	}
	return -1;
}