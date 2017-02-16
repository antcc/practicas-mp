/**
  * @file matriz.hpp
  * @brief Interfaz de la clase `Matriz`
  *
  */

#ifndef _MATRIZ_HPP_
#define _MATRIZ_HPP_

#include <iostream>

namespace ConectaN
{
  /**
    * @class Matriz
    * @brief Representa una estructura de datos bidimensionales
    *
    * Esta matriz "plantilla" puede almacenar datos de tipo entero o real
    * según necesidad.
    */
  template<class T> class Matriz
  {
    private:
      // ------------------------------------------------------------------------------------------
      // Datos miembro
      // ------------------------------------------------------------------------------------------

      T* m;
      int filas, columnas;

    public:
      // ------------------------------------------------------------------------------------------
      // Constructores / Destructor
      // ------------------------------------------------------------------------------------------

      Matriz(int f, int c);
      Matriz(const Matriz<T>& m);
      Matriz();
      ~Matriz() {delete[] m;}

      // ------------------------------------------------------------------------------------------
      // Métodos set/get
      // ------------------------------------------------------------------------------------------

      int getFilas() const {return filas;}
      int getColumnas() const {return columnas;}
      T getElemento(int f, int c) const;
      void setFilas(int f);
      void setColumnas(int c);
      void setElemento(int f, int c, T e);

      // ------------------------------------------------------------------------------------------
      // Operadores internos
      // ------------------------------------------------------------------------------------------

      const T& operator()(int f, int c) const {return m[f * columnas + c];}
      T& operator()(int f, int c) {return m[f * columnas + c];}
      Matriz& operator =(const Matriz<T>& matriz);

      // ------------------------------------------------------------------------------------------
      // Funciones amigas
      // ------------------------------------------------------------------------------------------

      template<class D> friend Matriz<D> operator +(const Matriz<D>& m1, const Matriz<D>& m2);
      template<class D> friend Matriz<D> operator -(const Matriz<D>& m1, const Matriz<D>& m2);
      template<class D, class N> friend Matriz<D> operator /(const Matriz<D>& m, N n);
      template<class D, class N> friend Matriz<D> operator *(const Matriz<D>& m, N n);

      // ------------------------------------------------------------------------------------------
      // Métodos públicos
      // ------------------------------------------------------------------------------------------

      void reset() {for (int i = 0; i < filas * columnas; i++) m[i] = 0;}
  };

  // ------------------------------------------------------------------------------------------
  // Operadores I/O
  // ------------------------------------------------------------------------------------------

  template<class T> std::ostream& operator <<(std::ostream& os, const Matriz<T>& matriz)
  {
    int filas = matriz.getFilas(), columnas = matriz.getColumnas();
    os << filas << ' ' << columnas << std::endl;
    for (int i = 0; i < filas; i++)
    {
      for (int j = 0; j < columnas; j++)
        os << matriz(i, j) << ' ';
      os << std::endl;
    }
    return os;
  }

  template<class T> std::istream& operator >>(std::istream& is, Matriz<T>& matriz)
  {
    int filas, columnas;
    is >> filas >> columnas;
    if (is)
      matriz = Matriz<T>(filas, columnas);
    for (int i = 0; i < filas; i++)
      for (int j = 0; j < columnas; j++)
        is >> matriz(i, j);
    return is;
  }

  // ------------------------------------------------------------------------------------------
  // Operadores externos
  // ------------------------------------------------------------------------------------------

  template<class T> Matriz<T> operator +(const Matriz<T>& m1, const Matriz<T>& m2)
  {
    int f = m1.getFilas(), c = m2.getColumnas();
    Matriz<T> m_nueva(f, c);
    for (int i = 0; i < f * c; i++)
        m_nueva.m[i] =  m1.m[i] + m2.m[i];
    return m_nueva;
  }

  template<class T> Matriz<T> operator -(const Matriz<T>& m1, const Matriz<T>& m2)
  {
    int f = m1.getFilas(), c = m2.getColumnas();
    Matriz<T> m_nueva(f, c);
    for (int i = 0; i < f * c; i++)
        m_nueva.m[i] =  m1.m[i] - m2.m[i];
    return m_nueva;
  }

  template<class T, class N> Matriz<T> operator /(const Matriz<T>& m, N n)
  {
    int f = m  .getFilas(), c = m.getColumnas();
    Matriz<T> m_nueva(f, c);
    for (int i = 0; i < f * c; i++)
        m_nueva.m[i] =  m.m[i] / n;
    return m_nueva;
  }

  template<class T, class N> Matriz<T> operator *(const Matriz<T>& m, N n)
  {
    int f = m.getFilas(), c = m.getColumnas();
    Matriz<T> m_nueva(f, c);
    for (int i = 0; i < f * c; i++)
        m_nueva.m[i] =  m.m[i] * n;
    return m_nueva;
  }

  template<class T> Matriz<T> operator *(const Matriz<T>& m1, const Matriz<T>& m2)
  {
    int f = m1.getFilas(), c = m2.getColumnas();
    Matriz<T> m_nueva(f, c);
    for (int i = 0; i < f; i++)
      for (int j = 0; j < c; j++)
      {
        double suma = 0;
        for (int k = 0; k < c; k++)
          suma = m1(i, k) * m2(k, j);
        m_nueva(i, j) = suma;
      }
    return m_nueva;
  }
}

#endif

/* Fin fichero: matriz.hpp */
