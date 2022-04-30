#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED



#endif // VIAJES_H_INCLUDED

/** \brief 								Esta funcion genera un Menu principal para elegir las opciones que desees.
 *
 * \return int							Devuelve el valor de la eleccion del usuario.
 *
 */
int eleccionMenu();


/** \brief								La funcion ingresarKilometros se utiliza para cuando el usuario selecciona la opcion 1 y sirve para pedirle que ingrese kilometros
 *
 * \return int							Devuelve los kilometros ingresados
 *
 */
int ingresarKilometros();


/** \brief								Esta funcion sirve para pedirle al usuario que ingrese el precio de una aerolinea
 *
 * \return float 						Devuelve el precio (valor) que selecciono el usuario
 *
 */
float ingresarPrecios();


/** \brief								La funcion informarResultados sirve para imprimir por pantalla todas las variables que ejecutamos
 * 										en el codigo, el descuento con tarjeta de debito, el interes con tarjeta de credito,
 * 		 								el precio en bitcoin, y el precio por kilometro.
 *
 * \param precioTarjetaDebito float		Recibe el precio con descuento para pagar con tarjeta de debito
 * \param precioTarjetaCredito float	Recibe el precio con interes para pagar con tarjeta de credito
 * \param precioConBitcoin float		Recibe el precio convertido para poder con bitcoin(BTC)
 * \param precioUnitario float			Recibe el precio por kilometro
 * \return void							No devuelve nada, porque la funcion se encarga de imprimir todos los valores
 *
 */
void informarResultados(float precioTarjetaDebito, float precioTarjetaCredito, float precioConBitcoin, float precioUnitario);


/** \brief								La funcion tajetaDebito sirve para calcular un 10% de descuento con el valor ingresado
 *
 * \param precio float					Recibe el valor para poder calcular el descuento
 * \return float						Devuelve el valor del precio con descuento
 *
 */
float tarjetaDebito(float precio);


/** \brief								Esta funcion sirve para calcular un 25% de interes con el valor ingresado
 *
 * \param precio float					Recibe el valor para poder calcular el interes
 * \return float						Devuelve el valor del precio con interes
 *
 */
float tarjetaCredito(float precio);


/** \brief								Esta funcion sirve para calcular la cantidad de bitcoin que se debe pagar segun el valor ingresado
 *
 * \param precio float					Recibe el valor a pagar
 * \return float						Devuelve la cantidad de bitcoin que debe pagar
 *
 */
float bitcoin(float precio);


/** \brief								Es una funcion que se utiliza para saber cuanto vale cada kilometro
 *
 * \param km int						Recibe la cantidad de kilometros totales del viaje
 * \param precio float					Recibe el precio total del viaje
 * \return float						Devuelve el valor de cuanto dinero sale cada kilometro, es decir el precio por kilometro
 *
 */
float calcularPrecioUnitario(int km, float precio);


/** \brief								Es una funcion que sirve para calcular la diferencia de precios entre dos valores
 *
 * \param precioAerolineas float		Recibe el primer valor
 * \param precioLatam float				Recibe el segundo valor
 * \return float						Devuelve el valor de la diferencia en positivo
 *
 */
float calcularDiferenciaDePrecio(float precioAerolineas, float precioLatam);


/** \brief								Es una opcion de confirmacion por si apretaste por equivocacion la opcion de salir
 *
 * \return char							Devuelve el caracter que ingreso el usuario
 *
 */
char confirmarSalida();
