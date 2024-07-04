#include <bits/stdc++.h>			//no me funen estoy en el lab y tengo tiempo limitado 
#include "splayTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	SplayTree b;
	b.insert(-1);
	b.insert(-3);
	b.insert(-7);
	b.insert(3);
	b.insert(6);
	b.insert(2);
	b.insert(8);
	//b.printTree(b.root);
	//b.root = b.leftRotation(b.root);
	//b.root = b.rightRotation(b.root);
	//b.printTree(b.root);
	
	cerr<<b.search(-3)<<endl;
	cerr<<b.search(0)<<endl;
	cerr<<b.search(31)<<endl;
	cerr<<b.search(-1)<<endl;
	b.printBT(b.root);
	return 0;
}


