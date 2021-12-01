#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Parsea los datos desde el archivo data.csv (modo texto).
 * \param pFile FILE* La dirección de memoria del archivo a parsear
 * \param lista LinkedList* Puntero a estructura LinkedList
 * \return int 0 si hubo error, 1 si no hubo error
 */
int parser_fromText(FILE* pFile, LinkedList* lista);



#endif // PARSER_H_INCLUDED
