/**
  * @file matriz_bit2.h
  * @brief Definición 2 de MatrizBit, mediante un vector-C de bool
  *
  */

#ifndef _MATRIZ_BIT2_H_
#define _MATRIZ_BIT2_H_

struct MatrizBit
{
  static const int MAX_ESPACIO = 100;

  int filas;
  int columnas;
  bool v[MAX_ESPACIO];
};

#endif

/* Fin fichero: matriz_bit2.h */
