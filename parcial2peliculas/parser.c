#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"

int parser_PeliculasFromText(FILE* pFile , LinkedList* pArrayListPeliculas)
{

	int todoOk = 0;
	eMovie* auxPelicula;
	char buffer[4][30];
	int auxCantidad;

	if(pFile!= NULL && pArrayListPeliculas!=NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			auxCantidad=fscanf(pFile,"%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
			if(auxCantidad==4)// ojo verificar q los campos sean igual a la cantidad q te piden
			{
				auxPelicula=new_PeliculaConParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

				if(auxPelicula!=NULL)
				{
					auxCantidad=ll_add(pArrayListPeliculas, auxPelicula);
					if(auxCantidad!=0)
					{
						eliminarUnaPelicula(auxPelicula);
						break;
					}
					else
					{
						todoOk=1;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	return todoOk;
}
