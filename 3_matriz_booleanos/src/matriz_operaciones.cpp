/**
  * @file matriz_operaciones.cpp
  * @brief Implementación de operaciones con MatrizBit, independientes de la representación
  *
  */

#include "matriz_operaciones.h"
#include <iosfwd> // istream,ostream
#include <cstring> //strlen, strcat
#include <fstream>
using namespace std;

bool Leer (istream& is, MatrizBit& m)
{
  int filas;
  int columnas;
  bool exito;

  // Saltar espacios
  while(isspace(is.peek()))
    is.ignore();

  // Primer formato
  if(is.peek() == 'X' || is.peek() == '.')
  {
    const int MAX_POS = 1024;
    char aux[MAX_POS];
    char valores[MAX_POS] = {'\0'};

    // Lectura anticipada
    is.getline(aux, MAX_POS);
    strcat(valores, aux);
    columnas = strlen(valores); // fijamos las columnas

    filas = 1;
    while(is.getline(aux, MAX_POS) && is && strlen(aux) == columnas)
    {
      strcat(valores, aux);
      filas++;
    }

    ////////////////// CONDICIÓN PARA is /////////////////////////////////
    exito = is.good() && Inicializar(m, filas, columnas);

    if (exito)
    {
      for (int i = 0; i < filas; i++)
      {
        for (int j = 0; j < columnas; j++)
        {
          char c = valores[columnas*i + j];
          if (c == 'X' || c == '.')
          {
            bool v = c == 'X' ? 1 : 0;
            SetElemento(m, i, j, v);
          }
          else
            return false;
        }
      }
    }
  }
  // Segundo formato
  else
  {
    is >> filas >> columnas;
    exito = is && Inicializar(m, filas, columnas);

    if (exito)
    {
      for (int i = 0; i < filas; i++)
      {
        for (int j = 0; j < columnas; j++)
        {
          bool aux;
          is >> aux;

          SetElemento(m, i, j, aux);
        }
      }
      exito = is;
    }
  }

  return exito;
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
      os << GetElemento(m, i, j) << " ";

    os << "\n";
  }
  os << "\n";

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
    for (int j = 0; j < COLUMNAS; j++)
      SetElemento(res, j, i, GetElemento(m, i, j));
}

//________________________________________________________________

void And (MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
  const int FILAS = GetFilas(m1);
  const int COLUMNAS = GetColumnas(m1);

  for (int i = 0; i < FILAS; i++)
    for (int j = 0; j < COLUMNAS; j++)
      SetElemento(res, i, j, GetElemento(m1, i, j) && GetElemento(m2, i, j));
}

//________________________________________________________________

void Or (MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
  const int FILAS = GetFilas(m1);
  const int COLUMNAS = GetColumnas(m1);

  for (int i = 0; i < FILAS; i++)
    for (int j = 0; j < COLUMNAS; j++)
      SetElemento(res, i, j, GetElemento(m1, i, j) || GetElemento(m2, i, j));
}

//________________________________________________________________

void Not (MatrizBit& res, const MatrizBit& m)
{
  const int FILAS = GetFilas(m);
  const int COLUMNAS = GetColumnas(m);

  for (int i = 0; i < FILAS; i++)
    for (int j = 0; j < COLUMNAS; j++)
      SetElemento(res, i, j, !GetElemento(m, i, j));
}

/* Fin fichero: matriz_operaciones.cpp */
