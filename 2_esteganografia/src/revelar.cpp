/** @file ocultar.cpp
  * @brief Programa para revelar un mensaje oculto en una imagen PPM o PGM
  *
  * Un ejemplo de ejecución es:
  *   > Introduzca la imagen de entrada: salida.ppm
  *   > Revelando...
  *   > El mensaje es:
  *   > ¡Hola mundo!
  *
  */

#include <iostream>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

int main()
{
  const int MAXNOMBRE = 100;
  const int MAXBUFFER = 1000000;
  const int MAXMENSAJE = 125000;

  unsigned char buffer[MAXBUFFER];
  char nombre[MAXNOMBRE];
  char mensaje[MAXMENSAJE];
  int f,c,n;
  TipoImagen img;
  TipoError error;

  cout << "Introduzca la imagen de entrada: ";
  cin.getline(nombre, MAXNOMBRE);

  img = LeerTipoImagen(nombre, f, c);

  if (img == IMG_PPM) {
    if(!LeerImagenPPM(nombre, f, c, buffer)) {
      cerr << "Falló la lecura." << endl;
      return 1;
    }
  }
  else if (img == IMG_PGM) {
    if(!LeerImagenPGM(nombre, f, c, buffer)) {
      cerr << "Falló la lecura." << endl;
      return 1;
    }
  }
  else {
    cerr << "Tipo de imagen no soportado." << endl;
    return 1;
  }

  // Revelar el mensaje
  n = img == IMG_PGM ? f*c : f*c*3;
  error = Revelar (buffer, n, mensaje, MAXMENSAJE);
  cout << "Revelando..." << endl;

  if (error == ERR_NINGUNO) {
    cout << "El mensaje oculto es:\n";
    cout << mensaje << endl;
  }
  else if (error == ERR_TAMANIO)
    cerr << "El mensaje es demasiado grande." << endl;
  else
    cerr << "El mensaje ocultado no contenía el terminador '\0'." << endl;
}

/* Fin Fichero: revelar.cpp */
