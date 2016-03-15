/**
  * @file rectangle.h
  * @brief Módulo que contiene la estructura Rectangle y funciones para manejar rectángulos
  * @author Miguel Lentisco & Antonio Coín
  */

#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "point.h"

// Declaración de Rectangle
// ------------------------------------------

/// Representa un rectángulo en 2D, a partir de las esquinas inferior izquierda y superior derecha
struct Rectangle {
  Point ll_corner;
  Point ur_corner;
};

// Funciones para manejar rectángulos
// -------------------------------------------

/**
  * @brief Lee un rectángulo desde un flujo, a partir de las esquinas inferior izquierda y superior derecha
  * @param Flujo de entrada (is), rectángulo a leer (r)
  * @pre El formato debe ser (x,y)-(z-t)
  * @return Devuelve si ha tenido éxito la lectura
  */
bool ReadRectangle ( std::istream& is, Rectangle& r );

/**
  * @brief Escribe un rectángulo a un flujo, en formato (x,y)-(z,t)
  * @param Flujo de salida (os), rectángulo a escribir (r)
  * @return Devuelve si ha tenido éxito la escritura
  */
bool WriteRectangle ( std::ostream& os, const Rectangle& r );

/**
  * @brief Inicializa un rectángulo a partir de dos puntos
  * @param Rectángulo a inicializar (r), esquina superior/inferior izquierda (p),
  * esquina superior/inferior derecha (q)
  * @pre Fallo si coinciden alguna de las dos coordenadas de p y q
  */
void InitRectangle ( Rectangle& r, const Point& p, const Point& q );

/// Devuelve el punto de la esquina inferior izquierda
Point LowerLeft ( const Rectangle& r );

/// Devuelve el punto de la esquina superior derecha
Point UpperRight ( const Rectangle& r );

/// Devuelve el área del rectángulo
double Area ( const Rectangle& r );

/// Devuelve si un punto está en el interior del rectángulo
bool IsWithin ( const Point& p, const Rectangle& r );

#endif
