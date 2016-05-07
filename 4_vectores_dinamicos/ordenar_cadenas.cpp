#include <iostream>
#include <fstream>
#include <cstring> // strcmp, strlen

using namespace std;

struct ListadoNombres {
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
}



// FIXME 2: Crear una función AddLineas 
//          que usa LeerLinea para cargar un flujo en un ListadoNombres (ver main)





// Función auxiliar para OrdenarShell
int CalcularSaltoInicial(int n)
{
   int salto= 1;
   while (salto<n/9)
      salto= salto*3+1;
   return salto;
}
// FIXME 3: Implementar la función OrdenarShell
// cmp es como strcmp (devuelve un entero negativo, cero o positivo)
// Consultar OrdenarShell para enteros, que se ha entregado resuelta
void OrdenarShell (ListadoNombres& listado, int cmp(const char* s1, const char* s2))
{
}



// FIXME 4: Crear una función que lista las líneas de un ListadoNombres (ver main)




// FIXME 5: Crear una función que libera un ListadoNombres (ver main)


// La función main esta terminada, no se debe tocar
int main(int argc, char* argv[])
{
   ListadoNombres listado= {0,0};
   bool ordenar= false;
   
   if (argc==1)
      AddLineas(cin, listado);
   else if (argc==2) {
      ifstream f(argv[argc-1]);
      if (!f) {
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
