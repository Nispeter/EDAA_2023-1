#include<bits/stdc++.h>
using namespace std;
 
//Nodo base del arbol
struct Node
{
  int data, degree;
  Node *child, *sibling, *parent;
};
//creacion de nuevos nodos, asignando padres y hermanos
Node* newNode(int key)
{
  Node *temp = new Node;
  temp->data = key;
  temp->degree = 0;
  temp->child = temp->parent = temp->sibling = NULL;
  return temp;
}
 
// Union de arboles binomiales 
Node* mergeBinomialTrees(Node *b1, Node *b2)
{
  /*El arbol mas pequeño se acopla
  al mas grande*/
  if (b1->data > b2->data)
    swap(b1, b2);
  //asignacion correspondiente del padre y los hermanos 
  b2->parent = b1;
  b2->sibling = b1->child;
  b1->child = b2;
  b1->degree++;
 
  return b1;
}
 
//union de heaps 
list<Node*> unionBionomialHeap(list<Node*> &l1,
              list<Node*> l2)
{
  /*new como heap nuevo que contendra ambos heaps 
    se crean 2 iteradores para recorrer ambos heaps 
    se hace push de cada elemento 
  */
  list<Node*> _new;
  list<Node*>::iterator it = l1.begin();
  list<Node*>::iterator ot = l2.begin();
  while (it!=l1.end() && ot!=l2.end())
  {
    // if D(l1) <= D(l2)
    if((*it)->degree <= (*ot)->degree)
    {
      _new.push_back(*it);
      it++;
    }
    // if D(l1) > D(l2)
    else
    {
      _new.push_back(*ot);
      ot++;
    }
  }
 
  //caso en que queden datos en alguno de los 2 heaps 
  while (it != l1.end())
  {
    _new.push_back(*it);
    it++;
  }
 

  while (ot!=l2.end())
  {
    _new.push_back(*ot);
    ot++;
  }
  return _new;
}
 
//ajuste de heaps en orden de tamano incremental y que ninguno tenga 
//el mismo tamano que el otro 
//escencialmente ajusta las restricciones para que sean un binomial heap.
list<Node*> adjust(list<Node*> &_heap)
{
  if (_heap.size() <= 1)
    return _heap;
  list<Node*> new_heap;
  list<Node*>::iterator it1,it2,it3;
  it1 = it2 = it3 = _heap.begin();
 
  //raices de cada arbol
  //si el tamano es exactamente 2 entonces el it3 no se usa
  if (_heap.size() == 2)
  {
    it2 = it1;
    it2++;
    it3 = _heap.end();
  }
  //en caso contrario los 3 primeros nodos se convierten en las raices 
  else
  {
    it2++;
    it3=it2;
    it3++;
  }
  while (it1 != _heap.end())
  {
    //por cada valor del heap
    if (it2 == _heap.end())
      it1++;
 
    //merge de arboles en caso de que tengan tamanos distntos 
    else if ((*it1)->degree < (*it2)->degree)
    {
      it1++;
      it2++;
      if(it3!=_heap.end())
        it3++;
    }
 
    //modificacion de iteradores cuando todos son el mismo nodo 
    else if (it3!=_heap.end() &&
        (*it1)->degree == (*it2)->degree &&
        (*it1)->degree == (*it3)->degree)
    {
      it1++;
      it2++;
      it3++;
    }
 
    // si solo 2 nodos son iguales implica que se pueden unir y continuar con los otros nodos de los arboles 
    else if ((*it1)->degree == (*it2)->degree)
    {
      Node *temp;
      *it1 = mergeBinomialTrees(*it1,*it2);
      it2 = _heap.erase(it2);
      if(it3 != _heap.end())
        it3++;
    }
  }
  return _heap;
}
 
//agregar el arbol en un heap, llama a la union de heaps
list<Node*> insertATreeInHeap(list<Node*> &_heap,
              Node *tree)
{
  list<Node*> temp;
 
  //se hace push back del arbol a la lista
  temp.push_back(tree);
 
  //se une el arbol y el heap 
  temp = unionBionomialHeap(_heap,temp);
 
  return adjust(temp);
}
 
// remover la  menor llave del arbol
list<Node*> removeMinFromTreeReturnBHeap(Node *tree)
{
  //lista auxiliar 
  list<Node*> heap;
  Node *temp = tree->child;
  Node *lo;
 
  // se itera por el arbol y se agrega al heap 
  //luego se quita el menor valor y se retorna el nuevo heap
  while (temp)
  {
    lo = temp;
    temp = temp->sibling;
    lo->sibling = NULL;
    heap.push_front(lo);
  }
  return heap;
}
 
// insertar valor al heap , 
list<Node*> insert(list<Node*> &_head, int key)
{
  Node *temp = newNode(key);//nuevo nodo
  return insertATreeInHeap(_head,temp);//insertar arbol en el heap 
}
 
//se obtiene el menor valor presente en el heap
Node* getMin(list<Node*> _heap)
{
  list<Node*>::iterator it = _heap.begin();
  Node *temp = *it;
  while (it != _heap.end())
  {
    if ((*it)->data < temp->data)
      temp = *it;
    it++;
  }
  return temp;
}
 
//se extrae el menor valor del heap 
list<Node*> extractMin(list<Node*> &_heap)
{
  list<Node*> new_heap,lo;
  Node *temp;

  //se obtienen el minimo de la lista de nodos
  temp = getMin(_heap);
  list<Node*>::iterator it;
  it = _heap.begin();
  while (it != _heap.end())
  {
    if (*it != temp)
    {
      //se crea un nuevo arbol donde se insertan todos los datos menos el minimo
      new_heap.push_back(*it);
    }
    it++;
  }
  //se  remueve el menor valor 
  lo = removeMinFromTreeReturnBHeap(temp);
  new_heap = unionBionomialHeap(new_heap,lo);
  new_heap = adjust(new_heap);
  return new_heap;
}
 
//imprimir el contenido de cada nodo del arbol
void printTree(Node *h)
{
  while (h)
  {
    cout << h->data << " ";
    printTree(h->child);
    h = h->sibling;
  }
}
 
//imprimir el contenido de cada arbol
void printHeap(list<Node*> &_heap)
{
  list<Node*> ::iterator it;
  it = _heap.begin();
  while (it != _heap.end())
  {
    printTree(*it);
    it++;
  }
}
 