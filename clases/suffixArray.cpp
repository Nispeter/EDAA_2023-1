#include <bits/stdc++.h>

using namespace std;


void* operator new(size_t count ){									//void* almacena cualquier typecast y puede ser casteado a cualquiera
	cerr<< "creo espacio " << count <<endl;							//las minusculas son mayores que las mayusculas
	return malloc(count);
}

class SuffixArray{
	private:
		string _t;
		string_view _sv;											//string solo de vista
		vector<unsigned> _arr;
		bool compareSuffix(unsigned a, unsigned b){					//trie si esque el a va antes que r
			return (_t.substr(a) < _t.substr(b));					//se realiza una copia en vez de mirarlo 
			
		}
	public: 
		SuffixArray(const string &s): _t(s), _arr(s.size()+1){
			_t.push_back('$');
			_sv = string_view(_t);
			iota(_arr.begin(), _arr.end(),0);
			sort(
				_arr.begin(),
				_arr.end(),

				/*
					WRAPPER#########################################################
					normalmente se le pasa todos los parametros a los funciones
					el bind efectua de weapper
					auto wrapper = bind()
					que recive menos parametros 
					sirve para mantener estaticos algunos parametros de funciones
					ademas las funciones normalmente usan 1 parametro mas que 
					es el puntero a si mismo.
						
					Las funciones dentro de otras no se pueden llamar a si mismas si 
					no poseen la referencias propias.
				*/

				bind(
					&SuffixArray::compareSuffix,
					this,
					placeholders::_1,
					placeholders::_2
					)

				/*
					FUNICON LAMBDA#################################################
					funcion que se declara in-line  
					su implementacion tiene objetivo similar al wapper
				
					[this](unsigned l, unsigned r) -> bool {
						this-> _sv.substr(l) < this->_sv.substr(r);
					}
				*/

				);
		}

		unsigned countMatches(const string &s){							//usar iterador en vez de auto
			auto lower = lower_bound(_arr.begin(), _arr.end(),s,		//lower bound busqueda binaria encuentra el match
					[this](unsigned l, const string &s) -> bool{
						return _sv.substr(l) < s;
					}
				);
			cout << "AAAA " << *lower <<endl;
			auto upper = upper_bound(_arr.begin(), _arr.end(),s,
				[this](const string &s, unsigned l ) -> bool{
						return _sv.substr(l,s.size())  > s;				//se llama a size para definir el inicio
					}
				);
			cout << "BBBB " << *upper <<endl;
			return distance (lower, upper);
		}

		void printArray(){
			for(unsigned i: _arr){
				cout<<i<<" "<<_sv.substr(i)<<endl;
			}
		}
};


int main(int argc, char const *argv[])
{
	SuffixArray SA("bananaanaanana");
	SA.printArray();
	string s;
	cin >> s;
	int c = SA.countMatches("s");
	cout<< c << "coincidencias "<<endl;
	return 0;
}