/**
  * @file jugador.hpp
  * @brief Interfaz de la clase `Jugador`
  *
  */

#ifndef _JUGADOR_HPP_
#define _JUGADOR_HPP_

#include <iosfwd>
#include "tablero.hpp"

namespace ConectaN
{
  /**
    * @class Jugador
    * @brief Representa un jugador (nombre, turno y puntos) del juego Conecta-N
    */
  class Jugador
  {
    protected:
      char* m_nombre;
      int m_turno;
      int m_puntos;
      int m_ganadas;
      int m_empates;

    public:
      Jugador();
      Jugador(const char* nombre, int turno, int puntos = 0, int ganadas = 0, int empates = 0);
      Jugador(const Jugador& jug);
      virtual ~Jugador() {delete[] m_nombre;}
      Jugador& operator=(const Jugador& jug);
      const char* nombre() const {return m_nombre;}
      int turno() const {return m_turno;}
      int puntos() const {return m_puntos;}
      int ganadas() const {return m_ganadas;}
      int empates() const {return m_empates;}
      void aumentaGanadas() {m_ganadas++;}
      void aumentaEmpates() {m_empates++;}
      virtual Posicion escogeColumna(Tablero& tab, std::istream& is = std::cin, std::ostream& os = std::cout) const;
      void sumaPuntos(const Tablero& tab);
  };

  /**
  * @class IA
  * @brief Representa una inteligencia artificial básica, derivada de Jugador.
  */
  class IA : public Jugador
  {
    public:
      IA(int puntos = 0, int ganadas = 0, int empates = 0, int turno = 2);
      IA& operator=(const Jugador& jug);
      Posicion escogeColumna(Tablero& tab, std::istream& is = std::cin, std::ostream& os = std::cout) const;
      Posicion posicionGanadora(const Tablero& tab) const;
  };

  std::ostream& operator<<(std::ostream& os, const Jugador& jug);
  std::istream& operator>>(std::istream& is, Jugador& jug);
  std::istream& operator>>(std::istream& is, IA& jug);
}

#endif

/* Fin fichero: jugador.hpp */
