// Construcción del suffix array y la BWT de un texto
//
// Prerrequisitos: Tener la biblioteca SDSL instalada
//
// Compilación: g++ -O3 -o sa sa.cpp -lsdsl -ldivsufsort -ldivsufsort64
#include <sdsl/suffix_arrays.hpp>
#include <string>
#include <iostream>
#include <algorithm>
using namespace sdsl;
using namespace std;
int main(int argc, char** argv) {
  if (argc !=  2) {
    cout << "Uso: " << argv[0] << " <archivo entrada>" << endl;
    return 1;
  }
  // Leemos el archivo de entrada y guardamos el contenido en 'seq'
  string infile(argv[1]);
  
  int_vector<> seq;
  int32_t n;
  {
    load_vector_from_file(seq, infile, 1);
    n = seq.size();
    
    seq.resize(n+1);
    n = seq.size();
    seq[n-1] = 0; // Representa el final de texto. Suele representarse por el
                  // símbolo $ 
  }
  cout << "Construyendo el Suffix array ..." << endl;
  
  int_vector<> sa(1, 0, bits::hi(n)+1);
  sa.resize(n);
  algorithm::calculate_sa((const unsigned char*)seq.data(), n, sa);

  Cst::int_vector<> sdsl::algorithm::locate();

  for (int i = 0; i < sa.size(); i++)
  {
    cout<<sa[i]<<endl;
  }
  

  cout << "Tamaño del SA " << size_in_mega_bytes(sa) << " MB." << endl;
  
  return 0;
}