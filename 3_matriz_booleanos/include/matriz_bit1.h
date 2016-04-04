/**
  * @file matriz_bit1.h
  * @brief Definición 1 de MatrizBit, mediante una matriz-C
  *
  */

#ifndef _MATRIZ_BIT1_H_
#define _MATRIZ_BIT1_H_

/// Estructura que representa una matriz de booleanos mediante una matriz-C de 10x10
struct MatrizBit
{
  static const int MAX_FILAS = 10;
  static const int MAX_COLUMNAS = 10;

  int filas;
  int columnas;
  bool matriz[MAX_FILAS][MAX_COLUMNAS];
};

#endif

/* Fin fichero: matriz_bit1.h */
