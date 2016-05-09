/**
  * @file conectaN.cpp
  * @brief Módulo para jugar una partida de Conecta-N
  *
  * Un ejemplo de ejecución es:
  *
  */

#include <iostream>
#include "tablero.h"
#include "jugador.h"
using namespace std;

int main(int argc, char* argv[])
{
  Tablero tab(6,7,4);
  cout << "Se ha creado un tablero de " << tab.filas() << " filas y " << tab.columnas()
       << " columnas, donde se deben conectar " << tab.fichas() << " fichas en línea.\n\n";

  char c;
  bool jugar = true;
  while (jugar) {
    while(!tab.finalizada()) {
        tab.prettyPrint();
        cout << "Elija columna para insertar (a-g): ";
        cin >> c;
        tab.insertar(c-96);
        cout << endl;
    }
    tab.prettyPrint(true);  // imprime estado final del tablero

    cout << "\nJugar de nuevo? (S/N): ";
    cin >> c;
    cout << endl;

    if (tolower(c) == 's')
      tab.vaciar();
    else
      jugar = false;
  }
  cout << "¡Hasta otra!" << endl;
}

/* Fin fichero: conectaN.cpp */
