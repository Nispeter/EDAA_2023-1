#include "binomialHeap.h"
#include "binaryHeap.h"
#include <cstdlib>
#include <time.h> 

using namespace std;

void genOld(vector <int> &v, int tam){
	for (int i = 0; i < tam; ++i)
	{
		v.push_back(i);
	}
}

void genAdd(vector <int> &v, int tam, int add){
	for (int i = 0; i < tam; ++i)
	{
		v.push_back(i + add);
	}
}

list<Node*>gen( list<Node*> l1, int tam){
	for (int i = 0; i < tam; ++i)
	{
		
		int val = rand()%tam;
		l1 = insert(l1,i);
	}
	return l1;
}


int main(int argc, char const *argv[])
{

	string op_mode = "ps";

	if(argc > 1){
		string argv1 = argv[1];
		cerr<<"arg"<<argv1<<endl;
		if(argv1 == "-pp")
			op_mode  = "pp";
		if(argv1 == "-un")
			op_mode  = "un";
	}

	int reps = 10000;
	int max = 10'0000;
	int base = 10000;
	int incr = 10000;



			for (auto size = base; size <= max; size += incr) {

				srand (time(NULL));
				ofstream myfile;

				vector<int> v;
				list<Node*> heap;
				heap = gen( heap, size);
				genOld(v,size);
				binaryHeap B(v);
		       	
		        if(op_mode == "ps"){
		        	
		        	double cont = 0;
		        	myfile.open ("outE.txt",ios::app);
		        	for (int i = 0; i < reps; ++i)
		        	{
		        		int val;
		        		val = size+i;

		        		auto start = chrono::high_resolution_clock::now();
			        	//####################INICIO DEL CLOCK####################
			        	heap = insert(heap,val);
			        	//#####################FIN DEL CLOCK#####################
			        	auto end = chrono::high_resolution_clock::now();
			        	chrono::duration<double> diff = end - start;
		        		cont += diff.count();
 						//myfile << diff.count() <<";"; 
		        	}
					cont /= reps;
 					myfile << cont <<";" ; 
  					myfile.close();


		        	cont = 0;
		        	myfile.open ("outB.txt",ios::app);
		        	for (int i = 0; i < reps; ++i)
		        	{
		        		int val;
		        		val = size+i;

		        		auto start = chrono::high_resolution_clock::now();
			        	//####################INICIO DEL CLOCK####################
			        	B.push(val);
			        	//#####################FIN DEL CLOCK#####################
			        	auto end = chrono::high_resolution_clock::now();
			        	chrono::duration<double> diff = end - start;
		        		cont += diff.count();
 						//myfile << diff.count() <<";"; 
		        	}
					cont /= reps;
 					myfile << cont <<";"; 
  					myfile.close();
		        }
		        else if(op_mode == "pp"){
		        	double cont = 0;
		        	myfile.open ("outE.txt",ios::app);
		        	for (int i = 0; i < reps; ++i)
		        	{

		        		auto start = chrono::high_resolution_clock::now();
			        	//####################INICIO DEL CLOCK####################
			        	heap = extractMin(heap);
			        	//#####################FIN DEL CLOCK#####################
			        	auto end = chrono::high_resolution_clock::now();
			        	chrono::duration<double> diff = end - start;
		        		cont += diff.count();
 						//myfile << diff.count() <<";"; 
		        	}
					cont /= reps;
 					myfile << cont <<";" ; 
  					myfile.close();


		        	cont = 0;
		        	myfile.open ("outB.txt",ios::app);
		        	for (int i = 0; i < reps; ++i)
		        	{

		        		auto start = chrono::high_resolution_clock::now();
			        	//####################INICIO DEL CLOCK####################
			        	B.pop();
			        	//#####################FIN DEL CLOCK#####################
			        	auto end = chrono::high_resolution_clock::now();
			        	chrono::duration<double> diff = end - start;
		        		cont += diff.count();
 						//myfile << diff.count() <<";"; 
		        	}
					cont /= reps;
 					myfile << cont <<";" ; 
  					myfile.close();
		        	
		        }
		        else if(op_mode == "un"){
		        	double cont = 0;
		        	reps = 200;
		        	myfile.open ("outE.txt",ios::app);
		        	for (int i = 0; i < reps; ++i)
		        	{
		        		
						list<Node*> vu;
						vu = gen(vu, size);


		        		auto start = chrono::high_resolution_clock::now();
			        	//####################INICIO DEL CLOCK####################
			        	heap = unionBionomialHeap(heap,vu);
			        	//#####################FIN DEL CLOCK#####################
			        	auto end = chrono::high_resolution_clock::now();
			        	chrono::duration<double> diff = end - start;
		        		cont += diff.count();
 						//myfile << diff.count() <<";"; 
		        	}
					cont /= reps;
 					myfile << cont <<";"; 
  					myfile.close();


		        	cont = 0;
		        	myfile.open ("outB.txt",ios::app);
		        	for (int i = 0; i < reps; ++i)
		        	{
		        		vector<int> v2;
						genAdd(v2,size,size);
						binaryHeap B2(v2);

		        		auto start = chrono::high_resolution_clock::now();
			        	//####################INICIO DEL CLOCK####################
			        	B.heapUnion(v2);
			        	//#####################FIN DEL CLOCK#####################
			        	auto end = chrono::high_resolution_clock::now();
			        	chrono::duration<double> diff = end - start;
		        		cont += diff.count();
 						//myfile << diff.count() <<";"; 
		        	}
					cont /= reps;
 					myfile << cont <<";"; 
  					myfile.close();
		        	

		      
		        	
		        }
		        
			}
		    ofstream myfile;
		    myfile.open ("outE.txt",ios::app);
 			myfile << "\n"; 
  			myfile.close();
  			myfile.open ("outB.txt",ios::app);
 			myfile << "\n"; 
  			myfile.close();
		
	

	return 0;
}


