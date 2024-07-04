#ifndef RATIO_H
#define RATIO_H

#include <iostream>

using namespace std;

class Node{
	public: 
		int key;
		Node* l = NULL;
		Node* r = NULL; 
		Node(int k):key(k){}
};

class BinaryTree {
	private: 
		int size = 0;
	public:
		Node* root = NULL;

		void inOrder(Node* n){
			if(n!= NULL){
				inOrder(n->l);
				cerr<<n->key<<" ";
				inOrder(n->r);
			}
		}
		void createNode(int k){
			if (size == 0){
				size++;
				root = new Node(k);
				return;
			}
			Node *t = root;
			while(t != NULL){
				if(t->key == k)return;
				if(t->key > k){
					if(t->l != NULL){
						t = t->l;
						continue;
					}
					t->l = new Node(k);
					break;
				}
				if(t->r != NULL){
					t = t->r;
					continue;
				}
				t->r = new Node(k);
				break;
			}
			size++;
		}
		bool searchNode(int k){
			Node *t = root;
			while(t!=NULL){
				if(t->key == k)
					return true;
				if(t->key > k){
					if(t->l != NULL){
						t = t->l;
						continue;
					}
					return false;
				}
				if(t->r != NULL){
					t = t->r;
					continue;
				}
				return false;
			}
			return false;
		}

		bool search(int k) {
			return searchNode(k);
		} 

		static Node* leftRotation(Node* t){
			if(t->r != NULL){
				Node* auxNode = t->r;
				t->r = auxNode->l;
				auxNode->l = t;
				return auxNode;
			}
			return t;
		}
		static Node* rightRotation(Node* t){
			if(t->l != NULL){
				Node* auxNode = t->l;
				t->l = auxNode->r;
				auxNode->r = t;
				return auxNode;
			}
			return t;
		}

		//Impresion de arbol rescatada de: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
		void printBT(const string& prefix, const Node* node, bool isLeft)
		{
		    if( node != nullptr )
		    {
		        cout << prefix;
		        cout << (isLeft ? "├──" : "└──" );
		        cout << node->key << std::endl;

		        printBT( prefix + (isLeft ? "│   " : "    "), node->r, true);
        		printBT( prefix + (isLeft ? "│   " : "    "), node->l, false);
		    }
		}
		void printBT(const Node* node)
		{
			printBT("", node, false);    
		}
 
};
#endif
/*
OBSEVACIONES: 
1->- recordar que este arbol binario debe heredar 
todas sus funciones a los otros arboles (por pauta)
2->- tiene funcionalidad de set por lo que no existiran
valores con la misma clave (por pauta)
3.- el nodo root se inicializa en 0 y no tengo tiempo para cambiarlo (estoy en la u)
*/



