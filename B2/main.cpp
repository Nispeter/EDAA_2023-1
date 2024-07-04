#include "binaryHeap.h"

using namespace std;


void genOld(vector <int> &v, int tam){
	for (int i = tam - 200; i < tam; ++i)
	{
		v.push_back(i);	
	}
}

int main(int argc, char const *argv[])
{
	int size = 200;
	vector<int> v;
	genOld(v,size);
	cerr<<"A"<<endl;
	binaryHeap B(v,size);
	cerr<<B.heap[0]<<endl;
	vector<int> v2;
	cerr<<"B"<<endl;
	genOld(v2,size);
	binaryHeap B2(v2,size);
	B.heapUnion(v2);

	cerr<<B.top()<<endl;
	B.pop();
	cerr<<B.top()<<endl;
	B.pop();
	cerr<<B.top()<<endl;
	B.pop();


	return 0;
}