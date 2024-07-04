#include <bits/stdc++.h>
//{}
using namespace std;

class rabinKarp{
	private:
		int primeValue = 457;
		int charAlf = 256;
		int tSize;
		int pSize;
		string text;
		string pattern;
		int i,j;
        int base = 1;
        int tHV = 0;
        int pHV = 0;

		void hashValues(){
            for (i = 0; i < pSize - 1; i++ ){
                base *= charAlf;
                base %= primeValue;
            }
            for(i = 0; i < pSize; i++ ){
                tHV = (charAlf * tHV + text[i]) % primeValue;
                pHV = (charAlf * pHV + pattern[i]) % primeValue;
            }
        }

	public: 
		rabinKarp(string &t, string &p){
			text = t;
			pattern = p;
			cerr<<text[0]<<endl;
			cerr<<pattern[0]<<endl;
			tSize = text.size();
            pSize = pattern.size();
            hashValues();
		}

        void search(){
            for(i = 0; i < tSize - pSize + 1; i++ ){
                if(tHV == pHV){
                    for(j = 0; j < pSize; j++){
                        if(text[i+j] != pattern[j])
                            break;
                    }
                    if(j == pSize)
                        cerr<<"pattern found at "<< i<<endl;
                }
                if(i < tSize - pSize){
                    tHV = (charAlf * (tHV - text[i] * base) + text[i + pSize])%primeValue;
                    if(tHV < 0)
                        tHV += primeValue;
                }
            }
        }

};

int main(int argc, char const *argv[])
{
	
	string text = "ACCTGCATCAAGCTTCAT";
	string pattern = "CAT";
	rabinKarp RK(text,pattern);
	RK.search();
	return 0;
}