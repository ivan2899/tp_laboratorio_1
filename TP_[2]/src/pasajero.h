#include "arrayPassenger.h"

#ifndef PASAJERO_H_INCLUDED
#define PASAJERO_H_INCLUDED


typedef struct{
    int num;
    char descripcion[16];
}eTipoDePasajero;

typedef struct{
    int num;
    char descripcion[10];
}eEstadoDeVuelo;


#endif // PASAJERO_H_INCLUDED

/** \brief imprime un menu principal para elegir que debe realizar el programa
 *
 * \return int devuelve la opcion elegida y validada
 *
 */
int menu();

/** \brief  imprime un submenu en modificar para elegir que debe modificar del pasajero
 *
 * \return int devuelve la opcion elegida y validada
 *
 */
int subMenuModificar();

/** \brief  imprime un submenu en informar para elegir que debe informar el programa
 *
 * \param criterio int* si debe ordenar descendente (0) o ascendente (1)
 * \return int devuelve la opcion elegida y validada
 *
 */
int subMenuInformar(int* criterio);



/** \brief Cambia el numero 1 o 2 por estado Activo o Inactivo, dependiendo de la descripcion dada
 *
 * \param estadoDeVuelo eEstadoDeVuelo* Puntero al array de estado de vuelo
 * \param tam int Tamaño del array
 * \param num int Numero que debe buscar en el array de estado de vuelo
 * \param descTipPasaj char* Puntero a una variable char para que le asigne la descripcion de "Activo" o "Inactivo"
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo o no existe el num] o (1) si esta todo ok
 *
 */
int buscarDescripcionEstadoDeVuelo(eEstadoDeVuelo* estadoDeVuelo, int tam, int num, char* descTipPasaj);

/** \brief Cambia el numero 1 o 2 o 3 por el tipo clase economica, primera clase, etc. Dependiendo de la descripcion dada
 *
 * \param tipoPasajero eTipoDePasajero* Puntero al array de tipo de pasajero
 * \param tam int Tamaño del array
 * \param num int Numero que debe buscar en el array de estado de vuelo
 * \param descTipPasaj char* Puntero a una variable char para que le asigne la descripcion
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo o no existe el num] o (1) si esta todo ok
 *
 */
int buscarDescripcionTipoPasajero(eTipoDePasajero* tipoPasajero, int tam, int num, char* descTipPasaj);

/** \brief Busca la primera posicion libre en el array con isEmpty (1)
 *
 * \param vec ePasajero* Puntero al array de pasajeros
 * \param tam int Tamaño del array
 * \param pIndex int* Puntero a una variable entera, que le asigna el indice de la primera posicion libre
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo] o (1) si esta todo ok
 *
 */
int buscarPosicionLibre(ePasajero* vec, int tam, int* pIndex);

/** \brief Cuenta todas las posiciones libres que existen en el array
 *
 * \param vec ePasajero* Puntero al array de pasajeros
 * \param tam int Tamaño del array
 * \param pCont int* Puntero a una variable entera, que le asigna el numero de las posiciones libres
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo] o (1) si esta todo ok
 *
 */
int buscarPosicionesDisponibles(ePasajero* vec, int tam, int* pCont);



/** \brief Imprime toda la lista de pasajeros ordenados por ID
 *
 * \param tam int Tamaño del array de pasajeros
 * \param lista ePasajero* Puntero al array de pasajeros
 * \param estado eEstadoDeVuelo* Puntero al array de estado de vuelo
 * \param tamEst int Tamaño del array de estado de vuelo
 * \param tipo eTipoDePasajero* Puntero al array de tipo de pasajero
 * \param tamTipo int Tamaño del array de tipo de pasajero
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo] o (1) si esta todo ok
 *
 */
int listarPasajeros(int tam, ePasajero* lista, eEstadoDeVuelo* estado, int tamEst, eTipoDePasajero* tipo, int tamTipo);

/** \brief Imprime toda la lista de pasajeros que tengan estado de vuelo "Activo" (1)
 *
 * \param tam int Tamaño del array de pasajeros
 * \param lista ePasajero* Puntero al array de pasajeros
 * \param estado eEstadoDeVuelo* Puntero al array de estado de vuelo
 * \param tamEst int Tamaño del array de estado de vuelo
 * \param tipo eTipoDePasajero* Puntero al array de tipo de pasajero
 * \param tamTipo int Tamaño del array de tipo de pasajero
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo] o (1) si esta todo ok
 *
 */
int listarPasajerosActivos(int tam, ePasajero* lista, eEstadoDeVuelo* estado, int tamEst, eTipoDePasajero* tipo, int tamTipo);

