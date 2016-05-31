/**
  * @file jugador.h
  * @brief Interfaz de la clase `Jugador`
  *
  */

#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include <iosfwd>

class Tablero;

/**
  * @class Jugador
  * @brief Representa un jugador (nombre, turno y puntos) del juego Conecta-N
  */
class Jugador {
    char *m_nombre;
    int m_turno;
    int m_puntos;
    int m_ganadas;
    int m_empates;
  public:
    Jugador();
    Jugador(const char* nombre, int turno, int puntos = 0, int ganadas = 0, int empates = 0);
    Jugador(const Jugador& jug);
    ~Jugador() {delete[] m_nombre;}
    Jugador& operator=(const Jugador& jug);
    const char* nombre() const {return m_nombre;}
    int turno() const {return m_turno;}
    int puntos() const {return m_puntos;}
    int ganadas() const {return m_ganadas;}
    int empates() const {return m_empates;}
    void aumentaGanadas() {m_ganadas++;}
    void aumentaEmpates() {m_empates++;}
    bool escogeColumna(Tablero& tab) const;
    void sumaPuntos(const Tablero& tab);
};

/**
  * @brief Sobrecarga el operador de salida de datos para escribir un jugador
  */
std::ostream& operator<<(std::ostream& os, const Jugador& jug);

/**
  * @brief Sobrecarga el operador de entrada de datos para leer un jugador
  */
std::istream& operator>>(std::istream& is, Jugador& jug);

#endif

/* Fin fichero: jugador.h */
