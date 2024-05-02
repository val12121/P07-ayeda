#include "tree.h"

template <class Key>
class ABB : public Tree<Key> {
  private:
    bool BuscarNodo(Node<Key>*&, const Key&);
    bool InsertNodo(Node<Key>*&, const Key&);
  public:
    ABB() : Tree<Key>() {};
    ~ABB() {};
    bool Buscar(Key k) { return BuscarNodo(this->nodo, k); }
    bool Insert(Key k) {
      if (this->nodo == NULL) {
        this->nodo = new Node<Key>(k);
        return true;
      }
      
      return InsertNodo(this->nodo, k);
    }
};

template <class Key> 
bool ABB<Key>::BuscarNodo(Node<Key>*& nodo, const Key& clave_dada) {
  if (nodo == NULL) 
      return false;
    if (clave_dada == nodo->dato) 
      return true;
    if (clave_dada < nodo->dato)
      return BuscarNodo(nodo->left_, clave_dada);
    return BuscarNodo(nodo->right_, clave_dada);
}

template <class Key>
bool ABB<Key>::InsertNodo(Node<Key>*& nodo, const Key& clave_dada) {
  if (nodo == NULL) {
    nodo = new Node<Key>(clave_dada, NULL);
    return true;
  }
  else if (clave_dada < nodo->dato) {
    if (nodo->left_ == NULL){
      nodo->left_ = new Node<Key>(clave_dada, NULL);
      return true;
    }
    else {
      InsertNodo(nodo->left_, clave_dada);
    }
  }
  else {
    if (nodo->right_ == NULL){
      nodo->right_ = new Node<Key>(clave_dada, NULL);
      return true;
    }
    else {
      InsertNodo(nodo->right_, clave_dada);
    }
  }
  return true;
}