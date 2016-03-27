/**
  * @file codificar.cpp
  * @brief Fichero con definiciones para la codificación de mensajes
  * en imágenes.
  *
  * Permite la codificación/descodificación de mensajes en imágenes
  * de tipo PGM,PPM
  *
  */

#include "codificar.h"
using namespace std;

namespace {
  const int BYTE = 8;

  int Longitud (const char c[])
  {
    int i = 0, l = 0;

    while (c[i++]) l++;

    return ++l; // Incluir el carácter '\0'
  }
}

// ________________________________________________________________________

TipoError Ocultar (unsigned char img[], int n, const char mensaje[])
{
  TipoError error = ERR_NINGUNO;
  int l = Longitud(mensaje);

  if (BYTE * l <= n) {
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < BYTE; ++j) {
        int aux = 1 << j;

        if (!((aux & mensaje[i]) == (aux & img[i]))) {  // No coinciden
          img[i] = aux & mensaje[i] ? aux | img[i] : ~aux & img[i];
        }
      }
    }
  }
  else
    error = ERR_TAMANIO;

  return error;
}

// ________________________________________________________________________

TipoError Revelar (const unsigned char img[], int n, char mensaje[], int l)
{
  TipoError error = ERR_NINGUNO;
  char letra = 1;

  int i = 0;
  while (i < n && letra != 0 && i < l) {
    letra = 0;

    for (int j = 0; j < BYTE; j++) {
      int aux = 1 << j;
      if (img[i] & aux)
        letra = aux | letra;
    }

    mensaje[i++] = letra;
  }

  if (i == l && letra)
    error = ERR_TAMANIO;
  else if (!letra)
    error = ERR_TERMINADOR;

  return error;
}

  /* Fin Fichero: codificar.cpp */
