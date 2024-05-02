#include "node.h"

template <class Key>
class Tree {
  protected:
		Node<Key>* nodo;
  public:
    Tree() : nodo{NULL} {}
    virtual ~Tree() {
			if (nodo == NULL) {
				delete nodo;       // Eliminar nodo
			}
    }
		const int Tam() { return TamRama(nodo); }
		const int TamRama(Node<Key>* nodo);

		virtual bool Insert(Key) = 0;
		virtual bool Buscar(Key) = 0;
		virtual void Mostrar() { 
			MostrarInOrder(nodo);
			std::cout << std::endl; 
		}

		virtual void MostrarInOrder(Node<Key>*& nodo) {
			if (nodo == NULL) return;
			MostrarInOrder(nodo->left_);
			std::cout << (nodo->dato) << " ";
			MostrarInOrder(nodo->right_);
		}
};

template <class Key>
const int Tree<Key>::TamRama(Node<Key>* nodo) {
	if (nodo == NULL) return 0 ;
	return (1 + TamRama(nodo->left_) + TamRama(nodo->right_) );
}