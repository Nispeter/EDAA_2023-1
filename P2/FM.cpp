// C program to find Burrows Wheeler transform
// of a given text

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

// Structure to store data of a rotation
struct rotation {
	int index;
	char* suffix;
};

// Compares the rotations and
// sorts the rotations alphabetically
int cmpfunc(const void* x, const void* y)
{
	struct rotation* rx = (struct rotation*)x;
	struct rotation* ry = (struct rotation*)y;
	return strcmp(rx->suffix, ry->suffix);
}

// Takes text to be transformed and its length as
// arguments and returns the corresponding suffix array
int* computeSuffixArray(char* input_text, int len_text)
{
	// Array of structures to store rotations and
	// their indexes
	struct rotation suff[len_text];

	// Structure is needed to maintain old indexes of
	// rotations after sorting them
	for (int i = 0; i < len_text; i++) {
		suff[i].index = i;
		suff[i].suffix = (input_text + i);
	}

	// Sorts rotations using comparison
	// function defined above
	qsort(suff, len_text, sizeof(struct rotation),
		cmpfunc);

	// Stores the indexes of sorted rotations
	int* suffix_arr
		= (int*)malloc(len_text * sizeof(int));
    //cerr<<"SA: ";
	//for (int i = 0; i < len_text; i++){
	//	suffix_arr[i] = suff[i].index;
	//	cerr<<suff[i].index<<" ";
    //    }
    //cerr<<endl;
	// Returns the computed suffix array
	return suffix_arr;
}

// Takes suffix array and its size
// as arguments and returns the
// Burrows - Wheeler Transform of given text
char* findLastChar(char* input_text,
				int* suffix_arr, int n)
{
	// Iterates over the suffix array to find
	// the last char of each cyclic rotation
	char* bwt_arr = (char*)malloc(n * sizeof(char));
	int i;
	for (i = 0; i < n; i++) {
		// Computes the last char which is given by
		// input_text[(suffix_arr[i] + n - 1) % n]
		int j = suffix_arr[i] - 1;
		if (j < 0)
			j = j + n;

		bwt_arr[i] = input_text[j];
	}

	bwt_arr[i] = '\0';

	// Returns the computed Burrows - Wheeler Transform
	return bwt_arr;
}

void buildArrays(int* suffix_arr, char* bwt_arr ,char* input_text, int len_text, map<char,int> &C, map<char,vector<int>> &Occ ){
	
	char prev;

	for (int i = 0; i < len_text; ++i)
	{
		if(input_text[suffix_arr[i]]  != prev){
            C[input_text[suffix_arr[i]]] = i;
            prev = input_text[suffix_arr[i]];
        }

        if(Occ[bwt_arr[i]].size()==0){
            for (int j = 0; j <= i; j++)
            {
                Occ[bwt_arr[i]].push_back(0);
            }
            for (map<char,vector<int>>::iterator itr = Occ.begin(); itr != Occ.end(); itr++)
            {
                char a = itr->first;
                if(i!=0 and a != bwt_arr[i]){
                    Occ[itr->first].push_back(Occ[itr->first][i-1]);
                }
            }
            Occ[bwt_arr[i]][i] = 1; 
        }
        else{
            for (map<char,vector<int>>::iterator itr = Occ.begin(); itr != Occ.end(); itr++)
            {
                if(i!=0){
                    Occ[itr->first].push_back(Occ[itr->first][i-1]);
                }
            }
            Occ[bwt_arr[i]][i] = Occ[bwt_arr[i]][i-1] + 1;
        }
			
	}

    /*for (map<char,int>::iterator itr = C.begin(); itr != C.end(); itr++)
    {
        cerr<<"C["<<itr->first<<"]="<<itr->second<<" ";
    }cerr<<endl;

    for (map<char,int>::iterator itr = C.begin(); itr != C.end(); itr++)
    {
        char aux = itr->first;
        cerr<<aux<<":"<<itr->second<<"= ";
        for (int i = 0; i < len_text; i++)
        {

            cerr<<Occ[aux][i]<<" ";
        }
        cerr<<endl;
    }*/

}

int  count(int* suffix_arr, char* bwt_arr ,char* input_text, string &pat, int len_text, map<char,int> &C, map<char,vector<int>> &Occ  ) {
    int i = pat.size()-1;
    char c = pat[i];
    int sp = C[c]-1;
    int ep = len_text-1;
    
    map<char,int>::iterator itr = C.find(c);
    itr++;
    ep = itr->second-1;
    i--;
    if(Occ[c][ep] > len_text or Occ[c][ep] < 0)
        ep = len_text-1;

    //cerr<<"prev -> ep "<<ep<<" sp "<<sp<<endl;
    while ((sp < ep) and (i >= 0) ) 
    {
        if(C[c]+Occ[c][ep] > len_text or C[c]+Occ[c][ep] < 0)
            break;
        c = pat[i];

        //cerr<<"ep "<<ep<<" sp "<<sp<<endl;
        //cerr<<"C["<<c<<"]="<<C[c]<<" epOcc["<<c<<"]["<<ep<<"]="<<Occ[c][ep]<<" spOcc["<<c<<"]["<<sp<<"]="<<Occ[c][sp]<<endl;
        
        sp = C[c]+Occ[c][sp]-1;
        
        ep = C[c]+Occ[c][ep]-1;
        i--;
    }
    //cerr<<ep<<" "<<sp<<endl;
    //if (ep<sp)
    //    return 0;5
    //return ep - sp + 1;
    return abs(ep - sp);
    

}

// Driver program to test functions above
void FM(string text,string pat)
{
	int size = text.size();
	char input_text[size+1];
	strcpy(input_text, text.c_str());
    //string pat = "si";
	int len_text = strlen(input_text);

	// Computes the suffix array of our text
	int* suffix_arr
		= computeSuffixArray(input_text, len_text);

	// Adds to the output array the last char
	// of each rotation
	char* bwt_arr
		= findLastChar(input_text, suffix_arr, len_text);
	
	//cin>>pat;

    map<char,int> C;
    map<char,vector<int>>Occ;
	buildArrays(suffix_arr,bwt_arr,input_text,len_text,C,Occ);
	int temp = count(suffix_arr,bwt_arr, input_text, pat, len_text,C,Occ);
    cerr<<"Cantidad de apariciones del patron "<<pat<<" : "<<temp<<endl;
	printf("Input text : %s\n", input_text);
	//printf("SA :");
	//for (int i = 0; i < sizeof(suffix_arr)/sizeof(suffix_arr[0]); ++i)
	//{
	//	printf("%d ",
	//	suffix_arr[i]);
	//}
	printf("\n");
	printf("BWT : %s\n",
		bwt_arr);
}
