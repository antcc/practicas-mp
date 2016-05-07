#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time

using namespace std;

// Genera un valor del intervalo [minimo,maximo]
int Uniforme (int minimo, int maximo)
{
   double u01= std::rand()/(RAND_MAX+1.0); // Uniforme01
   return minimo+(maximo-minimo+1)*u01;
}

// Intercambia dos números en un vector de enteros
void Swap (int *p, int *q)
{
  int aux = *p;
  *p = *q;
  *q = aux;
}

void Generar (int *v, int n, int max)
{
  const int MAX = 2*n;  // por ejemplo

  for (int i = 0; i < n; i++)
    v[i] = i % max + 1;

  // barajar
  for (int i = 0; i < MAX; i++) {
    int j = Uniforme(0,n-1);
    int k = Uniforme(0,n-1);

    Swap(v+j, v+k);
  }
}


int Buscar(const int *v, int pos, int n, int dato)
{
   for (int i = pos; i < n; ++i)
      if (v[i] == dato)
         return i;
   return n;
}

// @pre: el dato está en el vector
int* BuscarGarantizada(int *inicial, int dato)
{
  int *p = inicial;
  while (*p != dato ) {
    p++;
  }

  return p;
}

void OrdenarInsercion (int *v, int n)
{
  if (n > 1) {
    int j;

    for (int i = 1; i < n; i++) {
      int aux = v[i];

      for (j = i; j > 0 && aux < v[j-1]; j--)
        v[j] = v[j-1];

      v[j] = aux;
    }
  }
}

// @pre: vector vec ordenado
int BusquedaBinariaRec (const int *vec, int n, int dato)
{
  if (n > 0) {
    int izq = 0, dcha = n-1;
    int centro = (izq+dcha)/2;

    if (vec[centro] > dato)
      dcha = centro-1;
    else if (vec[centro] < dato)
      izq = centro+1;
    else
      return centro;

    BusquedaBinariaRec(vec+izq, dcha-izq+1, dato);
  }

  return -1;
}

// FIXME 10: Modificar función para implementar interpolación
int BusquedaBinaria (const int *vec, int n, int dato)
{
   int izq= 0, der= n-1;

   while (izq<=der) {
   int centro= (izq+der) / 2;
   if (vec[centro] > dato)
      der= centro-1;
   else if (vec[centro] < dato)
            izq= centro+1;
         else return centro;
   }
   return -1;
}


int main(int argc, char *argv[])
{
   if (argc != 3) {
      cerr << "Uso: " << argv[0] << " <número de datos> <máximo dato>" <<endl;
      return 1;
   }

   srand(time(0)); // Inicializamos generador de números

   int n = atoi(argv[1]);
   if (n < 5) {
      cerr << "Debería especificar al menos 5 elementos" << endl;
      return 2;
   }
   else {

     int *v = new int[n+1];

      int max = atoi(argv[2]);
      Generar(v,n,max);
      cout << "Generados: ";
      for (int i=0;i<n;++i)
         cout << v[i] << " ";
      cout << endl;

      // ordenarlos
      OrdenarInsercion(v, n);
      cout << "Ordenados: ";
      for (int i=0;i<n;++i)
         cout << v[i] << " ";
      cout << endl;

      int dato;
      cout << "Introduzca un dato a buscar: ";
      cin >> dato;

      v[n] = dato;

      int *pos = BuscarGarantizada(v, dato);
      while (pos-v != n) {
        cout << " Encontrado en: " <<  (pos - v) << endl;
        pos = BuscarGarantizada(pos+1, dato);
      }

      int dato_bin;
      cout << "Introduce un dato a buscar con búsqueda binaria: ";
      cin >> dato_bin;

      int pos_bin = BusquedaBinariaRec(v, n, dato_bin);
      cout << " Encontrado en: " << pos_bin << endl;

      delete[] v;
      v = 0;

   }
}
