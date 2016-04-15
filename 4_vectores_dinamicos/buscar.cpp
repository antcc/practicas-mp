#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time

using namespace std;

void Intercambiar (int* v, int n, int m)
{
	int aux = v[n];
	v[n] = v[m];
	v[m] = aux;
}

void Intercambiar (int* n, int* m)
{
	int aux = &n;
	&n = &m;
	&m = aux;
}

// Genera un valor del intervalo [minimo,maximo]
int Uniforme (int minimo, int maximo)
{
   double u01 = std::rand() / (RAND_MAX + 1.0); // Uniforme01
   return minimo + (maximo - minimo + 1) * u01;
}

// FIXME 1: Rellena el vector con n enteros del 1 a max y los mezcla (ver main)
void Generar (int* v, int n, int max)
{
	for (int i = 0; i < n; i++)
			// O begin[i] = i % max + 1; pero así es mas aleatorio (?)
			v[i] = Uniforme(1, max);

	for (int i = 0; i < n * 10; i++)
		// Intecambia posiciones
		Intercambiar(v, Uniforme(0, n - 1), Uniforme(0, n - 1));
}


// FIXME 4: Cambio de interfaz, devolviendo n si no está.
int Buscar (const int* v, int pos, int n, int dato)
{
   for (int i = pos; i < n; i++)
      if (v[i] == dato)
         return i;

   return n;
}

// FIXME 5: Implementar búsqueda garantizada. Pre: el dato está
// FIXME 7: Cambiar la interfaz de la función
int* BuscarGarantizada (const int* inicial, int dato)
{
	int* p = inicial;

	while (&p != dato)
		p++;

	return p;
}


// FIXME 8: Incluir algoritmo OrdenarInsercion
void OrdenarInsercion (int* v, int n)
{
	if (n > 1)
	{
		int* min = v;

		for (int* i = v; i < n + v; i++)
			if (&min > &i)
				min = i;

		Intercambiar(v, min);
		OrdenarInsercion(v + 1, n - 1);
	}
}
// FIXME 9: Incluir búsqueda binaria recursiva
int BusquedaBinariaRec(const int* vec, int n, int dato)
{
	int izq = 0, der = n - 1;

	if (izq <= der)
	{
		int centro = (izq + der) / 2;

		if (vec[centro] > dato)
			return BusquedaBinariaRec(vec, centro, dato);
		else if (vec[centro] < dato)
			return BusquedaBinariaRec(vec + centro, centro, dato);
		else
			return centro;
	}

	return -1;
}
// FIXME 10: Modificar función para implementar interpolación
int BusquedaBinariaInterp(const int* vec, int n, int dato)
{
	int izq = 0, der = n - 1;

	while (izq <= der)
	{
		int pos = izq + ((dato - vec[izq]) / (vec[der] - vec[izq])) * (der - izq);

		if (vec[pos]) > dato)
		der = pos - 1;
		else if (vec[pos] < dato)
			izq = pos + 1;
		else
			return pos;
	}

	return -1;
}

int main (int argc, char* argv[])
{
   if (argc != 3)
   {
	   cerr << "Uso: " << argv[0] << " <número de datos> <máximo dato>" << endl;
	   return 1;
   }

   srand(time(0)); // Inicializamos generador de números

   int n = atoi(argv[1]);

   if (n < 5)
   {
      cerr << "Debería especificar al menos 5 elementos" << endl;
      return 2;
   }
   else
   {
      // FIXME 1: prepara el vector v
	  // FIXME 6: reservar una posición más para garantizar la búsqueda
	   int* v = new int[n + 1];
	   int max = atoi(argc[2]);

	   Generar(v, n, max);
	   cout << "Generados: ";

	   for (int i = 0; i < n; i++)
		   cout << v[i] << " ";

		cout << endl;

		// FIXME 8: Ordenar el vector con OrdenarInsercion y listarlos
		cout << "Ordenados: ";
		OrdenarInsercion(v, n);


		// FIXME 2: Pregunta por dato a buscar y lo localiza
		// FIXME 3: Modificación para localizar todas las ocurrencias
		// Se añade otro parámetro? El guión lo dice pero no me queda claro
		// Al usar la otra función, ya no sale en el main la antigua

		int dato;

		cout << "Introduzca un dato a buscar: ";
		cin >> dato;

		// FIXME 6: Colocar el dato en la posición detrás de la última
		// FIXME 7: Cambiar a la nueva interfaz de la búsqueda
		int* ult_pos = v + n;
		&ult_post = dato;
		int* pos = BuscarGarantizada(v, dato);

		while (pos != ult_post)
		{
			cout << "\n Encontrado en: " << (pos - v);
			pos = BusquedaGarantizada(pos + 1, dato);
		}

		// FIXME 9: Preguntar por búsqueda binaria y resolver la posición
		cout << "\nIntroduzca un dato a buscar binario: ";
		cin >> dato;
		cout << "\n Encontrado en: " << BusquedaBinariaRec(v, n, dato);

		// FIXME 1: deja de usarse v
		delete[] v;
   }
}
