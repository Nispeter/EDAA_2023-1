#include "binaryTree.h"

using namespace std;

class SplayTree: public BinaryTree {
	private:
		/*Metodo principal del splayTree es el que regula las rotaciones
		segun frecuencia, recive como parametros un arbol binario t y un valor a buscar k
		luego este valor es reajustado hasta la raiz */
		/*OBSERVACION: cada vez que se haga referencia a nodo 1, 2 o 3 esto significa al nivel en 
		que se encuentran, siendo el 1 mas acercado a la raiz:
                t-----------nivel (1)
              /   \	
            l      r--------nivel (2)
          /   \  /   \
         l     r l    r-----nivel (3)
		*/
		Node* balance(Node* t,const int k){
			if(t != NULL and t->key != k){		
				//si la key se encuentra en el hijo izquierdo del nodo t
				if(k < t->key){
					//condicion de termino de busqueda 
					if(t->l == NULL)
						return t;
					/*Se requieren hacer rotaciones entre 3 nodos para poder subir el valor deseado a la raiz.
					se verificara si el nodo que se encuentra a 2 niveles de distancia de t (alejandose de la raiz)
					y en que modo: puede ser zig-zag o zig-zig.
					Se se llama a estas funciones para hacer rotaciones entre esos ultimos 2 nodos
					y luego se reasigna a t para hacer la utlima rotacion de las 3, esto conforma ambos modos
                        zig-zig:						zig-zag:
                               t           t                t               t
                              /             \              /                 \
                             l      ->       r            l        ->         r
                            /                 \            \                 /
                           l                   r            r               l
					*/
					//casos: t->L->R, t->L->L
					if(k > t->l->key){		
						t = zig_zag(t, k, 'r');
					}
					else{				
						t = zig_zig(t, k, 'r');
					}
					//reajuste final de t
					if(t->l == NULL)
						return t;
					return finishZig(t ,'r');
				}
				//si la key se encuentra en el hijo derecho del nodo t 
				else{
					//condicion de termino de la busqueda 
					if(t->r == NULL)
						return t;
					/*ocurre lo mismo que en la condicion anterior 
					la diferencia es que comienza desde el nodo de la derecha */
					//casos: t->R->L, t->R->R
					if(k > t->r->key){			
						t = zig_zig(t, k, 'l');
					}
					else{						
						t = zig_zag(t, k, 'l');
					}
					//reajuste final de t
					return finishZig(t ,'l');
				}
			}
			return t;
		}
		/*rotacion del segundo nodo con t*/
		Node* finishZig(Node* t, const char side){
			if(side == 'l' and t-> r!= NULL){
				return leftRotation(t);
			}
			else if(side == 'r' and t-> l!= NULL){
				return rightRotation(t);
			}
			return t;
		}
		//rotacion entre el segundo nodo y el tercero cuando estan ambos nodos de seguimiento al mismo lado de t
		Node* zig_zig(Node* t, const int k, const char side){
			if(side == 'l'){
				t->r->r = balance(t->r->r,k);
				t = leftRotation(t);
			}
			else {
				t->l->l = balance(t->l->l, k);
				t = rightRotation(t);
			}
			return t;
		}
		//rotacion entre el segundo nodo y el tercero cuando estan a lados contrarios respecto t
		//aqui se verifica si el contrario  es nulo para verificar si se puede hacer la rotacion
		Node* zig_zag(Node* t, const int k, const char side){
			if(side == 'r'){
				t->l->r = balance(t->l->r,k);
					if (t->l->r != NULL)
						t->l = leftRotation(t->l);
			}
			else {
				t->r->l = balance(t->r->l, k);
					if (t->r->l != NULL)
						t->r = rightRotation(t->r);
			}
			return t;
		}
	public: 
		SplayTree(){}


		/*llama a la funcion createNode del arbol binario
		entregandole el valor k a insertar.
		luego invoca a la funcion balance*/
		void insert(int k){
			createNode(k);
			root = balance(root, k);
		} 	
		/*Metodo para debugear, imprime el arbol*/
		bool searchDebug(int k){
			cerr<<"start of search: "<<k<<endl;
			printBT(root);
			Node *t = root;
			root = balance(root, k);
			cerr<<endl;
			printBT(root);
			return (root->key == k )? true : false;
		}	
		/*busqueda del valor k al balancear
		se mueve el valor buscado hasta la raiz, 
		luego se verifica si la raiz es igual a k*/
		bool search(int k){
			Node *t = root;
			root = balance(root, k);
			return (root->key == k )? true : false;
		}
};