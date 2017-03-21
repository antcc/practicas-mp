#include <iostream>
#include <iomanip>  // setw, setfill
#include <cassert>
#include "tablero.hpp"

namespace ConectaN
{

  Posicion operator +(Posicion p1, Posicion p2)
  {
    Posicion res = {p1.i + p2.i, p1.j+p2.j};
    return res;
  }

  Posicion operator -(Posicion p1, Posicion p2)
  {
    Posicion res = {p1.i - p2.i, p1.j - p2.j};
    return res;
  }

  bool operator ==(Posicion p1, Posicion p2)
  {
    bool res = p1.i == p2.i && p1.j == p2.j;
    return res;
  }

  // ------------------------------------------------------------------------------------------
  // Constructores
  // ------------------------------------------------------------------------------------------

  Tablero::Tablero(int f, int c, int n, int nInsert) : matriz(f,c), nAlinear(n), nInsertar(nInsert),
                                                       turno(1)
  {
    assert(f >= 4 && c >= 4 && nAlinear >= 3 && nInsertar > 0 && nInsertar < nAlinear);
    ult_pos.i = 0;
    ult_pos.j = 0;
  }

  Tablero::Tablero() : nAlinear(0), nInsertar(0), turno(0)
  {
    ult_pos.i = 0;
    ult_pos.j = 0;
  }

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
        if (matriz(i,j))
          n++;
    return n;
  }

  int Tablero::puntuacionPartida() const
  {
    assert(partidaFinalizada());
    return matriz.getFilas() * matriz.getColumnas() + nAlinear * 2 + fichasTotales();
  }

  Posicion Tablero::insertar(int c)
  {
    Posicion p = {-1, c};
    for (int i = matriz.getFilas() - 1; i > -1; i--)
      if (matriz.getElemento(i, c) == 0)
      {
        matriz.setElemento(i, c, turno);
        p.i = i;
        if (fichasTotales() % nInsertar == 0)
          turno = turno == 1 ? 2 : 1;
        return p;
    }
    return p;
  }

  int Tablero::partidaFinalizada() const
  {
    Posicion direcciones[8] = { {1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1} };
    int ficha = getElemento(ult_pos);
    if (ficha)
      for (int i = 0; i < 8; i++)
      {
        Posicion d = direcciones[i];
        int fichasAlineadas = 1;
        for (Posicion j = ult_pos + d; dentroTablero(j) && getElemento(j) == ficha; j = j + d, fichasAlineadas++);
        for (Posicion j = ult_pos - d; dentroTablero(j) && getElemento(j) == ficha; j = j - d, fichasAlineadas++);
        if (fichasAlineadas == nAlinear)
          return ficha;
      }
    return 0;
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
