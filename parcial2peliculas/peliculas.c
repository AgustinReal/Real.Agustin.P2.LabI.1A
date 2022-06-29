#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"


eMovie* new_Pelicula()
{
    eMovie* peliculaNueva=NULL;

    peliculaNueva=(eMovie*)malloc(sizeof(eMovie));

    if(peliculaNueva!=NULL)
    {
        Pelicula_SetId(peliculaNueva, 0);
        Pelicula_SetTitulo(peliculaNueva, "Error");
        Pelicula_SetGenero(peliculaNueva, "Error");
        Pelicula_SetRating(peliculaNueva, 0.0);
    }

    return peliculaNueva;
}
eMovie* new_PeliculaConParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr)
{
    eMovie* peliculaNueva=NULL;
    peliculaNueva=new_Pelicula();

    if(peliculaNueva!=NULL)
    {
        if(!(Pelicula_SetId(peliculaNueva, atoi(idStr))
             && Pelicula_SetTitulo(peliculaNueva, tituloStr)
             && Pelicula_SetGenero(peliculaNueva, generoStr)
             && Pelicula_SetRating(peliculaNueva, atof(duracionStr))))
        {
            eliminarUnaPelicula(peliculaNueva);
        }
    }

    return peliculaNueva;
}
void eliminarUnaPelicula(eMovie* pelicula)
{
    if(pelicula!=NULL)
    {
        free(pelicula);
        pelicula=NULL;
    }
}
int Pelicula_SetId(eMovie* pelicula, int id)
{
    int todoOk=-1;

    if(pelicula!=NULL && id>=0)
    {
        pelicula->id_peli=id;

        todoOk=1;
    }

    return todoOk;
}
int Pelicula_SetTitulo(eMovie* pelicula, char* titulo)
{
    int todoOk=-1;

    if(pelicula!=NULL && titulo!=NULL)
    {
        if(strlen(titulo)<50 && strlen(titulo)>4)
        {
            strcpy(pelicula->titulo, titulo);

            todoOk=1;
        }
    }

    return todoOk;
}
int Pelicula_SetGenero(eMovie* pelicula, char* genero)
{
    int todoOK=-1;

    if(pelicula!=NULL && genero!=NULL)
    {
        if(strlen(genero)<50 && strlen(genero)>4)
        {
            strcpy(pelicula->genero, genero);

            todoOK=1;
        }
    }

    return todoOK;
}
int Pelicula_SetRating(eMovie* pelicula, float rating)
{
    int todoOK=-1;

    if(pelicula!=NULL && rating>=0)
    {
        pelicula->rating=rating;

        todoOK=1;
    }

    return todoOK;
}
int Pelicula_GetId(eMovie* pelicula, int* id)
{
    int todoOk=-1;

    if(pelicula!=NULL && id!=NULL)
    {
        *id=pelicula->id_peli;

        todoOk=1;
    }

    return todoOk;
}
int Pelicula_GetTitulo(eMovie* pelicula, char* titulo)
{
    int todoOk=-1;

    if(pelicula!=NULL && titulo!=NULL)
    {
        strcpy(titulo, pelicula->titulo);

        todoOk=1;
    }

    return todoOk;
}
int Pelicula_GetGenero(eMovie* pelicula, char* genero)
{
    int todoOk=-1;

    if(pelicula!=NULL && genero!=NULL)
    {
        strcpy(genero, pelicula->genero);

        todoOk=1;
    }

    return todoOk;
}
int Pelicula_GetRating(eMovie* pelicula, float* rating)
{
    int todoOk=-1;

    if(pelicula!=NULL && rating!=NULL)
    {
        *rating=pelicula->rating;

        todoOk=1;
    }

    return todoOk;
}
int Pelicula_GetGeneroDescripcion(int numero, char* Genero)
{
        int todoOk=0;

    if(numero<=4 &&  numero>=1 && Genero!=NULL)
    {
        if(numero==1)
        {
            strcpy(Genero, "drama");
        }
        else if(numero==2)
        {
            strcpy(Genero, "comedia");
        }
        else if(numero==3)
        {
            strcpy(Genero, "accion");
        }
        else if(numero==4)
        {
            strcpy(Genero, "terror");
        }
        todoOk=1;
    }

    return todoOk;
}
void mostrarUnaPelicula(eMovie* pelicula)
{
    int id;
    char titulo[30];
    char genero[30];
    float rating;

    Pelicula_GetId(pelicula, &id);
    Pelicula_GetTitulo(pelicula, titulo);
    Pelicula_GetGenero(pelicula, genero);
    Pelicula_GetRating(pelicula, &rating);

    printf("|   %-3d   |   %-29s  |    %-12s |    %-3.2f     |\n", pelicula->id_peli, pelicula->titulo, pelicula->genero, pelicula->rating);
}
void* establecerRatingPeliculas(void* pElement)
{
    eMovie* auxPelicula=NULL;
    float rating;
    int maximo=1;
    int minimo=10;

    if(pElement!=NULL)
    {
        auxPelicula=(eMovie*)pElement;

        if(auxPelicula!=NULL)
        {
            rating=(float)((rand()%(maximo-minimo+1))+minimo)/10;

            Pelicula_SetRating(auxPelicula, rating);//asigno los valores entre 100-240
        }
    }

    return auxPelicula;
}
void* establecerNumerosAleatorios(void* pElement)
{
    eMovie* auxPelicula=NULL;
    char descripcion[30];
    int numeros;
    int maximo=4;
    int minimo=1;

    if(pElement!=NULL)
    {
        auxPelicula=(eMovie*)pElement;

        if(auxPelicula!=NULL)
        {
            numeros=rand()%(maximo-minimo+1)+minimo;
            Pelicula_GetGeneroDescripcion(numeros, descripcion);
            Pelicula_SetGenero(auxPelicula, descripcion);
        }
    }

    return auxPelicula;
}
int Pelicula_FiltrarDrama(void* elemento)
{
    int todoOk=-1;
    char generoPelicula[30]={"drama"};
    eMovie* generoAux;
    generoAux=(eMovie*) elemento;

    if(generoAux!=NULL)
    {
        if(strcmp(generoAux->genero, generoPelicula)==0)
        {
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }

    return todoOk;
}
int Pelicula_FiltrarComedia(void* elemento)
{
    int todoOk=-1;
    char generoPelicula[30]={"comedia"};
    eMovie* generoAux;
    generoAux=(eMovie*) elemento;

    if(generoAux!=NULL)
    {
        if(strcmp(generoAux->genero, generoPelicula)==0)
        {
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }

    return todoOk;
}
int Pelicula_FiltrarAccion(void* elemento)
{
    int todoOk=-1;
    char generoPelicula[30]={"accion"};
    eMovie* generoAux;
    generoAux=(eMovie*) elemento;

    if(generoAux!=NULL)
    {
        if(strcmp(generoAux->genero, generoPelicula)==0)
        {
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }

    return todoOk;
}
int Pelicula_FiltrarTerror(void* elemento)
{
    int todoOk=-1;
    char generoPelicula[30]={"terror"};
    eMovie* generoAux;
    generoAux=(eMovie*) elemento;

    if(generoAux!=NULL)
    {
        if(strcmp(generoAux->genero, generoPelicula)==0)
        {
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }

    return todoOk;
}
int Pelicula_OrdenamientoPorGeneroRating(void* punteroUno, void* punteroDos)
{
    int todoOk=0;
    float ratingUno;
    float ratingDos;
    char generoUno[30];
    char generoDos[30];
    eMovie* peliculaUno=NULL;
	eMovie* peliculaDos=NULL;

	peliculaUno=(eMovie*)punteroUno;
    peliculaDos=(eMovie*)punteroDos;

    if(peliculaUno!=NULL && punteroDos!=NULL)
    {
        Pelicula_GetRating(peliculaUno, &ratingUno);
        Pelicula_GetRating(peliculaDos, &ratingDos);
        Pelicula_GetGenero(peliculaUno, generoUno);
        Pelicula_GetGenero(peliculaDos, generoDos);

        if(strcmp(generoUno, generoDos)<0)
        {
            todoOk=1;
        }
        else if(strcmp(generoUno, generoDos)>0)
        {
            todoOk=-1;
        }
        else
        {
            if(strcmp(generoUno, generoDos)==0)
            {
                if(ratingUno > ratingDos)
                {
                    todoOk = 1;
                }
                else if(ratingUno < ratingDos)
                {
                    todoOk = -1;
                }
            }
        }
    }

    return todoOk;
}
