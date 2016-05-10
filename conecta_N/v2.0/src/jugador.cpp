/**
  * @file jugador.cpp
  * @brief Impmentación de la clase `Jugador`
  *
  */

#include <iostream>
#include <cstring>  // strlen, strcpy
#include <cassert>
#include "jugador.h"

Jugador::Jugador(char* nombre, int turno)
{
  m_nombre = new char[strlen(nombre)];
  strcpy(m_nombre, nombre);
  m_turno = turno;
  m_puntos = 0;
}

Jugador::Jugador(const Jugador& jug)
{
  m_nombre = new char[strlen(jug.m_nombre)];
  strcpy(m_nombre, jug.m_nombre);
  m_turno = jug.m_turno;
  m_puntos = jug.m_puntos;
}

Jugador& Jugador::operator=(const Jugador& jug)
{
  Jugador aux(jug);

  char *p = m_nombre;
  m_nombre = aux.m_nombre;
  aux.m_nombre = p;

  int i = m_turno;
  m_turno = aux.m_turno;
  aux.m_turno = i;

  i = m_puntos;
  m_puntos = aux.m_puntos;
  aux.m_puntos = i;

  return *this;
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
