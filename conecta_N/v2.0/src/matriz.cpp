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
  m_datos = 0;
}

Matriz::Matriz(int f, int c)
{
  m_datos = new int[f*c];
  m_filas = f;
  m_columnas = c;
  reset();
}

Matriz::Matriz(const Matriz& mat)
{
  m_datos = new int[mat.m_filas*mat.m_columnas];
  m_filas = mat.m_filas;
  m_columnas = mat.m_columnas;

  for (int f = 0; f < m_filas; f++)
    for (int c = 0; c < m_columnas; c++)
      m_datos[f * m_columnas + c] = mat.m_datos[f * mat.m_columnas + c];
}

Matriz& Matriz::operator=(const Matriz& mat)
{
  Matriz aux(mat);
  this->swap(aux);

  return *this;
}

int Matriz::get(int f, int c) const
{
  assert (f >= 0 && f < m_filas && c >= 0 && c < m_columnas);
  return m_datos[f * m_columnas + c];
}

void Matriz::set(int f, int c, int v)
{
  assert (f >= 0 && f < m_filas && c >= 0 && c < m_columnas);
  m_datos[f * m_columnas + c] = v;
}

void Matriz::reset()
{
  for (int i = 0; i < m_filas*m_columnas; i++)
    m_datos[i] = 0;
}

void Matriz::swap(Matriz& mat)
{
  int *p = m_datos;
  m_datos = mat.m_datos;
  mat.m_datos = p;

  int aux = m_filas;
  m_filas = mat.m_filas;
  mat.m_filas = aux;

  aux = m_columnas;
  m_columnas = mat.m_columnas;
  mat.m_columnas = aux;
}

/* Fin fichero: matriz.cpp */
