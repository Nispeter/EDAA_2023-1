#include <iostream>
#include <vector>

using namespace std;

int binaria(const vector<int> &v, int n, int l, int r){ 
	if (l > r)
		return -1;
	else {
		int m = l + (r-l)/2;
		if(v[m] == n){
			return m;
		}
		else if(n > v[m])
			return binaria(v,n,m+1,r);
		else if(n < v[m])
			return binaria(v,n,l,m-1);
	}
	return -1;
}
