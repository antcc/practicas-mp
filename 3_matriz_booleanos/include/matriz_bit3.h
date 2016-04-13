/**
  * @file matriz_bit3.h
  * @brief Definición 3 de MatrizBit, mediante un vector-C de char
  *
  */

#ifndef _MATRIZ_BIT3_H_
#define _MATRIZ_BIT3_H_

struct MatrizBit
{
  static const int MAX_ESPACIO = 100;

  unsigned int espacio;
  char v[MAX_ESPACIO];
};

#endif

/* Fin fichero: matriz_bit3.h */
