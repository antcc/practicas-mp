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

/// Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
Point ReadPoint ();

/// Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void WritePoint ( const Point& p );

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