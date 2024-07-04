#include "SA.h"
#include "BM.h"
#include "parse.h"
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
	}

	int reps = 50;
	
if(op_mode == "t"){
	int max = 100'000;
	int base = 100;
	int incr = 10;

	srand (time(NULL));
				
				for (auto size = base; size <= max; size *= incr) {
					double cont = 0;
					ofstream myfile; 
		        	
		        	myfile.open ("outT.txt",ios::app);
		        	for (int i = 0; i < reps; ++i)
		        	{
		        		int total_lines = size;
    					int random_lines = 10;
    					pattern_len = 5;
    					set <string>  stringSet = getStaticPattern(total_lines,random_lines);
    					int valSet = rand()%stringSet.size();
    					set<string>::iterator iter = stringSet.begin();
    					advance(iter,valSet);
    					string pattern = *iter;

    					std::string line;
						std::ifstream file("test.txt");
						int line_number = 0;
						string text = "";
						while (std::getline(file, line)) {
							text.append(" "+line);
						    if(line_number > total_lines)
						        break;
						    ++line_number;
					   	}
					   	SuffixArray SA(text);

		        		auto start = chrono::high_resolution_clock::now();
			        	//####################INICIO DEL CLOCK####################
		        		int c = SA.countMatches(pattern);
			        	//#####################FIN DEL CLOCK#####################
			        	auto end = chrono::high_resolution_clock::now();
			        	chrono::duration<double> diff = end - start;
		        		cont += diff.count();
		        	}
					cont /= reps;
 					myfile <<cont <<"," ; 
  					myfile.close();

  					cont = 0;
		        	myfile.open ("outT.txt",ios::app);
		        	for (int i = 0; i < reps; ++i)
		        	{
		        		int total_lines = size;
    					int random_lines = 10;
    					pattern_len = 5;
    					set <string>  stringSet = getStaticPattern(total_lines,random_lines);
    					int valSet = rand()%stringSet.size();
    					set<string>::iterator iter = stringSet.begin();
    					advance(iter,valSet);
    					string pattern = *iter;

    					std::string line;
						std::ifstream file("test.txt");
						int line_number = 0;
						string text = "";
						while (std::getline(file, line)) {
							text.append(" "+line);
						    if(line_number > total_lines)
						        break;
						    ++line_number;
					   	}
		        		auto start = chrono::high_resolution_clock::now();
		        		cerr<<"pat_"<<pattern<<" ";
			        	//####################INICIO DEL CLOCK####################
			        	
		        		search(text,pattern);
			        	//#####################FIN DEL CLOCK#####################
			        	auto end = chrono::high_resolution_clock::now();
			        	chrono::duration<double> diff = end - start;
		        		cont += diff.count();
		        	}
					cont /= reps;
 					myfile <<cont <<","; 
  					myfile.close();
		        }

			
		    ofstream myfile;
		    myfile.open ("outT.txt",ios::app);
 			myfile << "\n"; 
  			myfile.close();
  			myfile.open ("outP.txt",ios::app);
 			myfile << "\n"; 
  			myfile.close();

			}

else if(op_mode == "p"){
	srand (time(NULL));
				int max = 8;
				int base = 2;
				int incr = 1;

				for (auto size = base; size <= max; size += incr) {
					double cont = 0;
					ofstream myfile;

		        	
		        	int space = 0;
		        	for (int i = 0; i < reps; ++i)
		        	{
		        		int total_lines = 10'000;
    					int random_lines = 10;
    					pattern_len = size;
    					set <string>  stringSet = getStaticPattern(total_lines,random_lines);
    					int valSet = rand()%stringSet.size();
    					set<string>::iterator iter = stringSet.begin();
    					advance(iter,valSet);
    					string pattern = *iter;

    					std::string line;
						std::ifstream file("test.txt");
						int line_number = 0;
						string text = "";
						while (std::getline(file, line)) {
							text.append(" "+line);
						    if(line_number > total_lines)
						        break;
						    ++line_number;
					   	}
					   	
					   	auto start = chrono::high_resolution_clock::now();
					   	SuffixArray SA(text);
					   	auto end = chrono::high_resolution_clock::now();
					   	chrono::duration<double> diff = end - start;
		        		space += diff.count();

					   	cerr<<"pat_"<<pattern<<" ";
		        		start = chrono::high_resolution_clock::now();
			        	//####################INICIO DEL CLOCK####################
		        		int c = SA.countMatches(pattern);
			        	//#####################FIN DEL CLOCK#####################
			        	end = chrono::high_resolution_clock::now();
			        	diff = end - start;
		        		cont += diff.count();

		        	}
		        	myfile.open ("outS.txt",ios::app);
					space /= reps;
					myfile <<space <<"," ; 
					myfile.close();
					myfile.open ("outP.txt",ios::app);
					cont /= reps;
 					myfile <<cont <<"," ; 
  					myfile.close();

  					cont = 0;
		        	myfile.open ("outP.txt",ios::app);
		        	for (int i = 0; i < reps; ++i)
		        	{
		        		int total_lines = 10'000;
    					int random_lines = 10;
    					pattern_len = size;
    					set <string>  stringSet = getStaticPattern(total_lines,random_lines);
    					int valSet = rand()%stringSet.size();
    					set<string>::iterator iter = stringSet.begin();
    					advance(iter,valSet);
    					string pattern = *iter;

    					std::string line;
						std::ifstream file("test.txt");
						int line_number = 0;
						string text = "";
						while (std::getline(file, line)) {
							text.append(" "+line);
						    if(line_number > total_lines)
						        break;
						    ++line_number;
					   	}
					   	cerr<<"pat_"<<pattern<<" ";
		        		auto start = chrono::high_resolution_clock::now();
			        	//####################INICIO DEL CLOCK####################
		        		search(text,pattern);
			        	//#####################FIN DEL CLOCK#####################
			        	auto end = chrono::high_resolution_clock::now();
			        	chrono::duration<double> diff = end - start;
		        		cont += diff.count();
		        		sleep(20);
		        	}
					cont /= reps;
 					myfile <<cont <<","; 
  					myfile.close();
		        }

			
		    ofstream myfile;
		    myfile.open ("outP.txt",ios::app);
 			myfile << "\n"; 
  			myfile.close();
  			myfile.open ("outP.txt",ios::app);
 			myfile << "\n"; 
  			myfile.close();

			}

	

	return 0;
}

