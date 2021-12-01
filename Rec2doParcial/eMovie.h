#ifndef EMOVIE_H_INCLUDED
#define EMOVIE_H_INCLUDED


typedef struct
{
    int id_peli;
    char titulo[128];
    char genero[128];
    float rating;
}eMovie;



/** \brief Crea una nueva estructura eMovie con todos sus campos inicializados en 0
 *
 * \return eMovie* retorna la nueva eMovie creada
 *
 */
eMovie* eMovie_new();





/** \brief Borra la estructura eMovie que se le pasa por parametro
 *
 * \param this eMovie* pelicula a ser borrada
 * \return void
 *
 */
void eMovie_delete(eMovie* this);





/** \brief Crea una nueva eMovie asignandole cada uno de los campos pasados por parametro
 *
 * \param idStr char* id
 * \param titulo char* titulo
 * \param genero char* genero
 * \param ratingStr char* rating
 * \return eMovie* retorna la eMovie creada
 *
 */
eMovie* eMovie_newParametros(char* idStr,char* titulo,char* genero, char* ratingStr);


//getters y setters



/** \brief Le asigna a la eMovie  el id pasado por parametro validando que sea valido
 *
 * \param this eMovie* estructura a la que se le asignara el id
 * \param id int id que sera asignado
 * \return int retorna 1 en caso de haber podido setear el id, 0 en caso de id no valido o error
 *
 */
int eMovie_setId(eMovie* this,int id);




/** \brief Carga el valor del id de la pelicula por referencia en la direccion de memoria que pasamos
 *
 * \param this eMovie* estructura de donde se sacara el valor
 * \param id int* campo donde se cargara el valor
 * \return int  retorna 1 en caso de exito, 0 en caso de error
 *
 */
int eMovie_getId(eMovie* this,int* id);






/** \brief Le asigna a la eMovie  el titulo pasado por parametro validando que sea valido
 *
 * \param this eMovie*
 * \param titulo char*
 * \return int retorna 1 en caso de exito, 0 en caso de error o titulo no valido
 *
 */
int eMovie_setTitulo(eMovie* this,char* titulo);





/** \brief  Carga el valor del titulo de la pelicula por referencia en la direccion de memoria que pasamos
 *
 * \param this eMovie*
 * \param titulo char*
 * \return int retorna 1 en caso de poder haberlo cargado, 0 en caso de error
 *
 */
int eMovie_getTitulo(eMovie* this,char* titulo);






/** \brief Le asigna a la eMovie  el genero pasado por parametro validando que sea valido
 *
 * \param this eMovie*
 * \param genero char*
 * \return int retorna 1 en caso de haberlo asignado, 0 en caso de error o genero no valido
 *
 */
int eMovie_setGenero(eMovie* this,char* genero);






/** \brief Carga el valor del genero de la pelicula por referencia en la direccion de memoria que pasamos
 *
 * \param this eMovie*
 * \param genero char*
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int eMovie_getGenero(eMovie* this,char* genero);







/** \brief  Carga el valor del rating de la pelicula por referencia en la direccion de memoria que pasamos
 *
 * \param this eMovie*
 * \param rating float*
 * \return int int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int eMovie_getRating(eMovie* this,float* rating);




/** \brief Le asigna a la eMovie  el rating pasado por parametro validando que sea valido
 *
 * \param this eMovie*
 * \param rating float
 * \return int retorna 1 en caso de haberlo asignado, 0 en caso de error o rating no valido
 *
 */
int eMovie_setRating(eMovie* this,float rating);







/** \brief Le asigna un valor random entre 1 y 10 con 1 decimal a el campo rating de la pelicula pasada por parametro
 *
 * \param movie void*
 * \return void*
 *
 */
void* eMovie_cargarRating(void* movie);





/** \brief Le asigna un genero random entre los 4 disponibles a la pelicula pasada por parametro
 *
 * \param movie void*
 * \return void*
 *
 */
void* eMovie_cargarGenero(void* movie);





/** \brief filtra si la pelicula es de genero Comedia
 *
 * \param pElement void*
 * \return int retorna 1 en caso de que sea de comedia, 0 en caso de que no sea
 *
 */
int eMovie_filterComedy(void* pElement);



/** \brief filtra si la pelicula es de genero Accion
 *
 * \param pElement void*
 * \return int retorna 1 en caso de que sea de Accion, 0 en caso de que no sea
 *
 */
int eMovie_filterAction(void* pElement);





/** \brief filtra si la pelicula es de genero terror
 *
 * \param pElement void*
 * \return int retorna 1 en caso de que sea de terror, 0 en caso de que no sea
 *
 */
int eMovie_filterTerror(void* pElement);




/** \brief filtra si la pelicula es de genero Drama
 *
 * \param pElement void*
 * \return int retorna 1 en caso de que sea de drama, 0 en caso de que no sea
 *
 */
int eMovie_filterDrama(void* pElement);



/** \brief Funcion utilizada para ordenar las peliculas pasadas por parametro por genero y por rating
 *
 * \param pelicula 1 a comparar
 * \param pelicula 2 a comparar
 * \return retorna 1 o -1 en caso de poder ordenarse, 0 en caso de error
 *
 */

int eMovie_ordenarGenero(void* peli1, void* peli2);



#endif // EMOVIE_H_INCLUDED
