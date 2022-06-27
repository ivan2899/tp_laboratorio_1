#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Passenger.h"
#include "miPasajero.h"


int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    if(path != NULL && pArrayListPassenger != NULL)
    {
        FILE* f = fopen(path, "r");
        if(f != NULL)
        {
            if(parser_PassengerFromText(f, pArrayListPassenger))
            {
                todoOk = 1;
            }
            fclose(f);
        }
    }
    return todoOk;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    if(path != NULL && pArrayListPassenger != NULL)
    {
        FILE* f = fopen(path, "rb");

        if(f != NULL)
        {
            if(parser_PassengerFromBinary(f, pArrayListPassenger))
            {
                todoOk = 1;
            }
            fclose(f);
        }
    }
    return todoOk;
}

int controller_addPassenger(LinkedList* pArrayListPassenger, int* pId)
{
    int todoOk = 0;
    char auxNombre[50];
    char auxApellido[50];
    float auxPrecio;
    char auxCodigoVuelo[10];
    char auxEstadoDelVuelo[20];
    char auxTipoPasajero[20];
    Passenger* newPass;

    if(pArrayListPassenger != NULL && pId != NULL)
    {
        if(
            (pedirYValidarString(50, auxNombre, "Ingrese el nombre: ", "Error, reingrese el nombre mayor a 2 y menor a 49 caracteres: ", 2)) &&
            (pedirYValidarString(50, auxApellido, "Ingrese el apellido: ", "Error, reingrese el apellido mayor a 1 menor a 49 caracteres: ", 1)) &&
            (pedirYValidarFloat(&auxPrecio, "Ingrese el precio: ", "Error, reingrese el precio menor a 1millon y mayor a 1: ", 1, 1000000)) &&
            (pedirYValidarString(10, auxCodigoVuelo, "Ingrese el codigo de vuelo: ", "Error, reingrese el codigo de vuelo menor a 10 caracteres: ", 1)) &&
            (pedirYValidarString(20, auxEstadoDelVuelo, "Ingrese el estado del vuelo: ", "Error, reingrese el estado del vuelo menor a 20 caracteres", 1)) &&
            (pedirYValidarString(20, auxTipoPasajero, "Ingrese el tipo de pasajero: ", "Error, reingrese el tipo de pasajero menor a 20 caracteres", 4)))
        {
            newPass = Passenger_newParametros(*pId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoDelVuelo);
            ll_add(pArrayListPassenger, newPass);
            todoOk = 1;
            *pId = *pId + 1;
        }
    }
    return todoOk;
}

int controller_editPassenger(LinkedList* pArrayListPassenger, int* pId)
{
    int todoOk = 0;
    int auxId;
    int indice;
    char conf;
    int opcion;
    Passenger* auxPass;
    char auxNombre[50];
    char auxApellido[50];
    float auxPrecio;
    char auxCodigoVuelo[10];
    char auxEstadoDelVuelo[20];
    char auxTipoPasajero[20];

    if(pArrayListPassenger != NULL && pId != NULL)
    {
        controller_ListPassenger(pArrayListPassenger);

        pedirYValidarInt(&auxId, "Ingrese el id de un pasajero: ", "Error, reingrese el id de un pasajero mayor a 1: ", 1, *pId);

        if((ll_buscarId(pArrayListPassenger, auxId, &indice)))
        {
            auxPass = (Passenger*) ll_get(pArrayListPassenger, indice);
            printf("Ingres%c el id %d: \n", 162, auxId);
            mostrarPasajeroSolo(auxPass);

            confirma("Esta seguro que desea modificarlo?", &conf);

            if(conf == 's')
            {
                subMenuModif(&opcion);
                switch(opcion)
                {
                case 1:
                    printf("Ha ingresado a modificar el nombre\n\n");
                    if(pedirYValidarString(50, auxNombre, "Ingrese el nombre: ", "Error, reingrese el nombre menor a 49 caracteres: ", 2))
                    {
                        strcpy(auxPass->nombre, auxNombre);
                    }
                    break;
                case 2:
                    printf("Ha ingresado a modificar el apellido\n\n");
                    if(pedirYValidarString(50, auxApellido, "Ingrese el apellido: ", "Error, reingrese el apellido menor a 49 caracteres: ", 1))
                    {
                        strcpy(auxPass->apellido, auxApellido);
                    }
                    break;
                case 3:
                    printf("Ha ingresado a modificar el precio\n\n");
                    if(pedirYValidarFloat(&auxPrecio, "Ingrese el precio: ", "Error, reingrese el precio menor a 1millon y mayor a 1: ", 1, 1000000))
                    {
                        auxPass->precio = auxPrecio;
                    }
                    break;
                case 4:
                    printf("Ha ingresado a modificar el c%cdigo de vuelo\n\n", 162);
                    if(pedirYValidarString(10, auxCodigoVuelo, "Ingrese el codigo de vuelo: ", "Error, reingrese el codigo de vuelo menor a 10 caracteres: ", 1))
                    {
                        strcpy(auxPass->codigoVuelo, auxCodigoVuelo);
                    }
                    break;
                case 5:
                    printf("Ha ingresado a modificar el estado del vuelo\n\n");
                    if(pedirYValidarString(20, auxEstadoDelVuelo, "Ingrese el estado del vuelo: ", "Error, reingrese el estado del vuelo menor a 20 caracteres: ", 1))
                    {
                        strcpy(auxPass->estadoDelVuelo, auxEstadoDelVuelo);
                    }
                    break;
                case 6:
                    printf("Ha ingresado a modificar el tipo de pasajero\n\n");
                    if(pedirYValidarString(20, auxTipoPasajero, "Ingrese el tipo de pasajero: ", "Error, reingrese el tipo de pasajero menor a 20 caracteres: ", 4))
                    {
                        strcpy(auxPass->tipoPasajero, auxTipoPasajero);
                    }
                    break;
                default:
                    printf("Se ha cancelado la modificaci%cn", 162);
                    break;
                }
            }
            else
            {
                printf("Se cancel%c la modificacion del pasajero", 162);
            }
        }
        else
        {
            printf("No se encontr%c el id ingresado", 162);
        }
    }

    return todoOk;
}

