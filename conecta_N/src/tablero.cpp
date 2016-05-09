/**
  * @file tablero.cpp
  * @brief Impmentación de la clase `Tablero`
  *
  */

#include <iostream>
#include <iomanip>  // setw, setfill
#include <cassert>
#include "tablero.h"

Tablero::Tablero(int f, int c, int fichas)
{
  m_tablero = Matriz(f,c);
  m_fichas = fichas;
  m_turno = 1;
}

TipoFicha Tablero::get(int f, int c) const
{
  return static_cast<TipoFicha>(m_tablero.get(f,c));
}

bool Tablero::finalizada() const
{
  int fils = filas();
  int cols = columnas();
  int f,c;
  bool finalizada = false;

  if (m_turno > fils*cols)
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

int Tablero::ganador() const
{
  int ganador = 0;

  if (finalizada()) {
    if (m_turno < filas() * columnas())
      ganador = m_turno%2 == 0 ? 1 : 2;
  }

  return ganador;
}

int Tablero::puntuacion() const
{
  assert(finalizada());
  int puntos = 0;
  int tam = filas() * columnas();

  puntos += 2 * tam;
  puntos += m_fichas;
  puntos += m_turno % tam;

  return puntos;
}

void Tablero::insertar(int c)
{
  TipoFicha ficha = turnoActual()%2 == 0 ? FICHA_J2 : FICHA_J1;
  int f = filas() - 1;
  c -= 1;

  while(get(f,c) != VACIA)
    f--;

  assert(f >= 0);
  m_tablero.set(f,c,ficha);
  m_turno++;
}

void Tablero::vaciar()
{
  m_tablero.reset();
  m_turno = 1;
}

void Tablero::prettyPrint(bool fin) const
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

  std::cout << std::setfill('=') << std::setw(4*columnas())
            << " " << std::endl;

  if (!fin) {
    if (m_turno%2 == 0)
      std::cout << "Turno: jugador 2 (o)";
    else
      std::cout << "Turno: jugador 1 (x)";
    std::cout << std::endl;
  }
  else {
    std::cout << "Partida finalizada. ";
      if (ganador() == 1)
        std::cout << "El ganador es el jugador 1, con " << puntuacion() << " puntos.\n";
      else if (ganador() == 2)
        std::cout << "El ganador es el jugador 2, con " << puntuacion() << " puntos.\n";
      else
        std::cout << "La partida terminó en empate.\n";
  }
}

/* Fin fichero: tablero.cpp */
