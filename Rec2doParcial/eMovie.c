#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "eMovie.h"




eMovie* eMovie_new()
{
    eMovie* nuevaPeli;

    nuevaPeli = (eMovie*) malloc(sizeof(eMovie));

    if(nuevaPeli!=NULL)
    {
        nuevaPeli->id_peli=0;

        strcpy(nuevaPeli->titulo,"nn");

        strcpy(nuevaPeli->genero,"nn");

        nuevaPeli->rating=0;




    }

    return nuevaPeli;
}




void eMovie_delete(eMovie* this)
{
    if(this != NULL)
    {
        free(this);
    }

}






eMovie* eMovie_newParametros(char* idStr,char* titulo,char* genero, char* ratingStr)
{

    eMovie* nuevaPeli;

    nuevaPeli = eMovie_new();

    if(nuevaPeli!=NULL)
    {
        if( !(eMovie_setId(nuevaPeli, atoi(idStr)) &&
                eMovie_setTitulo(nuevaPeli, titulo) &&
                eMovie_setGenero(nuevaPeli, genero) &&
                eMovie_setRating(nuevaPeli, atoi(ratingStr)) )

          )
        {
            free(nuevaPeli);
            nuevaPeli=NULL;


        }



    }

    return nuevaPeli;

}

//getters y setters


int eMovie_setId(eMovie* this,int id)
{
    int todoOk=0;

    if(this != NULL && id>=1)
    {
        this->id_peli = id;
        todoOk=1;
    }


    return todoOk;




}





int eMovie_getId(eMovie* this,int* id)
{
    int todoOk=0;

    if(this != NULL && id!= NULL)
    {
        *id = this->id_peli;
        todoOk=1;
    }


    return todoOk;
}





int eMovie_setTitulo(eMovie* this,char* titulo)
{
    int todoOk=0;

    if(this != NULL && titulo!=NULL)
    {



        if(strlen(titulo)<127)
        {
            strcpy(this->titulo,titulo);
            todoOk=1;
        }

    }


    return todoOk;


}




int eMovie_getTitulo(eMovie* this,char* titulo)
{
     int todoOk=0;

    if(this != NULL && titulo!= NULL)
    {
        strcpy(titulo,this->titulo);
        todoOk=1;
    }


    return todoOk;
}






int eMovie_setGenero(eMovie* this,char* genero)
{
     int todoOk=0;

    if(this != NULL && genero!=NULL)
    {

        if(strlen(genero)<128)
        {
            strcpy(this->genero,genero);
            todoOk=1;
        }

    }


    return todoOk;




}




int eMovie_getGenero(eMovie* this,char* genero)
{

     int todoOk=0;

    if(this != NULL && genero!= NULL)
    {
        strcpy(genero,this->genero);
        todoOk=1;
    }


    return todoOk;




}



int eMovie_getRating(eMovie* this,float* rating)
{
    int todoOk=0;

    if(this != NULL && rating!= NULL)
    {
        *rating = this->rating;
        todoOk=1;
    }


    return todoOk;




}

int eMovie_setRating(eMovie* this,float rating)
{

    int todoOk=0;

    if(this != NULL && rating>=0)
    {
        this->rating = rating;
        todoOk=1;
    }


    return todoOk;


}



void* eMovie_cargarRating(void* movie)
{
    float rating;
    float decimal;

    if(movie!=NULL)
    {

        //rand() % (max-min+1)+min

        rating = rand()  % (10-1+1) + 1;

        if(rating<10)
        {
            decimal = rand() % (9-1+1) + 1;

            decimal= (float) decimal/10;

            rating += decimal;
        }

        eMovie_setRating(movie,rating);

    }




    return movie;
}


void* eMovie_cargarGenero(void* movie)
{
    int num;
    char genero[30];

    if(movie!=NULL)
    {

        num = rand() % (4-1+1) + 1;

        switch(num)
        {
            case 1:
            strcpy(genero,"Drama");
            break;

            case 2:
            strcpy(genero,"Comedia");
            break;

            case 3:
            strcpy(genero,"Accion");
            break;

            case 4:
            strcpy(genero,"Terror");
            break;

        }


    }


    eMovie_setGenero(movie,genero);



    return movie;

}



int eMovie_filterComedy(void* pElement)
{
    char genero[30] = "Comedia";
    int retorno = 0;


    if(strcmp(genero,((eMovie*)pElement)->genero)==0)
    {

     retorno=1;

    }


    return retorno;

}

int eMovie_filterAction(void* pElement)
{
    char genero[30] = "Accion";
    int retorno = 0;


    if(strcmp(genero,((eMovie*)pElement)->genero)==0)
    {

       retorno=1;

    }


    return retorno;

}

int eMovie_filterDrama(void* pElement)
{
    char genero[30] = "Drama";
    int retorno = 0;


    if(strcmp(genero,((eMovie*)pElement)->genero)==0)
    {

       retorno=1;

    }


    return retorno;

}

int eMovie_filterTerror(void* pElement)
{
    char genero[30] = "Terror";
    int retorno = 0;


    if(strcmp(genero,((eMovie*)pElement)->genero)==0)
    {

      retorno=1;
    }


    return retorno;

}




int eMovie_ordenarGenero(void* peli1, void* peli2)
{

    int ordenamiento = 0;
    char genero1[128];
    char genero2[128];
    float rating1;
    float rating2;

    eMovie_getGenero(peli1,genero1);
    eMovie_getGenero(peli2,genero2);

    eMovie_getRating(peli1,&rating1);
    eMovie_getRating(peli2,&rating2);


    if(strcmp(genero1, genero2) > 0)
    {
        ordenamiento = 1;
    }
    else if(strcmp(genero1, genero2) < 0)
    {
        ordenamiento = -1;
    }
    else
    {
        if(rating1>rating2)
        {
            ordenamiento = 1;
        }
        else if(rating1<rating2)
        {
             ordenamiento = -1;
        }





    }

    return ordenamiento;


}






