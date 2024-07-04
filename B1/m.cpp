#include <iostream>
#include <vector>
#include "secuencial.h"
#include "galopante.h"
#include <numeric>
#include <chrono>
#include <iomanip>

using namespace std;


void gen(vector <int> &v, int tam){
	for (int i = 0; i < tam; ++i)
	{
		v[i] = i+1;
	}
}

volatile int sink;
int main(int argc, char const *argv[])
{
	string dist_mode = "n";
	string search_mode = "s";

	if(argc > 0){
		string argv1 = argv[1];
		if(argv1 == "-p")
			dist_mode = "p";

		if(argc > 1){
			string argv2 = argv[2];
			if(argv2 == "-b")
				search_mode = "b";
			else if (argv2 == "-g")
				search_mode = "g";
			}
	}

	int reps = 5000;

	if(dist_mode == "n"){

		vector<int> v(1000000000);
		gen(v, 1000000000);

		for (int i = 0; i < reps; ++i)
		{
		for (auto size = 100; size <= 1'000'000'000; size *= 10) {
			int num = size;
	        int e;

	        auto start = chrono::high_resolution_clock::now();

	        if(search_mode == "s")
						e = secuencial(v,size, num);
					else if(search_mode == "b")
						e = binaria(v,num,0,size);
					else if(search_mode == "g")
						e = galopante(v,size, num);

	        auto end = chrono::high_resolution_clock::now();
	        chrono::duration<double> diff = end - start;
	        cout << diff.count() <<";";  
		}
		    cout<<endl;
		}
	}
	else if(dist_mode == "p"){

		for (int i = 0; i < reps; ++i)
		{
			int size = 500000000;
			vector<int> v(size);
			gen(v, size);

			for (int i = 1; i <= 6; i++) {
					int num = size/6*i;
					//cerr<<num<<endl;
	        int e;

	        auto start = chrono::high_resolution_clock::now();

					if(search_mode == "s")
						e = secuencial(v,size, num);
					else if(search_mode == "b")
						e = binaria(v,num,0,size);
					else if(search_mode == "g")
						e = galopante(v,size, num);

	        auto end = chrono::high_resolution_clock::now();
	        chrono::duration<double> diff = end - start;
	        cout << diff.count() <<";";  
	    }
	    cout<<endl;
	  }
	}
	return 0;
}

/*
Incremento de variable 
n  = 1 seg de ejecucion 
n > 10e6
*/