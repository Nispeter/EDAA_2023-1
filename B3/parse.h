#include <bits/stdc++.h>

using namespace std;

int pattern_len = 5;
set<std::string> tokens;

void staticPattern(string line){
    //vector <string> tokens;
    stringstream check1(line);
    string intermediate;
    while(getline(check1, intermediate, ' ')){
        if(intermediate.size() == pattern_len)
            tokens.insert(intermediate);
    }
}

void cleanLine(string &line){
    for (int i = 0; i < line.size(); ++i)
    {
        if(line[i]!= ' ' and ((line[i] < 65 or line[i] > 90) and ( line[i] < 97 or line[i] > 122))){
            line[i] = ' ';
        }
    }
}

void printTokens(set<string> &t){
    cerr<<"tokens: "<<endl;
    for (set<string>::iterator itr = t.begin() ; itr != t.end() ; itr++)
    {
        cerr<<*itr<<" ;";
    }
    cerr<<endl;
}

set <string> getStaticPattern(int number_of_lines,int  number_of_lines_to_select)
{
    //int number_of_lines = 10'000;

  // a vector to hold all the indices: 0 to number_of_lines
  std::vector<int> line_indices(number_of_lines);
  std::iota(begin(line_indices), end(line_indices), 0); // init line_indices

  // C++11 random library (should be preferred over rand()/srand())
  std::random_device r;
  std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
  std::mt19937 eng(seed);

  // shuffle the line_indices:
  std::shuffle(begin(line_indices), end(line_indices), eng);

  //int number_of_lines_to_select = 10;
  assert(number_of_lines_to_select <= number_of_lines);

  std::string line;
  std::ifstream file("test.txt");

  int line_number = 0;
  while (std::getline(file, line)) {
    for (int i = 0; i < number_of_lines_to_select; ++i) {
      if (line_number == line_indices[i]) {
        
        cleanLine(line);
        //std::cout <<"line "<<line_number<<": "<< line << '\n';
        staticPattern(line);
      }
    }
    if(line_number > number_of_lines)
        break;
    ++line_number;
   }
    return tokens;
}

