#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*	Recibe la ruta del archivo a parsear
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*	Recibe la ruta del archivo a parsear
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */
