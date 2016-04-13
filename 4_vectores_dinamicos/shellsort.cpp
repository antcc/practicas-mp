#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time

using namespace std;

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
   double u01= std::rand() / (RAND_MAX+1.0); // Uniforme01
   return minimo + (maximo-minimo+1) * u01;
}

// Rellena el vector con n enteros del 1 a max y los mezcla
void Generar(int* v, int n, int max)
{
   for (int i=0; i<n; ++i) {
      v[i]= i%max+1;
   }
   int pos1, pos2;
   for (int i=0; i<10*n; ++i) {
      pos1= Uniforme(0,n-1);
      pos2= Uniforme(0,n-1);
      int aux= v[pos1];
      v[pos1]= v[pos2];
      v[pos2]= aux;
   }
}

// ----------------------

int CalcularSaltoInicial(int n)
{
   int salto= 1;
   while (salto<n/9)
      salto= salto*3+1;
   return salto;
}

void OrdenarShell (int vector[], int n)
{
   for (int salto= CalcularSaltoInicial(n); salto>0; salto= salto/3) {
      // Aplicamos Inserción a cada vector que empieza en v+salto de salto en salto
      for (int i=salto; i<n; ++i) { // Los va procesando todos los v-saltos a la vez
         int x= vector[i];
         int j;
         for (j=i; j>=salto && x<vector[j-salto]; j=j-salto)
         vector[j]= vector[j-salto];
         vector[j]= x;
      }
   }
}

/* // Función para ojear la relación del shell con el de Inserción.
void OrdenarInsercion (int vector[], int n)
{
  for (int i=1;i<n;++i){
    int x= vector[i];
    int j;
    for (j=i;j>0 && x<vector[j-1];--j) 
      vector[j]= vector[j-1];
    vector[j]= x;
  }
}
*/

// ----------------------


void Mostrar(const char* cabecera, const int vec[], int n)
{
   cout << cabecera;
   for (int i=0; i<n; ++i)
         cout << vec[i] << " "; 
   cout << endl;
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
      
      int* v= new int[n];
      Generar(v,n,max);
      
      Mostrar("Generados: ", v,n);
      OrdenarShell(v, n);
      Mostrar("Ordenados: ", v,n);
      
      delete[] v;
      
   }
}
  
  