/**
  * @file matriz_operaciones.cpp
  * @brief Implementación de operaciones con MatrizBit, independientes de la representación
  *
  */

#include <iosfwd> // istream,ostream
#include <cstring> // strlen, strcat
#include <fstream>
#include "matriz_operaciones.h"
using namespace std;

void EliminarBlancos(istream& is)
{
  while(isspace(is.peek()))
    is.ignore();
}

//________________________________________________________________

bool Leer (istream& is, MatrizBit& m)
{
  int filas;
  int columnas;
  bool exito;

  EliminarBlancos(is);

  /*
    Primer formato: 'X' --> 1 ; '.' --> 0
  */
  if (is.peek() == 'X' || is.peek() == '.')
  {
    const int MAX_POS = 1024;
    char valores[MAX_POS];
    char aux[MAX_POS];

    is.getline(valores, MAX_POS);
    columnas = strlen(valores);
    filas = 1;
    EliminarBlancos(is);

    while (is.getline(aux, MAX_POS))
    {
      if (strlen(aux) != columnas)
        return false;

      strcat(valores, aux);
      filas++;
      EliminarBlancos(is);
    }

    exito =  is.eof() && Inicializar(m, filas, columnas);

    if (exito)
      for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
        {
          char c = valores[columnas*i + j];

          if (c == 'X' || c == '.')
            SetElemento(m, i, j, c == 'X');
          else
            return false;
        }
  }
  /*
    Segundo formato: Lectura de '1' y '0'
  */
  else
  {
    is >> filas >> columnas;
    exito = is && Inicializar(m, filas, columnas);

    if (exito)
    {
      for (int i = 0; i < filas && exito; i++)
        for (int j = 0; j < columnas; j++)
        {
          char aux;
          is >> aux;

          if (aux == '1' || aux == '0')
            SetElemento(m, i, j, aux);
          else
            return false;
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
      os << (GetElemento(m, i, j) ? '1' : '0') << ' ';

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
