/**
  * @file point.h
  * @brief Declaración de la estructura Point y cabeceras de funciones para manejar puntos 2D
  * @author Miguel Lentisco & Antonio Coín
  */

#ifndef _POINT_H_
#define _POINT_H_

// Declaración de Point
// -------------------------------------------

/// Representa un Punto en 2D, a través de sus coordenadas x e y
struct Point {
  double x;
  double y;
};

// Funciones para manejar puntos
// --------------------------------------------

/**
  * @brief Lee un punto desde la entrada estándar, en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
  * @deprecated Se aconseja el uso de la función con un parámetro (ver siguiente)
  */
Point ReadPoint ();

/**
  * @brief Lee un punto desde un flujo de entrada
  * @param Flujo de entrada de datos (is), punto a leer (p)
  * @prec El formato debe ser (x,y)
  * @return Devuelve si ha tenido éxito la lectura
  */
bool ReadPoint ( std::istream& is, Point& p );

/**
  * @brief Escribe un punto a la salida estándar, en formato (x,y), incluyendo la escritura de '(' ',' y ')'
  * @deprecated Se aconseja el uso de la función con dos parámetros (ver siguiente)
  */
void WritePoint ( const Point& p );

/**
  * @brief Escribe un punto a un flujo de salida, en el mismo formato (x,y)
  * @param Flujo de salida de datos (os), punto a escribir (p)
  * @return Devuelve si ha tenido éxito la escritura
  */
bool WritePoint ( std::ostream& os, const Point& p );

/// Inicializa un punto con dos valores cx cy
void InitPoint ( Point& p, double cx, double cy );

/// Devuelve la coordenada X del punto p
double GetX ( const Point& p );

/// Devuelve la coordenada Y del punto p
double GetY ( const Point& p );

/// Devuelve la distancia euclídea entre p1 y p2
double Distance ( const Point& p1, const Point& p2 );

/// Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Point MiddlePoint ( const Point& p1, const Point& p2 );

#endif
