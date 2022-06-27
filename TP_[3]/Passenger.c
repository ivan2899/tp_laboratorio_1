#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Passenger.h"

Passenger* Passenger_new()
{
    Passenger* newPassenger = (Passenger*) calloc(1, sizeof(Passenger));
    return newPassenger;
}

Passenger* Passenger_newParametros(int id,char* nombreStr, char* apellidoStr, float precio, char* codigodeVueloStr, char* tipoPasajero, char* estadoVuelStr)
{
    Passenger* newPassengerParam = Passenger_new();

    if(newPassengerParam != NULL)
    {
        if(!(   Passenger_setId(newPassengerParam, id) &&
                Passenger_setNombre(newPassengerParam, nombreStr) &&
                Passenger_setApellido(newPassengerParam, apellidoStr) &&
                Passenger_setPrecio(newPassengerParam, precio) &&
                Passenger_setTipoPasajero(newPassengerParam, tipoPasajero) &&
                Passenger_setCodigoVuelo(newPassengerParam, codigodeVueloStr) &&
				Passenger_setEstadoVuelo(newPassengerParam, estadoVuelStr)))
        {
            Passenger_delete(newPassengerParam);
            newPassengerParam = NULL;
        }
    }
    return newPassengerParam;
}

void Passenger_delete(Passenger* this)
{
    free(this);
}

int Passenger_setId(Passenger* this,int id)
{
    int todoOk = 0;
    if(this != NULL && id >= 1)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) <= 50 && strlen(nombre) >= 2)
    {
        strcpy(this->nombre, nombre);
        strlwr(this->nombre);
        (this->nombre)[0] = toupper((this->nombre)[0]);

        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
    {
        int todoOk = 0;
        if(this != NULL && nombre != NULL )
        {
            strcpy(nombre, this->nombre);
            todoOk = 1;
        }
        return todoOk;
    }
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
    int todoOk = 0;
    if(this != NULL && apellido != NULL && strlen(apellido) <= 50 && strlen(apellido) >= 2)
    {
        strcpy(this->apellido, apellido);
        strlwr(this->apellido);
        (this->apellido)[0] = toupper((this->apellido[0]));
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
    int todoOk = 0;
    if(this != NULL && apellido != NULL )
    {
        strcpy(apellido, this->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
    int todoOk = 0;
    if(this != NULL && tipoPasajero != NULL && strlen(tipoPasajero) <= 20 && strlen(tipoPasajero) >= 1)
    {
        strcpy(this->tipoPasajero, tipoPasajero);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
    int todoOk = 0;
    if(this != NULL && tipoPasajero != NULL)
    {
        strcpy(tipoPasajero, this->tipoPasajero);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
    int todoOk = 0;
    if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) <= 10 && strlen(codigoVuelo) >= 1)
    {
        strcpy(this->codigoVuelo, codigoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
    int todoOk = 0;
    if(this != NULL && codigoVuelo != NULL)
    {
        strcpy(codigoVuelo, this->codigoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int todoOk = 0;
	    if(this != NULL && estadoVuelo != NULL && strlen(estadoVuelo) <= 20 && strlen(estadoVuelo) >= 1)
	    {
	        strcpy(this->estadoDelVuelo, estadoVuelo);
	        todoOk = 1;
	    }
	    return todoOk;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int todoOk = 0;
		    if(this != NULL && estadoVuelo != NULL)
		    {
		        strcpy(estadoVuelo, this->estadoDelVuelo);
		        todoOk = 1;
		    }
		    return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
    int todoOk = 0;
    if(this != NULL && precio > 0 && precio < 1000000)
    {
        this->precio = precio;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
    int todoOk = 0;
    if(this != NULL && precio != NULL )
    {
        *precio = this->precio;
        todoOk = 1;
    }
    return todoOk;
}

