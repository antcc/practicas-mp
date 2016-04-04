/**
  * @file matriz_operaciones.cpp
  * @brief Implementación de operaciones con MatrizBit, independientes de la representación
  *
  */

#include "matriz_operaciones.h"
#include <iosfwd> // istream,ostream
#include <fstream>
using namespace std;

bool Leer (istream& is, MatrizBit& m)
{
  int filas;
  int columnas;

  is >> filas >> columnas;

  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      bool aux;
      is >> aux;

      SetElemento(m, i, j, aux);
    }
  }

  return is;
}

//________________________________________________________________

bool Escribir (ostream& os, const MatrizBit& m)
{
  const int FILAS = GetFilas(m);
  const int COLUMNAS = GetColumnas(m);

  os << FILAS << " " << COLUMNAS << "\n";

  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      os << GetElemento(m, i, j) << " ";
    }
    os << "\n";
  }

  return os;
}

//________________________________________________________________

bool Leer (const char nombre[], MatrizBit& m)
{
  ifstream f(nombre);

  return Leer(f, m);
}

//________________________________________________________________

bool Escribir (const char nombre[], const MatrizBit& m)
{
  ofstream f(nombre);

  return Escribir(f, m);
}

//________________________________________________________________

void Traspuesta (MatrizBit& res, const MatrizBit& m)
{
  const int FILAS = GetFilas(m);
  const int COLUMNAS = GetColumnas(m);

  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      SetElemento(res, j, i, GetElemento(m, i, j));
    }
  }
}

//________________________________________________________________

void And (MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
  const int FILAS = GetFilas(m1);
  const int COLUMNAS = GetColumnas(m1);

  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      SetElemento(res, i, j, GetElemento(m1, i, j) && GetElemento(m2, i, j));
    }
  }
}

//________________________________________________________________

void Or (MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
  const int FILAS = GetFilas(m1);
  const int COLUMNAS = GetColumnas(m1);

  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      SetElemento(res, i, j, GetElemento(m1, i, j) || GetElemento(m2, i, j));
    }
  }
}

//________________________________________________________________

void Not (MatrizBit& res, const MatrizBit& m)
{
  const int FILAS = GetFilas(m);
  const int COLUMNAS = GetColumnas(m);

  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      SetElemento(res, i, j, !GetElemento(m, i, j));
    }
  }
}

/* Fin fichero: matriz_operaciones.cpp */
