#ifndef MIPASAJERO_H_
#define MIPASAJERO_H_

#include "Passenger.h"
#include "LinkedList.h"

/** \brief Menu para elegir la opcion de abm o guardar o cargar
 *
 * \return int	Retorna la opcion
 *
 */
int option();

/** \brief Menu para elegir que desea modificar
 *
 * \param opcion int*	Recibe el puntero para guardar la opcion elegida
 * \return int	Retorna la opcion
 *
 */
int subMenuModif(int* opcion);

/** \brief Menu para elegir que desea modificar
 *
 * \param opcion int*	Recibe el puntero para guardar la opcion elegida
 * \param orden int*	Recibe el puntero para guardar el elegido Ascendente(1) o descendente (0)
 * \return int	Retorna la opcion
 *
 */
int subMenuOrdenar(int* opcion, int* orden);



/** \brief Muestra un pasajero del linked list, sin formato
 *
 * \param auxPass Passenger*	Recibe el puntero del pasajero a mostrar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int mostrarPasajero(Passenger* auxPass);

/** \brief Muestra un pasajero del linked list, con formato (un cuadro armado)
 *
 * \param auxPass Passenger*	Recibe el puntero del pasajero a mostrar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int mostrarPasajeroSolo(Passenger* auxPass);

/** \brief Le pide la ruta al usuario
 *
 * \param pPath char*	Recibe el puntero de un vector a donde se va a guardar la ruta
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirPath(char* pPath);



/** \brief Valida que el vector no se desborde
 *
 * \param tam int	Recibe el tamaño del vector
 * \param auxCad[100] char	Recibe el tamaño del texto de 100 caracteres como maximo
 * \return int	Retorna (1)Si salio todo bien, (0)Si se desbordo
 *
 */
int validarGets(int tam, char auxCad[100]);

/** \brief Borra el \n del texto
 *
 * \param cadena char*	Recibe el texto
 * \param tam int	Recibe el tamaño del vector
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int validarFgets(char* cadena, int tam);

/** \brief Pide y valida un Int con parametros recibidos
 *
 * \param resultado int* puntero a donde se va a guardar el resultado
 * \param mensaje[50] char	Mensaje que le pida al usuario el numero
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el numero
 * \param minimo int	Numero minimo a validar
 * \param maximo int	Numero maximo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarInt(int* resultado, char mensaje[50], char mensajeError[50], int minimo, int maximo);

/** \brief Pide y valida un Float con parametros recibidos
 *
 * \param resultado float* puntero a donde se va a guardar el resultado
 * \param mensaje[50] char	Mensaje que le pida al usuario el numero
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el numero
 * \param minimo float	Numero minimo a validar
 * \param maximo float	Numero maximo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarFloat(float* resultado, char mensaje[50], char mensajeError[50], float minimo, float maximo);

/** \brief Pide y valida un Char con parametros recibidos
 *
 * \param resultado char*	puntero a donde se va a guardar la letra
 * \param mensaje[50] char	Mensaje que le pida al usuario el caracter
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el caracter
 * \param minimo char	caracter minimo a validar
 * \param maximo char	caracter maximo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarChar(char* resultado, char mensaje[50], char mensajeError[50], char minimo, char maximo);

/** \brief Pide y valida un string con parametros recibidos
 *
 * \param maximo int	valor del maximo texto que puede recibir
 * \param cadena char*	puntero a donde se va a guardar el texto
 * \param mensaje[50] char	Mensaje que le pida al usuario el texto
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el texto
 * \param minimo char	largo de texto minimo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarString(int maximo, char* cadena,  char mensaje[50], char mensajeError[50], int minimo);



/** \brief Menu de confirmacion de salida
 *
 * \param eleccion char*	Recibe un puntero a donde se guarde la opcion elegida
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int confirmaSalida(char* eleccion);

/** \brief Menu de confirmacion de salida
 *
 * \param cadena char*	Recibe un texto que le muestre al usuario que tiene que elegir
 * \param cadena char*	Recibe un puntero a donde se guarde la opcion elegida
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int confirma(char* cadena, char* letra);



/** \brief Abre el archivo donde esta el ultimo ID y lo carga
 *
 * \param mayorId int*	Recibe un puntero en donde se guarde el id
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int cargarId(int* mayorId);

/** \brief Abre un archivo para guardar el ultimo ID
 *
 * \param mayorId int	Recibe el valor del id a guardar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int guardarId(int mayorId);

/** \brief Abre un archivo para guardar el ultimo ID
 *
 * \param this LinkedList*	Recibe el puntero al linked list
 * \param id int*	Recibe un puntero a donde guarde el mayo ID
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int mayorId(LinkedList* this, int* id);

/** \brief Busca un id en el linked list
 *
 * \param this LinkedList*	Recibe el puntero al linked list
 * \param id int	Recibe el id a buscar
 * \param index int*	Recibe un puntero a donde guarda el indice
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int ll_buscarId(LinkedList* this, int id, int* index);



/** \brief Ordena a los pasajeros por el ID
 *
 * \param type1 void*	Recibe un valor
 * \param type2 void*	Recibe otro valor
 * \return int	Retorna (1)Si type 1 es mayor, (-1) Si type 2 es mayor
 *
 */
int sortPassengersById(void* type1, void* type2);

/** \brief Ordena a los pasajeros por el NOMBRE
 *
 * \param type1 void*	Recibe un valor
 * \param type2 void*	Recibe otro valor
 * \return int	Retorna (1)Si type 1 es mayor, (-1) Si type 2 es mayor
 *
 */
int sortPassengersByName(void* type1, void* type2);

/** \brief Ordena a los pasajeros por el APELLIDO
 *
 * \param type1 void*	Recibe un valor
 * \param type2 void*	Recibe otro valor
 * \return int	Retorna (1)Si type 1 es mayor, (-1) Si type 2 es mayor
 *
 */
int sortPassengersByLastName(void* type1, void* type2);

/** \brief Ordena a los pasajeros por el PRECIO
 *
 * \param type1 void*	Recibe un valor
 * \param type2 void*	Recibe otro valor
 * \return int	Retorna (1)Si type 1 es mayor, (-1) Si type 2 es mayor
 *
 */
int sortPassengersByPrice(void* type1, void* type2);

/** \brief Ordena a los pasajeros por el CODIGO DE VUELO
 *
 * \param type1 void*	Recibe un valor
 * \param type2 void*	Recibe otro valor
 * \return int	Retorna (1)Si type 1 es mayor, (-1) Si type 2 es mayor
 *
 */
int sortPassengersByFlycode(void* type1, void* type2);

/** \brief Ordena a los pasajeros por el ESTADO DE VUELO
 *
 * \param type1 void*	Recibe un valor
 * \param type2 void*	Recibe otro valor
 * \return int	Retorna (1)Si type 1 es mayor, (-1) Si type 2 es mayor
 *
 */
int sortPassengersByStatusFlight(void* type1, void* type2);

/** \brief Ordena a los pasajeros por el TIPO DE PASAJERO
 *
 * \param type1 void*	Recibe un valor
 * \param type2 void*	Recibe otro valor
 * \return int	Retorna (1)Si type 1 es mayor, (-1) Si type 2 es mayor
 *
 */
int sortPassengersByType(void* type1, void* type2);

#endif /* MIPASAJERO_H_ */
