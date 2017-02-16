/**
  * @file conectaN.cpp
  * @brief Módulo para jugar una partida de Conecta-N
  *
  * Un ejemplo de ejecución es:
  * ```
  * ./conectaN partida.conf
  * ```
  */

#include <iostream>
#include <fstream>
#include <cstring>  // strcmp
#include <ctime>  // time
#include <cstdlib>  // srand, rand
#include "tablero.hpp"
#include "jugador.hpp"

using namespace std;
using namespace ConectaN;

const char* CONF_ID = "#MP-CONECTAN-1.0";

void Cargar(const char* nombre, Tablero& tab,
            Jugador& jug1, Jugador& jug2)
{
  ifstream f(nombre);
  char aux[1024];
  while(isspace(f.peek()))
    f.ignore();

  f.getline(aux,1024);
  if(!strcmp(aux, CONF_ID)) {
    f >> jug1;
    f >> jug2;
    f >> tab;
  }
}

void Salvar(const char* nombre, const Tablero& tab,
            const Jugador& jug1, const Jugador& jug2)
{
  ofstream f(nombre);

  f << CONF_ID << '\n';
  f << jug1 << endl;
  f << jug2 << endl;
  f << tab;
}

void DialogoSalvar (const Tablero& tab,
                    const Jugador& jug1, const Jugador& jug2)
{
  char c;
  cout << "¿Desea guardar la partida? (S/N): ";
  do {
    cin >> c;
    c = tolower(c);
  } while (c != 's' && c != 'n');

  if (c == 's') {
    char nombre[1024];
    cout << "Introduzca el nombre del archivo de configuración: ";
    cin >> nombre;
    Salvar(nombre, tab, jug1, jug2);
    cout << "Partida guardada.\n";
  }
}

void MuestraResultados (const Jugador& j1, const Jugador& j2)
{
    cout << j1.nombre() << ": " << j1.ganadas() << " ganadas que acumulan "
         << j1.puntos() << " puntos.\n";
    cout << j2.nombre() << ": " << j2.ganadas() << " ganadas que acumulan "
         << j2.puntos() << " puntos.\n";
}

int main(int argc, char* argv[])
{
  const int MIN = 4;
  int f, c, fichas, nInsertar;
  char nombre_j1[1024];
  char nombre_j2[1024];
  Tablero tab;
  Jugador j1;
  Jugador j2;

  if (argc == 1) {
    cout << "Introduzca filas: ";
    do {
      cin >> f;
    } while(f < MIN);
    cout << "Introduzca columnas: ";
    do {
      cin >> c;
    } while(c < MIN);

    int min = f <= c ? f : c;

    cout << "Introduzca fichas a alinear " << "(3-" << min-1 << "): ";
    do {
      cin >> fichas;
    } while(fichas < 3 || fichas >= min);

    cout << "Número de fichas a introducir en cada turno " << "(1-" << fichas-2 << "): ";
    do {
      cin >> nInsertar;
    } while (nInsertar < 1 || nInsertar > fichas-2);
    cout << "Introduzca el nombre del primer jugador: ";
    cin >> nombre_j1;
    cout << "Introduzca el nombre del segundo jugador: ";
    cin >> nombre_j2;
    cout << endl;

    tab = Tablero(f,c,fichas, nInsertar);
    j1 = Jugador(nombre_j1, 1),
    j2 = Jugador(nombre_j2, 2);
  }
  else if (argc == 2) {
    Cargar(argv[1], tab, j1, j2);
    cout << "Partida cargada.\n";
  }
  else {
    cerr << "conectaN: el programa se inicia sin parámetros, "
         << "o proporcionando un archivo de configuración.\n";
    return 1;
  }

  // Semilla para jugador automático
  if (j1.nombre()[0] == '@' || j2.nombre()[0] == '@' )
    srand(time(0));

  Jugador *jugador;
  int ganador;

  // Bucle principal del juego
  bool jugar = true;
  while (jugar) {
    /*
      En cada partida, mientras que esta no finalice, cada
      jugador escoge por turnos una columna para insertar
      una ficha.
    */
    int turno;
    bool finalizada = false;
    while(!finalizada) {
      turno = tab.turnoActual();
      jugador = turno == 1 ? &j1 : &j2;
      int insertadas = 0;
      while (insertadas < tab.getNInsertar() && !finalizada) {
        int c = jugador->escogeColumna(tab);

        if (c == -1) {
          cout << "Columna incorrecta. ";
          DialogoSalvar(tab, j1, j2);
          cout << endl;
        }
        else {
          int f = tab.ultimaFilaLibre(c-1) + 1; // +1 porque queremos la última fila insertada
          cout << tab.fichasRestantes() << ' ' << tab.turnoActual() << endl;
          ganador = tab.partidaFinalizada(f,c-1); // c-1 porque las columnas empezaban en 1
          finalizada = ganador || (tab.fichasTotales() == tab.getFilas() * tab.getColumnas());
          insertadas++;
        }
      }
    }
    tab.prettyPrint();  // imprimir estado final
    cout << "Partida finalizada. ";
    if (ganador == 1)
      cout << "Ganador: jugador 1.\n";
    else if (ganador == 2)
      cout << "Ganador: jugador 2.\n";
    else
      cout << "La partida terminó en empate.\n";
    jugador = ganador ? (ganador == 1 ? &j1 : &j2) : 0;

    if(jugador)
    {
      jugador->aumentaGanadas();
      jugador->sumaPuntos(tab);
    }
    else {
      j1.aumentaEmpates();
      j2.aumentaEmpates();
    }

    cout << "\n-- Resultados tras la partida --\n";
    MuestraResultados(j1, j2);

    char c;
    cout << "\n¿Jugar de nuevo? (S/N): ";
    do {
      cin >> c;
      c = tolower(c);
    } while (c != 's' && c != 'n');
    cout << endl;

    if (c != 's')
      jugar = false;

    tab.vaciar();
  }
  cout << "Resultados finales:\n";
  MuestraResultados(j1,j2);
  cout << j1.empates() << " empates.\n\n";

  DialogoSalvar(tab, j1, j2);
}

/* Fin fichero: conectaN.cpp */
