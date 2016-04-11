/**
  * @file matriz_bit4.cpp
  * @brief Implementación de funciones para MatrizBit de tipo 4
  *
  */

namespace
{
  const int MAX_POS = 32;
}

bool Inicializar (MatrizBit& m, int fils, int cols)
{
  bool exito = fils * cols <= m.MAX_ESPACIO && fils >= 0 && cols >= 0;

  if (exito)
  {

  }

  return exito;
}

//________________________________________________________________

int GetFilas (const MatrizBit& m)
{

}

//________________________________________________________________

int GetColumnas (const MatrizBit& m)
{

}

//________________________________________________________________

bool GetElemento (const MatrizBit& m, int f, int c)
{

}

//________________________________________________________________

void SetElemento (MatrizBit& m, int f, int c, bool v)
{

}

/* Fin fichero: matriz_bit4.cpp */
