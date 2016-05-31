/**
  * @file tablero.cpp
  * @brief Impmentación de la clase `Tablero`
  *
  */
#include <iostream>
#include <iomanip>  // setw, setfill
#include <cassert>
#include "tablero.h"

Tablero::Tablero() : m_tablero(0,0)
{
  m_fichas = 0;
  m_turno = 0;
  m_finalizada = false;
}

Tablero::Tablero(int f, int c, int fichas) : m_tablero(f,c)
{
  assert(f >= 4 && c >= 4 && fichas >= 3 && fichas < (f <= c) ? f : c);
  m_fichas = fichas;
  m_turno = 1;
  m_finalizada = false;
}

bool Tablero::compruebaFinalizada() const
{
  int fils = filas();
  int cols = columnas();
  int f,c;
  bool finalizada = false;

  if (fichasTotales() >= fils*cols)
    return true;

  for (int i = fils - 1; i >= 0 && !finalizada; i--) {
    for (int j = 0; j < cols && !finalizada; j++) {
      TipoFicha ficha = get(i,j);
      if (ficha != VACIA) {
        f = i-1;
        int n = 1;
        while(n < m_fichas && f >= 0 && get(f,j) == ficha) {
          n++;
          f--;
        }
        finalizada = n == m_fichas;

        if (!finalizada) {
          c = j+1;
          n = 1;
          while(n < m_fichas && c < cols && get(i,c) == ficha) {
            n++;
            c++;
          }
          finalizada = n == m_fichas;
        }

        if (!finalizada) {
          f = i-1;
          c = j+1;
          n = 1;
          while(n < m_fichas && c < cols && f >= 0 && get(f,c) == ficha) {
            n++;
            f--;
            c++;
          }
          finalizada = n == m_fichas;
        }

        if (!finalizada) {
          f = i+1;
          c = j+1;
          n = 1;
          while(n < m_fichas && c < cols && f < fils && get(f,c) == ficha) {
            n++;
            f++;
            c++;
          }
          finalizada = n == m_fichas;
        }
      }
    }
  }

  return finalizada;
}

Tablero::TipoFicha Tablero::get(int f, int c) const
{
  return static_cast<TipoFicha>(m_tablero.get(f,c));
}

int Tablero::fichasTotales() const
{
  int fils = filas();
  int cols = columnas();
  int fichas = 0;

  for (int i = 0; i < fils; i++)
    for (int j = 0; j < cols; j++)
      if (m_tablero.get(i,j) != VACIA)
        fichas++;

  return fichas;
}

void Tablero::insertar(int c)
{
  TipoFicha ficha = m_turno == 1 ? FICHA_J1 : FICHA_J2;
  int f = filas() - 1;
  c -= 1;

  while(get(f,c) != VACIA)
    f--;

  assert(f >= 0);
  m_tablero.set(f,c,ficha);
  m_turno = m_turno == 1 ? 2 : 1;
  m_finalizada = compruebaFinalizada();
}

int Tablero::ganador() const
{
  int ganador = 0;

  if (m_finalizada)
    if (fichasTotales() < filas() * columnas())
      ganador = m_turno == 1 ? 2 : 1;

  return ganador;
}

int Tablero::puntuacion() const
{
  assert(m_finalizada);
  int puntos = 0;
  int tam = filas() * columnas();

  puntos += 2 * tam;
  puntos += m_fichas * (m_fichas - 1);
  puntos += tam - (fichasTotales() % tam);

  return puntos;
}

void Tablero::prettyPrint(std::ostream& os) const
{
  int fils = filas();
  int cols = columnas();

  // Colores (ANSI escape colors)
  const char* ROJO = "\033[0;31m";
  const char* AMARILLO = "\033[0;33m";
  const char* DEFAULT = "\033[0m";

  for (char i = 97; i < 97 + cols; i++)
    os << "[" << i << "] ";
  os << std::endl;

  for (int i = 0; i < fils; i++) {
    for (int j = 0; j < cols; j++) {
      os << "[";
      if (get(i,j) == FICHA_J1)
        os << ROJO << "x" << DEFAULT;
      else if (get(i,j) == FICHA_J2)
        os << AMARILLO << "o" << DEFAULT;
      else
        os << " ";
      os << "] ";
    }
    os << std::endl;
  }

  os << std::setfill('=') << std::setw(4 * columnas())
     << " " << std::endl;

  if (!m_finalizada) {
    if (m_turno == 1)
      os << "Turno: jugador 1 (" << ROJO << "x" << DEFAULT << ")";
    else
      os << "Turno: jugador 2 (" << AMARILLO << "o" << DEFAULT << ")";
    os << std::endl;
  }
  else {
    os << "Partida finalizada. ";
      if (ganador() == 1)
        os << "Ganador: jugador 1.\n";
      else if (ganador() == 2)
        os << "Ganador: jugador 2.\n";
      else
        os << "La partida terminó en empate.\n";
  }
}

void Tablero::vaciar()
{
  m_tablero.reset();
  m_finalizada = false;

  // Cambiar turno
  if (fichasTotales()%2 != 0)
    m_turno = m_turno == 1 ? 2 : 1;
}

std::ostream& operator<<(std::ostream& os, const Tablero& tab)
{
  os << tab.m_fichas << " " << tab.m_turno << std::endl;
  os << tab.m_tablero;
  return os;
}

std::istream& operator>>(std::istream& is, Tablero& tab)
{
  is >> tab.m_fichas >> tab.m_turno;
  is >> tab.m_tablero;
  return is;
}

/* Fin fichero: tablero.cpp */
