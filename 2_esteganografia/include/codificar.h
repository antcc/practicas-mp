/**
  * @file codificar.h
  * @brief Módulo para codificar un mensaje en una imagen
  *
  * Permite ocultar o revelar un mensaje de una imagen PPM o PGM
  *
  */

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

/**
  * @brief Tipo de error
  *
  * Declara una serie de constantes para representar los distintos tipos
  * de error que pueden darse a la hora de ocultar o revelar un mensaje.
  *
  * @see Ocultar
  * @see Revelar
  */
enum TipoError {ERR_NINGUNO,    ///< La operación ha tenido éxito
                ERR_TAMANIO,    ///< El mensaje no cabe en la imagen, o en la cadena
                ERR_TERMINADOR  ///< El mensaje oculto no termina en el carácter '\0'
               };

/**
  * @brief Permite ocultar un mensaje en una imagen PPM o PGM
  *
  * @param img Vector de bytes que corresponden a los valores de los píxeles de la imagen
  * @param n Tamaño del vector anterior @a (img)
  * @param mensaje Cadena de caracteres que representa un mensaje a ocultar
  * @return Devuelve un valor de @a TipoError, indicando si ha habido algún error
  * al ocultar el mensaje, y de qué tipo ha sido.
  *
  * @pre La cadena @a mensaje debe terminar con el carácter '\0'
  */
TipoError Ocultar (unsigned char img[], int n, const char mensaje[]);

/**
  * @brief Permite revelar un mensaje de una imagen PPM o PGM
  *
  * @param img Vector de bytes que corresponden a los valores de los píxeles de la imagen
  * @param n Tamaño del vector anterior @a (img)
  * @param mensaje Parámetro de salida con el mensaje revelado (cadena de caracteres)
  * @param l Tamaño de la cadena @a mensaje
  * @return Devuelve un valor de @a TipoError, indicando si ha habido algún error
  * al revelar el mensaje, y de qué tipo ha sido.
  *
  */
TipoError Revelar (const unsigned char img[], int n, char mensaje[], int l);

#endif

/* Fin Fichero: codificar.h */
