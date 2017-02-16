/**
  * @file tablero.cpp
  * @brief Impmentación de la clase `Tablero`
  *
  */

#include <iostream>
#include <iomanip>  // setw, setfill
#include <cassert>
#include "tablero.hpp"

namespace ConectaN
{
  // ------------------------------------------------------------------------------------------
  // Constructores
  // ------------------------------------------------------------------------------------------

  Tablero::Tablero(int f, int c, int n, int nInsert) : matriz(f,c), nAlinear(n), nInsertar(nInsert), turno(1)
  {
    assert(f >= 4 && c >= 4 && nAlinear >= 3 && nInsertar > 0 && nInsertar < nAlinear);
  }

  Tablero::Tablero() : nAlinear(0), nInsertar(0), turno(0) {}

  // ------------------------------------------------------------------------------------------
  // Métodos set/get
  // ------------------------------------------------------------------------------------------

  void Tablero::setNAlinear(int n)
  {
    assert(n > 3);
    nAlinear = n;
  }

  void Tablero::setNInsertar(int n)
  {
    assert(n > 0 && n < nAlinear);
    nInsertar = n;
  }

  // ------------------------------------------------------------------------------------------
  // Métodos públicos
  // ------------------------------------------------------------------------------------------

  int Tablero::fichasTotales() const
  {
    int n = 0;
    for (int i = 0; i < matriz.getFilas(); i++)
      for (int j = 0; j < matriz.getColumnas(); j++)
        if (matriz(i,j)) n++;
    return n;
  }

  int Tablero::puntuacionPartida() const
  {
    assert(partidaFinalizada());
    return matriz.getFilas() * matriz.getColumnas() + nAlinear * 2 + fichasTotales();
  }

  int Tablero::ultimaFilaLibre(int col) const
  {
    int f = matriz.getFilas() - 1;
    while(matriz(f,col)) f--;
    return f;
  }

  void Tablero::insertar(int c)
  {
    c -= 1; // las columnas empiezan en 1
    int f = ultimaFilaLibre(c);

    assert(f >= 0);
    matriz.setElemento(f,c,turno);
    if (fichasTotales() % nInsertar == 0)
      turno = turno == 1 ? 2 : 1;
  }

  /*
    Parámetros: i es la fila y j la columna de la posición donde se ha puesto ficha,
    (la última en ponerse), n son las fichas en linea acumuladas, s la dirección que debe seguir (0 son todas).
    Devuelve 1 si ha ganado el jugador 1,2 si ha ganado el jugador 2, o bien 0 si hay empate o no ha finalizado
  */
  int Tablero::partidaFinalizada(int i, int j, int n, int s) const
  {
    if (fichasTotales() == matriz.getFilas() * matriz.getColumnas())
      return 0;
    if (i < matriz.getFilas() && j < matriz.getColumnas()
        && matriz(i,j) == (fichasRestantes() < nInsertar ? turno : jugadorAnterior()))
    {
      if (n == nAlinear)
        return jugadorAnterior();
      switch (s)
      {
        case 0:
        {
          int resultado = 0;
          for (int k = 1; k < 9 && !resultado; k++)
            resultado = partidaFinalizada(i, j, n + 1, k);
          return resultado;
        }

        case 1:
          return partidaFinalizada(i - 1, j, n + 1, 1);

        case 2:
          return partidaFinalizada(i - 1, j + 1, n + 1, 2);

        case 3:
          return partidaFinalizada(i, j + 1, n + 1, 3);

        case 4:
          return partidaFinalizada(i + 1, j + 1, n + 1, 4);

        case 5:
          return partidaFinalizada(i + 1, j, n + 1, 5);

        case 6:
          return partidaFinalizada(i + 1, j - 1, n + 1, 6);

        case 7:
          return partidaFinalizada(i, j - 1, n + 1, 7);

        case 8:
          return partidaFinalizada(i - 1, j - 1, n + 1, 8);
      }
    }
    return 0;
  }

  // Método de fuerza bruta
  int Tablero::partidaFinalizada() const
  {
    int resultado = 0;
    for (int i = 0; i < matriz.getFilas() && !resultado; i++)
      for (int j = 0; j < matriz.getColumnas() && !resultado; j++)
        resultado = partidaFinalizada(i, j);
    return resultado;
  }

  void Tablero::prettyPrint(char c1, char c2, std::ostream& os) const
  {
    int filas = matriz.getFilas();
    int columnas = matriz.getColumnas();

    // Colores (ANSI escape colors)
    const char* ROJO = "\033[0;31m";
    const char* AMARILLO = "\033[0;33m";
    const char* DEFAULT = "\033[0m";

    for (char i = 97; i < 97 + columnas; i++)
      os << "[" << i << "] ";
    os << std::endl;

    for (int i = 0; i < filas; i++) {
      for (int j = 0; j < columnas; j++) {
        os << "[";
        if (matriz(i,j) == 1)
          os << ROJO << c1 << DEFAULT;
        else if (matriz(i,j) == 2)
          os << AMARILLO << c2 << DEFAULT;
        else
          os << " ";
        os << "] ";
      }
      os << std::endl;
    }
    os << std::setfill('=') << std::setw(4 * columnas)
       << " " << std::endl;

    if (!partidaFinalizada()) {
      if (turno == 1)
        os << "Turno: jugador 1 (" << ROJO << "x" << DEFAULT << ")";
      else
        os << "Turno: jugador 2 (" << AMARILLO << "o" << DEFAULT << ")";
      os << std::endl;
    }
  }

  void Tablero::vaciar()
  {
    matriz.reset();
    if (fichasTotales() % 2)
      turno = turno == 1 ? 2 : 1;
  }

  // ------------------------------------------------------------------------------------------
  // Operadores I/O
  // ------------------------------------------------------------------------------------------

  std::ostream& operator<<(std::ostream& os, const Tablero& tab)
  {
    os << tab.nAlinear << ' ' << tab.nInsertar << ' ' << tab.turno << std::endl;
    os << tab.matriz;
    return os;
  }

  std::istream& operator>>(std::istream& is, Tablero& tab)
  {
    is >> tab.nAlinear >> tab.nInsertar >> tab.turno;
    is >> tab.matriz;
    return is;
  }
}

/* Fin fichero: tablero.cpp */
