#include "avl.h"
using namespace std;

int main(int argc, char *argv[])
{
  ArbolAVL<int> dni;
  dni.Insert(20);
  dni.Insert(10);
  dni.Insert(15);

  dni.Mostrar();
  dni.print();
  std::cout << std::endl;
  return 0;
}