#include "binaryTree.h"

using namespace std;

class RBTNode: public Node {
	public:
        RBTNode(int k);
        RBTNode* parent = nullptr;
        RBTNode* l = nullptr;
        RBTNode* r = nullptr;
        bool color = false;
};

class RedBlackTree: public BinaryTree {
	private:
		int size = 0;
		RBTNode* createNode(int k);
		void fixInsert(RBTNode *n);
		void right_rotate(RBTNode *n);
		void left_rotate(RBTNode *n);

	public: 
		RBTNode *root = nullptr;
		bool search(int k);
		void printColors(const string& prefix, const RBTNode* node, bool isLeft);
		void insert(int k);
};