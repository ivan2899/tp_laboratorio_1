#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* Recibe la ruta del archivo para cargar los datos en modo texto
 * \param pArrayListPassenger LinkedList* Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*	Recibe la ruta del archivo para cargar los datos en modo binario
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \param pId int*	Recibe el puntero al id de los pasajeros
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* pId);

/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
* \param pId int*	Recibe el puntero al id de los pasajeros
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, int* pId);

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \param pId int*	Recibe el puntero al id de los pasajeros
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, int* pId);

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*	Recibe la ruta de donde va a guardar el archivo en modo texto
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char*	Recibe la ruta de donde va a guardar el archivo en modo binario
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Menu de salida.
 *
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \param confirma char*	Recibe el puntero a la letra de confirmacion
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_exit(LinkedList* pArrayListPassenger, char* confirma);

#endif /* CONTROLLER_H_ */
