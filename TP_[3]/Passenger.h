#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char estadoDelVuelo[20];
	char tipoPasajero[20];
}Passenger;

/** \brief Crea un nuevo pasajero
 *
 * \return Passenger* Retorna la referencia al pasajero
 *
 */
Passenger* Passenger_new();

/** \brief Crea un nuevo pasajero con los parametros dados
 *
 * \param id int*	Recibe la referencia del id para autoincrementarlo
 * \param nombreStr char*	Recibe la referencia del nombre para cargarlo en el nuevo pasajero
 * \param apellidoStr char*	Recibe la referencia del apellido para cargarlo en el nuevo pasajero
 * \param precio float	Recibe el valor del precio para cargarlo en el nuevo pasajero
 * \param codigodeVueloStr char*	Recibe la referencia del codigo de vuelo para cargarlo en el nuevo pasajero
 * \param tipoPasajero char* Recibe el texto del tipo de pasajero para cargarlo en el nuevo pasajero Primera clase, Clase ejecutiva, Clase economica
 * \param estadoVuelStr char*	Recibe la referencia del estado de vuelo para cargarlo en el nuevo pasajero
 * \return Passenger* Retorna la referencia al pasajero
 *
 */
Passenger* Passenger_newParametros(int id,char* nombreStr, char* apellidoStr, float precio, char* codigodeVueloStr, char* tipoPasajero, char* estadoVuelStr);

/** \brief Libera el espacio en memoria dinamica
 *
 * \param this Passenger* Recibe la referencia del pasajero a liberar
 * \return void
 *
 */
void Passenger_delete(Passenger* this);



/** \brief Carga el id en la estructura del  pasajero
 *
 * \param this Passenger* Recibe la estructura del pasajero
 * \param id int Recibe el id a cargar
 * \return int Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_setId(Passenger* this,int id);

/** \brief Carga el id en la referencia recibida
 *
 * \param this Passenger* Recibe la estructura del pasajero
 * \param id int* Recibe la referencia donde se va a cargar el id desde la estructura pasajero
 * \return int Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_getId(Passenger* this,int* id);



/** \brief Carga el nombre en la estructura del pasajero
 *
 * \param this Passenger* Recibe la estructura del pasajero
 * \param nombre char*	Recibe el vector del nombre a cargar en la estructura
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_setNombre(Passenger* this,char* nombre);

/** \brief Carga el nombre en el vector recibido
 *
 * \param this Passenger* Recibe la estructura del pasajero
 * \param nombre char*	Recibe el vector donde se va a cargar el nombre desde la estructura pasajero
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_getNombre(Passenger* this,char* nombre);



/** \brief Carga el apellido en la estructura del pasajero
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param apellido char*	Recibe el vector del apellido a cargar en la estructura
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/** \brief Carga el apellido en el vector recibido
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param apellido char*	Recibe el vector donde se va a cargar el apellido desde la estructura pasajero
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_getApellido(Passenger* this,char* apellido);



/** \brief Carga el tipo de pasajero en la estructura del pasajero
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param tipoPasajero char*	Recibe el tipo del pasajero Primera clase, Clase ejecutiva, Clase economica
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

/** \brief Carga el tipo de pasajero en la referencia recibida
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param tipoPasajero char*	Recibe la referencia donde se va a cargar el tipo de pasajero desde la estructura pasajero
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);



/** \brief Carga el codigo de vuelo en la estructura del pasajero
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param codigoVuelo char*	Recibe el vector del codigo de vuelo a cargar en la estructura
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/** \brief Carga el codigo de vuelo en el vector recibido
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param codigoVuelo char*	Recibe el vector donde se va a cargar el codigo de vuelo desde la estructura pasajero
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);



/** \brief Carga el estado de vuelo en la estructura del pasajero
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param estadoVuelo char*	Recibe el vector del estado de vuelo a cargar en la estructura
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

/** \brief Carga el estado de vuelo en el vecor recibido
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param estadoVuelo char*	Recibe el vector del estado de vuelo donde se va a cargar el estado de vuelo desde la estructura
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);



/** \brief Carga el precio en la estructura del pasajero
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param precio float	Recibe el precio a cargar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_setPrecio(Passenger* this,float precio);

/** \brief Carga el precio en la referencia recibida
 *
 * \param this Passenger*	Recibe la estructura del pasajero
 * \param precio float*	Recibe la referencia donde se va a cargar el precio desde la estructura pasajero
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Passenger_getPrecio(Passenger* this,float* precio);

#endif /* PASSENGER_H_ */