/** \brief Imprime un pasajero de la lista de pasajeros que tenga el id que se ingresa
 *
 * \param indice int Id para imprimir el pasajero
 * \param lista ePasajero* Puntero al array de pasajeros
 * \param estado eEstadoDeVuelo* Puntero al array de estado de vuelo
 * \param tamEst int Tamaño del array de estado de vuelo
 * \param tipo eTipoDePasajero* Puntero al array de tipo de pasajero
 * \param tamTipo int Tamaño del array de tipo de pasajero
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo o id inexistente] o (1) si esta todo ok
 *
 */
int listarUnPasajero(int indice, ePasajero* lista, eEstadoDeVuelo* estado, int tamEst, eTipoDePasajero* tipo, int tamTipo);



/** \brief Valida que la cadena ingresada no haga desbordar al vector
 *
 * \param tam int Tamaño del vector
 * \param auxCad[100] char Puntero de cadena ingresada
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo] o (1) si esta todo ok
 *
 */
int validarGets(int tam, char auxCad[100]);

/** \brief Ingreso y validacion de pasajero
 *
 * \param vec ePasajero* Puntero a vector auxiliar
 * \param pId int* Puntero del id, dentro del codigo se autoincrementa para que no se repitan los id
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo] o (1) si esta todo ok
 *
 */
int ingresoPasajero(ePasajero* vec, int* pId);

/** \brief Ingreso una opcion para poder modificar el campo elegido de la estructura de pasajeros
 *
 * \param vec ePasajero* Puntero a vector original
 * \param indice int Indice del pasajero a modificar
 * \param modif int Eleccion de lo que quiere modificar, el nombre, apellido, etc.
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo o indice inexistente] o (1) si esta todo ok
 *
 */
int modificacionPasajero(ePasajero* vec, int indice, int modif);

/** \brief Ingreso un numero y se harcodean esa cantidad de pasajeros si el array tiene espacio disponible
 *
 * \param vec ePasajero* Puntero a vector de pasajeros
 * \param tam int Tamaño del vector de pasajeros
 * \param rep int repeticiones que se quieren harcodear
 * \param id int* puntero al Id para asignarle uno a las personas harcodeadas
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo o las rep superan el limite disponible] o (1) si esta todo ok
 *
 */
int harcodearPasajeros(ePasajero* vec, int tam, int rep, int* id);

/** \brief Informa lista de pasajeros ordenados por apellido y tipo si la opcion (1),
 *          Informa la suma total, el promedio y la cantidad de pasajeros que superan el limite si la opcion (2)
 *          Informa la lista de pasajeros que esten activos, ordenados por codigo de vuelo si la opcion(3)
 *
 * \param vec ePasajero* Puntero a vector de pasajeros
 * \param tam int Tamaño del vector de pasajeros
 * \param estado eEstadoDeVuelo* Puntero a vector de estado de vuelo
 * \param tamEst int Tamaño del vector de estado de vuelo
 * \param tipo eTipoDePasajero* Puntero a vector de tipo de pasajero
 * \param tamTipo int Tamaño del vector de tipo de pasajeros
 * \param opcion int Opcion segun que es lo que quiere informar
 * \param criterio int Si lo ordena de manera descendente (0) o ascendente(1)
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo o opcion o criterio invalidos] o (1) si esta todo ok
 *
 */
int informarPasajero(ePasajero* vec, int tam, eEstadoDeVuelo* estado, int tamEst, eTipoDePasajero* tipo, int tamTipo, int opcion, int criterio);

/** \brief Calcula la suma de todos los precios de los pasajeros y el promedio
 *
 * \param vec ePasajero* Puntero a vector de pasajeros
 * \param tam int Tamaño del vector de pasajeros
 * \param suma float* Puntero a una variable float para que le asigne el valor de la suma total de los precios
 * \param prom float* Puntero a una variable float para que le asigne el valor del promedio total de los precios
 * \param contPasajeros int* Puntero a una variable int para que le asigne el valor de las personas que superan el promedio de precio
 * \return int devuelve (0) si dio error [Tamaño invalido o puntero nulo] o (1) si esta todo ok
 *
 */
int totalYPromedio(ePasajero* vec, int tam, float* suma, float* prom, int* contPasajeros);



/** \brief Cartel de confimarcion
 *
 * \param eleccion char* Letra a ingresar, si es "s" se valida
 * \return int devuelve (0) si dio error [Puntero nulo] o (1) si esta todo ok
 *
 */
int confirma(char* eleccion);

/** \brief Cartel de salida de funcion
 *
 * \param eleccion char* Letra a ingresar, si es "s" se valida
 * \return int devuelve (0) si dio error [Puntero nulo] o (1) si esta todo ok
 *
 */
int confirmaSalida(char* eleccion);

/** \brief Cartel de ingreso de funcion
 *
 * \param eleccion char* Letra a ingresar, si es "s" se valida
 * \param mensaje char* Cadena que imprime para que el usuario sepa a donde esta por ingresar
 * \return int devuelve (0) si dio error [Puntero nulo] o (1) si esta todo ok
 *
 */
int confirmaIngreso(char* eleccion, char* mensaje);

