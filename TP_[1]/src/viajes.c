#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "viajes.h"


int eleccionMenu()
{
    int eleccion;

    system("cls");
    printf("|||  Menu Principal  ||| \n\n\n");
    printf("Seleccione una opcion: \n\n");
    printf("1. Ingresar kilometros \n2. Ingresar precio de vuelos\n");
    printf("3. Calcular los costos \n4. Informar resultados\n");
    printf("5. Carga forzada de datos\n6. Salir\n\n");
    printf("Opcion: ");
    scanf("%d", &eleccion);

    return eleccion;
}

int ingresarKilometros()
{
	int kilometros;

    printf("Ingrese los kilometros que tiene el viaje: ");
    scanf("%d", &kilometros);
    while(kilometros<=0)
    {
        printf("\nSe ha ingresado un numero incorrecto. \nReingrese los kilometros que tiene el viaje: ");
        scanf("%d", &kilometros);
    }

    return kilometros;
}

float ingresarPrecios()
{
    float precio;


    scanf("%f", &precio);
    while(precio <= 0)
    {
        printf("Se ha ingresado un numero incorrecto. \nReingrese el precio que tiene el viaje: ");
        scanf("%f", &precio);
    }

    return precio;
}

float tarjetaDebito(float precio)
{
    float precioConDescuento;
    precioConDescuento = precio *0.9;

    return precioConDescuento;
}

float tarjetaCredito(float precio)
{
    float precioConInteres;
    precioConInteres = precio * 1.25;

    return precioConInteres;
}

float bitcoin(float precio)
{
    float precioBitcoin;
    precioBitcoin = precio/4606954.55;

    return precioBitcoin;
}

float calcularPrecioUnitario(int km, float precio)
{
    float precioPorKm;
    precioPorKm = precio / km;

    return precioPorKm;
}

float calcularDiferenciaDePrecio(float precioAerolineas, float precioLatam)
{
    float diferencia;

    if(precioAerolineas >= precioLatam)
    {
        diferencia = precioAerolineas - precioLatam;
    }
    else if(precioLatam > precioAerolineas)
    {
        diferencia = precioLatam - precioAerolineas;
    }

    return diferencia;

}

void informarResultados(float precioTarjetaDebito, float precioTarjetaCredito, float precioConBitcoin, float precioUnitario)
{
    printf("a) Precio con tarjeta de debito: $ %.2f (10%% descuento)\n", precioTarjetaDebito);
    printf("b) Precio con tarjeta de credito: $ %.2f (25%% interes)\n", precioTarjetaCredito);
    printf("c) Precio pagando con bitcoin: %f BTC\n", precioConBitcoin);
    printf("d) Mostrar precio unitario: $ %.2f (precio por kilometro)\n", precioUnitario);
}

char confirmarSalida()
{
    char salida;

    system("cls");
    printf("Esta seguro que desea salir? \nPresione s (si) n (no): ");
    fflush(stdin);
    scanf("%c", &salida);
    salida = tolower(salida);

    return salida;
}
