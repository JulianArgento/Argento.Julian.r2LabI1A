

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"
#include "eMovie.h"

#include "utn.h"
#include "Controller.h"

int main()
{

    char salir = 'n';
    int carga=0;
    int cargagenero=0;
    int ordenar=0;

    LinkedList* lista = ll_newLinkedList();

    srand(time(NULL));
    do
    {

        switch(menu())
        {

        case 1:

        if(ll_isEmpty(lista))
        {



           controller_loadFromText("movies.csv",lista);



        }
        else
        {
            printf("Solo se puede cargar la lista una vez.\n");
        }


        break;

        case 2:

        if(ll_isEmpty(lista))
        {
            printf("Se debe cargar el archivo de texto antes de operar.\n");
        }
        else
        {
            controller_listPelis(lista);
        }



        break;

        case 3:
        if(ll_isEmpty(lista))
        {
            printf("Se debe cargar el archivo de texto antes de operar.\n");
        }
        else
        {




           lista = ll_map(lista,eMovie_cargarRating);
           carga = 1;
           printf("Las pelis fueron cargadas\n");
        }


        break;

        case 4:
        if( ll_isEmpty(lista))
        {
            printf("Se debe cargar el archivo de texto  antes de operar.\n");
        }
        else
        {


        lista = ll_map(lista,eMovie_cargarGenero);
        cargagenero=1;
        printf("Las pelis fueron cargadas\n");


        }


        break;

        case 5:
        if( !carga || !cargagenero)
        {
            printf("Se debe cargar el archivo de texto y los valores de rating y genero antes de operar.\n");
        }
        else
        {


        controller_filterGenero(lista);



        }


        break;

       case 6:
        if( !carga || !cargagenero)
        {
            printf("Se debe cargar el archivo de texto y los valores de rating y genero antes de operar.\n");
        }
        else
        {


        ll_sort(lista,eMovie_ordenarGenero,1);
        printf("La lista ha sido ordenada\n\n");
        ordenar=1;

        }


        break;


       case 7:
        if( !carga || !cargagenero || !ordenar)
        {
            printf("Se debe cargar el archivo de texto los valores de rating y genero, y ordenar la lista antes de operar.\n");
        }
        else
        {


       controller_saveAsText("moviesOrdenadas.csv",lista);


        }


        break;




        case 8:
            getConfirmacion("Confirma la salida? (s para si, n para no): ",&salir);

            break;

        default:
            printf("Opcion no valida\n");

            break;



        }
        system("pause");
    }
    while(salir == 'n');

    ll_deleteLinkedList(lista);

    return 0;



    return 0;
}







