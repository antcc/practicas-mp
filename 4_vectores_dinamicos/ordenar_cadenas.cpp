#include <iostream>
#include <fstream>
#include <cstring> // strcmp, strlen

using namespace std;

struct ListadoNombres
{
   char** cadenas;
   int ncads;
};

// Suponemos las líneas son como mucho de 1024 caracteres
// Devuelve el puntero nulo si hay error.
// Recuerde que cin.getline "devuelve true" (realmente es el flujo) en caso de éxito
// FIXME 1: Crear función LeerLinea que lee una línea de un archivo, y devuelve un bloque
//          en memoria dinámica con una copia de la línea
char* LeerLinea(istream& flujo)
{
  char mensaje[1024];
  char* p = (flujo.getline(mensaje, 10) ? new char[strlen(mensaje)] : 0;

  return p;
}


// FIXME 2: Crear una función AddLineas
//          que usa LeerLinea para cargar un flujo en un ListadoNombres (ver main)
void AddLineas(ListadoNombres& lis, istream& flujo)
{
  char* c_aux = LeerLinea(flujo);

  while(c_aux)
  {
    int size_aux = lis.ncads;
    char** p_aux = new char*[size_aux + 1];

    for (int i = 0; i < size_aux; i++)
      p_aux[i] = lis.cadenas[i];

    p_aux[size_aux] = c_aux;
    Liberar(lis);
    lis.cadenas = p_aux;
    lis.ncads++;
    c_aux = LeerLinea(flujo);
  }
}

// Función auxiliar para OrdenarShell
int CalcularSaltoInicial(int n)
{
   int salto = 1;

   while (salto < n / 9)
      salto = salto * 3 + 1;

   return salto;
}

// FIXME 3: Implementar la función OrdenarShell
// cmp es como strcmp (devuelve un entero negativo, cero o positivo)
// Consultar OrdenarShell para enteros, que se ha entregado resuelta
void OrdenarShell (ListadoNombres& listado, int cmp(const char* s1, const char* s2)) // no entiendo cmp
{
  int size_aux = listado.ncads;

  for (int salto = CalcularSaltoInicial(size_aux); salto > 0; salto /= 3 )
  {
     for (int i = salto; i < size_aux; i++)
     {
        char** p_aux = listado.cadenas;
        char* x = p_aux[i];
        int j;

        for (j = i; j >= salto && *x < *(p_aux[j - salto]); j -= salto)
          p_aux[j] = p_aux[j - salto];

        p_aux[j] = x;
     }
  }
}

// FIXME 4: Crear una función que lista las líneas de un ListadoNombres (ver main)
void Mostrar(?? msg, ostream& flujo, const ListadoNombres& lista)
{
  flujo << msg;

  for (int i = 0; i < ncads; i++)
  {
    for (int j = 0, aux_size = strlen(lista.cadenas[i]); j < aux_size; j++)
      flujo << *(lista.cadenas[i] + j) //// lista.cadenas[i][j] ???

    flujo << "\n";
  }
}

// FIXME 5: Crear una función que libera un ListadoNombres (ver main)
void Liberar (ListadoNombres& lista)
{
  for (int i = 0; i < ncads; i++)
  {
    delete[] lista.cadenas[i];
  }

  delete[] lista.cadenas;
}

// La función main esta terminada, no se debe tocar
int main(int argc, char* argv[])
{
   ListadoNombres listado = {0,0};
   bool ordenar = false;

   if (argc == 1)
      AddLineas(cin, listado);
   else if (argc == 2)
   {
      ifstream f(argv[argc-1]);

      if (!f)
      {
         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
         return 1;
      }
      AddLineas(f, listado);
   }
   else
   {
      cerr << "Uso: " << argv[0] << " [<fichero>]" << endl;
      return 1;
   }

   Mostrar("Original:\n", cout, listado);
   OrdenarShell(listado, strcmp);
   Mostrar("\nResultado:\n", cout, listado);
   Liberar(listado); // Libera la memoria reservada
}
