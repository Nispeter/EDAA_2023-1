#include "binaria.h"

using namespace std;

int galopante(const vector<int> &v, int size, int n){
	if(v[0] == n)
		return 0;
	int j = 1;
	while(j < size && n > v[j]){
			j *= 2;
	}
	j = (size < j) ? size : j;
	return binaria(v, n , j/2, j);
}

