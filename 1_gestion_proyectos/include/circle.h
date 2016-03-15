/**
  * @file circle.h
  * @brief Módulo que contiene la estructura Circle y cabeceras de funciones para manejar círculos
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

/**
  * @brief Lee círculo desde la entrada estándar, en formato radio-centro, incluyendo '-'
  * y leyendo "centro" con ReadPoint
  * @deprecated Se aconseja el uso de la función con un parámetro
  */
Circle ReadCircle ();

/**
  * @brief Lee un círculo desde un flujo de entrada, usando ReadPoint para leer el centro.
  * @param Flujo de entrada de datos (is), círculo a leer (c)
  * @pre El formato debe ser radio-(x,y), donde (x,y) es el centro
  * @return Devuelve si ha tenido éxito la lectura
  */
bool ReadCircle ( std::istream& is, Circle& c );

/**
  * @brief Escribe círculo a la salida estándar, en formato radio-centro, incluyendo '-'
  * y escribiendo "centro" con WritePoint
  * @deprecated Se aconseja el uso de la función con dos parámetros
  */
void WriteCircle ( const Circle& c );

/**
  * @brief Escribe un círculo a un flujo de salida, en formato radio-centro, escribiendo
  * "centro" con WritePoint
  * @param Flujo de salida de datos (os), círculo a escribir (c)
  * @return Devuelve si ha tenido éxito la escritura
  */
bool WriteCircle ( std::ostream& os, const Circle& c );

/// Inicializa circulo c con centro y radio
void InitCircle ( Circle& c, const Point& center, double radius );

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
