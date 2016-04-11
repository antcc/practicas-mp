/**
  * @file matriz_bit3.cpp
  * @brief Implementación de funciones para MatrizBit de tipo 3
  *
  */

namespace
{
  const int MAX_POS = 16;
}

bool Inicializar (MatrizBit& m, int fils, int cols)
{
  bool exito = fils * cols <= m.MAX_ESPACIO && fils >= 0 && cols >= 0;

  if (exito)
  {
    m.espacio = (fils << MAX_POS) + cols;

    for (int i = 0; i < fils; i++)
      m.v[i] = '0';
  }

  return exito;
}

//________________________________________________________________

int GetFilas (const MatrizBit& m)
{
  return (m.espacio - GetColumnas(m)) >> MAX_POS;
}

//________________________________________________________________

int GetColumnas (const MatrizBit& m)
{
  int columnas = 0;

  for (int i = MAX_POS - 1; i >= 0; i--)
  {
    int aux = 1 << i;
    columnas += aux & m.espacio;
  }

  return columnas;
}

//________________________________________________________________

bool GetElemento (const MatrizBit& m, int f, int c)
{
  return m.v[GetColumnas(m)*f + c] == '1';
}

//________________________________________________________________

void SetElemento (MatrizBit& m, int f, int c, bool v)
{
  const int COLS = GetColumnas(m);
  const int FILS = GetFilas(m);

  if (f < FILS && c < COLS && f >= 0 && c >= 0)
    m.v[COLS*f + c] = v ? '1' : '0';
}

/* Fin fichero: matriz_bit3.cpp */