int controller_removePassenger(LinkedList* pArrayListPassenger, int* pId)
{
    int todoOk = 0;
    int auxId;
    int indice;
    char conf;
    Passenger* auxPass;


    if(pArrayListPassenger != NULL && pId != NULL)
    {
        controller_ListPassenger(pArrayListPassenger);

        pedirYValidarInt(&auxId, "Ingrese el id de un pasajero: ", "Error, reingrese el id de un pasajero mayor a 1: ", 1, *pId);

        if((ll_buscarId(pArrayListPassenger, auxId, &indice)))
        {
            auxPass = (Passenger*) ll_get(pArrayListPassenger, indice);
            printf("Ingres%c el id %d: \n", 162, auxId);
            mostrarPasajeroSolo(auxPass);

            confirma("Esta seguro que desea eliminarlo?", &conf);

            if(conf == 's')
            {
                ll_remove(pArrayListPassenger, indice);
                todoOk = 1;
            }
            else
            {
                printf("Se cancel%c la baja del pasajero", 162);
            }
        }
        else
        {
            printf("No se encontr%c el id ingresado", 162);
        }



    }

    return todoOk;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    Passenger* auxPass = NULL;
    if(pArrayListPassenger != NULL)
    {
        printf(" ____________________________________________________________________________________________________________________________________________________________________________ \n");
        printf("|  ID |                      NOMBRE                      |                      APELLIDO                    |  PRECIO |   CODIGO   |   ESTADO DE VUELO  |  TIPO DE PASAJERO  |\n");
        for(int i=0; i<ll_len(pArrayListPassenger); i++)
        {
            auxPass = (Passenger*) ll_get(pArrayListPassenger, i);
            printf("|-----|--------------------------------------------------|--------------------------------------------------|---------|------------|--------------------|--------------------|\n");
            mostrarPasajero(auxPass);
        }
        printf("|____________________________________________________________________________________________________________________________________________________________________________|");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int opcion;
    int orden;
    char conf;

    if(pArrayListPassenger != NULL)
    {
        subMenuOrdenar(&opcion, &orden);
        switch(opcion)
        {
        case 1:
            printf("Ha ingresado a ordenar por id\n\n");
            printf("ordenando, aguarde por favor ... \n\n");
            ll_sort(pArrayListPassenger, sortPassengersById, orden);
            break;
        case 2:
            printf("Ha ingresado a ordenar por nombre\n\n");
            printf("ordenando, aguarde por favor ... \n\n");
            ll_sort(pArrayListPassenger, sortPassengersByName, orden);
            break;
        case 3:
            printf("Ha ingresado a ordenar por apellido\n\n");
            printf("ordenando, aguarde por favor ... \n\n");
            ll_sort(pArrayListPassenger, sortPassengersByLastName, orden);
            break;
        case 4:
            printf("Ha ingresado a ordenar por precio\n");
            printf("ordenando, aguarde por favor ... \n\n");
            ll_sort(pArrayListPassenger, sortPassengersByPrice, orden);
            break;
        case 5:
            printf("Ha ingresado a ordenar por c%cdigo de vuelo\n\n", 162);
            printf("ordenando, aguarde por favor ... \n\n");
            ll_sort(pArrayListPassenger, sortPassengersByFlycode, orden);
            break;
        case 6:
            printf("Ha ingresado a ordenar por estado del vuelo\n\n");
            printf("ordenando, aguarde por favor ... \n\n");
            ll_sort(pArrayListPassenger, sortPassengersByStatusFlight, orden);
            break;
        case 7:
            printf("Ha ingresado a ordenar por tipo de pasajero\n\n");
            printf("ordenando, aguarde por favor ... \n\n");
            ll_sort(pArrayListPassenger, sortPassengersByType, orden);
            break;
        default:
            printf("Se ha cancelado el ordenamiento");
            break;
        }

        if(opcion != 8)
        {
            confirma("Se ordeno correctamente, quiere listarlos? ", &conf);
            todoOk = 1;
            if(conf == 's')
            {
                controller_ListPassenger(pArrayListPassenger);
            }
        }
    }

    return todoOk;
}

int controller_saveAsText(char* path, LinkedList* pArrayListPassenger)
{

    int todoOk = 0;
    Passenger* auxPass;
    int cant;
    char conf;
    int nextId;

    if(path != NULL && pArrayListPassenger != NULL)
    {
        FILE* file = fopen(path, "r");

        if(file != NULL)
        {
            printf("Precauci%cn!, ya existe un archivo con ese nombre y se va a sobrescribir\n", 162);
            confirma("Desea guardarlo con el mismo nombre, de todas formas? ", &conf);
        }
        fclose(file);

        if(file == NULL || conf == 's')
        {
            file = fopen(path, "w");
            fprintf(file, "ID,NOMBRE,APELLIDO,PRECIO,CODIGO,ESTADO DE VUELO,TIPO DE PASAJERO\n");
            for(int i=0; i<ll_len(pArrayListPassenger); i++)
            {
                auxPass = ll_get(pArrayListPassenger, i);
                if(auxPass != NULL)
                {
                    cant = fprintf(file, "%d, %s, %s, %f, %s, %s, %s\n", auxPass->id, auxPass->nombre, auxPass->apellido, auxPass->precio, auxPass->codigoVuelo, auxPass->estadoDelVuelo, auxPass->tipoPasajero);
                    todoOk = 1;
                }
                if(cant <1)
                {
                    return todoOk;
                }
            }
            fclose(file);
        }

        mayorId(pArrayListPassenger, &nextId);
        guardarId(nextId);
    }

    return todoOk;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    Passenger* auxPas;
    int cant;
    char conf;
    int nextId;
    char cadena[80] = {"ID,NOMBRE,APELLIDO,PRECIO,CODIGO,ESTADO DE VUELO,TIPO DE PASAJERO\n"};

    if(path != NULL && pArrayListPassenger != NULL)
    {
        FILE* pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            printf("Precauci%cn!, ya existe un archivo con ese nombre y se va a sobrescribir\n", 162);
            confirma("Desea guardarlo con el mismo nombre, de todas formas? ", &conf);
        }
        fclose(pFile);

        if(pFile == NULL || conf == 's')
        {
            pFile = fopen(path, "wb");
            fwrite(cadena, sizeof(char), 80, pFile);
            for(int i=0; i<ll_len(pArrayListPassenger); i++)
            {
                auxPas = ll_get(pArrayListPassenger, i);
                if(auxPas != NULL)
                {
                    cant = fwrite(auxPas, sizeof(Passenger), 1, pFile);
                    todoOk = 1;
                }
                if(cant <1)
                {
                    return todoOk;
                }
            }
            fclose(pFile);
        }
        mayorId(pArrayListPassenger, &nextId);
        guardarId(nextId);

    }
    return todoOk;
}

int controller_exit(LinkedList* pArrayListPassenger, char* confirma)
{
    int todoOk = 0;

    if(confirma != NULL)
    {
        confirmaSalida(confirma);

        if(*confirma == 's')
        {
            ll_deleteLinkedList(pArrayListPassenger);
        }
    }
    return todoOk;
}
