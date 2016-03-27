/**
  * @file central.cpp
  * @brief Calcula círculo con centro en medio de dos círculos y radio la mitad de la distancia
  * @author Agarrido
  *
  * Un ejemplo de ejecución es:
  *   Introduzca un circulo en formato radio-(x,y): 3-(0,0)
  *   Introduzca otro circulo: 4-(5,0)
  *   El círculo que pasa por los dos centros es: 2.5-(2.5,0)
  */

#include <iostream>
#include "circle.h"
using namespace std;

int main()
{
  Circle c1,c2;

  do
  {
   cout << "Introduzca un circulo en formato radio-(x,y): ";
   c1 = ReadCircle();
   cout << "Introduzca otro circulo: ";
   c2 = ReadCircle();
  } while ( Distance( GetCenter( c1 ), GetCenter( c2 ) ) == 0 );

  Circle res;

  InitCircle( res, MiddlePoint( GetCenter( c1 ), GetCenter( c2 ) ),
              Distance( GetCenter( c1 ), GetCenter( c2 ) ) / 2 );

  cout << "El círculo que pasa por los dos centros es: ";
  WriteCircle( res );
  cout << endl;
}
