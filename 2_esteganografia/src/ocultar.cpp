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
#include <cstring>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

int main() {
  const int MAXNOMBRE = 100;
  const int MAXBUFFER = 1000000;
  const int MAXMENSAJE = 125000;

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
    cerr << "Tipo de imagen no soportado." << endl;
    return 1;
  }

  // Ocultar el mensaje
  n = img == IMG_PGM ? f*c : f*c*3;
  error = Ocultar (buffer, n, mensaje);
  cout << "Ocultando...\n";

  if (error == ERR_NINGUNO) {
    // Añadir la extensión correspondiente
    img == IMG_PPM ? strcat(salida, ".ppm") : strcat(salida, ".pgm");

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
