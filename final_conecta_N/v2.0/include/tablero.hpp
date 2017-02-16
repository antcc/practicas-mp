/**
  * @file tablero.hpp
  * @brief Interfaz de la clase `Tablero`
  *
  */

#ifndef _TABLERO_HPP_
#define _TABLERO_HPP_

#include <iosfwd>
#include "matriz.hpp"

namespace ConectaN
{
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
      int getElemento(int f, int c) const {return matriz(f,c);}
      int turnoActual() const {return turno;}
      void setNAlinear(int n);
      void setNInsertar(int n);

      // ------------------------------------------------------------------------------------------
      // Métodos públicos
      // ------------------------------------------------------------------------------------------

      int fichasTotales() const;
      int puntuacionPartida() const;
      int fichasRestantes() const {return nInsertar - fichasTotales() % nInsertar;}
      int partidaFinalizada(int i, int j, int n = 0, int s = 0) const;
      int partidaFinalizada() const;
      int ultimaFilaLibre(int col) const;
      void insertar(int c);
      void prettyPrint(char c1 = 'x', char c2 = 'o', std::ostream& os = std::cout) const;
      void vaciar();

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

/* Fin fichero: tablero.hpp */
