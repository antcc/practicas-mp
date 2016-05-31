/**
  * @file conectaN.cpp
  * @brief Módulo para jugar una partida de Conecta-N
  *
  * Un ejemplo de ejecución es:
  * ```
  * ./conectaN
  * ```
  */

#include <iostream>
#include <fstream>
#include <cstring>  // strcmp
#include <ctime>  // time
#include <cstdlib>  // srand, rand
#include "tablero.h"
#include "jugador.h"
using namespace std;

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

int main(int argc, char* argv[])
{
  const int MIN = 4;
  int f, c, fichas;
  char nombre_j1[1024];
  char nombre_j2[1024];
  Tablero tab;
  Jugador j1, j2;

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
    cout << "Introduzca el nombre del primer jugador: ";
    cin >> nombre_j1;
    cout << "Introduzca el nombre del segundo jugador: ";
    cin >> nombre_j2;
    cout << endl;

    tab = Tablero(f,c,fichas);
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

  // Bucle principal del juego
  bool jugar = true;
  while (jugar) {
    /*
      En cada partida, mientras que esta no finalice, cada
      jugador escoge por turnos una columna para insertar
      una ficha.
    */
    while(!tab.finalizada()) {
      if(tab.turnoActual() == 1) {
        if (!j1.escogeColumna(tab)) {
          cout << "Columna incorrecta. ";
          DialogoSalvar(tab, j1, j2);
          cout << endl;
        }
      }
      else {
        if (!j2.escogeColumna(tab)) {
          cout << "Columna incorrecta. ";
          DialogoSalvar(tab, j1, j2);
          cout << endl;
        }
      }
    }
    tab.prettyPrint();  // imprimir estado final

    if(tab.ganador() == 1) {
      j1.aumentaGanadas();
      j1.sumaPuntos(tab);
    }
    else if (tab.ganador() == 2) {
      j2.aumentaGanadas();
      j2.sumaPuntos(tab);
    }
    else {
      j1.aumentaEmpates();
      j2.aumentaEmpates();
    }

    cout << "\n-- Resultados tras la partida --\n";
    cout << j1.nombre() << ": " << j1.ganadas() << " ganadas que acumulan "
         << j1.puntos() << " puntos.\n";
    cout << j2.nombre() << ": " << j2.ganadas() << " ganadas que acumulan "
         << j2.puntos() << " puntos.\n";

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
  cout << j1.nombre() << ": " << j1.ganadas() << " ganadas que acumulan "
       << j1.puntos() << " puntos.\n";
  cout << j2.nombre() << ": " << j2.ganadas() << " ganadas que acumulan "
       << j2.puntos() << " puntos.\n";
  cout << j1.empates() << " empates.\n\n";

  DialogoSalvar(tab, j1, j2);
}

/* Fin fichero: conectaN.cpp */
