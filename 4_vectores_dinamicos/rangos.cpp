#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time
#include <iomanip> // setw

using namespace std;

// Genera un valor del intervalo [minimo,maximo]
inline
int Uniforme(int minimo, int maximo)
{
   double u01= std::rand() / (RAND_MAX+1.0); // Uniforme01
   return minimo + (maximo-minimo+1) * u01;
}

inline
void Intercambiar(int& a, int& b)
{
   int aux(a);
   a=b;
   b=aux;
}
  
void Generar(int* begin, int* end, int max)
{
   int n= end-begin;

   for (int i=0;i<n;++i)
      begin[i]=i%max+1;

   int *pos1,*pos2;
   for (int i=0;i<10*n;++i) {
      pos1= begin+Uniforme(0,n-1);
      pos2= begin+Uniforme(0,n-1);
      Intercambiar(*pos1,*pos2);
   }
}

void Mostrar(const char* cabecera, const int* begin, const int* end)
{
   cout << cabecera;
   while (begin!=end)
      cout << *begin++ << " ";
   cout << endl;
}


// FIXME 1: Busca un dato en el rango [begin,end)
int* Buscar(int* begin, int* end, int dato)
{
}


void OrdenarGnomo (int vec[], int n)
{
   int i= 1;
   while (i<n) { // Mientras no nos salimos por la derecha
      if (vec[i-1]<=vec[i])
         i++;
      else {
         Intercambiar(vec[i-1],vec[i]);
         if (i>0) i--;
      }
   }
}

// FIXME 2: Crear una función OrdenarGnomo que recibe un rango que ordenar






void Doble(int& d)
{
   d*= 2;
}

// FIXME 3: Crear una función Transformar que recibe un rango y una función con la que transformar cada dato.






// FIXME 4: Mezclar dos rangos en otro. Se supone que hay espacio
void Mezclar(const int* b1, const int* e1, 
             const int* b2, const int* e2, int* begin)
{
}


int main(int argc, char* argv[])
{
   if (argc!=3) {
      cerr << "Uso: " << argv[0] << " <número de datos> <máximo dato>" <<endl;
      return 1;
   }
   
   srand(time(0)); // Inicializamos generador de números
   
   int n= atoi(argv[1]);
   if (n<5) {
      cerr << "Debería especificar al menos 5 elementos" << endl;
      return 2;
   }
   else {
      int max= atoi(argv[2]);
      if (max<5) {
         cerr << "Debería especificar un max de al menos 5" << endl;
         return 3;
      }
      int* v1= new int[n];
      
      Generar(v1,v1+n,max);
      Mostrar("Generados: ",v1,v1+n);
      
      // FIXME 1: Pregunta por dato a buscar y localizar todas las ocurrencias


      OrdenarGnomo(v1,n);
      Mostrar("Ordenados: ",v1,v1+n);

      int* v2= new int[n];
      Generar(v2,v2+n,max);
      Mostrar("Segundo v: ",v2,v2+n);
      
      // FIXME 2: Llamar a OrdenarGnomo con un rango para ordenar v2 y mostrar el resultado
      
      
      // FIXME 3: Transformar v2 con la función "Doble"


      // FIXME 4: Mezclar v1,v2 en v3 y presentar el resultado

      
      
      delete[] v2;
      delete[] v1;
   }
}
  
  