#include <bits/stdc++.h>

using namespace std;

void* operator new(size_t count){
	cerr << "creo espacio " << count <<endl;
	return malloc(count);
}

class SuffixArray{
	private:	
	string _t;
	string_view _sv;
	vector<unsigned> _arr;

	bool compareSuffix(unsigned l, unsigned r){
		// true si es que l va antes que r
		return _sv.substr(l) < _sv.substr(r);
	}

	public:
	SuffixArray(const string &s) : _t(s) , _arr(s.size()+1) {
		
		_t.push_back('$');
		_sv  = string_view(_t);
		iota(_arr.begin(),_arr.end(),0);

		sort(_arr.begin(), _arr.end(), 
//alternativa 1
			[this](unsigned l, unsigned r) -> bool{
				return this->_sv.substr(l)<this->_sv.substr(r);
			} 
//alternativa 2
/*
			bind(&SuffixArray::compareSuffix,
				this,placeholders::_1, placeholders::_2)	*/
				); 


	}

	unsigned countMatches(const string &s){

		auto lower = lower_bound(_arr.begin(),_arr.end(),s,
			[this](unsigned l, const string &s) -> bool{
				// true si es que el string s no esta antes
				return _sv.substr(l) < s;
			} );

		auto upper = upper_bound(_arr.begin(), _arr.end(), s,

			[this](const string &s,unsigned l ) -> bool{
				// true si es que el string s no esta antes
				return _sv.substr(l,s.size()) > s;
				} );


		cout << "AAAA "<<  *lower <<endl;

		cout << "BBBB "<<  *upper<<endl;

		return distance(lower,upper);
	}

	void printArray(){
		for(unsigned i : _arr){
			cout << i << " " <<_sv.substr(i) <<endl;
		}
	}

};

void saludaYAlgo(const string &s, int n){
	cout << s << " y el int es " << n<<endl;
}

int main(){
	SuffixArray SA("bananaranaanaanana");
	SA.printArray();
	string s;
	cin >> s;
	int c = SA.countMatches(s);
	cout << c << " coincidencias"<<endl;
}
