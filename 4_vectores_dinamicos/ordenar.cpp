#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time
#include <iomanip> // setw

using namespace std;

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
   double u01= std::rand() / (RAND_MAX+1.0); // Uniforme01
   return minimo + (maximo-minimo+1) * u01;
}

void Generar(int *v, int n, int max)
{
   for (int i=0;i<n;++i) {
      v[i]=i%max+1;
   }
   int pos1,pos2;
   for (int i=0; i<10*n; ++i) {
      pos1= Uniforme(0,n-1);
      pos2= Uniforme(0,n-1);
      int aux= v[pos1];
      v[pos1]= v[pos2];
      v[pos2]= aux;
   }
}

// FIXME 1: Mejora el algoritmo de burbuja para el caso de vector casi-ordenado
// FIXME 2: Modificar el algoritmo anterior para realizar una ordenación bidireccional
// FIXME 5: Parametrizar el método de ordenación. Generar el último listado con otro orden.
void OrdenarBurbuja (int vec[], int n)
{
   for (int i=n-1; i>0; --i) 
      for (int j=0; j<i; ++j)
         if (vec[j] > vec[j+1]) {
            int aux = vec[j];
            vec[j]  = vec[j+1];
            vec[j+1]= aux;
         }
}
// FIXME 5: Añadir posibles formas de ordenación para parámetro de OrdenarBurbuja

// FIXME 3: Incluir función que ordena punteros a los datos


int main(int argc, char *argv[])
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
      int *v= new int[n];
      
      Generar(v,n,max);
      
      // FIXME 4: Imprimir los generados ordenados usando punteros
      
      cout << "Generados: ";
      for (int i=0; i<n; ++i)
         cout <<  setw(3) << v[i] << " "; 
      cout << endl;
      
      // FIXME 5: Cambiar la llamada para usar el parámetro
      OrdenarBurbuja(v,n);
      
      cout << "Ordenados: ";
      for (int i=0; i<n; ++i)
         cout <<  setw(3) << v[i] << " "; 
      cout << endl;
      
      //FIXME 4: Imprimir el salto en posiciones de cada elemento
      
      delete[] v;
      
   }
}
  
  