#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pasajero.h"
#include "arrayPassenger.h"

#define TAM 2000
#define TAM_EST_VUELO 2
#define TAM_TIPO_PASAJERO 3


int main(void)
{
	setbuf(stdout, NULL);

    char confSalida = 'n';
    char confIngreso = 'n';
    char mensaje[50];
    int contEspacio;
    int banderaMenu = 0;
    int opcionInformar;
    int opcionModificar;
    int id = 1000;
    int idRequerido;
    int indice;
    int harcodeo;
    int criterio = 0;
    ePasajero lista[TAM];
    ePasajero aux;
    eTipoDePasajero tipo[TAM_TIPO_PASAJERO]=
    {
        {1, "Primera clase"},
        {2, "Clase ejecutiva"},
        {3, "Economica"}
    };
    eEstadoDeVuelo estado[TAM_EST_VUELO] =
    {
        {1, "Activo"},
        {2, "Inactivo"}
    };


    initPassengers(lista, TAM);
    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            strcpy(mensaje, "Alta pasajero");
            confirmaIngreso(&confIngreso, mensaje);

            if(confIngreso == 'S')
            {
                printf("Ha ingresado a la opcion Alta del pasajero\n\n");
                if(buscarPosicionLibre(lista, TAM, &indice))
                {
                    ingresoPasajero(&aux, &id);
                    addPassenger(lista, TAM, aux.id, aux.nombre, aux.apellido, aux.precio, aux.codigoDeVuelo, aux.tipoDePasajero, aux.estadoDelVuelo, indice);
                    banderaMenu = 1;
                }
                else
                {
                    printf("No hay mas espacio en el sistema!!\n");
                }
            }
            else
            {
                printf("Se cancelo el alta de pasajero\n\n");
            }

            system("pause");
            confIngreso = 'n';
            break;
        case 2:
            if(banderaMenu == 1)
            {
                strcpy(mensaje, "Modificar pasajero");
                confirmaIngreso(&confIngreso, mensaje);

                if(confIngreso == 'S')
                {
                    printf("Ha ingresado a la opcion Modificar pasajero\n\n");
                    listarPasajeros(TAM, lista, estado, TAM_EST_VUELO, tipo, TAM_TIPO_PASAJERO);
                    printf("\nIngrese el id del pasajero al que le quiera modificar un valor: ");
                    scanf("%d", &idRequerido);

                    if(findPassengerById(lista, TAM, idRequerido, &indice))
                    {
                        system("cls");
                        listarUnPasajero(indice, lista, estado, TAM_EST_VUELO, tipo, TAM_TIPO_PASAJERO);
                        opcionModificar = subMenuModificar();
                        modificacionPasajero(lista, indice, opcionModificar);
                    }
                    else
                    {
                        printf("No se encontro un id existente\n\n");
                    }
                }
                else
                {
                    printf("Se cancelo la modificacion de pasajero\n\n");
                }
            }
            else
            {
                printf("\nSe debe ingresar un pasajero antes de acceder a la funcion\n");
            }

            system("pause");
            confIngreso = 'n';
            break;
        case 3:
            if(banderaMenu == 1)
            {
                strcpy(mensaje, "Baja pasajero");
                confirmaIngreso(&confIngreso, mensaje);

                if(confIngreso == 'S')
                {
                    printf("Ha ingresado a la opcion Darle de baja al pasajero\n\n");
                    listarPasajeros(TAM, lista, estado, TAM_EST_VUELO, tipo, TAM_TIPO_PASAJERO);
                    printf("\nIngrese el id del pasajero que le quiera dar de baja: ");
                    scanf("%d", &idRequerido);

                    confIngreso = 'n'; // reseteo la variable

                    system("cls");
                    if(findPassengerById(lista, TAM, idRequerido, &indice))
                    {
                        listarUnPasajero(indice, lista, estado, TAM_EST_VUELO, tipo, TAM_TIPO_PASAJERO);

                        printf("Confirma darle de baja al Pasajero \"%s %s\" con id %d?\n", lista[indice].nombre, lista[indice].apellido, idRequerido);
                        confirma(&confIngreso);
                    }

                    if(confIngreso == 'S')
                    {
                        if(removePassenger(lista, TAM, idRequerido))
                        {
                            printf("Se le dio de baja al pasajero correctamente\n\n");
                        }
                        else
                        {
                            printf("Ocurrio un error al dar de baja al pasajero\n\n");
                        }
                    }
                    else
                    {
                        printf("La baja del pasajero fue cancelada\n\n");
                    }
                }
                else
                {
                    printf("La baja del pasajero fue cancelada\n\n");
                }
            }
            else
            {
                printf("\nSe debe ingresar un pasajero antes de acceder a la funcion\n");
            }
            system("pause");
            confIngreso = 'n';
            break;
        case 4:
            strcpy(mensaje, "Carga forzada");
            confirmaIngreso(&confIngreso, mensaje);

            if(confIngreso == 'S')
            {
                printf("Ha ingresado a la opcion Carga forzada de pasajeros\n\n");
                buscarPosicionesDisponibles(lista, TAM, &contEspacio);
                printf("Elija la cantidad de pasajeros que desea cargar forzadamente (un maximo de %d pasajeros): ", contEspacio);
                scanf("%d", &harcodeo);
                if(harcodearPasajeros(lista, TAM, harcodeo, &id))
                {
                    printf("Se cargaron los pasajeros correctamente\n\n");
                    banderaMenu = 1;
                }
                else if(contEspacio == 0)
                {
                    printf("No hay mas espacio en el sistema!!\n\n");
                }
                else
                {
                    printf("No se pudo cargar los pasajeros porque supera el limite: %d\n\n", contEspacio);
                }
            }
            else
            {
                printf("La carga forzada fue cancelada\n\n");
            }

            system("pause");
            confIngreso = 'n';
            break;
        case 5:
            if(banderaMenu == 1)
            {
                opcionInformar = subMenuInformar(&criterio);
                informarPasajero(lista, TAM, estado, TAM_EST_VUELO, tipo, TAM_TIPO_PASAJERO, opcionInformar, criterio);
            }
            else
            {
                printf("\nSe debe ingresar un pasajero antes de acceder a la funcion\n");
            }
            system("pause");
            break;
        case 6:
            confirmaSalida(&confSalida);
            break;
        }
    }
    while(confSalida != 'S');


    return 0;
}
