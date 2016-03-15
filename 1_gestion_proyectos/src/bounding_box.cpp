/**
  * @file bounding_box.cpp
  * @brief Calcula el rectángulo delimitador más pequeño de una nube de puntos
  * @author Miguel Lentisco & Antonio Coín
  */

#include <iostream>
#include <fstream>
#include <limits>
#include "rectangle.h"

using namespace std;

/**
  * @brief Elimina comentarios de un archivo de cara a una posterior lectura del contenido
  * @pre Los comentarios comienzan con "delim" y acaban al final de línea
  */
void EraseComment ( istream& is, char delim )
{
  // Avanzamos hasta encontrar algo distinto a un blanco o el carácter "delim"
  while ( isspace( is.peek() ) || is.peek() == delim )
  {
    if ( is.peek() == delim )
      is.ignore( 1024, '\n' );  // Suponemos que las líneas tienen menos de 1024 caracteres
    else
      is.ignore();
  }
}

/**
  * @brief Calcula el rectángulo delimitador más pequeño de una nube de puntos
  * @param Flujo de entrada de datos (is)
  */
Rectangle BoundingBox ( istream& is )
{
  double min_x, max_x, min_y, max_y;
  Point p;
  Rectangle bounding;
  const char DELIM = '#';

  // También podríamos inicializarlas a las coordenadas del primer punto leído
  min_x = min_y = numeric_limits<double>::max();
  max_x = max_y = numeric_limits<double>::min();

  EraseComment( is, DELIM );

  while( ReadPoint( is, p ) )
  {
    if( p.x < min_x )
      min_x = p.x;
    else if( p.x > max_x )
      max_x = p.x;

    if( p.y < min_y )
      min_y = p.y;
    else if( p.y > max_y )
      max_y = p.y;

    EraseComment( is, DELIM );
  }

  InitRectangle( bounding, InitPoint( min_x, min_y ), InitPoint( max_x, max_y ) );

  return bounding;
}

int main( int argc, char* argv[] )
{
  Rectangle bounding;
  bool input_finished;

  if ( argc == 1 ) { // Si no se ha introducido el nombre del archivo como parámetro
    bounding = BoundingBox( cin );
    input_finished = cin.eof();   // Comprueba si se ha leído hasta el final
  }
  else {
    ifstream f( argv[1] );

    if ( !f ) {
      cerr << "No se puede abrir el archivo " << argv[1] << endl;
      return 1;   // Forzamos el cierre, devolviendo al sistema un error
    }

    bounding = BoundingBox( f );
    input_finished = f.eof();
  }

  if ( !input_finished ) {
    cerr << "Error inesperado: no se han podido leer todos los datos." << endl;
    return 1;
  }

  cout << "El rectángulo delimitador más pequeño de la nube de puntos es: ";
  WriteRectangle( cout, bounding );
  cout << ", con un área de " << Area( bounding ) << endl;
}
