/**
  * @file tablero.h
  * @brief Interfaz de la clase `Tablero`
  *
  */

#ifndef _TABLERO_H_
#define _TABLERO_H_

#include "matriz.h"

/**
  * @class Tablero
  * @brief Gestiona un tablero de tamaño variable para el juego Conecta-N
  */
class Tablero {
    Matriz m_tablero;
    const int M_FICHAS;
    int m_turno;
    bool m_finalizada;

    /**
      * @brief Comprueba si hay alguna alineación de `M_FICHAS`
      *
      * @retval @a true si la partida ha finalizado con un ganador
      * @retval @a false si la partida aún no hay un ganador
      */
    bool compruebaFinalizada() const;
  public:
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

    Tablero(int f, int c, int fichas);  //@pre 4 <= f,c <= 20, 3 <= fichas < min{f,c} - 1
    int filas() const {return m_tablero.filas();}
    int columnas() const {return m_tablero.columnas();}
    int fichas() const {return M_FICHAS;}
    int turnoActual() const {return m_turno;}
    bool finalizada() const {return m_finalizada;}
    TipoFicha get(int f, int c) const;
    int fichasTotales() const;
    void insertar(int c);   // las columnas empiezan en 1
    int ganador() const;  // 0 empate(o no finalizado), 1 j1, 2 j2
    int puntuacion() const; // @pre: la partida debe estar finalizada
    void prettyPrint() const;
    void vaciar();
};

#endif

/* Fin fichero: tablero.h */
