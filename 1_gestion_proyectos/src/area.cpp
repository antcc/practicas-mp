/**
  * @file area.cpp
  * @brief Calcula el área de un círculo leído desde la entrada estándar
  * @author Miguel Lentisco & Antonio Coín
  *
  * Un ejemplo de ejecución es:
  *   Introduzca un círculo con el formato radio-(x,y): 2-(0,1)
  *   El área del círculo es: 12.5664
  */

#include <iostream>
#include "circle.h"
using namespace std;

int main()
{
	cout << "Introduzca un círculo con el formato radio-(x,y): ";
	Circle c = ReadCircle();
	cout << "El área del círculo es: " << Area( c ) << endl;
}
