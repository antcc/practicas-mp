/**
  * @file matriz_bit4.h
  * @brief Definición 4 de MatrizBit, mediante un vector-C de unsigned int
  *
  */

#ifndef _MATRIZ_BIT4_H_
#define _MATRIZ_BIT4_H_

struct MatrizBit
{
  static const int MAX_ESPACIO = 4;

  unsigned short int espacio;
  unsigned int v[MAX_ESPACIO];
};

/* Fin fichero: matriz_bit4.h */
