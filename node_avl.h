#include "node.h"

template <class Key>
class nodoAVL : public Node<Key> {
public:
  // Constructor:
  nodoAVL(int dat, nodoAVL<Key> *iz = NULL,
          nodoAVL<Key> *de = NULL) : Node<Key>(dat), dato(dat), bal(0), izdo(iz), dcho(de) {}
  ~nodoAVL() {
    if (izdo != NULL) {
      delete izdo;
      izdo = NULL;
    }
    if (dcho != NULL) {
      delete dcho;
      dcho = NULL;
    }
  }
  // Miembros:
  int dato;
  int bal;
  nodoAVL<Key> *izdo;
  nodoAVL<Key> *dcho;
  
};
