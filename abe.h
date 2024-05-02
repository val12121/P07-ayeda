#include "tree.h"

template <class Key>
class ABE : public Tree<Key> {
  private:
    bool BuscarNodo(Node<Key>*&, const Key&);
    bool InsertNodoEqui(Node<Key>*&, const Key&);
  public:
    ABE() : Tree<Key>() {};
    ~ABE() {};
    bool Buscar(Key k) { return BuscarNodo(this->nodo, k); }
    bool Insert(Key k) {
      if (this->nodo == NULL) {
        this->nodo = new Node<Key>(k);
        return true;
      }
      return Insert(this->nodo, k) { 
        if (nodo == NULL)
        nodo = new Node(dato, NULL, NULL);
        else InsertNodoEqui(dato, nodo);
      }
    }
};

template <class Key> 
bool ABE<Key>::BuscarNodo(Node<Key>*& nodo, const Key& clave_dada) {}

template <class Key>
bool ABE<Key>::InsertNodoEqui(Node<Key>*& nodo, const Key& clave_dada) {
    if (TamRama(nodo->left_) <= TamRama(nodo->right_)) {
    if (nodo->left_ != NULL)
      InsertaEquilRama(dato, nodo->left_);
    else
      nodo->left_ = new nodoB(dato, NULL, NULL);
  }
  else {
    if (nodo->right_ != NULL) 
      InsertaEquilRama(dato, nodo->right_);
    else
      nodo->right_ = new nodoB(dato, NULL, NULL);
  }
}