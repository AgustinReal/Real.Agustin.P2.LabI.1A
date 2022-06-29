#include <stdio.h>
#include <stdlib.h>

int menuPrincipal()
{
	int opcion;

	printf( " _____________________________________________________ \n"
			"|                                                     |\n"
			"|                   **MENU PRINCIPAL**                |\n"
			"|                **UTN FILMS ARGENTINA**              |\n"
			"|_____________________________________________________|\n"
			"|                                                     |\n"
			"|1-CARGAR LOS DATOS DE LAS PELICULAS EN MODO TEXTO.   |\n"
			"|2-IMPRIMIR LISTA PELICULAS.                          |\n"
			"|3-ASIGNAR RATING A LAS PELICULAS.                    |\n"
			"|4-ASIGNAR GENERO A LAS PELICULAS.                    |\n"
			"|5-FILTRAR POR GENERO DE PELICULAS.                   |\n"
			"|6-ORDENAMIENTO PELICULAS.                            |\n"
			"|7-GUARDAR LOS DATOS DE LAS PELICULAS EN MODO TEXTO.  |\n"
			"|8-SALIR.                                             |\n"
			"|_____________________________________________________|\n");

	printf("Usted eligio: ");
	scanf("%d", &opcion);

	return opcion;
}
int menuFiltradoPorGenero()
{
    	int opcion;

	printf( " _____________________________________________________ \n"
			"|                                                     |\n"
			"|                   **MENU FILTRADOS**                |\n"
			"|                **UTN FILMS ARGENTINA**              |\n"
			"|_____________________________________________________|\n"
			"|                                                     |\n"
			"|1-FILTRADO POR GENERO DRAMA.                         |\n"
			"|2-FILTRADO POR GENERO COMEDIA.                       |\n"
			"|3-FILTRADO POR GENERO ACCION.                        |\n"
			"|4-FILTRADO POR GENERO TERROR.                        |\n"
			"|5-SALIR                                              |\n"
			"|_____________________________________________________|\n");

	printf("Usted eligio: ");
	scanf("%d", &opcion);

	return opcion;
}
int menuOrdenamiento()
{
    int opcion;

	printf( " _____________________________________________________ \n"
			"|                                                     |\n"
			"|                 **MENU ORDENAMIENTO**               |\n"
			"|                **UTN FILMS ARGENTINA**              |\n"
			"|_____________________________________________________|\n"
			"|                                                     |\n"
			"|1-ORDENAMIENTO DE TIPO ASCENDENTE.                   |\n"
			"|2-ORDENAMIENTO DE TIPO DESCENDENTE.                  |\n"
			"|3-SALIR.                                             |\n"
			"|_____________________________________________________|\n");

	printf("Usted eligio: ");
	scanf("%d", &opcion);

	return opcion;
}
