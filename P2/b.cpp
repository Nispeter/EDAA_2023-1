#include <bits/stdc++.h>
using namespace std;

class rabinKarp{
	private:
		int primeValue = 457;
		int charAlf = 256;
		int tSize;
		int pSize;
		string text;
		string pattern;
        int base = 1;
        int tHV = 0;
        int pHV = 0;

		void hashValues(){
            for(int i = 0; i < pSize; i++ ){
                tHV = (charAlf * tHV + text[i]) % primeValue;
                pHV = (charAlf * pHV + pattern[i]) % primeValue;
                if(i != 0){
                    base *= charAlf;
                    base %= primeValue;
                }
            }
        }

        void rollHash(int i){
           if(i < tSize - pSize){
                tHV = (charAlf * (tHV - text[i] * base) + text[i + pSize]);
                tHV %= primeValue;
                if(tHV < 0)
                    tHV += primeValue; 
            }
        }

	public: 
		rabinKarp(string &t, string &p){
			text = t;
			pattern = p;
			tSize = text.size();
            pSize = pattern.size();
            hashValues();
		}

        void search(){
            int j = 0;
            for(int i = 0; i < tSize - pSize + 1; i++ ){
                if(tHV == pHV){
                    for(j = 0; j < pSize; j++){
                        if(text[i+j] != pattern[j])
                            break;  
                        if(j == pSize-1)
                            cerr<<"pos: "<< i <<endl;
                    }
                    
                }
                rollHash(i);
            }
        }

};

int main(int argc, char const *argv[])
{
	
	string text = "ACCTGCATCA AGCTTCAT";
	string pattern = "CAT";
	rabinKarp RK(text,pattern);
	RK.search();
	return 0;
}



/*
Formula hash rescatada de: https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/
*/