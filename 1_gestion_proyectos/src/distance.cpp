/**
  * @file distance.cpp
  * @brief Calcula la longitud total de un trayecto determinado por una secuencia de dos o más puntos
  * @author Miguel Lentisco & Antonio Coín
  */

#include <iostream>
#include <fstream>
#include "point.h"

using namespace std;

/**
  * @brief Elimina comentarios de un archivo de cara a una posterior lectura del contenido
  * @pre Los comentarios comienzan con '#' y acaban al final de línea
  */
void EraseComment ( istream& is )
{
  // Avanzamos hasta encontrar algo distinto a un blanco o el carácter '#'
  while ( isspace( is.peek() ) || is.peek() == '#' )
  {
    if (is.peek() == '#')
      is.ignore( 1024, '\n' );  // Suponemos que las líneas tienen menos de 1024 caracteres
    else
      is.ignore();
  }
}

/**
  * @brief Calcula la distancia total de un trayecto, leyendo la secuencia de puntos que lo determinan
  * con ReadPoint
  * @param Flujo de entrada de datos (is)
  */
double TotalDistance ( istream& is )
{
  double distance;
  Point p[2];

  // Leemos el primer punto, eliminando comentarios
  EraseComment( is );
  ReadPoint( is, p[0] );
  EraseComment ( is );

  while ( ReadPoint( is, p[1] ) )
  {
    distance += Distance (p[0], p[1]);
    p[0] = p[1];
    EraseComment( is );
  }

  return distance;
}

int main( int argc, char* argv[] )
{
  double total_distance;
  bool input_finished;

  if (argc == 1){ // Si no se ha introducido el nombre del archivo como parámetro
    total_distance = TotalDistance( cin );
    input_finished = cin.eof();   // Comprueba si se ha leído hasta el final
  }
  else {
    ifstream f(argv[1]);

    if (!f) {
      cerr << "No se puede abrir el archivo " << argv[1] << endl;
      return 1;   // Forzamos el cierre, devolviendo al sistema un error
    }

    total_distance = TotalDistance( f );
    input_finished = f.eof();
  }

  if (!input_finished) {
    cerr << "Error inesperado: no se han podido leer todos los datos." << endl;
    return 1;
  }

  cout << "La distancia total del trayecto es: " << total_distance << endl;
}
