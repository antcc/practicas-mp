/**
  * @file matriz_bit2.cpp
  * @brief Implementación de funciones para MatrizBit de tipo 2
  *
  */

#include "matriz_bit.h"
using namespace std;

bool Inicializar (MatrizBit& m, int fils, int cols)
{
  bool exito = fils * cols <= m.MAX_ESPACIO && fils >= 0 && cols >= 0;

  if (exito)
  {
    m.filas = fils;
    m.columnas = cols;

    for (int i = 0; i < fils; i++)
      for (int j = 0; j < cols; j++)
        m.v[cols*i + j] = 0;
  }

  return exito;
}

//________________________________________________________________

int GetFilas (const MatrizBit& m)
{
  return m.filas;
}

//________________________________________________________________

int GetColumnas (const MatrizBit& m)
{
  return m.columnas;
}

//________________________________________________________________

bool GetElemento (const MatrizBit& m, int f, int c)
{
  return m.v[m.columnas*f + c];
}

//________________________________________________________________

void SetElemento (MatrizBit& m, int f, int c, bool v)
{
  if (f <= m.filas && c <= m.columnas && f >= 0 && c >= 0)
    m.v[m.columnas*f + c] = v;
}

/* Fin fichero: matriz_bit2.cpp */
