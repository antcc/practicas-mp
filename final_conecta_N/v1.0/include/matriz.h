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
    int m_datos[20][20];
    int m_filas, m_columnas;
  public:
    Matriz();
    // @pre: 0 <= f,c <= 20
    // inicializa a 0
    Matriz(int f, int c);
    int filas() const {return m_filas;}
    int columnas() const {return m_columnas;}
    // @pre: 0 <= f,c <= 20
    int get(int f, int c) const;
    // @pre: 0 <= f,c <= 20
    void set(int f, int c, int v);
    // pone todo a 0
    void reset();
};

#endif

/* Fin fichero: matriz.h */
