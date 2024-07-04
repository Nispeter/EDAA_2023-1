#include "binaryTree.h"

using namespace std;

class AVLNode: public Node {
	public:
        AVLNode(int k);
        int altura;
        int factor;
};

class AVLTree: public BinaryTree {
	private:
		int mysize = 0;
		void calcularAltura(Node* recorrido);
		void calcularFactor(Node* recorrido);
		void balancear(Node* recorrido, Node* padre);
		void AVLLeftRotation(Node* recorrido, Node* padre);
		void AVLRightRotation(Node* recorrido, Node* padre);
		void insertRecursivo(int elementoInsertado, Node* recorrido, Node* padre);
		bool empty();
	public:
		//Node* head;
        AVLTree();
		void insert(int elementoInsertado);
};