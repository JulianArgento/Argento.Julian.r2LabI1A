#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "eMovie.h"


int parser_fromText(FILE* pFile, LinkedList* lista)
{
    int todoOk=0;
    eMovie* auxPeli = NULL;
    char buffer[2][5];
    char auxNombre[128];
    char auxGenero[128];



    if(pFile != NULL && lista != NULL )
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",buffer[0],auxNombre,auxGenero,buffer[1]);
        do
        {


            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",buffer[0],auxNombre,auxGenero,buffer[1])<4)
            {
                break;
            }



            auxPeli = eMovie_newParametros(buffer[0],auxNombre,auxGenero,buffer[1]);

            if(auxPeli!=NULL)
            {

                ll_add(lista, auxPeli);
                todoOk=1;

            }
            else
            {
                break;
            }


        }
        while(!feof(pFile));


    }

    return todoOk;
}





