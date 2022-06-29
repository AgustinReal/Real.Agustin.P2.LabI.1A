#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "peliculas.h"
#include "inputs.h"
#include "parser.h"
#include "menu.h"


int main()
{
    char salir;
    LinkedList* listaPeliculas=ll_newLinkedList();
    int flagSeCargoLaLista=0;
    int flagSeGuardoEnTexto=0;
    int flagSeAplicaronLosMapeos3=0;
    int flagSeAplicaronLosMapeos4=0;


    do{
        switch(menuPrincipal())
        {
        	case 1:
        		if(flagSeCargoLaLista==1)
                {
                    printf("\nYa se ha invocado la carga en modo texto...\n");
                }
                else
                {
                    controller_loadFromText("movies.csv", listaPeliculas);
                    flagSeCargoLaLista=1;
                }
        		break;
            case 2:
                if(flagSeCargoLaLista>0)
                {
                    controller_ListPeliculas(listaPeliculas);
                }
                else
                {
                    printf("\nNo se ha invocado la carga en modo texto...\n");
                }
                break;
            case 3:
                if(flagSeCargoLaLista>0)
                {
                    controller_MapRatingPelis(listaPeliculas);
                    flagSeAplicaronLosMapeos3=1;
                }
                else
                {
                    printf("\nNo se ha invocado la carga en modo texto...\n");
                }
                break;
            case 4:
                if(flagSeCargoLaLista>0)
                {
                    controller_MapGeneroPelis(listaPeliculas);
                    flagSeAplicaronLosMapeos4=1;
                }
                else
                {
                    printf("\nNo se ha invocado la carga en modo texto...\n");
                }
                break;
            case 5:
                if(flagSeCargoLaLista>0 && flagSeAplicaronLosMapeos3>0 && flagSeAplicaronLosMapeos4>0)
                {
                    controller_FiltradosDeGeneros(listaPeliculas);
                }
                else
                {
                    printf("\nNo se ha invocado la carga en modo texto o no se aplicaron filtros...\n");
                }
                break;
            case 6:
                if(flagSeCargoLaLista>0 && flagSeAplicaronLosMapeos3>0 && flagSeAplicaronLosMapeos4>0)
                {
                    controller_SortPeliculas(listaPeliculas);
                }
                else
                {
                    printf("\nNo se ha invocado la carga en modo texto o no se aplicaron filtros...\n");
                }
                break;
            case 7:
                if(flagSeCargoLaLista>0 && flagSeAplicaronLosMapeos3>0 && flagSeAplicaronLosMapeos4>0)
                {
                    controller_saveAsText("ultimoArchivo.CSV", listaPeliculas);
                    flagSeGuardoEnTexto=1;
                }
                else
                {
                    printf("\nNo se ha invocado la carga en modo texto o no se aplicaron filtros...\n");
                }
                break;
            case 8:
                if(flagSeCargoLaLista>0 && flagSeGuardoEnTexto>0)
                {
                    ingresoChar(&salir, "Ingrese  S para salir del menu principal (s/n): ");
                    ll_deleteLinkedList(listaPeliculas);
                }
                else
                {
                    printf("\nNo se ha invocado la carga en modo texto...\n");
                }
                break;
            default:
            	printf("ERROR. INGRESE UNA OPCION (1-8)\n");
            	break;
        }
    }while(salir!='s');
    return 0;
}


