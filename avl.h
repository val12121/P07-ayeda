#include "node_avl.h"
#include "abb.h"
#include <queue>

template <class Key>
class ArbolAVL : public ABB<Key>
{
private:
  nodoAVL<Key> *raiz;
  bool BuscarNodo(nodoAVL<Key> *&nodo, const Key &clave_dada);

public:
  ArbolAVL() : ABB<Key>(), raiz{NULL} {}
  ~ArbolAVL()
  {
    if (raiz != NULL)
    {
      delete raiz;
      raiz = NULL;
    }
  }
  bool Buscar(Key k) { return BuscarNodo(this->raiz, k); }
  bool Insert(Key k)
  {
    if (Buscar(k))
    {
      return false;
    }

    if (this->raiz == NULL)
    {
      this->raiz = new nodoAVL<Key>(k);
      return true;
    }
    nodoAVL<Key> *nuevo = new nodoAVL<Key>(k, 0);
    bool crece = false;
    return inserta_bal(raiz, nuevo, crece);
  }

  bool inserta_bal(nodoAVL<Key> *&nodo, nodoAVL<Key> *&nuevo, bool &crece);

  void rotacion_II(nodoAVL<Key> *&nodo);
  void rotacion_DI(nodoAVL<Key> *&nodo);
  void rotacion_ID(nodoAVL<Key> *&nodo);
  void rotacion_DD(nodoAVL<Key> *&nodo);

  void insert_re_balancea_izda(nodoAVL<Key> *&nodo, bool &crece);
  void insert_re_balancea_dcha(nodoAVL<Key> *&nodo, bool &crece);

  void print() const;

  virtual void Mostrar()
  {
    MostrarInOrder(raiz);
    std::cout << std::endl;
  }

  virtual void MostrarInOrder(nodoAVL<Key> *&nodo)
  {
    if (nodo == NULL)
      return;
    MostrarInOrder(nodo->izdo);
    std::cout << (nodo->dato) << " ";
    MostrarInOrder(nodo->dcho);
  }
};

template <class Key>
bool ArbolAVL<Key>::BuscarNodo(nodoAVL<Key> *&nodo, const Key &clave_dada)
{
  if (nodo == NULL)
    return false;
  if (clave_dada == nodo->dato)
    return true;
  if (clave_dada < nodo->dato)
    return BuscarNodo(nodo->izdo, clave_dada);
  return BuscarNodo(nodo->dcho, clave_dada);
}

template <class Key>
bool ArbolAVL<Key>::inserta_bal(nodoAVL<Key> *&nodo,
                                nodoAVL<Key> *&nuevo, bool &crece)
{
  if (nodo == NULL)
  {
    nodo = nuevo;
    crece = true;
  }
  else if (nuevo->dato < nodo->dato)
  {
    inserta_bal(nodo->izdo, nuevo, crece);
    if (crece)
      insert_re_balancea_izda(nodo, crece);
  }
  else
  {
    inserta_bal(nodo->dcho, nuevo, crece);
    if (crece)
      insert_re_balancea_dcha(nodo, crece);
  }
  return true;
}

template <class Key>
void ArbolAVL<Key>::rotacion_II(nodoAVL<Key> *&nodo)
{
  nodoAVL<Key>* nodo1 = nodo->izdo;
  nodo->izdo = nodo1->dcho;
  nodo1->dcho = nodo;
  if (nodo1->bal == 1)
  {
    nodo->bal = 0;
    nodo1->bal = 0;
  }
  else
  { // nodo1->bal == 0
    nodo->bal = 1;
    nodo1->bal = -1;
  }
  nodo = nodo1;
}

template <class Key>
void ArbolAVL<Key>::rotacion_DD(nodoAVL<Key> *&nodo)
{
  nodoAVL<Key>* nodo1 = nodo->dcho;
  nodo->dcho = nodo1->izdo;
  nodo1->izdo = nodo;
  if (nodo1->bal == -1)
  {
    nodo->bal = 0;
    nodo1->bal = 0;
  }
  else
  { // nodo1->bal == 0
    nodo->bal = -1;
    nodo1->bal = 1;
  }
  nodo = nodo1;
}

