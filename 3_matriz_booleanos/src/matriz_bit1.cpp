/**
  * @file matriz_bit1.cpp
  * @brief Implementación de funciones para MatrizBit de tipo 1
  *
  */

bool Inicializar (MatrizBit& m, int fils, int cols)
{
  bool exito = fils <= m.MAX_FILAS && cols <= m.MAX_COLUMNAS
             && fils >= 0 && cols >= 0;

  if (exito)
  {
    m.filas = fils;
    m.columnas = cols;

    for (int i = 0; i < fils; i++)
      for (int j = 0; j < cols; j++)
        m.matriz[i][j] = false;
  }

  return exito;
}

//________________________________________________________________

int GetFilas (const MatrizBit& m)
{
  return m.filas;
}

//________________________________________________________________

int GetColumnas (const MatrizBit& m)
{
  return m.columnas;
}

//________________________________________________________________

bool GetElemento (const MatrizBit& m, int f, int c)
{
  return m.matriz[f][c];
}

//________________________________________________________________

void SetElemento (MatrizBit& m, int f, int c, bool v)
{
  if (f < m.filas && c < m.columnas && f >= 0 && c >= 0)
    m.matriz[f][c] = v;
}

/* Fin fichero: matriz_bit1.cpp */
