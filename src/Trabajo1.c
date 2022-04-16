#include <stdio.h>
#include <stdlib.h>
#include "viajes.h"

int main()
{
	setbuf(stdout, NULL);

    // Declaracion de variables
    int etapaMenu = 0; // etapaMenu es para validaciones, como que no puedas ingresar el precio del vuelo si no ingresaste los km todavia
    char salida = 'n';
    int kilometros;
    float precioVueloAerolineas;
    float precioVueloLatam;
    float tarjetaDebitoAerolineas;
    float tarjetaCreditoAerolineas;
    float bitcoinAerolineas;
    float precioUnitarioAerolineas;
    float tarjetaDebitoLatam;
    float tarjetaCreditoLatam;
    float bitcoinLatam;
    float precioUnitarioLatam;
    float diferenciaDePrecio;

    do
    {
        system("cls");
        switch(eleccionMenu())
        {

        case 1:
            if(etapaMenu >= 0)
            {
                printf("\nHa seleccionado opcion 1 (Ingresar kilometros) \n\n");
                kilometros = ingresarKilometros();
                etapaMenu++;
            }
            break;

        case 2:
            if(etapaMenu >= 1)
            {
                printf("\nHa seleccionado opcion 2 (Ingresar precio de vuelos) \n\n");
                printf("Ingrese el precio que tiene el viaje de Aerolineas: ");
                precioVueloAerolineas = ingresarPrecios();
                printf("\nIngrese el precio que tiene el viaje de Latam: ");
                precioVueloLatam = ingresarPrecios();
                etapaMenu++;
            }
            else
            {
                printf("\nNo puedes ingresar los precios de vuelo, sin antes ingresar los Kilometros\n");
                system("pause");
            }
            break;

        case 3:
            if(etapaMenu >= 2)
            {
                printf("\nHa seleccionado opcion 3 (Calcular los costos) \n\n");

                //Vuelo Aerolineas
                tarjetaDebitoAerolineas = tarjetaDebito(precioVueloAerolineas);
                tarjetaCreditoAerolineas = tarjetaCredito(precioVueloAerolineas);
                bitcoinAerolineas = bitcoin(precioVueloAerolineas);
                precioUnitarioAerolineas = calcularPrecioUnitario(kilometros, precioVueloAerolineas);

                //Vuelo Latam
                tarjetaDebitoLatam = tarjetaDebito(precioVueloLatam);
                tarjetaCreditoLatam = tarjetaCredito(precioVueloLatam);
                bitcoinLatam = bitcoin(precioVueloLatam);
                precioUnitarioLatam = calcularPrecioUnitario(kilometros, precioVueloLatam);

                diferenciaDePrecio = calcularDiferenciaDePrecio(precioVueloAerolineas, precioVueloLatam);

                etapaMenu++;
                printf("Los costos se calcularon correctamente\n");
                system("pause");
            }
            else
            {
                printf("\nDebes ingresar el precio de vuelo para poder calcular los costos\n");
                system("pause");
            }
            break;

        case 4:
            if(etapaMenu >= 3)
            {
                printf("\nHa seleccionado opcion 4 (Informar resultados) \n\n");

                printf("\nKMs Ingresados: %d km\n", kilometros);
                printf("\nPrecio Aerolineas: $ %.2f\n", precioVueloAerolineas);
                informarResultados(tarjetaDebitoAerolineas, tarjetaCreditoAerolineas, bitcoinAerolineas, precioUnitarioAerolineas);
                printf("\nPrecio Latam: $%.2f\n", precioVueloLatam);
                informarResultados(tarjetaDebitoLatam, tarjetaCreditoLatam, bitcoinLatam, precioUnitarioLatam);
                printf("\nLa diferencia de precio es: $ %.2f\n\n", diferenciaDePrecio);
                system("pause");

                etapaMenu = 0;
            }
            else
            {
                printf("\nDebes calcular los costos para poder informar los resultados\n");
                system("pause");
            }
            break;

        case 5:
                system("cls");
                printf("\nHa seleccionado opcion 5 (Carga forzada de datos) \n\n");

                kilometros = 7090;
                precioVueloAerolineas = 162965;
                precioVueloLatam = 159339;

                tarjetaDebitoAerolineas = tarjetaDebito(precioVueloAerolineas);
                tarjetaCreditoAerolineas = tarjetaCredito(precioVueloAerolineas);
                bitcoinAerolineas = bitcoin(precioVueloAerolineas);
                precioUnitarioAerolineas = calcularPrecioUnitario(kilometros, precioVueloAerolineas);

                tarjetaDebitoLatam = tarjetaDebito(precioVueloLatam);
                tarjetaCreditoLatam = tarjetaCredito(precioVueloLatam);
                bitcoinLatam = bitcoin(precioVueloLatam);
                precioUnitarioLatam = calcularPrecioUnitario(kilometros, precioVueloLatam);

                diferenciaDePrecio = calcularDiferenciaDePrecio(precioVueloAerolineas, precioVueloLatam);


                printf("\nKMs Ingresados: %d km\n", kilometros);
                printf("\nPrecio Aerolineas: $ %.2f\n", precioVueloAerolineas);
                informarResultados(tarjetaDebitoAerolineas, tarjetaCreditoAerolineas, bitcoinAerolineas, precioUnitarioAerolineas);
                printf("\nPrecio Latam: $%.2f\n", precioVueloLatam);
                informarResultados(tarjetaDebitoLatam, tarjetaCreditoLatam, bitcoinLatam, precioUnitarioLatam);
                printf("\nLa diferencia de precio es: $ %.2f\n\n", diferenciaDePrecio);
                system("pause");

            break;

        case 6:
            salida = confirmarSalida();
            break;

        default:
            printf("\nOcurrio un error al seleccionar el numero, vuelva a intentarlo\n");
            system("pause");
            break;
        }

    }
    while(salida != 's');

    return 0;
}
