
#include "LinkedList.h"





/** \brief Abre y cierra el archivo de texto que sera leido, pasandole los datos a parser para poder cargar esos datos en una LinkedList
 *
 * \param path char* nombre del archivo de texto que se abrira
 * \param lista LinkedList* lista donde se cargaran los datos
 * \return int retorna 1 en caso de poder cargar la lista, 0 en caso de error
 *
 */
int controller_loadFromText(char* path, LinkedList* lista);



/** \brief Imprime en pantalla la pelicula pasada or parametro
 *
 * \param peli eMovie*
 * \return int
 *
 */
int controller_printPeli(eMovie* peli);



/** \brief Recorre la LinkedList pasada por parametro para poder printear todas las peliculas de la lista
 *
 * \param lista LinkedList*
 * \return int retorna 1 en caso de poder printear las peliculas, 0 en caso de error
 *
 */
int controller_listPelis(LinkedList* lista);



/** \brief Guarda la lista en un archivo de texto de mismo path al pasado por parametro
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int controller_saveAsText(char* path, LinkedList*  lista);



/** \brief Filtra la lista por el genero seleccionado y guarda la lista generada en un archivo de texto
 *
 * \param lista LinkedList*
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int controller_filterGenero(LinkedList* lista);

