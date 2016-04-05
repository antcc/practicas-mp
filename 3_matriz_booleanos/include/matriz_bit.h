/**
  * @file matriz_bit.h
  * @brief Fichero cabecera para insertar la implementación deseada
  *
  * Permite modificar la implementación mediante un número del 1 a 4
  *
  */

#ifndef _MATRIZ_BIT_H_
#define _MATRIZ_BIT_H_

#define CUAL_COMPILO 2

#if CUAL_COMPILO==1
  #include "matriz_bit1.h"
#elif CUAL_COMPILO==2
  #include "matriz_bit2.h"
#elif CUAL_COMPILO==3
  #include "matriz_bit3.h"
#else
  #include "matriz_bit4.h"
#endif

/**
  * @brief Inicializa un objeto de tipo Matriz de booleanos
  *
  * @param m objeto a inicializar
  * @param fils número de filas
  * @param cols número de columnas
  * @return si ha tenido éxito la inicialización, en cuyo caso @a m es una matriz @a fils x @a cols con valores 0
  */
bool Inicializar (MatrizBit& m, int fils, int cols);

/**
  * @brief Filas de una matriz
  *
  * @param m objeto a consultar
  * @return el número de filas de @a m
  */
int GetFilas (const MatrizBit& m);

/**
  * @brief Columnas de una matriz
  *
  * @param m objeto a consultar
  * @return el número de columnas de @a m
  */
int GetColumnas (const MatrizBit& m);

/**
  * @brief Consulta del valor de una posición
  *
  * @param m objeto a consultar
  * @param f fila
  * @param c columna
  * @return el valor contenido en la fila @a f columna @a c de @a m
  *
  * @pre 0 <= f <= m.MAX_FILAS, 0 <= c <= m.MAX_COLUMNAS
  */
bool GetElemento (const MatrizBit& m, int f, int c);

/**
  * @brief Cambiar el valor de una posición
  *
  * @param m objeto a modificar
  * @param f fila
  * @param c columna
  * @param v valor a asignar
  * @post el valor contenido en la fila @a f columna @a c de @a m pasa a valer @a v
  */
void SetElemento (MatrizBit& m, int f, int c, bool v);

#endif

/* Fin fichero: matriz_bit.h */
