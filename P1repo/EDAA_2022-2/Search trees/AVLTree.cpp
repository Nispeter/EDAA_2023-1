#include "AVLTree.h"

/**
El siguiente código esta basado una implementación de AVL hecha por Iván Montti y Rodrigo San Martín para la asignatura de
Estructura de Datos 2021. Se ha modificado para que pueda heredar del BinaryTree. 
 **/

using namespace std;

AVLTree::AVLTree() {}

// El padre pasará a ser el hijo izquierdo del recorrido.
void AVLTree::AVLLeftRotation(Node* recorrido, Node* padre) {

    //AVLNode* aux = recorrido->r;
    Node* aux = recorrido->r;

    // Si el recorrido es root, el hijo derecho será el root.
    if (padre == NULL) {
        root = aux;
    } else if (padre->l == recorrido) {
    	// Si el nodo recorrido es el hijo izquierdo del padre, el hijo derecho del recorrido lo remplazara.
        padre->l = aux;
    } else if (padre->r == recorrido) {
    	// Si el nodo recorrido es el hijo derecho del padre, el hijo derecho del recorrido lo remplazara.
        padre->r = aux;
    }

    // Intercambiamos los hijos.
    recorrido->r = aux->l;
    aux->l = recorrido;

    // Recalculamos la altura y el factor.
    calcularAltura(recorrido);
    calcularFactor(recorrido);
    calcularAltura(aux);
    calcularFactor(aux);
}

// El padre pasará a ser el hijo derecho del recorrido.
void AVLTree::AVLRightRotation(Node* recorrido, Node* padre) {

    //AVLNode* aux = recorrido->l;
    Node* aux = recorrido->l;
    
    // Si el recorrido es root, el hijo izquierdo será el root.
    if (padre == NULL) {
        root = aux;
    } else if (padre->l == recorrido) {
    	// Si el nodo recorrido es el hijo izquierdo del padre, el hijo izquierdo del recorrido lo remplazara.
        padre->l = aux;
    } else if (padre->r == recorrido) {
    	// Si el nodo recorrido es el hijo derecho del padre, el hijo izquierdo del recorrido lo remplazara.
        padre->r = aux;
    }

    // Intercambiamos los hijos.
    recorrido->l = aux->r;
    aux->r = recorrido;

    // Recalculamos la altura y el factor.
    calcularAltura(recorrido);
    calcularFactor(recorrido);
    calcularAltura(aux);
    calcularFactor(aux);
}

// Balancea un sub-árbol si no cumple la invariante AVL.
void AVLTree::balancear(Node* recorrido, Node* padre) {

    // No podemos balancear un nodo inexistente.
    if (!recorrido) return;

    if (((AVLNode*)recorrido)->factor <= -2) {
        // El factor es menor que -1 por lo tanto es Left Heavy y no cumple la invariante.

        if (((AVLNode*)recorrido->l)->factor == -1) {

            // LeftLeft
            AVLRightRotation(recorrido, padre);
        } else if (((AVLNode*)recorrido->l)->factor == 1) {

            // LeftRight
            // Entiéndase acá que el "padre" es el recorrido, en la primera rotación.
            AVLLeftRotation(recorrido->l, recorrido);
            AVLRightRotation(recorrido, padre);
        }
    } else if (((AVLNode*)recorrido)->factor >= 2) {
        // El factor es mayor que +1 por lo tanto es Right Heavy y no cumple la invariante.

        if (((AVLNode*)recorrido->r)->factor == 1) {

            // RightRight
            AVLLeftRotation(recorrido, padre);
        } else if (((AVLNode*)recorrido->r)->factor == -1){

            // RightLeft
            // Entiéndase acá que el "padre" es el recorrido, en la primera rotación.
            AVLRightRotation(recorrido->r, recorrido);
            AVLLeftRotation(recorrido, padre);
        }
    }

    // El factor pertenece a [-1, 0, +1], ya esta balanceado.
}

// Calcula la altura del nodo, la cual es la altura mayor de sus hijos mas uno.
// Consideramos la "altura" de un hijo nulo como -1, para esto utilizamos el operador ternario.
//
// En el caso de una hoja su altura es igual a max(-1, -1) + 1, lo que resulta en 0 y es correcto.

void AVLTree::calcularAltura(Node *recorrido) {
    ((AVLNode*)recorrido)->altura = max((recorrido->l ? ((AVLNode*)recorrido->l)->altura : -1),(recorrido->r ? ((AVLNode*)recorrido->r)->altura : -1)) + 1;
}

// Calcula el factor de balance del nodo, que definimos como Altura(Derecho) - Altura(Izquierdo).
//
//  factor = -2 => Left Heavy - No cumple invariante
//  factor = -1 => Left Heavy - Cumple invariante
//  factor =  0 => Balanceado
//  factor = +1 => Right Heavy - Cumple invariante
//  factor = +2 => Right Heavy - No cumple invariante.
//
//  Utilizamos el operador ternario en el caso de que exista un hijo nulo.

void AVLTree::calcularFactor(Node *recorrido) {
    ((AVLNode*)recorrido)->factor = (recorrido->r ? ((AVLNode*)recorrido->r)->altura : -1) - (recorrido->l ? ((AVLNode*)recorrido->l)->altura : -1);
}

void AVLTree::insertRecursivo(int elementoInsertado, Node* recorrido, Node* padre){

    // Si encontramos una clave igual no insertamos y retornamos.
    if(recorrido->key == elementoInsertado) return;

    // Si la clave es menor que la actual, revisar el hijo izquierdo.
    if (elementoInsertado < recorrido->key) {
        // Si no existe hijo izquierdo, insertamos.
        if (recorrido->l == NULL) {
            AVLNode* nuevo = new AVLNode(0);

            nuevo->l = NULL;
            nuevo->r = NULL;
            nuevo->altura = 0;
            nuevo->factor = 0;

            nuevo->key = elementoInsertado;
            recorrido->l = nuevo;
            mysize++;
            return;
        }

        // Si el existe el hijo izquierdo, continuamos.
        insertRecursivo(elementoInsertado, recorrido->l, recorrido);

        // Re-calculamos la altura, factor y balanceamos si es necesario.
        calcularAltura(recorrido);
        calcularFactor(recorrido);
        balancear(recorrido, padre);
    } else {
        // Si la clave es mayor que la actual, revisar el hijo derecho.

        // Si no existe hijo derecho, insertamos.
        if (recorrido->r == NULL) {
        	AVLNode* nuevo = new AVLNode(0);

            nuevo->l = NULL;
            nuevo->r = NULL;
            nuevo->altura = 0;
            nuevo->factor = 0;

            nuevo->key = elementoInsertado;
            recorrido->r = nuevo;
            mysize++;
            return;
        }

        // Si el existe el hijo derecho, continuamos.
        insertRecursivo(elementoInsertado, recorrido->r, recorrido);

        // Re-calculamos la altura, factor y balanceamos si es necesario.
        calcularAltura(recorrido);
        calcularFactor(recorrido);
        balancear(recorrido, padre);
    }
}

void AVLTree::insert(int elementoInsertado){

    // Si es el primer par a insertar.
    if (empty()) {
        AVLNode* start = new AVLNode(0);

        start->l = NULL;
        start->r = NULL;
        start->altura = 0;
        start->factor = 0;

        start->key = elementoInsertado;
    	root = start;
    	mysize++;
        return;
    } else {
        insertRecursivo(elementoInsertado, root, NULL);
    }
}

bool AVLTree::empty(){
    return (mysize == 0);
}

AVLNode::AVLNode(int k) : Node(k) {

}
