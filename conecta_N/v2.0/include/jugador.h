/**
  * @file jugador.h
  * @brief Interfaz de la clase `Jugador`
  *
  */

#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "tablero.h"

/**
  * @class Jugador
  * @brief Representa un jugador (nombre, turno y puntos) del juego Conecta-N
  */
class Jugador {
    char *m_nombre;
    int m_turno;
    int m_puntos;
  public:
    Jugador(char* nombre, int turno);
    Jugador(const Jugador& jug);
    ~Jugador() {delete[] m_nombre;}
    Jugador& operator=(const Jugador& jug);
    const char* nombre() const {return m_nombre;}
    int turno() const {return m_turno;}
    int puntos() const {return m_puntos;}
    void escogeColumna(Tablero& tab) const;
    void sumaPuntos(const Tablero& tab);
};

#endif

/* Fin fichero: jugador.h */
