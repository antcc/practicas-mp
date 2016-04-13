#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// FIXME 5: añadir un nuevo campo
struct VecDin {
   int* datos;
   int usados;
   int reservados;
};

// FIXME 1: Redimensions v para que se quede con "nuevo" elementos
// FIXME 5: tener en cuenta un nuevo campo en v
void ReSize(VecDin& v, int nuevo)
{
	if (nuevo > v.reservados)
	{
		int* p = new int[nuevo];

		for (int i = 0; i < v.usados; i++)
			p[i] = v.datos[i];

		delete[] v.datos;
		v.datos = p;
		v.usados = v.reservados = nuevo;
	}
	else
		v.usados = nuevo;
	
}

// FIXME 4: Añade un dato al final del vector
// FIXME 6: Mejora de eficiencia con reservados
void Add(VecDin& v, int dato)
{
	if (v.usados == v.reservados)
	{
		ReSize(v, 2 * v.reservados);
		ReSize(v, 0.5 * v.reservados + 1);
		v.datos[v.usados - 1] = dato;
	}
	else
	{
		ReSize(v, v.usados + 1);
		v.datos[v.usados - 1] = dato;
	}
}

// FIXME 2: Lee objetos int hasta final de flujo y devuelve VecDin con los datos (usa ReSize)
VecDin LeerVecDin(istream& flujo)
{
	VecDin vector = { 0, 0, 0 };
	int dato;

	while (flujo >> dato)
	{
		Add(vector, dato);
	}

	return vector;
}

// FIXME 3: Muestra en un flujo de salida los datos enteros de un VecDin (ver main)

void Mostrar(VecDin& v, ostream& flujo)
{
	for (int i = 0; i < v.usados; i++)
		flujo << v.datos[i] << " ";
}

// FIXME 3: Libera la memoria reservada en un VecDin (ver main)

void Liberar(VecDin& v)
{
	delete[] v.datos;
}


// FIXME 7: Ordena v con "Selección" implementado recursivo
void SeleccionRecursivo(int* v, int n)
{
	if (n > 1)
	{
		int menor = 0;

		for (int i = 0; i < n; i++)
			if (v[menor] > v[i])
				menor = i;

		int aux = v[0];
		v[0] = v[menor];
		v[menor] = aux;

		SeleccionRecursivo(v + 1, n - 1);
	}
	else
	{
		return;
	}
}

// FIXME 7: Usa SeleccionRecursivo para ordenar v
void Ordenar(VecDin& v)
{
	SeleccionRecursivo(v.datos, v.usados);
}


int main(int argc, char *argv[])
{
   VecDin v = {0, 0, 0};
   
   if (argc == 1)
      v = LeerVecDin(cin);
   else
   {
	   int nFichero = 1;
	   bool ordenar = false;

	   if (!strcmp(argv[1], "-s"))
	   {
		   nFichero = 2;
		   ordenar = true;
	   }
	   
	   ifstream f(argv[nFichero]);
	   
	   if (!f) 
	   {
		   cerr << "Error: Fichero " << argv[nFichero] << " no válido." << endl;
		   return 1;
	   }
	   
	   v = LeerVecDin(f);
	   
	   if (ordenar)
		   Ordenar(v);
   }

   Mostrar(v, cout);
   Liberar(v);
}  
