#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[30];
    char genero[30];
    float rating;

}eMovie;

#endif // PELICULAS_H_INCLUDED

/** \brief Esta funcion: Se encarga de realizar una nueva pelicula con valores inicializados en 0.
 *
 * \return eMovie* Retorna la pelicula creada si tuvo exito.
 *
 */
eMovie* new_Pelicula();

/** \brief Esta funcion: Se encarga de realizar una nueva pelicula a partir de parametros establecidos.
 *
 * \param idStr char* En este apartado contiene el ID que se le quiere asignar a la pelicula.
 * \param tituloStr char* En este apartado contiene el titulo que se le quiere asignar a la pelicula.
 * \param generoStr char* En este apartado contiene el genero que se le quiere asignar a la pelicula.
 * \param duracionStr char* En este apartado contiene la duracion que se le quiere asignar a la pelicula.
 * \return eMovie* Retorna la pelicula creado si tuvo exito.
 *
 */
eMovie* new_PeliculaConParametros(char* idStr, char* tituloStr, char* generoStr, char* ratingStr);

/** \brief Esta funcion: Elimina de memoria de la pelicula.
 *
 * \param pelicula eMovie* Libera la memoria ocupada por la pelicula.
 * \return void
 *
 */
void eliminarUnaPelicula(eMovie* pelicula);

/** \brief Esta funcion: Se encarga de mostrar un pelicula pasado por parametro.
 *
 * \param pelicula eMovie* La pelicula a mostrar.
 * \return void
 *
 */
void mostrarUnaPelicula(eMovie* pelicula);

//Setters

/** \brief Esta funcion: Se encarga de obtener el Id de la pelicula en la lista general.
 *
 * \param pelicula eMovie*: Este es un elemento a buscar en la lista.
 * \param id int: El id a obtener en la lista.
 * \return  Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_SetId(eMovie* pelicula, int id);

/** \brief Esta funcion: Se encarga de obtener el titulo de la pelicula en la lista general.
 *
 * \param pelicula eMovie*: Este es un elemento a buscar en la lista.
 * \param titulo char*: El titulo a obtener en la lista.
 * \return  Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_SetTitulo(eMovie* pelicula, char* titulo);

/** \brief Esta funcion: Se encarga de obtener el genero de la pelicula en la lista general.
 *
 * \param pelicula eMovie*: Este es un elemento a buscar en la lista.
 * \param genero char*: El genero a obtener en la lista.
 * \return  Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_SetGenero(eMovie* pelicula, char* genero);

/** \brief Esta funcion: Se encarga de obtener el duracion de la pelicula en la lista general.
 *
 * \param pelicula eMovie*: Este es un elemento a buscar en la lista.
 * \param duracion int: La duracion a obtener en la lista.
 * \return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_SetRating(eMovie* pelicula, float rating);

//Getters

/** \brief Esta funcion: Se encarga de colocar el id de la pelicula en la lista general.
 *
 * \param pelicula eMovie*: Esta es la lista.
 * \param id int*: El id a colocar en la lista.
 * \return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_GetId(eMovie* pelicula, int* id);

/** \brief Esta funcion: Se encarga de colocar el titulo de la pelicula en la lista general.
 *
 * \param pelicula eMovie*: Esta es la lista.
 * \param titulo char*: El titulo a colocar en la lista.
 * \return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_GetTitulo(eMovie* pelicula, char* titulo);

/** \brief Esta funcion: Se encarga de colocar el genero de la pelicula en la lista general.
 *
 * \param pelicula eMovie*: Esta es la lista.
 * \param genero char*: El genero a colocar en la lista.
 * \return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_GetGenero(eMovie* pelicula, char* genero);

/** \brief Esta funcion: Se encarga de colocar la duracion de la pelicula en la lista general.
 *
 * \param pelicula eMovie*: Esta es la lista.
 * \param duracion int*: La duracion a colocar en la lista.
 * \return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_GetRating(eMovie* pelicula, float* rating);

/** \brief Esta funcion: Se encarga de cambiar numeros (1-4) por generos de peliculas.
 *
 * \param numero int: Numeros 1-4
 * \param Genero char*: Genero a cambiar.
 * \return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_GetGeneroDescripcion(int numero, char* Genero);

//mapeos
/** \brief Esta funcion establece el rating al campo vacio por defecto de la lista movies.
 *
 * \param pElement void*: Es el elemento a asignar el rating solicictado.
 * \return void*
 *
 */
void* establecerRatingPeliculas(void* pElement);

/** \brief Esta funcion establece numeros emtre 1-4 al campo genero por defecto de la lista movies y
 *   y cmabias los enteros por los generos solicitados.
 *
 * \param pElement void*: Es el elemento a asignar el genero solicictado.
 * \return void*
 *
 */
void* establecerNumerosAleatorios(void* pElement);

//filters
/** \brief Esta funcion se queda con todos los elementos que tengo en el campo genero "drama".
 *
 * \param elemento void*: Es el elementocon el genero solicictado "drama".
 * \return int Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_FiltrarDrama(void* elemento);

/** \brief Esta funcion se queda con todos los elementos que tengo en el campo genero "comedia".
 *
 * \param elemento void*: Es el elementocon el genero solicictado "comedia".
 * \return int Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_FiltrarComedia(void* elemento);

/** \brief Esta funcion se queda con todos los elementos que tengo en el campo genero "accion".
 *
 * \param elemento void*: Es el elementocon el genero solicictado "accion".
 * \return int Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_FiltrarAccion(void* elemento);

/** \brief Esta funcion se queda con todos los elementos que tengo en el campo genero "terror".
 *
 * \param elemento void*: Es el elementocon el genero solicictado "terror".
 * \return int Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 *
 */
int Pelicula_FiltrarTerror(void* elemento);


//ordenamiento
/** \brief Esta funcion: obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento  por genero y rating.
 *
 * \param punteroUno void*: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * \param punteroDos void*: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * \return retorna: -2 si algun puntero es NULL, 0 si son iguales los estados de vuelos, -1 si el el segundo es mayor. 1 si el primero es mayor
 *
 */
int Pelicula_OrdenamientoPorGeneroRating(void* punteroUno, void* punteroDos);