/*
if(heap_mode == "e"){

		for (int i = 0; i < reps; ++i)
		{
			for (auto size = base; size <= max; size += incr) {

				

				list<Node*> heap;
				heap = genBinomial(heap, size);
				int val;
				if(op_mode == "ps")
					val = rand()%size;
				list<Node*> heapVu;
				if(op_mode == "un"){
					genBinomial(heapVu,size);
				}

		        auto start = chrono::high_resolution_clock::now();
		        //####################INICIO DEL CLOCK####################
		        if(op_mode == "ps"){
		        	heap = insert(heap,val);
		        }
		        else if(op_mode == "pp"){
		        	heap = extractMin(heap);
		        }
		        else if(op_mode == "un"){
		        	heap = unionBionomialHeap(heap,heapVu);
		        }
		        //#####################FIN DEL CLOCK#####################
		        auto end = chrono::high_resolution_clock::now();
		        chrono::duration<double> diff = end - start;
		        cout << diff.count() <<";";  
			}
		    cout<<endl;
		}
	}
	else if(heap_mode == "b"){

		for (int i = 0; i < reps; ++i)
		{
			for (auto size = base; size <= max; size += incr) {

				srand (time(NULL));

				vector<int> v;
				v.reserve(size);
				gen(v,size);
				binaryHeap B(v);

				int val;
				if(op_mode == "ps")
					val = rand()%size;
				vector<int> vu;
				if(op_mode == "un"){
					vu.reserve(size);
					gen(vu,size);
					make_heap(vu.begin(),vu.end());
				}

		        auto start = chrono::high_resolution_clock::now();
		        //####################INICIO DEL CLOCK####################
		        if(op_mode == "ps"){
		        	B.push(val);
		        }
		        else if(op_mode == "pp"){
		        	B.pop();
		        }
		        else if(op_mode == "un"){
		        	B.heapUnion(vu);
		        }
				//#####################FIN DEL CLOCK#####################	
		        auto end = chrono::high_resolution_clock::now();
		        chrono::duration<double> diff = end - start;
		        cout << diff.count() <<";";  
		    }
	    	cout<<endl;
	  }
	}

*/