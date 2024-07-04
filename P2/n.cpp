#include <bits/stdc++.h>
#include <time.h> 
#include "parse.h"
#include "SA.h"
#include "FM.h"

using namespace std;

int main(int argc, char const *argv[])
{
	///////////////////PARSE///////////////////////
	srand (time(NULL));
	int total_lines = 10'000;
	int random_lines = 10;
	pattern_len = 5;
	set <string>  stringSet = getStaticPattern(total_lines,random_lines);
	int valSet = rand()%stringSet.size();
	set<string>::iterator iter = stringSet.begin();
	advance(iter,valSet);
	string pattern = *iter;

	string line;
	std::ifstream file("test.txt");
	int line_number = 0;
	string text = "";
	while (std::getline(file, line)) {
		text.append(" "+line);
		if(line_number > total_lines)
			break;
		++line_number;
	}
	
	///////////////////TEST////////////////////////
	cerr<<"pat: "<<pattern<<endl;
	string  a = "mississippi";
	string b = "s" ;

	//rabinKarp RK(text,pattern);
	FM(text);
    count(pattern);

	SuffixArray SA(text);
	int c = SA.countMatches(pattern);
	cerr<<c<<endl;

	return 0;
}