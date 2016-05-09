/**
  * @file matriz.h
  * @brief Interfaz de la clase `Matriz`
  *
  */

#ifndef _MATRIZ_H_
#define _MATRIZ_H_

/**
  * @class Matriz
  * @brief Gestiona una estructura bidimensional de datos enteros
  */
class Matriz {
    int m_matriz[20][20];
    int m_filas, m_columnas;
  public:
    Matriz();
    Matriz(int f, int c); // inicializa todo a 0; @pre: 0 <= f,c <= 20
    int filas() const {return m_filas;}
    int columnas() const {return m_columnas;}
    int get(int f, int c) const;
    void set(int f, int c, int v);  // @pre: 0 <= f,c <= 20
};

#endif

/* Fin fichero: matriz.h */
