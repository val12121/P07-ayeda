#include "avl.h"
using namespace std;

void Menu() {
  std::cout << "\n<<< MENU >>>\n";
  std::cout << " [0] Salir\n [1] Insertar clave\n [2] Buscar clave\n [3] Mostrar árbol inorden\n";
}

int main(int argc, char *argv[])
{
  ArbolAVL<int> dni;
  //dni.Insert(20);
  //dni.Insert(10);
  //dni.Insert(15);

  //dni.Mostrar();
  //dni.print();
  //std::cout << std::endl;

  string tipoArbol;
  string metodoInicializacion;
  int numElementos = 0;
  string nombreArchivo;
  int end = 0;
  int elementos = 1;
  ABB<int> tree;
  ArbolAVL<int> tree_avl;
  int eleccion;
  std::string traza;
  int counter = 0;

  // Leer las opciones de la línea de comandos
  for (int i = 1; i < argc; ++i) {
    string opcion = argv[i];
    if (opcion == "-ab") {
      if (i + 1 < argc) {
        tipoArbol = argv[i + 1];
        ++i;
      }
    } else if (opcion == "-init") {
      if (i + 1 < argc) {
        metodoInicializacion = argv[i + 1];
        ++i;
      }
      if (i + 1 < argc && metodoInicializacion != "manual") {
        numElementos = stoi(argv[i + 1]);
        ++i;
      }
      if (i + 1 < argc && metodoInicializacion == "file") {
        nombreArchivo = argv[i + 1];
        ++i;
      }
    }
  }

  // Mostrar las opciones seleccionadas
  cout << "Tipo de árbol: " << tipoArbol << endl;
  cout << "Método de inicialización: " << metodoInicializacion << endl;
  if (metodoInicializacion != "manual")
    cout << "Número de elementos: " << numElementos << endl;
  if (metodoInicializacion == "file")
    cout << "Nombre del archivo: " << nombreArchivo << endl;

  Menu();

  while (end == 0) {

    if (tipoArbol == "abb") {
    }
    else if (tipoArbol == "avl") {
    }
    if (metodoInicializacion == "manual") {
      while (elementos != 0) { 
        if (tipoArbol == "abb") {
          std::cin >> elementos;
          tree.Insert(elementos);
        } else if (tipoArbol == "avl") {
          std::cin >> elementos;
          tree_avl.Insert(elementos);
        }
      }
    }
    if (metodoInicializacion == "random") {
      elementos = 1;
      
      std::cout << "Introduzca número de elementos: ";
      std::cin >> numElementos;
      while (counter != numElementos) {
        elementos = rand() % numElementos * 10;
        if (!tree.Buscar(elementos)) {
          if (tipoArbol == "abb") {
            counter++;
            tree.Insert(elementos);
          }
          else if (tipoArbol == "avl") {
            counter++;
            tree_avl.Insert(elementos);
          }
        }
      }
    }

    std::cin >> eleccion; 
    if (eleccion == 0) { return 0; }
    if (eleccion == 1) { 
      std::cout << "Inserte número: ";
      if (tipoArbol == "abb") {
        std::cin >> elementos;
        tree.Insert(elementos);
      }
      else if (tipoArbol == "avl") {
        std::cin >> elementos;
        tree_avl.Insert(elementos);
      }
    }
    if (eleccion == 2) {
      std::cout << "Inserte número: ";
      std::cin >> elementos;
      if (tipoArbol == "abb") {
        if (tree.Buscar(elementos)) {
          std::cout << "Elemento encontrado\n";
        } else {
          std::cout << "Elemento no encontrado\n";
        }
      }
      if (tipoArbol == "avl") {
        if (tree_avl.Buscar(elementos)) {
          std::cout << "Elemento encontrado\n";
        } else {
          std::cout << "Elemento no encontrado\n";
        }
      }
    }
    if (eleccion == 3 && tipoArbol == "abb" || tipoArbol == "abe") {
      tree.Mostrar();
    }
    else if (eleccion == 3 && tipoArbol == "avl") {
      tree_avl.print();
    }
    std::cout << std::endl;
    cout << "Tipo de árbol: " << tipoArbol << endl;
    cout << "Método de inicialización: " << metodoInicializacion << endl;
    if (metodoInicializacion != "manual")
      cout << "Número de elementos: " << numElementos << endl;
    if (metodoInicializacion == "file")
      cout << "Nombre del archivo: " << nombreArchivo << endl;
  }
  
  return 0;
}