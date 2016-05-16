/**
  * @file jugador.cpp
  * @brief Impmentación de la clase `Jugador`
  *
  */

#include <iostream>
#include <cstring>  // strcpy
#include <cassert>
#include "jugador.h"

Jugador::Jugador(char *nombre, int turno)
{
  strcpy(m_nombre, nombre);
  m_turno = turno;
  m_puntos = 0;
}

void Jugador::escogeColumna(Tablero& tab) const
{
  assert(m_turno == tab.turnoActual());

  int cols = tab.columnas() - 1;
  char c;

  tab.prettyPrint();

  do {
    std::cout << m_nombre << ", escoja una columna (a-" << static_cast<char>(97+cols) << "): ";
    std::cin >> c;
  } while (c < 97 || c > 97+cols);

  std::cout << std::endl;
  tab.insertar(c-96);  // las columnas empiezan en 1
}

void Jugador::sumaPuntos(const Tablero& tab)
{
  m_puntos += tab.puntuacion();
}

/* Fin fichero: jugador.cpp */
