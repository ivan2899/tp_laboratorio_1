#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arrayPassenger.h"
#include "pasajero.h"

int initPassengers(ePasajero* vec, int tam)
{
    int todoOk = 0;

    if(vec && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int addPassenger(ePasajero* lista, int tam, int id, char* nombre,char*
                 apellido,float precio,char* codigoDeVuelo,int tipoDePasajero, int estadoDelVuelo, int i)
{
    int todoOk = 0;

    if(lista && tam>0 && id>999 && nombre && apellido && precio>0 && codigoDeVuelo && tipoDePasajero>0 && tipoDePasajero<4 && estadoDelVuelo>=1 && estadoDelVuelo<= 2 && i>=0)
    {
        lista[i].id = id;
        strcpy(lista[i].nombre, nombre);
        strcpy(lista[i].apellido, apellido);
        lista[i].precio = precio;
        strcpy(lista[i].codigoDeVuelo, codigoDeVuelo);
        lista[i].tipoDePasajero = tipoDePasajero;
        lista[i].estadoDelVuelo = estadoDelVuelo;
        lista[i].isEmpty = 0;
        todoOk = 1;
    }
    return todoOk;
}

int findPassengerById(ePasajero* vec, int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(vec && tam > 0 && pIndex && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty == 0 && vec[i].id == id)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int removePassenger(ePasajero* vec, int tam, int id)
{
    int todoOk = 0;
    int indice;

    if(vec && tam>0 && id>0)
    {
        if(findPassengerById(vec, tam, id, &indice))
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
        }
    }

    return todoOk;
}

int printPassengers(ePasajero* lista, int tam)
{
    int todoOk = 0;

    if(lista && tam>0)
    {
        for(int i; i<tam; i++)
        {
                if(!(lista[i].isEmpty))
            {
            printf("| %4d | %50s | %50s | %9.2f | %9s | %2d | %2d |\n",  lista[i].id, lista[i].nombre, lista[i].apellido, lista[i].precio, lista[i].codigoDeVuelo, lista[i].tipoDePasajero, lista[i].estadoDelVuelo);
            todoOk = 1;
            }
        }
    }
    return todoOk;
}

int sortPassengers(ePasajero* lista, int tam, int criterio)
{
    int todoOk = 0;
    ePasajero aux;

    if(lista && tam>0 && criterio >=0 && criterio <=1)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(!(lista[i].isEmpty) && !(lista[j].isEmpty))
                {
                    if(((lista[i].tipoDePasajero == lista[j].tipoDePasajero) && stricmp(lista[i].apellido, lista[j].apellido) > 0 && criterio == 1) ||
                    ((lista[i].tipoDePasajero == lista[j].tipoDePasajero) && stricmp(lista[i].apellido, lista[j].apellido) < 0 && criterio == 0)    ||
                    (lista[i].tipoDePasajero != lista[j].tipoDePasajero && lista[i].tipoDePasajero > lista[j].tipoDePasajero && criterio == 1)  ||
                    (lista[i].tipoDePasajero != lista[j].tipoDePasajero && lista[i].tipoDePasajero < lista[j].tipoDePasajero && criterio == 0))
                    {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                    }

                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int sortPassengersByCode(ePasajero* lista, int tam, int criterio)
{
        int todoOk = 0;
    ePasajero aux;

    if(lista && tam>0 && criterio >=0 && criterio <=1)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(!(lista[i].isEmpty) && !(lista[j].isEmpty) && lista[i].estadoDelVuelo && lista[j].estadoDelVuelo)
                {
                    if((stricmp(lista[i].codigoDeVuelo, lista[j].codigoDeVuelo) > 0 && criterio == 1) ||
                        (stricmp(lista[i].codigoDeVuelo, lista[j].codigoDeVuelo) < 0 && criterio == 0))
                    {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                    }
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
