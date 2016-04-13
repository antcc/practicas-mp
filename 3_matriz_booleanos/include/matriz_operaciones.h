/**
  * @file matriz_operaciones.h
  * @brief Fichero cabecera para funciones del tipo MatrizBit independientes de la representación
  *
  */

#ifndef _MATRIZ_OPER_H_
#define _MATRIZ_OPER_H_

#include <iosfwd> // istream, ostream
#include "matriz_bit.h"

/**
  * @brief Lee una matriz en formato texto desde un flujo
  *
  * @param is flujo desde el que leer la matriz
  * @param m objeto donde almacenar la matriz, si se consigue leer
  * @return si la operación ha tenido éxito
  */
bool Leer (std::istream& is, MatrizBit& m);

/**
  * @brief Escribe una matriz en formato texto en un flujo
  *
  * @param os flujo donde escribir la matriz
  * @param m objeto que contiene la matriz a escribir
  * @return si la operación ha tenido éxito
  */
bool Escribir (std::ostream& os, const MatrizBit& m);

/**
  * @brief Lee una matriz en formato texto desde un fichero
  *
  * @param nombre nombre del archivo que contiene la matriz
  * @param m objeto donde almacenar la matriz, si se consigue leer
  * @return si la operación ha tenido éxito
  */
bool Leer (const char nombre[], MatrizBit& m);

/**
  * @brief Escribe una matriz en formato texto en un fichero
  *
  * @param nombre nombre del archivo donde almacenar la matriz
  * @param m objeto que contiene la matriz a escribir
  * @return si la operación ha tenido éxito
  * @warning El archivo se creará o se sobreescribirá
  */
bool Escribir (const char nombre[], const MatrizBit& m);

/**
  * @brief Traspuesta de una matriz de booleanos
  *
  * @param res Objeto donde almacenar el resultado
  * @param m Operando
  * @post El contenido de @a res contiene la traspuesta de @a m
  *
  */
void Traspuesta (MatrizBit& res, const MatrizBit& m);

/**
  * @brief AND entre dos matrices de booleanos
  *
  * @param res Objeto donde almacenar el resultado
  * @param m1 primer operando
  * @param m2 segundo operando
  * @pre Las dimensiones de @a m1 y @a m2 deben coincidir
  * @post El contenido de @a res contiene el resultado de @a m1 AND @a m2
  */
void And (MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2);

/**
  * @brief OR entre dos matrices de booleanos
  *
  * @param res Objeto donde almacenar el resultado
  * @param m1 primer operando
  * @param m2 segundo operando
  * @pre Las dimensiones de @a m1 y @a m2 deben coincidir
  * @post El contenido de @a res contiene el resultado de @a m1 OR @a m2
  */
void Or (MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2);

/**
  * @brief NOT de una matriz de booleanos
  *
  * @param res Objeto donde almacenar el resultado
  * @param m Operando
  * @post El contenido de @a res contiene el resultado de NOT @a m
  */
void Not (MatrizBit& res, const MatrizBit& m);

#endif

/* Fin fichero: matriz_operaciones.h */
