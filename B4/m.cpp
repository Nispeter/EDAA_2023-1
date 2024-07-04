#include "segment.h"
#include "sparse.h"
#include <cstdlib>
#include <time.h> 

using namespace std;

int main(int argc, char const *argv[])
{

	string op_mode = "t";

	if(argc > 1){
		string argv1 = argv[1];
		cerr<<"arg"<<argv1<<endl;
		if(argv1 == "-p")
			op_mode  = "p";
        else if(argv1 == "-m1")
			op_mode  = "m1";
        else if(argv1 == "-m2")
			op_mode  = "m2";
	}
    int reps = 50;

    if(op_mode == "t"){
        int max = 700'000;
        int base = 100'000;
        int incr = 100'000;

	    srand (time(NULL));
        vector<int> v;
        v.reserve(max);

        ofstream myfile; 
        myfile.open ("outSP.txt",std::ofstream::out | std::ofstream::trunc);
        myfile.close();
        myfile.open ("outSE.txt",std::ofstream::out | std::ofstream::trunc);
        myfile.close();

        for (auto size = base; size <= max; size += incr) {
            cerr<<"Segment tree "<<size<<endl;
            double call = 0;
            double cons = 0;
            
            myfile.open ("outSP.txt",ios::app);
            v.clear();
            //cerr<<v.size()<<" "<<&v<<" "<<v.max_size()<<" "<<v.capacity()<<endl;
            
            for (int i = 0; i <= size; i++)
            {
                int temp = rand()%size+1;
                //cerr<<i<<" "<<temp<<endl;
                v.push_back(temp);
            }
            

            for (int i = 0; i < reps; ++i)
            {
                int a = 0,b = 0;
                while(a==b){
                    a = rand()%(size+1);
                    b = rand()%(size+1);
                }
                if(a > b)
                    swap(a,b);

                auto start = chrono::high_resolution_clock::now();
                //####################INICIO DEL CLOCK####################
                SegmentTree SgT(v);
                //#####################FIN DEL CLOCK#####################
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> diff = end - start;
                cons += diff.count();

                start = chrono::high_resolution_clock::now();
                //####################INICIO DEL CLOCK####################
                SgT.RMQ(a,b);
                //#####################FIN DEL CLOCK#####################
                end = chrono::high_resolution_clock::now();
                diff = end - start;
                call += diff.count();
               
            }
            cons /= reps;
            myfile <<cons <<"," ; 
            call /= reps;
            myfile <<call <<"," ; 
            myfile.close();

            cerr<<"Sparse table "<<size<<endl;
            cons = 0;
            call = 0;
            myfile.open ("outSE.txt",ios::app);
            for (int i = 0; i < reps; ++i)
            {
                int a = 0,b = 0;
                while(a==b){
                    a = rand()%(size+1);
                    b = rand()%(size+1);
                }
                if(a > b)
                    swap(a,b);

                auto start = chrono::high_resolution_clock::now();
                //####################INICIO DEL CLOCK####################
                SparseTable SpT(v);
                //#####################FIN DEL CLOCK#####################
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> diff = end - start;
                cons += diff.count();

                start = chrono::high_resolution_clock::now();
                //####################INICIO DEL CLOCK####################
                SpT.RMQ(a,b);
                //#####################FIN DEL CLOCK#####################
                end = chrono::high_resolution_clock::now();
                diff = end - start;
                call += diff.count();
            }
            cons /= reps;
            myfile <<cons <<"," ; 
            call /= reps;
            myfile <<call <<"," ; 
            myfile.close();
        }


    // ofstream myfile;
    // myfile.open ("outSP.txt",ios::app);
    // myfile << "\n"; 
    // myfile.close();
    // myfile.open ("outSE.txt",ios::app);
    // myfile << "\n"; 
    // myfile.close();

    }

    else if(op_mode == "p"){
	int max = 700'000;
    int base = 100'000;
    int incr = 100'000;
    int size = 400'000;

    srand (time(NULL));
    vector<int> v;
    v.reserve(max);

    ofstream myfile; 
    myfile.open ("outPP.txt",std::ofstream::out | std::ofstream::trunc);
    myfile.close();
    myfile.open ("outPE.txt",std::ofstream::out | std::ofstream::trunc);
    myfile.close();

    for (auto range = size/8; range <= size; range += size/8) {
        cerr<<"Segment tree "<<size<<endl;
        double call = 0;
        
        myfile.open ("outPP.txt",ios::app);
        v.clear();
        //cerr<<v.size()<<" "<<&v<<" "<<v.max_size()<<" "<<v.capacity()<<endl;
        
        for (int i = 0; i <= size; i++)
        {
            int temp = rand()%size+1;
            //cerr<<i<<" "<<temp<<endl;
            v.push_back(temp);
        }
        

        for (int i = 0; i < reps; ++i)
        {
            SegmentTree SgT(v);
            auto start = chrono::high_resolution_clock::now();
            //####################INICIO DEL CLOCK####################
            SgT.RMQ(0,range);
            //#####################FIN DEL CLOCK#####################
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> diff = end - start;
            call += diff.count();
        }
        call /= reps;
        myfile <<call <<"," ; 
        myfile.close();

        cerr<<"Sparse table "<<size<<endl;
        call = 0;
        myfile.open ("outPE.txt",ios::app);
        for (int i = 0; i < reps; ++i)
        {
            int a = 0,b = 0;
            while(a==b){
                a = rand()%(size+1);
                b = rand()%(size+1);
            }
            if(a > b)
                swap(a,b);
            SparseTable SpT(v);
            auto start = chrono::high_resolution_clock::now();
            //####################INICIO DEL CLOCK####################
            SpT.RMQ(0,range);
            //#####################FIN DEL CLOCK#####################
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> diff = end - start;
            call += diff.count();
        }
        call /= reps;
        myfile <<call <<"," ; 
        myfile.close();

        }

    }
    else if(op_mode == "m1"){
    int base = 400'000;
    int incr = 100'000;
    int max = 400'000;

    srand (time(NULL));
    vector<int> v;
    v.reserve(max);

    v.clear(); 
    for (int i = 0; i <= base/4; i++)
    {
        int temp = rand()%base/4+1;
        //cerr<<i<<" "<<temp<<endl;
        v.push_back(temp);
    }


    SegmentTree SgT(v);
    SgT.RMQ(0,base/4);
    sleep (20);
    
   
    }
    else if(op_mode == "m2"){
    int base = 400'000;
    int incr = 100'000;
    int max = 400'000;

    srand (time(NULL));
    vector<int> v;
    v.reserve(max);

    v.clear(); 
    for (int i = 0; i <= base/4; i++)
    {
        int temp = rand()%base/4+1;
        //cerr<<i<<" "<<temp<<endl;
        v.push_back(temp);
    }
    SparseTable SpT(v);
    SpT.RMQ(0,base/4);
    sleep (20);
    }

	return 0;
}

