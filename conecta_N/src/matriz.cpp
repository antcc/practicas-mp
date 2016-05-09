/**
  * @file matriz.cpp
  * @brief Implementación de la clase `Matriz`
  *
  */

#include <cassert>
#include "matriz.h"

Matriz::Matriz()
{
  m_filas = m_columnas = 0;
  reset();
}

Matriz::Matriz(int f, int c)
{
  assert (f >= 0 && f <= 20 && c >= 0 && c <= 20);
  m_filas = f;
  m_columnas = c;
  reset();
}

int Matriz::get(int f, int c) const
{
  assert (f >= 0 && f < m_filas && c >= 0 && c < m_columnas);
  return m_matriz[f][c];
}

void Matriz::set(int f, int c, int v)
{
  assert (f >= 0 && f < m_filas && c >= 0 && c < m_columnas);
  m_matriz[f][c] = v;
}

void Matriz::reset()
{
  for (int i = 0; i < filas(); i++)
    for (int j = 0; j < columnas(); j++)
      m_matriz[i][j] = 0;
}

/* Fin fichero: matriz.cpp */
