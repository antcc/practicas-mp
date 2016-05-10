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
  return m_datos[f][c];
}

void Matriz::set(int f, int c, int v)
{
  assert (f >= 0 && f < m_filas && c >= 0 && c < m_columnas);
  m_datos[f][c] = v;
}

void Matriz::reset()
{
  for (int i = 0; i < m_filas; i++)
    for (int j = 0; j < m_columnas; j++)
      m_datos[i][j] = 0;
}

/* Fin fichero: matriz.cpp */
