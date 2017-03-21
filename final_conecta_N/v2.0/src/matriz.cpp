#include <iostream>
#include <cassert>
#include "matriz.hpp"

namespace ConectaN
{
  // ------------------------------------------------------------------------------------------
  // Tipos de matrices válidos
  // ------------------------------------------------------------------------------------------

  template class Matriz<int>;
  template class Matriz<float>;
  template class Matriz<double>;

  // ------------------------------------------------------------------------------------------
  // Constructores / Destructor
  // ------------------------------------------------------------------------------------------
  template<class T> Matriz<T>::Matriz(int f, int c): filas(f), columnas(c)
  {
    m = new T[f * c];
    reset();
  }

  template<class T> Matriz<T>::Matriz(const Matriz<T>& m_nueva) : m(new T[m_nueva.filas * m_nueva.columnas]),
                                                                 filas(m_nueva.filas), columnas(m_nueva.columnas)
  {
    for (int i = 0; i < filas * columnas; i++)
      m[i] = m_nueva.m[i];
  }

  template<class T> Matriz<T>::Matriz(): m(0), filas(0), columnas(0) {}

  // ------------------------------------------------------------------------------------------
  // Métodos set/get
  // ------------------------------------------------------------------------------------------
  template<class T> void Matriz<T>::setFilas(int f)
  {
    Matriz<T> m_aux(f, columnas);
    for (int i = 0; i < f; i++)
      for (int j = 0; j < columnas; j++)
          m_aux(i, j) = getElemento(i, j);
    *this = m_aux;
  }

  template<class T> void Matriz<T>::setColumnas(int c)
  {
    Matriz<T> m_aux(filas, c);
    for (int i = 0; i < filas; i++)
      for (int j = 0; j < c; j++)
        m_aux(i, j) =  getElemento(i, j);
    *this = m_aux;
  }

  template<class T> T Matriz<T>::getElemento(int f, int c) const
  {
    assert (f >= 0 && f < filas && c >= 0 && c < columnas);
    return m[f * columnas + c];
  }
  template<class T> void Matriz<T>::setElemento(int f, int c, T e) {
    assert (f >= 0 && f < filas && c >= 0 && c < columnas);
    m[f * columnas + c] = e;
  }

  // ------------------------------------------------------------------------------------------
  // Operadores internos
  // ------------------------------------------------------------------------------------------
  template<class T> Matriz<T>& Matriz<T>::operator =(const Matriz<T>& matriz)
  {
    if (this != &matriz)
    {
      delete[] m;
      filas = matriz.filas;
      columnas = matriz.columnas;
      m = new T[filas * columnas];
      for (int i = 0; i < filas * columnas; i++)
        m[i] = matriz.m[i];
    }
    return *this;
  }
}
