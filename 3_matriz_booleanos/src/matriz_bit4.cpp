/**
  * @file matriz_bit4.cpp
  * @brief Implementación de funciones para MatrizBit de tipo 4
  *
  */

const int BITS_INT = 32;
const int POS_MAX = 8;

bool Inicializar (MatrizBit& m, int fils, int cols)
{
  const int ELEMENTOS = fils * cols;
  bool exito = fils * cols <= BITS_INT * m.MAX_ESPACIO && fils >= 0 && cols >= 0;

  if (exito)
  {
    m.espacio = (fils << POS_MAX) | cols;
    const int POS_VECTOR = ELEMENTOS / BITS_INT;
    const int POS_BIT = ELEMENTOS % BITS_INT;

    if (ELEMENTOS >= BITS_INT)
      for (int i = 0; i < POS_VECTOR; i++)
        m.v[i] = 0;

    int aux = m.v[POS_VECTOR];

    for (int i = 0; i < POS_BIT; i++)
      aux &= ~(1 << i);

    m.v[POS_VECTOR] = aux;
  }

  return exito;
}

//________________________________________________________________

int GetFilas (const MatrizBit& m)
{
  return m.espacio >> POS_MAX;
}

//________________________________________________________________

int GetColumnas (const MatrizBit& m)
{
  return m.espacio & 0xFF;
}

//________________________________________________________________

bool GetElemento (const MatrizBit& m, int f, int c)
{
  const int POS = f * GetColumnas(m) + c;
  
  return (1 << POS % BITS_INT) & m.v[POS / BITS_INT];
}

//________________________________________________________________

void SetElemento (MatrizBit& m, int f, int c, bool v)
{
  const int COLS = GetColumnas(m);
  const int FILS = GetFilas(m);

  if (f < FILS && c < COLS && f >= 0 && c >= 0)
  {
    const int POS = f * COLS + c;
    const int POS_VECTOR = POS / BITS_INT;
    const int POS_BIT = POS % BITS_INT;
    unsigned int aux = 1 << POS_BIT;

    if (v)
      m.v[POS_VECTOR] |= aux;
    else
      m.v[POS_VECTOR] &= ~aux;
  }
}

/* Fin fichero: matriz_bit4.cpp */
