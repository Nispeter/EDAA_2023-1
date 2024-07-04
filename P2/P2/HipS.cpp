#include "SA.h"
#include "RK.h"
#include "FM.h"

#include "parse.h"
#include <cstdlib>
#include <time.h> 

using namespace std;

int main(int argc, char const *argv[])
{
	string op_mode = "1";

	if(argc > 1){
		string argv1 = argv[1];
		cerr<<"arg"<<argv1<<endl;
		if(argv1 == "-2")
			op_mode  = "2";
        if(argv1 == "-3")
			op_mode  = "3";
	}

	int total_lines = 10'000;
    int random_lines = 10;
    pattern_len = 5;

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

    set <string>  stringSet = getStaticPattern(total_lines,random_lines);
    int valSet = rand()%stringSet.size();
    set<string>::iterator iter = stringSet.begin();
    advance(iter,valSet);
    string pattern = *iter;
	
    if(op_mode == "1"){			
        cerr<<"SA"<<endl;
        SuffixArray SA(text);
        int c = SA.count(pattern);
        cerr<<pattern<<" found "<<c<<" times"<<endl;
        }	
    else if (op_mode == "2"){
        cerr<<"RK"<<endl;
        rabinKarp RK(text,pattern);
        int c = RK.count();
        cerr<<pattern<<" found "<<c<<" times"<<endl;
    }	
    else if (op_mode == "3"){
        cerr<<"FM"<<endl;
        FM(text);
        int c = count(pattern);
        cerr<<pattern<<" found "<<c<<" times"<<endl;
    }
    sleep(20);
    return 0;
}