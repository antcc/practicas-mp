/** @file ocultar.cpp
  * @brief Programa para ocultar un mensaje en una imagen PPM o PGM
  *
  * Un ejemplo de ejecución es:
  *   > Introduzca la imagen de entrada: original.ppm
  *   > Introduzca la imagen de salida: salida
  *   > Introduzca el mensaje: ¡Hola mundo!
  *   > Ocultando...
  *   > Mensaje ocultado correctamente.
  *
  */

#include <iostream>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

/// Devuelve la longitud de la cadena @a c
int Longitud (const char c[])
{
  int i = 0, l = 0;

  while (c[i++]) l++;

  return l;
}

/// Añade la cadena @a c2 al final de la cadena @a c1
void Concatenar (char c1[], const char c2[])
{

}

int main() {
  const int MAXNOMBRE = 100;
  const int MAXBUFFER = 1000000;
  const int MAXMENSAJE = 125000;
  const int TAMANIO_EXT = 4;

  unsigned char buffer[MAXBUFFER];
  char original[MAXNOMBRE];
  char salida[MAXNOMBRE];
  char mensaje[MAXMENSAJE];
  int f,c,n;
  TipoImagen img;
  TipoError error;

  cout << "Introduzca el nombre de la imagen original: ";
  cin.getline(original, MAXNOMBRE);
  cout << "Introduzca el nombre de la imagen modificada: ";
  cin.getline(salida, MAXNOMBRE);
  cout << "Introduzca el mensaje a codificar: ";
  cin.getline(mensaje, MAXMENSAJE);

  img = LeerTipoImagen(original, f, c);

  if (img == IMG_PPM) {
    if(!LeerImagenPPM(original, f, c, buffer)) {
      cerr << "Falló la lecura." << endl;
      return 1;
    }
  }
  else if (img == IMG_PGM) {
    if(!LeerImagenPGM(original, f, c, buffer)) {
      cerr << "Falló la lecura." << endl;
      return 1;
    }
  }
  else {
    cerr << "img de imagen no soportado." << endl;
    return 1;
  }

  // Ocultar el mensaje
  n = img == IMG_PGM ? f*c : f*c*3;
  error = Ocultar (buffer, n, mensaje);

  if (error == ERR_NINGUNO) {
    // Añadir la extensión correspondiente
    const char extension[TAMANIO_EXT + 1] = {'.','p','p','m','\0'};
    //Concatenar(salida, extension);

    bool exito = img == IMG_PGM ? EscribirImagenPGM(salida, buffer, f, c)
                                 : EscribirImagenPPM(salida, buffer, f, c);

    if (exito)
      cout << "Mensaje ocultado correctamente." << endl;
    else
      cerr << "Error: no se pudo guardar la imagen con el mensaje oculto." << endl;
  }
  else
    cerr << "Error: el mensaje es demasiado grande.";
}

/* Fin Fichero: ocultar.cpp */
