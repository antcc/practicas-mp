#ifndef _TABLERO_HPP_
#define _TABLERO_HPP_

#include <iosfwd>
#include "matriz.hpp"

namespace ConectaN
{
  struct Posicion
  {
    int i;
    int j;
  };

  Posicion operator +(Posicion p1, Posicion p2);
  Posicion operator -(Posicion p1, Posicion p2);
  bool operator ==(Posicion p1, Posicion p2);

  /**
    * @class Tablero
    * @brief Gestiona un tablero de tamaño variable para el juego Conecta-N
    */
  class Tablero
  {
      // ------------------------------------------------------------------------------------------
      // Datos miembro
      // ------------------------------------------------------------------------------------------
      Matriz<int> matriz;
      int nAlinear;
      int nInsertar;
      int turno;
      Posicion ult_pos;

      // ------------------------------------------------------------------------------------------
      // Méotodos privados
      // ------------------------------------------------------------------------------------------
      int jugadorAnterior() const {return turno == 1 ? 2 : 1;}

    public:
      // ------------------------------------------------------------------------------------------
      // Constructores
      // ------------------------------------------------------------------------------------------
      Tablero(int f, int c, int nAlinear, int nInsert);
      Tablero();

      // ------------------------------------------------------------------------------------------
      // Métodos set/get
      // ------------------------------------------------------------------------------------------
      Matriz<int> getMatriz() const {return matriz;}
      int getFilas() const {return matriz.getFilas();}
      int getColumnas() const {return matriz.getColumnas();}
      int getNAlinear() const {return nAlinear;}
      int getNInsertar() const {return nInsertar;}
      Posicion getUltPos() const {return ult_pos;}
      int getElemento(int f, int c) const {return matriz(f,c);}
      int getElemento(Posicion p) const {return matriz(p.i,p.j);}
      int turnoActual() const {return turno;}
      void setNAlinear(int n);
      void setNInsertar(int n);
      void setUltPos(Posicion p) {ult_pos = p;}

      // ------------------------------------------------------------------------------------------
      // Métodos públicos
      // ------------------------------------------------------------------------------------------
      int fichasTotales() const;
      int puntuacionPartida() const;
      int partidaFinalizada() const;
      int ultimaFilaInsertada(int col) const;
      Posicion insertar(int c);
      void prettyPrint(char c1 = 'x', char c2 = 'o', std::ostream& os = std::cout) const;
      void vaciar();
      bool dentroTablero(Posicion p) const {return p.i > -1 && p.i < getFilas() && p.j > -1 && p.j < getColumnas();}

      // ------------------------------------------------------------------------------------------
      // Declaración amistad operadores I/O
      // ------------------------------------------------------------------------------------------
      friend std::ostream& operator<<(std::ostream& os, const Tablero& tab);
      friend std::istream& operator>>(std::istream& is, Tablero& tab);
  };

  // ------------------------------------------------------------------------------------------
  // Operadores I/O
  // ------------------------------------------------------------------------------------------
  std::ostream& operator<<(std::ostream& os, const Tablero& tab);
  std::istream& operator>>(std::istream& is, Tablero& tab);
}

#endif
