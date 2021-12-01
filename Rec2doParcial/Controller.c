#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>

#include "eMovie.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"


/** \brief Carga los datos del archivo de texto en la lista (modo texto).
 *
 * \param path char* nombre del archivo a cargar
 * \param lista LinkedList* lista donde se cargaran los archivos
* \return int retorna 0 en caso de error, 1 en caso de haber cargado el archivo
 *
 */


int controller_loadFromText(char* path, LinkedList* lista)
{
   int todoOk=0;
    FILE* f = NULL;

    if(path!=NULL && lista!=NULL)
    {


        f=fopen(path, "r");

        if(  f!=NULL  && (parser_fromText(f, lista)==1))
        {

            printf("Se ha cargado el archivo de texto.\n\n");
            todoOk=1;
        }
        else
        {
            printf("\nNo se pudo cargar el archivo de texto.\n\n");
        }
        fclose(f);
    }
    return todoOk;
}








int controller_printPeli(eMovie* peli)
{
    int todoOk=0;
    int id;

    char titulo[128];

    char genero[30];

    float rating;

    if(peli!=NULL)
    {
        eMovie_getId(peli,&id);
        eMovie_getTitulo(peli,titulo);
        eMovie_getGenero(peli,genero);
        eMovie_getRating(peli,&rating);



        printf("   %d      %30s       %30s                %.2f     \n",id,titulo,genero,rating);



        todoOk=1;
    }




    return todoOk;
}






int controller_listPelis(LinkedList* lista)
{
    int todoOk=0;
    int tam;

    eMovie* auxPeli = NULL;

    if(lista!= NULL)
    {
        system("cls");
        printf("       *** Listado de Peliculas ***      \n");
        printf("   Id                        Titulo                                   Genero                   Rating\n");
        printf("-----------------------------------------------------------------------------------------------------------\n");

        tam=ll_len(lista);

        if(tam>0)
        {
            for(int i=0; i<tam; i++)
            {
                auxPeli = ll_get(lista, i);
                controller_printPeli( auxPeli);


            }
        }
        printf("\n");





        todoOk=1;
    }




    return todoOk;



}




int controller_saveAsText(char* path, LinkedList* lista)
{
    int todoOk=0;
    FILE* f = NULL;
    eMovie* peli = NULL;
    int tam;
    int id;
	char titulo[128];
	char genero[30];
	float rating;

	if(path!=NULL && lista!=NULL)
	{
		f=fopen(path, "w");
		peli=eMovie_new();
		tam=ll_len(lista);

		fprintf(f, "id_peli,titulo,genero,rating\n");

		for(int i=0; i<tam; i++)
		{
			peli=ll_get(lista, i);

			if(peli!=NULL)
			{
                eMovie_getId(peli,&id);
                eMovie_getTitulo(peli,titulo);
                eMovie_getGenero(peli,genero);
                eMovie_getRating(peli,&rating);

				fprintf(f, "%d,%s,%s,%f\n", id, titulo,genero,rating);
				todoOk=1;
			}
		}
		fclose(f);
		printf("El archivo de texto fue guardado con exito.\n");
	}

    return todoOk;

}

int controller_filterGenero(LinkedList* lista)
{
    int todoOk=0;
    int (*funcion)(void*);
    char path[30];



        if(lista!=NULL)
        {

            switch(subMenu())
            {

            case 1:
            funcion = eMovie_filterComedy;
            strcpy(path,"moviesComedia.csv");

            break;

             case 2:
            funcion = eMovie_filterAction;
            strcpy(path,"moviesAccion.csv");

            break;

             case 3:
            funcion = eMovie_filterTerror;
            strcpy(path,"moviesTerror.csv");

            break;

             case 4:
            funcion = eMovie_filterDrama;
            strcpy(path,"moviesDrama.csv");

            break;



            case 5:
            return todoOk;
            break;

            default:
            printf("Opcion invalida\n");
            break;




            }

            LinkedList* listaFiltrada = ll_filter(lista,funcion);

            controller_listPelis(listaFiltrada);

            printf("\n\n Lista filtrada con exito \n\n");

            controller_saveAsText(path,listaFiltrada);


            ll_deleteLinkedList(listaFiltrada);

            todoOk=1;
        }





    return todoOk;

}







