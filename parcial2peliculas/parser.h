#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED
/**
 * @fn int parser_PassengerFromText(FILE*, LinkedList*)
 * @brief Esta funcion parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param pFile: Es el archivo a parsear en este caso modo texto.
 * @param pArrayListEmployee: La lista de empleados.
 * @return Retorna 1 o 0: 1 si se puedo parsear o 0 si no se pudo parsear.
 */
int parser_PeliculasFromText(FILE* pFile , LinkedList* pArrayListPeliculas);
