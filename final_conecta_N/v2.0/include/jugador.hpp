/**
  * @file jugador.hpp
  * @brief Interfaz de la clase `Jugador`
  *
  */

#ifndef _JUGADOR_HPP_
#define _JUGADOR_HPP_

#include <iosfwd>

namespace ConectaN
{
  class Tablero;

  /**
    * @class Jugador
    * @brief Representa un jugador (nombre, turno y puntos) del juego Conecta-N
    */
  class Jugador {
      // ------------------------------------------------------------------------------------------
      // Datos miembro
      // ------------------------------------------------------------------------------------------

      char *m_nombre;
      int m_turno;
      int m_puntos;
      int m_ganadas;
      int m_empates;

    public:
      // ------------------------------------------------------------------------------------------
      // Constructores y destructor
      // ------------------------------------------------------------------------------------------

      Jugador(const char* nombre, int turno, int puntos = 0, int ganadas = 0, int empates = 0);
      Jugador();
      Jugador(const Jugador& jug);
      ~Jugador() {delete[] m_nombre;}

      // ------------------------------------------------------------------------------------------
      // Operadores internos
      // ------------------------------------------------------------------------------------------

      Jugador& operator=(const Jugador& jug);

      // ------------------------------------------------------------------------------------------
      // Métodos set/get
      // ------------------------------------------------------------------------------------------

      const char* nombre() const {return m_nombre;}
      int turno() const {return m_turno;}
      int puntos() const {return m_puntos;}
      int ganadas() const {return m_ganadas;}
      int empates() const {return m_empates;}
      void aumentaGanadas() {m_ganadas++;}
      void aumentaEmpates() {m_empates++;}

      // ------------------------------------------------------------------------------------------
      // Métodos públicos
      // ------------------------------------------------------------------------------------------

      int escogeColumna(Tablero& tab) const;
      void sumaPuntos(const Tablero& tab);
  };

  // ------------------------------------------------------------------------------------------
  // Operadores I/O
  // ------------------------------------------------------------------------------------------

  std::ostream& operator<<(std::ostream& os, const Jugador& jug);
  std::istream& operator>>(std::istream& is, Jugador& jug);
}

#endif

/* Fin fichero: jugador.hpp */
