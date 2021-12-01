#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", input);
}




int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloNumerico(int num)
{
    int todoOk=0;

    char buffer[20];

    itoa(num,buffer,10);

    if(esNumerico(buffer))
    {
        todoOk=1;



    }


    return todoOk;

}



int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux)&&strlen(aux)<51)
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

void getConfirmacion(char mensaje[], char* rta)
{
    char confirmacion= *rta;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&confirmacion);

     while(confirmacion!='s'&& confirmacion!='n')
            {
                printf("Opcion no valida.");
                printf("%s",mensaje);
                fflush(stdin);
                scanf("%c",&confirmacion);
            }
    *rta = confirmacion;


}


int menu()
{
    system("cls");

    int opcion;


    printf("-----Elija la operacion a realizar-----\n\n\n");
    printf("*****************************************************/\n");
    printf("1. Cargar los datos  desde el archivo ingresado (modo texto).\n");
    printf("2. Listar \n");
    printf("3. Cargar Rating de las pelis\n");
    printf("4. Asignar genero\n");
    printf("5. Filtrar por genero\n");
    printf("6. Ordenar peliculas\n");
    printf("7. Guardar peliculas\n");


    printf("8. Salir\n");
    printf("*****************************************************/\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;




}

int subMenu()
{
    system("cls");

    int opcion;


    printf("-----Elija el genero que desea filtrar-----\n\n\n");

    printf("1.Comedia \n");
    printf("2.Accion \n");
    printf("3.Terror \n");
    printf("4.Drama \n");


    printf("4. Salir\n");

    printf("Ingrese opcion: ");
    printf("\n\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;



}







