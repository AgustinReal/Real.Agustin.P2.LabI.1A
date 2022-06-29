#ifndef CONTROLLER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

//punto 1
/** \brief Carga los datos de las peliculas desde el archivo movies.csv (modo texto).
 *
 * \param path char*: Es el camino que esta asignado el archivo en este caso en modo texto.
 * \param pArrayListPeliculas LinkedList*: Lista de los peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPeliculas);

//punto 2
/** \brief Esta funcion permite mostrar las lista de las peliculas cargados.
 *
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_ListPeliculas(LinkedList* pArrayListPeliculas);

//punto 3
/** \brief Esta funcion asigna el rating a lista de peliculas mediante la funcion de ll_map.
 *
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_MapRatingPelis(LinkedList* pArrayListPeliculas);

//punto 4
/** \brief Esta funcion asigna el genero a lista de peliculas mediante la funcion de ll_map.
 *
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_MapGeneroPelis(LinkedList* pArrayListPeliculas);

//punto 5
/** \brief Esta funcion filtra por el genero Drama
 *
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_FiltroDrama(LinkedList* pArrayListPeliculas);

/** \brief Esta funcion filtra por el genero comedia
 *
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_FiltroComedia(LinkedList* pArrayListPeliculas);

/** \brief Esta funcion filtra por el genero accion
 *
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_FiltroAccion(LinkedList* pArrayListPeliculas);

/** \brief Esta funcion filtra por el genero Terror
 *
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_FiltroTerror(LinkedList* pArrayListPeliculas);

/** \brief Esta funcion filtra por el genero elegido por el usuario
 *
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_FiltradosDeGeneros(LinkedList* pArrayListPeliculas);

//punto 7
/** \brief Esta funcion Guarda los datos de las peliculas en el archivo  (modo texto).
 *
 * \param path char*: Es el camino que esta asignado el archivo en este caso en modo texto.
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPeliculas);

//PUNTO 6
/** \brief Esta la funcion que llamo en main para que el usuario elija los 2 tipos de ordenamiento. mediante un menu.
 *
 * \param pArrayListPeliculas LinkedList*: Lista de las peliculas.
 * \return int Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_SortPeliculas(LinkedList* pArrayListPeliculas);
