#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED

typedef struct
{
int id;
char nombre[51];
char apellido[51];
float precio;
char codigoDeVuelo[10];
int tipoDePasajero;
int estadoDelVuelo;
int isEmpty;
}ePasajero;

#endif  // ARRAYPASSENGER_H_INCLUDED

/** \brief  To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE (1) in all
 * position of the array
 *
 * \param vec ePasajero* Pointer to array of passenger
 * \param tam int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int initPassengers(ePasajero* vec, int tam);



/** \brief add in a existing list of passengers the values received as parameters
 *           in the first empty position
 *
 * \param lista ePasajero* Pointer to array of passenger
 * \param tam int Array length
 * \param id int Id Passenger
 * \param nombre char* Name Passenger
 * \param apellido char* LastName Passenger
 * \param precio float price Passenger
 * \param codigoDeVuelo char* FlyCode Passenger
 * \param tipoDePasajero int typePassenger (first class, business class, etc)
 * \param estadoDelVuelo int statusFlight (1 is "Active", 2 is "Inactive")
 * \param i int (index to load array)
 * \return int Return (0) if Error [Invalid length or NULL pointer or without free space] - (1) if Ok
 *
*/
int addPassenger(ePasajero* lista, int tam, int id, char* nombre,char*
                 apellido,float precio,char* codigoDeVuelo,int tipoDePasajero, int estadoDelVuelo, int i);


/** \brief find a Passenger by Id and returns the index position in array in pointer pIndex.
 *
 * \param vec ePasajero* Pointer to array of passenger
 * \param tam int Array length
 * \param id int Id Passenger
 * \param pIndex int* First free index
 * \return int Return (0) if Error [Invalid length or NULL pointer or without free space] - (1) if Ok
 *
 */
int findPassengerById(ePasajero* vec, int tam,int id, int* pIndex);


/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * \param vec ePasajero* Pointer to array of passenger
 * \param tam int Array length
 * \param id int Id Passenger
 * \return int Return (0) if Error [Invalid length or NULL pointer or without free space] - (1) if Ok
 *
 */
int removePassenger(ePasajero* vec, int tam, int id);


/** \brief  print the content of passengers array
 *
 * \param lista ePasajero* Pointer to array of passenger
 * \param tam int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer or without free space] - (1) if Ok
 *
 */
int printPassengers(ePasajero* lista, int tam);


/** \brief Sort the elements in the array of passengers, the argument criterio
indicate UP or DOWN order
 *
 * \param lista ePasajero* Pointer to array of passenger
 * \param tam int Array length
 * \param criterio int Order(1 UP, 0 DOWN)
 * \return int Return (0) if Error [Invalid length or NULL pointer or without free space] - (1) if Ok
 *
 */
int sortPassengers(ePasajero* lista, int tam, int criterio);


/** \brief Sort the elements in the array of passengers, the argument criterio
 *          indicate UP or DOWN order by code
 *
 * \param lista ePasajero* Pointer to array of passenger
 * \param tam int Array length
 * \param criterio int Order(1 UP, 0 DOWN)
 * \return int Return (0) if Error [Invalid length or NULL pointer or without free space] - (1) if Ok
 *
 */
int sortPassengersByCode(ePasajero* lista, int tam, int criterio);

