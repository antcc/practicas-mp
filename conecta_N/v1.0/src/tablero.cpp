/**
  * @file tablero.cpp
  * @brief Impmentación de la clase `Tablero`
  *
  */

#include <iostream>
#include <iomanip>  // setw, setfill
#include <cassert>
#include "tablero.h"

Tablero::Tablero(int f, int c, int fichas) : m_tablero(f,c), M_FICHAS(fichas)
{
  assert(f >= 4 && c >= 4 && fichas >= 3 && fichas < (f <= c) ? f : c);
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
        while(n < M_FICHAS && f >= 0 && get(f,j) == ficha) {
          n++;
          f--;
        }
        finalizada = n == M_FICHAS;

        if (!finalizada) {
          c = j+1;
          n = 1;
          while(n < M_FICHAS && c < cols && get(i,c) == ficha) {
            n++;
            c++;
          }
          finalizada = n == M_FICHAS;
        }

        if (!finalizada) {
          f = i-1;
          c = j+1;
          n = 1;
          while(n < M_FICHAS && c < cols && f >= 0 && get(f,c) == ficha) {
            n++;
            f--;
            c++;
          }
          finalizada = n == M_FICHAS;
        }

        if (!finalizada) {
          f = i+1;
          c = j+1;
          n = 1;
          while(n < M_FICHAS && c < cols && f < fils && get(f,c) == ficha) {
            n++;
            f++;
            c++;
          }
          finalizada = n == M_FICHAS;
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
  int fichas = 0;

  for (int i = 0; i < filas(); i++)
    for (int j = 0; j < columnas(); j++)
      if (m_tablero.get(i,j) != VACIA)
        fichas++;

  return fichas;
}

void Tablero::insertar(int c)
{
  TipoFicha ficha = turnoActual() == 1 ? FICHA_J1 : FICHA_J2;
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
  puntos += M_FICHAS * (M_FICHAS - 1);
  puntos += tam - (fichasTotales() % tam);

  return puntos;
}

void Tablero::prettyPrint() const
{
  int fils = filas();
  int cols = columnas();

  for (char i = 97; i < 97 + cols; i++)
    std::cout << "[" << i << "] ";
  std::cout << std::endl;

  for (int i = 0; i < fils; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << "[";
      if (get(i,j) == FICHA_J1)
        std::cout << "x";
      else if (get(i,j) == FICHA_J2)
        std::cout << "o";
      else
        std::cout << " ";
      std::cout << "] ";
    }
    std::cout << std::endl;
  }

  std::cout << std::setfill('=') << std::setw(4 * columnas())
            << " " << std::endl;

  if (!m_finalizada) {
    if (m_turno == 1)
      std::cout << "Turno: jugador 1 (x)";
    else
      std::cout << "Turno: jugador 2 (o)";
    std::cout << std::endl;
  }
  else {
    std::cout << "Partida finalizada. ";
      if (ganador() == 1)
        std::cout << "Ganador: jugador 1.\n";
      else if (ganador() == 2)
        std::cout << "Ganador: jugador 2.\n";
      else
        std::cout << "La partida terminó en empate.\n";
  }
}

void Tablero::vaciar()
{
  m_tablero.reset();
  m_turno = 1;
  m_finalizada = false;
}

/* Fin fichero: tablero.cpp */
