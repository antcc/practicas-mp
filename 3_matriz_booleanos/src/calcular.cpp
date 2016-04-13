/**
  * @file calcular.cpp
  * @brief Módulo que permite realizar operaciones unarias y binarias con
  * matrices de booleanos.
  *
  * La sintaxis de llamada es: calcular OPERACIÓN [Parámetros]
  *   - OPERACIÓN: AND, OR (binarias); NOT, TRS (unarias)
  *   - [Parámetros]: nombre(s) de fichero(s) donde se encuentra(n) la(s) matriz (matrices) en cada caso.
  *   Si no se especifican, se leerá desde la entrada estándar.
  *
  * Un ejemplo de ejecución es:
  *   ```
  *   > calcular NOT identidad.mat  (Identidad de orden 4)
  *   4 4
  *   0 1 1 1
  *   1 0 1 1
  *   1 1 0 1
  *   1 1 1 0
  *   ```
  */

#include <iostream>
#include <cstring>  // strcmp
#include "matriz_operaciones.h"
using namespace std;

/// Tipo que representa la operación elegida sobre las matrices
enum Tipo_Operacion { AND,          ///< Operación AND lógica elemento a elemento
                      OR,           ///< Operación OR lógica elemento a elemento
                      NOT,          ///< Operación NOT lógica elemento a elemento
                      TRS,          ///< Traspuesta de una matriz
                      DESCONOCIDO   ///< Operación desconocida
                    };

/// Asignar el tipo de operación en función de la entrada del usuario
Tipo_Operacion LeerOperacion (const char operacion[])
{
  Tipo_Operacion tipo = DESCONOCIDO;

  if (!strcmp(operacion,"AND"))
    tipo = AND;
  else if (!strcmp(operacion,"OR"))
    tipo = OR;
  else if (!strcmp(operacion,"NOT"))
    tipo = NOT;
  else if (!strcmp(operacion,"TRS"))
    tipo = TRS;

  return tipo;
}

//____________________________________________________________

int main(int argc, char* argv[])
{
  if (argc == 1)
  {
    cerr << "calcular: No se ha introducido ninguna operación. Abortando...\n";
    return 1;
  }
  else
  {
    Tipo_Operacion op = LeerOperacion(argv[1]);
    const bool IS_DESCONOCIDO = op == DESCONOCIDO;

    if (IS_DESCONOCIDO)
    {
        cerr << "calcular: La operación introducida no es válida. Abortando...\n";
        return 2;
    }
    else
    {
      const bool IS_NOT = op == NOT;
      const bool IS_TRS = op == TRS;

      MatrizBit m;
      MatrizBit res;

      if (IS_NOT || IS_TRS)
      {
        if (argc == 2)
        {
          if(!Leer(cin, m))
          {
            cerr << "calcular: Error en la lectura de la matriz. Abortando...\n";
            return 4;
          }
        }
        else if (argc == 3)
        {
          if (!Leer(argv[2], m))
          {
            cerr << "calcular: Error en la lectura de la matriz. Abortando...\n";
            return 4;
          }
        }
        else
        {
          cerr << "calcular: Demasiados argumentos para una operación unaria. Abortando...\n";
          return 3;
        }

        // Realizar la operación
        if (IS_NOT ? Inicializar(res, GetFilas(m), GetColumnas(m))
               : Inicializar(res, GetColumnas(m), GetFilas(m)))
        {
          IS_NOT ? Not(res, m) : Traspuesta(res, m);
          cout << "\n";

          if(!Escribir(cout, res))
          {
            cerr << "calcular: Error escribiendo la matriz resultado. Abortando...\n";
            return 5;
          }
        }
      }

      else  // IS_OR || IS_AND
      {
        MatrizBit n;

        if (argc == 2)
        {
          if(!(Leer(cin, m) && Leer(cin, n)))
          {
            cerr << "calcular: Error en la lectura de las matrices. Abortando...\n";
            return 4;
          }
        }
        else if (argc == 3)
        {
          if(!(Leer(argv[2], n) && Leer(cin, m)))
          {
            cerr << "calcular: Error en la lectura de las matrices. Abortando...\n";
            return 4;
          }
        }
        else if (argc == 4)
        {
          if(!(Leer(argv[2], m) && Leer(argv[3], n)))
          {
            cerr << "calcular: Error en la lectura de las matrices. Abortando...\n";
            return 4;
          }
        }
        else
        {
          cerr << "calcular: Demasiados argumentos para una operación binaria. Abortando...\n";
          return 3;
        }

        // Realizar la operación
        const bool IS_OR = op == OR;
        if((GetFilas(m) == GetFilas(n)) && (GetColumnas(m) == GetColumnas(n)))
        {
          res = m;
          IS_OR ? Or(res, m, n) : And(res, m, n);
          cout << "\n";

          if (!Escribir(cout, res))
          {
            cerr << "calcular: Error escribiendo la matriz resultado. Abortando...\n";
            return 5;
          }
        }
        else
        {
          cerr << "calcular: No se puede realizar una operación binaria sobre matrices cuya "
               << "dimensión no coincide. Abortando...\n";
          return 6;
        }
      }
    }
  }
}

/* Fin fichero: calcular.cpp */
