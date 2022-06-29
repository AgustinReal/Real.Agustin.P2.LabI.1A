#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"
#include "Controller.h"
#include "inputs.h"
#include "menu.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPeliculas)
{
	int retorno=-1;
	FILE* pFile=fopen(path, "r");

	if(pArrayListPeliculas!=NULL && path!=NULL)
	{
		printf("Invoco al controller texto\n");
		parser_PeliculasFromText(pFile, pArrayListPeliculas);
		retorno=1;
	}
	return retorno;
}
int controller_ListPeliculas(LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;

	if(pArrayListPeliculas!=NULL)
	{
		int lenList =ll_len(pArrayListPeliculas);


		printf(" ____________________________________________________________________________\n");
		printf("|                                                                            |\n");
		printf("|                          ***LISTADO DE PELICULAS***                        |\n");
		printf("|                              **UTN ARGENTINA**                             |\n");
		printf("|                                                                            |\n");
		printf("|____________________________________________________________________________|\n");
		printf("|         |                                  |                 |             |\n");
		printf("|  *ID*   |    *TITULOS DE LAS PELICULAS*    |    *GENEROS*    |  D*RATINGS*  |\n");
		printf("|_________|__________________________________|_________________|_____________|\n");

		for (int i=0;i<lenList;i++)
		{
			eMovie* pPelicula=ll_get(pArrayListPeliculas, i);
			mostrarUnaPelicula(pPelicula);
		}

		printf("|_________|__________________________________|_________________|_____________|\n");

		todoOk=1;
	}
	return todoOk;
}
int controller_MapRatingPelis(LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;

    if(pArrayListPeliculas!=NULL)
    {
        if(ll_isEmpty(pArrayListPeliculas)==0)
        {
            printf(" ________________________________________________________________\n");
            printf("|                                                                |\n");
            printf("|                   ***UTN FILMS ARGENTINA***                    |\n");
            printf("|            **ASIGNACION DE RATING A LAS PELICULAS**            |\n");
            printf("|________________________________________________________________|\n");


            pArrayListPeliculas=ll_map(pArrayListPeliculas, establecerRatingPeliculas);
        }
    }
    else
    {
        printf("\nNo se han ingresando peliculas al sistema...\n");
    }

    return todoOk;
}
int controller_MapGeneroPelis(LinkedList* pArrayListPeliculas)
{
        int todoOk=-1;

    if(pArrayListPeliculas!=NULL)
    {
        if(ll_isEmpty(pArrayListPeliculas)==0)
        {
            printf(" ________________________________________________________________\n");
            printf("|                                                                |\n");
            printf("|                   ***UTN FILMS ARGENTINA***                    |\n");
            printf("|            **ASIGNACION DE GENEROS A LAS PELICULAS**           |\n");
            printf("|________________________________________________________________|\n");


            pArrayListPeliculas=ll_map(pArrayListPeliculas, establecerNumerosAleatorios);
        }
    }
    else
    {
        printf("\nNo se han ingresando peliculas al sistema...\n");
    }

    return todoOk;
}
int controller_saveAsText(char* path , LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;
	int id;
	char titulo[30];
	char genero[20];
	float rating;
	eMovie* peliculaAux=NULL;
	FILE* pFile;

	if(path!=NULL && pArrayListPeliculas!=NULL)
	{
		pFile=fopen(path, "w");

		peliculaAux=new_Pelicula();

		if(peliculaAux!=NULL)
		{
			fprintf(pFile, "id,titulo,genero,rating\n");
			for(int i=0;i<ll_len(pArrayListPeliculas);i++)
			{
				peliculaAux=(eMovie*) ll_get(pArrayListPeliculas, i);
				if(peliculaAux!=NULL)
				{
					Pelicula_GetId(peliculaAux, &id);
                    Pelicula_GetTitulo(peliculaAux, titulo);
                    Pelicula_GetGenero(peliculaAux, genero);
                    Pelicula_GetRating(peliculaAux, &rating);

					fprintf(pFile,"%d,%s,%s,%.2f\n",id,titulo,genero,rating);
					todoOk=1;
				}
				else
				{
					todoOk=0;
					break;
				}
			}
		}
		fclose(pFile);

		if(todoOk)
		{
			printf("Se ha guardado correctamente el listado!\n");
		}
	}

	return todoOk;
}
int controller_FiltroDrama(LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;
    LinkedList* auxListaFiltro=NULL;

    if(pArrayListPeliculas!=NULL)
    {
        auxListaFiltro=ll_filter(pArrayListPeliculas, Pelicula_FiltrarDrama);
        controller_ListPeliculas(auxListaFiltro);
        controller_saveAsText("peliculaGeneroDrama.csv", auxListaFiltro);
        todoOk=1;
    }

    return todoOk;
}
int controller_FiltroComedia(LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;
    LinkedList* auxListaFiltro=NULL;

    if(pArrayListPeliculas!=NULL)
    {
        auxListaFiltro=ll_filter(pArrayListPeliculas, Pelicula_FiltrarComedia);
        controller_ListPeliculas(auxListaFiltro);
        controller_saveAsText("peliculaGeneroDrama.csv", auxListaFiltro);
        todoOk=1;
    }

    return todoOk;
}
int controller_FiltroAccion(LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;
    LinkedList* auxListaFiltro=NULL;

    if(pArrayListPeliculas!=NULL)
    {
        auxListaFiltro=ll_filter(pArrayListPeliculas, Pelicula_FiltrarAccion);
        controller_ListPeliculas(auxListaFiltro);
        controller_saveAsText("peliculaGeneroAccion.csv", auxListaFiltro);
        todoOk=1;
    }

    return todoOk;
}
int controller_FiltroTerror(LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;
    LinkedList* auxListaFiltro=NULL;

    if(pArrayListPeliculas!=NULL)
    {
        auxListaFiltro=ll_filter(pArrayListPeliculas, Pelicula_FiltrarTerror);
        controller_ListPeliculas(auxListaFiltro);
        controller_saveAsText("peliculaGeneroTerror.csv", auxListaFiltro);
        todoOk=1;
    }

    return todoOk;
}
int controller_FiltradosDeGeneros(LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;
    int opcion;

    if(pArrayListPeliculas!=NULL)
    {
        do
        {
            opcion=menuFiltradoPorGenero();

            switch(opcion)
            {
                case 1:
                    controller_FiltroDrama(pArrayListPeliculas);
                    break;
                case 2:
                    controller_FiltroComedia(pArrayListPeliculas);
                    break;
                case 3:
                    controller_FiltroAccion(pArrayListPeliculas);
                    break;
                case 4:
                    controller_FiltroTerror(pArrayListPeliculas);
                    break;
                case 5:
                    break;
                default:
                    printf("ERROR. REINGRESE OPCION 1-5: \n");
                    break;
            }

        }while(opcion!=12);
    }

    return todoOk;
}
int controller_SortPeliculas(LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;
    int opcion;

    if(pArrayListPeliculas!=NULL)
    {
        do
        {
            opcion=menuOrdenamiento();
            switch(opcion)
            {
                case 1:
                    ll_sort(pArrayListPeliculas, Pelicula_OrdenamientoPorGeneroRating, 1);
                    break;
                case 2:
                    ll_sort(pArrayListPeliculas, Pelicula_OrdenamientoPorGeneroRating, 0);
                    break;
                default:
                    printf("ERROR. REINGRESE OPCION 1-3: \n");
                    break;
            }
        }while(opcion!=3);

        todoOk=1;
    }

    return todoOk;
}
