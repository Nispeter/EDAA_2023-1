#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *r = nullptr;
    node *l = nullptr;
};

class SegmentTree{
    private:
        node* root;
        vector<int> in;
        node* build(int l, int r){ //creacion de arbol con asignacion post-order
            int mid = (l+r)/2;
            if(l == r){
                node*n = new node();
                n->val = in[l];
                return n;
            } 
            node* n = new node();
            n->l = build(l, mid);
            n->r = build(mid+1, r);
            if(n->l != nullptr and n->r != nullptr){
               n->val = min(n->l->val,n->r->val);
            }
            return n;
        }
        /*
        Existen 3 casos:
        El rango de busqueda calza exacto caon el rango completo 
        El rango de busqueda queda fuera del rango completo 
        El rango de busqueda abarca parciarlmente el rango completo
        */
        int RMQ_op(node* n, int low_bound, int upp_bound, int l, int r){ 
            if(low_bound <= l and upp_bound >= r)
                return n->val;
            if(r < low_bound or l > upp_bound)
                return INT_MAX;
            int mid = (l+r)/2;
            return min(
                RMQ_op(n->l, low_bound, upp_bound, l , mid),
                RMQ_op(n->r, low_bound, upp_bound, mid+1 , r)  
            );
            
        }

        void printBT(const std::string& prefix, const node* node, bool isLeft)
        {
            if( node != nullptr )
            {
                std::cout << prefix;

                std::cout << (isLeft ? "├──" : "└──" );

                std::cout << node->val << std::endl;

                printBT( prefix + (isLeft ? "│   " : "    "), node->l, true);
                printBT( prefix + (isLeft ? "│   " : "    "), node->r, false);
            }
        }
        void update_op(int pos, int value, node* n, int l, int r){
            
            if(pos < l or pos > r)
                return;
            else if(l == r){
                n->val = value;
                return ;
            }
            if(n->val > value)
                n->val = value;
            int mid = (l+r)/2;
            update_op(pos,value,n->l,l,mid);
            update_op(pos,value,n->r,mid+1,r);
        }

        void printBT(const node* node)
        {
            printBT("", node, false);    
        }

    public:
        SegmentTree(const vector<int> &in):in(in){
            root = build(0, in.size()-1);
            //printBT(root);
        }
        int RMQ(int l, int u){
            return  RMQ_op(root, l, u, 0,  in.size()-1); 
        }
        void update(int pos, int value ){
            update_op(pos,value,root,0,in.size()-1);
            //printBT(root);
        }
};


//Imprimir arbol binario rescatado de: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c