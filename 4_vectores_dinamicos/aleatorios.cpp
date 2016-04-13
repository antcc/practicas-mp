#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time

using namespace std;

int main(int argc, char *argv[])
{
   if (argc!=2) {
      cerr << "Uso: " << argv[0] << " <número de datos>" <<endl;
      return 1;
   }
   
   srand(time(0)); // Inicializamos generador de números
   
   int n= atoi(argv[1]);
   if (n>0) {
      for (int i=0;i<n;++i)
         cout << rand()%n << " "; // %n, por ejemplo
      cout << endl;
   }
}
  
  
