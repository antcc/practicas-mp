/**
  * @file jugador.cpp
  * @brief Impmentación de la clase `Jugador`
  *
  */

#include <iostream>
#include <cstring>  // strlen, strcpy
#include <cassert>
#include <cstdlib>  // rand
#include "jugador.h"
#include "tablero.h"

namespace
{
  // Generar enteros pseudoaleatorios en el intervalo [minimo,maximo]
  inline int Uniforme(int minimo, int maximo)
  {
    double u01= rand() / (RAND_MAX+1.0); // Uniforme01
    return minimo + (maximo-minimo+1) * u01;
  }
}

Jugador::Jugador()
{
  m_nombre = 0;
  m_turno = m_puntos = 0;
  m_ganadas = m_empates = 0;
}

Jugador::Jugador(const char* nombre, int turno, int puntos, int ganadas, int empates)
{
  m_nombre = new char[strlen(nombre)];
  strcpy(m_nombre, nombre);
  m_turno = turno;
  m_puntos = puntos;
  m_ganadas = ganadas;
  m_empates = empates;
}

Jugador::Jugador(const Jugador& jug)
{
  m_nombre = new char[strlen(jug.m_nombre)];
  strcpy(m_nombre, jug.m_nombre);
  m_turno = jug.m_turno;
  m_puntos = jug.m_puntos;
  m_ganadas = jug.m_ganadas;
  m_empates = jug.m_empates;
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

  i = m_ganadas;
  m_ganadas = aux.m_ganadas;
  aux.m_ganadas = i;

  i = m_empates;
  m_empates = aux.m_empates;
  aux.m_empates = i;

  return *this;
}

bool Jugador::escogeColumna(Tablero& tab) const
{
  assert(m_turno == tab.turnoActual());

  int cols = tab.columnas() - 1;
  char c;

  if (m_nombre[0] == '@') {
    do {
    c = Uniforme('a', 'a' + cols);
    } while (tab.get(0, c-97) != Tablero::VACIA);

    tab.insertar(c-96);
  }
  else {
    tab.prettyPrint();

    std::cout << m_nombre << ", escoja una columna (a-" << static_cast<char>(97+cols) << "): ";
    std::cin >> c;
    std::cout << std::endl;

    if(c < 97 || c > 97+cols)
      return false;

    tab.insertar(c-96);  // las columnas empiezan en 1
  }
  return true;
}

void Jugador::sumaPuntos(const Tablero& tab)
{
  m_puntos += tab.puntuacion();
}

std::ostream& operator<<(std::ostream& os, const Jugador& jug)
{
  os << "#" << jug.nombre() << std::endl;
  os << jug.turno() << ' ' << jug.puntos() << std::endl;
  os << jug.ganadas() << ' ' << jug.empates();

  return os;
}

std::istream& operator>>(std::istream& is, Jugador& jug)
{
  char nombre[1024];
  int turno, puntos;
  int ganadas, empates;

  while (is.peek() != '#')
    is.ignore();

  is.ignore();  // ignorar '#'
  is.getline(nombre, 1024);
  is >> turno >> puntos;
  is >> ganadas >> empates;
  if (is)
    jug = Jugador(nombre, turno, puntos, ganadas, empates);

  return is;
}

/* Fin fichero: jugador.cpp */
