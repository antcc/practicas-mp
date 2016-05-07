#include <iostream>
#include <fstream> // ifstream
#include <cstring> // strcmp
using namespace std;

struct VecDin {
   int *datos;
   int usados;
   int reservados;
};

void ReSize(VecDin& v, int nuevo)
{
  if (nuevo > v.reservados) {
    int *p = new int[nuevo];

    for (int i = 0; i < v.usados; i++)
      p[i] = v.datos[i];

    delete[] v.datos;
    v.datos = p;
    v.reservados = nuevo;
  }

  v.usados = nuevo;
}

void Add(VecDin& v, int dato)
{
  if (v.usados < v.reservados)
    ReSize(v, v.usados + 1);
  else {
    ReSize(v, 2 * v.reservados);
    ReSize(v, (v.usados / 2) + 1);
  }

  v.datos[v.usados - 1] = dato;
}

VecDin LeerVecDin(istream& is)
{
  VecDin v = {0,0,0};

  int dato;
  while (is >> dato) {
    Add(v, dato);
  }

  return v;
}

void Mostrar(VecDin v, ostream& os)
{
  for (int i = 0; i < v.usados; i++)
    os << v.datos[i] << " ";
  os << "\n";
}

void Liberar(VecDin& v)
{
  delete[] v.datos;
  v.datos = 0;
  v.usados = 0;
}

// Intercambia dos números en un vector de enteros
void Swap (int *p, int *q)
{
  int aux = *p;
  *p = *q;
  *q = aux;
}


void SeleccionRecursivo(int *v, int n)
{
  if (n > 1) {
    int pos_min = 0;

    for (int i = 1; i < n; i++) {
      if (v[i] < v[pos_min])
        pos_min = i;
    }

    if (pos_min != 0)
      Swap(v+pos_min, v);

    SeleccionRecursivo(v+1, n-1);
  }
}

void Ordenar(VecDin& v)
{
  SeleccionRecursivo(v.datos, v.usados);
}


int main(int argc, char *argv[])
{
   VecDin v = {0,0,0};
   bool ordenar = false;

   if (argc == 1)
     v = LeerVecDin(cin);

   else if (argc == 2) {
     if (!strcmp(argv[1],"-s")) {
       v = LeerVecDin(cin);
       ordenar = true;
     }
     else {
      ifstream f(argv[1]);
      if (!f) {
         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
         return 1;
      }
      v = LeerVecDin(f);
   }
 }

   else {
      ordenar = !strcmp(argv[1], "-s");
      if (!ordenar) {
        cerr << "Error: Argumento incorrecto." << endl;
        return 2;
      }
      else {
      ifstream f(argv[2]);
      if (!f) {
         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
         return 1;
      }
      v = LeerVecDin(f);
    }
   }

   if (ordenar)
    Ordenar(v);
   Mostrar(v,cout);
   Liberar(v); // Libera la memoria reservada
}
