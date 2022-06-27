#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Passenger.h"
#include "miPasajero.h"




int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    char encabezados[7][20];
    Passenger* auxPass;
    int cant;
    char conf;

    if(ll_len(pArrayListPassenger) > 0)
    {
        confirma("Se van a sobreescribir los pasajeros en memoria, desea cargarlo de todas formas?", &conf);
    }

    if(ll_len(pArrayListPassenger) == 0 || conf == 's')
    {
        ll_clear(pArrayListPassenger);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", encabezados[0], encabezados[1], encabezados[2], encabezados[3], encabezados[4], encabezados[5], encabezados[6]);
        while(!feof(pFile))
        {
            auxPass = Passenger_new();
            if(auxPass != NULL)
            {
                cant = fscanf(pFile, " %d, %[^,], %[^,], %f, %[^,], %[^,], %[^\n] \n", &auxPass->id, auxPass->nombre, auxPass->apellido, &auxPass->precio, auxPass->codigoVuelo, auxPass->estadoDelVuelo, auxPass->tipoPasajero);
                if(cant <1)
                {
                    return todoOk;
                }
                ll_add(pArrayListPassenger, auxPass);
            }
            todoOk = 1;
        }
    }

    return todoOk;
}


int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    char encabezados[80];
    Passenger* auxPass;
    int cant;
    char conf;

    if(ll_len(pArrayListPassenger) > 0)
    {
        confirma("Se van a sobreescribir los pasajeros en memoria, desea cargarlo de todas formas?", &conf);
    }

    if(ll_len(pArrayListPassenger) == 0 || conf == 's')
    {
        fread(encabezados, sizeof(char), 80, pFile);
        while(!feof(pFile))
        {
            auxPass = Passenger_new();
            if(auxPass != NULL)
            {
                cant = fread(auxPass, sizeof(Passenger), 1, pFile);
                if(cant <1)
                {
                    return todoOk;
                }
                ll_add(pArrayListPassenger, auxPass);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}
