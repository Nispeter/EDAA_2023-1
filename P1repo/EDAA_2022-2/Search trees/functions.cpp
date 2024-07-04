#include <vector>
#include <math.h>

using namespace std;

bool binaria(const vector<int> &v, int val, int l, int r){
	while(l<r){
		int m = (l+r)/2;
		if(v[m] == val) return true;
		if(v[m] > val) r = m-1;
		else l = m+1;
	}
	if(v[l] == val) return true;
	return false;
}

bool lineal(const vector<int> &v, int val){
	for (int i = 0; i < v.size(); ++i){
		if(v[i] == val) return true;
	}
	return false;
}

bool galopante(const vector<int> &v,int val){
	if(v[0] == val)return true;
	if(v.size() == 1) return false;
	int i = 1;
	while(2*i < v.size() and v[2*i] < val) i *= 2;
	if(2*i >= v.size()) return binaria(v, val , i, v.size()-1);
	return binaria(v,val, i, 2*i);
} 

double variance(double *arr, int tam, double med){
	double var = 0;
	for (int i = 0; i < tam; ++i)
	{
		var += pow(arr[i]*1000 - med, 2);
	}
	return var/tam;
}