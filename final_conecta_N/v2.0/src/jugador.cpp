/**
  * @file jugador.cpp
  * @brief Impmentación de la clase `Jugador`
  *
  */

#include <iostream>
#include <cstring>  // strlen, strcpy
#include <cassert>
#include <cstdlib>  // rand
#include "jugador.hpp"

namespace
{
  // Generar enteros pseudoaleatorios en el intervalo [minimo,maximo]
  inline int Uniforme(int minimo, int maximo)
  {
    double u01 = rand() / (RAND_MAX+1.0); // Uniforme01
    return minimo + (maximo-minimo+1) * u01;
  }
}

namespace ConectaN
{
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

  Posicion Jugador::escogeColumna(Tablero& tab, std::istream& is, std::ostream& os) const
  {
    assert(m_turno == tab.turnoActual());

    int cols = tab.getColumnas() - 1;
    char aux;
    Posicion p = {-1, -1};

    tab.prettyPrint();
    os << m_nombre << ", escoja una columna (a-" << static_cast<char>(97+cols) << "): ";
    is >> aux;
    os << std::endl;

    int c = aux - 'a';

    if(c < 0 || c > cols)
      return p;

    return tab.insertar(c);
  }

  void Jugador::sumaPuntos(const Tablero& tab)
  {
    m_puntos += tab.puntuacionPartida();
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

  IA::IA(int puntos, int ganadas, int empates, int turno)
    : Jugador("IA", turno, puntos, ganadas, empates) {}

  IA& IA::operator=(const Jugador& jug)
  {
    m_turno = jug.turno();
    m_ganadas = jug.ganadas();
    m_empates = jug.empates();
    m_turno = jug.turno();
    return *this;
  }

  Posicion IA::escogeColumna(Tablero& tab, std::istream& is, std::ostream& os) const
  {
    assert(m_turno == tab.turnoActual());

    Posicion p_ganadora = posicionGanadora(tab);
    Posicion error = {-1, -1};
    int c = p_ganadora.j;
    if (p_ganadora == error)
    {
      int cols = tab.getColumnas() - 1;

      do
      {
        c = Uniforme(0, cols);
      } while (tab.getElemento(0, c));
    }

    Posicion d = tab.insertar(c);
    return d;
  }

  Posicion IA::posicionGanadora(const Tablero& tab) const
  {
    Posicion direcciones[8] = { {1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1} };
    int ficha = tab.getElemento(tab.getUltPos());
    Posicion error = {-1, -1};
    if (ficha)
      for (int i = 0; i < 8; i++)
      {
        Posicion d = direcciones[i];
        Posicion hueco_medio = {-1, -1};
        Posicion hueco_final1 = {-1, -1};
        Posicion hueco_final2 = {-1, -1};
        int fichasAlineadas = 0;
        bool saltaEspacio = true;
        for (Posicion j = tab.getUltPos();
            tab.dentroTablero(j) && (tab.getElemento(j) == ficha || (saltaEspacio && !tab.getElemento(j) && tab.dentroTablero(j + d)
            && tab.getElemento(j + d) == ficha)); j = j + d, fichasAlineadas++)
        {
          Posicion aux_sig = j + d;
          if (!tab.getElemento(j) && tab.dentroTablero(aux_sig) && tab.getElemento(aux_sig))
          {
            hueco_medio = j;
            fichasAlineadas--;
            saltaEspacio = false;
          }
          if (tab.getElemento(j) && tab.dentroTablero(aux_sig) && !tab.getElemento(aux_sig))
            hueco_final1 = aux_sig;
        }

        for (Posicion j = tab.getUltPos();
             tab.dentroTablero(j) && (tab.getElemento(j) == ficha || (saltaEspacio && !tab.getElemento(j) && tab.dentroTablero(j - d)
             && tab.getElemento(j - d) == ficha)); j = j - d, fichasAlineadas++)
        {
          Posicion aux_sig = j - d;
          if (!tab.getElemento(j) && tab.dentroTablero(aux_sig) && tab.getElemento(aux_sig))
          {
            hueco_medio = j;
            fichasAlineadas--;
            saltaEspacio = false;
          }
          if (tab.getElemento(j) && tab.dentroTablero(aux_sig) && !tab.getElemento(aux_sig))
            hueco_final2 = aux_sig;
        }

        if (fichasAlineadas == tab.getNAlinear()) {
          if (hueco_medio == error)
          {
            if (hueco_final1 == error)
              return hueco_final2;
            else
              return hueco_final1;
          }
          else
            return hueco_medio;
          }
      }
    return error;
  }

  std::istream& operator>>(std::istream& is, IA& jug)
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
      jug = IA(puntos, ganadas, empates, turno);

    return is;
  }
}

/* Fin fichero: jugador.cpp */
