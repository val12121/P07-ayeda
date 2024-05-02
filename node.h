#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class Key>
class Node {
  public:
  // Constructor:
  Node(const Key& dat, Node<Key>* left=NULL,Node<Key>* right=NULL) : dato(dat), left_(left), right_(right) {}
  virtual ~Node() {
    if (left_ != NULL) {
      delete left_;
    }
    if (right_ != NULL) {
      delete right_;
    }
  }         
  // Miembros:
  Key dato;   	
  Node<Key>* left_; 	
  Node<Key>* right_;
};

#endif