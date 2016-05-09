/**
  * @file tablero.h
  * @brief Interfaz de la clase `Tablero`
  *
  */

#ifndef _TABLERO_H_
#define _TABLERO_H_

#include "matriz.h"

/**
  * @brief Tipo de ficha
  *
  * Declara una serie de constantes para codificar los distintos tipos
  * de fichas (contenido de cada casilla del tablero) que pueden darse
  * a la hora de representar un tablero del juego Conecta-N.
  *
  */
enum TipoFicha { VACIA,    ///<  Representa una ficha o casilla vacia
                 FICHA_J1, ///<  Representa una ficha del jugador 1
                 FICHA_J2  ///<  Representa una ficha del jugador 2
                };

/**
  * @class Tablero
  * @brief Gestiona un tablero de tamaño variable para el juego Conecta-N
  */
class Tablero {
    Matriz m_tablero;
    int m_fichas;
    int m_turno;
  public:
    Tablero(int f, int c, int fichas);
    int filas() const {return m_tablero.filas();}
    int columnas() const {return m_tablero.columnas();}
    int fichas() const {return m_fichas;}
    TipoFicha get(int f, int c) const;
    bool finalizada() const;
    int turnoActual() const {return m_turno;}
    int ganador() const;  // 0 empate(o no finalizado), 1 j1, 2 j2
    int puntuacion() const; // @pre: la partida debe estar finalizada
    void insertar(int c);   // las columnas empiezan en 1
    void vaciar();
    void prettyPrint(bool fin = false) const;
};

#endif

/* Fin fichero: tablero.h */
