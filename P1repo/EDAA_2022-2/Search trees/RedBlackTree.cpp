#include "RedBlackTree.h"

using namespace std;

//definimos constantes para mejor comprension de codigo
#define red false
#define black true

void RedBlackTree::left_rotate(RBTNode *n){
	RBTNode *n2 = n->r;
	RBTNode *n3 = n->r->l;
	//actualizamos padre del elemento 2
	if(n == root){//reemplaza root
		n2->parent = n2;
		root = n2;
	}
	else if(n->parent->l == n){
		n2->parent = n->parent;
		n->parent->l = n2;
	}
	else{
		n2->parent = n->parent;
		n->parent->r = n2;
	} 
	//ejecutamos rotacion
	n2->l = n;
	n->r = n3;
	n->parent = n2;
	if(n3 != nullptr)n3->parent = n;
}

void RedBlackTree::right_rotate(RBTNode *n){
	RBTNode *n2 = n->l;
	RBTNode *n3 = n->l->r;
	//actualizamos padre del nodo 2
	if(n == root){//reemplaza root
		n2->parent = n2;
		root = n2;
	}
	else if(n->parent->l == n){
		n2->parent = n->parent;
		n->parent->l = n2;
	}
	else{
		n2->parent = n->parent;
		n->parent->r = n2;
	}
	//ejecutamos rotacion
	n2->r = n;
	n->l = n3;
	n->parent = n2;
	if(n3 != nullptr)n3->parent = n;
}

void RedBlackTree::fixInsert(RBTNode *n){//balanceamos el arbol
	while(n->parent->color == red){
		if(n == root){//caso root
			n->color = black;
			return;
		}
		RBTNode* uncle;
		RBTNode* granp = n->parent->parent;

		if(n->parent != granp->l) uncle = granp->l;//determinamos nodo uncle
		else uncle = granp->r;

		//caso uncle rojo
		if(uncle != nullptr and uncle->color == red){
			granp->color = red;
			n->parent->color = black;
			uncle->color = black;
			n = granp;
			continue;
		}
		//casos black uncle
		//caso triangulo derecho
		else if(n->parent->l == n and granp->r == n->parent){
			RBTNode *newn = n->parent;
			right_rotate(n->parent);
			n = newn;
		}
		//caso triangulo izquierdo
		else if(n->parent->r == n and granp->l == n->parent){
			RBTNode *newn = n->parent;
			left_rotate(n->parent);
			n = newn;
		}
		//caso linea hacia la derecha
		if(n->parent->r == n and granp->r == n->parent){
			granp->color = red;
			n->parent->color = black;
			left_rotate(granp);
		}
		else{//caso linea a la izquierda
			granp->color = red;
			n->parent->color = black;
			right_rotate(granp);

		}

	}

}

RBTNode* RedBlackTree::createNode(int k){//override
	if (size == 0){//primer nodo
		size++;
		root = new RBTNode(k);
		root->parent = root;
		return root;
	}
	RBTNode *t = root;
	while(t != nullptr){//encontramos lugar en el arbol e insertamos registrando padre
		if(t->key == k)return nullptr;
		if(t->key > k){
			if(t->l != nullptr){
				t = t->l;
				continue;
			}
			t->l = new RBTNode(k);
			t->l->parent = t;
			size++;
			return t->l;
		}
		if(t->r != nullptr){
			t = t->r;
			continue;
		}
		t->r = new RBTNode(k);
		t->r->parent = t;
		size++;
		return t->r;
	}
	return nullptr;
}

void RedBlackTree::insert(int k){
	RBTNode *newN =  createNode(k);//creamos nodo
	if(newN == nullptr)return;//ya existia nodo en set
	fixInsert(newN);
}

void RedBlackTree::printColors(const string& prefix, const RBTNode* node, bool isLeft)
{//funcion de impresion
    if( node != nullptr )
    {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        string c;
        if(node->color == black)c = "b";
        else c = "r";
        cout << node->key <<" "<<c<< std::endl;

        printColors( prefix + (isLeft ? "│   " : "    "), node->r, true);
		printColors( prefix + (isLeft ? "│   " : "    "), node->l, false);
    }
}

bool RedBlackTree::search(int k){
	RBTNode *t = root;
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

RBTNode::RBTNode(int k):Node(k){}