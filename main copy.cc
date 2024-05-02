#include "avl.h"
using namespace std;

int main(int argc, char* argv[]) {
  string tipoArbol;
  string metodoInicializacion;
  int numElementos = 0;
  string nombreArchivo;
  int end = 0;
  int elementos = 1;
  ABB<int> tree;
  int eleccion;

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

  std::cout << "\n<<< MENU >>>\n";
  std::cout << " [0] Salir\n [1] Insertar clave\n [2] Buscar clave\n [3] Mostrar árbol inorden\n";

  while (end == 0) {

    if (tipoArbol == "abb") {
      ABB<int> tree;
    }
    if (metodoInicializacion == "manual") {
      while (elementos != 0) {
        std::cin >> elementos;
        tree.Insert(elementos);
      }
    }

    std::cout << "\n<<< MENU >>>\n";
    std::cout << " [0] Salir\n [1] Insertar clave\n [2] Buscar clave\n [3] Mostrar árbol inorden\n";
    std::cin >> eleccion; 
    if (eleccion == 0) { return 0; }
    if (eleccion == 1) { 
      std::cout << "Inserte número: ";
      std::cin >> elementos;
      tree.Insert(elementos);
    }
    if (eleccion == 2) {
      std::cout << "Inserte número: ";
      std::cin >> elementos;
      tree.Buscar(elementos);
    }
    if (eleccion == 3) {
      tree.Mostrar();
    }
  }
  
  return 0;
}