template <class Key>
void ArbolAVL<Key>::rotacion_ID(nodoAVL<Key> *&nodo)
{
  nodoAVL<Key> *nodo1 = nodo->izdo;
  nodoAVL<Key> *nodo2 = nodo1->dcho;
  nodo->izdo = nodo2->dcho;
  nodo2->dcho = nodo;
  nodo1->dcho = nodo2->izdo;
  nodo2->izdo = nodo1;
  if (nodo2->bal == -1)
    nodo1->bal = 1;
  else
    nodo1->bal = 0;
  if (nodo2->bal == 1)
    nodo->bal = -1;
  else
    nodo->bal = 0;
  nodo2->bal = 0;
  nodo = nodo2;
}

template <class Key>
void ArbolAVL<Key>::rotacion_DI(nodoAVL<Key> *&nodo)
{
  nodoAVL<Key> *nodo1 = nodo->dcho;
  nodoAVL<Key> *nodo2 = nodo1->izdo;
  nodo->dcho = nodo2->izdo;
  nodo2->izdo = nodo;
  nodo1->izdo = nodo2->dcho;
  nodo2->dcho = nodo1;
  if (nodo2->bal == 1)
    nodo1->bal = -1;
  else
    nodo1->bal = 0;
  if (nodo2->bal == -1)
    nodo->bal = 1;
  else
  {
    nodo->bal = 0;
    nodo2->bal = 0;
    nodo = nodo2;
  }
}

template <class Key>
void ArbolAVL<Key>::insert_re_balancea_izda(
    nodoAVL<Key> *&nodo, bool &crece)
{
  switch (nodo->bal)
  {
  case -1:
    nodo->bal = 0;
    crece = false;
    break;
  case 0:
    nodo->bal = 1;
    break;
  case 1:
    nodoAVL<Key> *nodo1 = nodo->izdo;
    if (nodo1->bal == 1)
      rotacion_II(nodo);
    else
      rotacion_ID(nodo);
    crece = false;
  }
}

template <class Key>
void ArbolAVL<Key>::insert_re_balancea_dcha(
    nodoAVL<Key> *&nodo, bool &crece)
{
  switch (nodo->bal)
  {
  case 1:
    nodo->bal = 0;
    crece = false;
    break;
  case 0:
    nodo->bal = -1;
    break;
  case -1:
    nodoAVL<Key> *nodo1 = nodo->dcho;
    if (nodo1->bal == -1)
      rotacion_DD(nodo);
    else
      rotacion_DI(nodo);
    crece = false;
  }
}

template <class Key>
void ArbolAVL<Key>::print() const
{
  std::queue<nodoAVL<Key> *> nodes;
  nodes.push(raiz);
  int level{0};
  int counter{0};
  int max_iterations{1};
  while (!nodes.empty())
  {
    if (counter == max_iterations - 1)
    {
      std::cout << "\nNivel " << level << ": ";
      ++level;
      max_iterations *= 2;
    }
    if (nodes.front() == NULL)
    {
      std::cout << "[.]";
      nodes.pop();
      std::queue<nodoAVL<Key> *> aux = nodes;
      bool finish{1};
      while (!aux.empty() && finish)
      {
        if (aux.front() != NULL)
        {
          finish = 0;
        }
        aux.pop();
      }
      if (!finish)
      {
        nodes.push(NULL);
        nodes.push(NULL);
      }
    }
    else
    {
      nodoAVL<Key> *node = nodes.front();
      nodes.pop();
      std::cout << "[" << node->dato << "]" << "(" << node->bal << ")";
      nodes.push(node->izdo);
      nodes.push(node->dcho);
    }
    ++counter;
  }
}