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
    int *m_datos;
    int m_filas, m_columnas;
  public:
    Matriz();
    Matriz(const Matriz& mat);
    ~Matriz() {delete[] m_datos;}
    Matriz& operator=(const Matriz& mat);
    Matriz(int f, int c); // inicializa todo a 0; @pre: 0 <= f,c <= 20
    int filas() const {return m_filas;}
    int columnas() const {return m_columnas;}
    int get(int f, int c) const;  // @pre: 0 <= f,c <= 20
    void set(int f, int c, int v);  // @pre: 0 <= f,c <= 20
    void reset(); // pone todo a 0
    void swap(Matriz& mat);
};

#endif

/* Fin fichero: matriz.h */
