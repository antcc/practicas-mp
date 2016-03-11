/**
  * @file circle.h
  * @brief Declaración de la estructura Circle y cabeceras de funciones para manejar círculos
  * @author Miguel Lentisco & Antonio Coín
  */

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "point.h"

// Declaración de Circle
// ------------------------------------------

/// Representa un círculo en 2D, a través de su centro y su radio
struct Circle {
    Point center;
    double radius;
};

// Funciones para manejar círculos
// -------------------------------------------

/// Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con ReadPoint
Circle ReadCircle();

/// Escribe círculo en formato radio-centro, incluyendo '-' y escribiendo "centro" con WritePoint
void WriteCircle( const Circle& c );

/// Inicializa circulo c con centro y radio
void InitCircle ( Circle& c, Point center, double radius );

/// Devuelve el centro de c
Point GetCenter ( const Circle& c );

/// Devuelve el radio de c
double GetRadius ( const Circle& c );

/// Devuelve el área del círculo c
double Area ( const Circle& c );

/// Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool IsWithin ( const Point& p, const Circle& c );

/// Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distance ( const Circle& c1, const Circle& c2 );

#endif
