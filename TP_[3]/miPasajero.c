#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "miPasajero.h"
#include "Passenger.h"
#include "Linkedlist.h"

int confirmaSalida(char* eleccion)
{
    int todoOk = 0;
    char auxSalida;

    if(eleccion)
    {
        system("cls");
        printf(" ______________________________________ \n");
        printf("|   Ha ingresado a la opcion SALIR     |\n");
        printf("|______________________________________|\n\n");
        printf("Esta seguro que desea salir?\n");
        printf("Ingrese una letra, \"s\" para si: ");
        fflush(stdin);
        scanf("%c", &auxSalida);
        auxSalida = tolower(auxSalida);
        while(auxSalida != 's' && auxSalida != 'n')
        {
            printf("Reingrese una letra, \"s\" (si) o \"n\" (no): ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = tolower(auxSalida);
        }

        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}

int option()
{
    int opcion;

    printf("\n _______________________________________________________________________________\n"
           "|                                    					        |\n"
           "|        		  *** MENU PRINCIPAL***       	    	                |\n"
           "|_______________________________________________________________________________|\n"
           "|                                    					        |\n"
           "|  1) Cargar los datos de los pasajeros desde un archivo .csv(modo texto)       |\n"
           "|  2) Cargar los datos de los pasajeros desde un archivo .bin(modo binario)     |\n"
           "|  3) Alta al pasajero 								|\n"
           "|  4) Modificar pasajero   				    		        |\n"
           "|  5) Baja al pasajero                          			        |\n"
           "|  6) Listar pasajeros                          				|\n"
           "|  7) Ordenar pasajeros                             			        |\n"
           "|  8) Guardar los datos de los pasajeros en archivo .csv(modo texto)	        |\n"
           "|  9) Guardar los datos de los pasajeros en archivo .bin(modo binario)          |\n"
           "| 10) Salir                             					|\n"
           "|_______________________________________________________________________________|\n\n"
          );


    printf("Ingrese opci%cn: ", 162);
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 10)
    {
        fflush(stdin);      //Limpio el buff de entrada para que en el caso de que arriba ingresen una letra no se rompa el prorgama
        printf("Se ingreso una opci%cn erronea, ingrese la opcion nuevamente: ", 162);
        scanf("%d", &opcion);
    }
    return opcion;
}

int pedirPath(char* pPath)
{
    int todoOk = 0;

    if(pPath != NULL)
    {
        printf("Ingrese la ruta del archivo: ");
        fflush(stdin);
        gets(pPath);
        while(!(validarGets(50, pPath)))
        {
            printf("Reingrese el nuevo nombre del archivo siendo menor a 50 caracteres: ");
            gets(pPath);
        }
        todoOk = 1;
    }

    return todoOk;
}


int validarGets(int tam, char auxCad[100])
{
    int validacion = 0;
    if(tam > 0 && auxCad)
    {
        if(strlen(auxCad) < tam)
        {
            validacion = 1;
        }
    }
    return validacion;
}

int mayorId(LinkedList* this, int* id)
{
    int todoOk = 0;
    Passenger* auxPass = NULL;
    int mayor;
    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            auxPass = (Passenger*) ll_get(this, i);
            if(i == 0 || auxPass->id > mayor)
            {
                mayor = auxPass->id;
            }
        }
        *id = mayor + 1;
        todoOk = 1;
    }
    return todoOk;
}

int mostrarPasajero(Passenger* auxPass)
{
    int todoOk = 0;
    if(auxPass != NULL)
    {
        printf("|%5d|%50s|%50s|%9.2f|%12s|%20s|%20s|\n", auxPass->id, auxPass->nombre, auxPass->apellido, auxPass->precio, auxPass->codigoVuelo, auxPass->estadoDelVuelo, auxPass->tipoPasajero);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarPasajeroSolo(Passenger* auxPass)
{
    int todoOk = 0;
    if(auxPass != NULL)
    {
        printf(" ____________________________________________________________________________________________________________________________________________________________________________ \n");
        printf("|  ID |                      NOMBRE                      |                      APELLIDO                    |  PRECIO |   CODIGO   |   ESTADO DE VUELO  |  TIPO DE PASAJERO  |\n");
        printf("|-----|--------------------------------------------------|--------------------------------------------------|---------|------------|--------------------|--------------------|\n");
        printf("|%5d|%50s|%50s|%9.2f|%12s|%20s|%20s|\n", auxPass->id, auxPass->nombre, auxPass->apellido, auxPass->precio, auxPass->codigoVuelo, auxPass->estadoDelVuelo, auxPass->tipoPasajero);
        printf("|____________________________________________________________________________________________________________________________________________________________________________|");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int confirma(char cadena[100], char* letra)
{
    int todoOk = 0;
    char auxLetra;

    if(letra != NULL)
    {
        printf("%s", cadena);
        printf("\n\n Ingrese S (si) o N (no): ");
        fflush(stdin);
        scanf("%c", &auxLetra);
        auxLetra = tolower(auxLetra);

        printf("\n");
        while((auxLetra != 's') && (auxLetra != 'n'))
        {
            printf("Se introdujo una letra erronea, reingrese por favor \"S\" (si) o \"N\" (no): ");
            fflush(stdin);
            scanf("%c", &auxLetra);
            auxLetra = tolower(auxLetra);
        }

        *letra = auxLetra;
        todoOk = 1;
    }

    return todoOk;
}

int guardarId(int mayorId)
{
    int todoOk = 0;

    if(mayorId > 1)
    {
        FILE* pF = fopen("ID_NO TOCAR", "wb");

        if(pF != NULL)
        {
            fwrite(&mayorId, sizeof(int), 1, pF);
            fclose(pF);
            todoOk = 1;
        }
    }
    return todoOk;
}

int cargarId(int* mayorId)
{
    int todoOk = 0;

    if(mayorId != NULL)
    {
        FILE* pF = fopen("ID_NO TOCAR", "rb");

        if(pF != NULL)
        {
            fread(mayorId, sizeof(int), 1, pF);
            fclose(pF);
            todoOk = 1;
        }
    }
    return todoOk;
}

int validarFgets(char* cadena, int tam)
{
    int todoOk = 0;

    if(cadena != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(cadena[i] == '\n')
            {
                cadena[i] = '\0';
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int pedirYValidarInt(int* resultado, char mensaje[50], char mensajeError[50], int minimo, int maximo)
{
    int todoOk = 0;
    char auxCad[50];
    int auxInt;


    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s", mensaje);
        fflush(stdin);
        gets(auxCad);
        while(!(validarGets(50, auxCad)))
        {
            printf("Error, reingrese un numero menor a 50 cifras");
            fflush(stdin);
            gets(auxCad);
        }
        auxInt = atoi(auxCad);

        while(auxInt < minimo || auxInt > maximo)
        {
            printf ("\n%s",mensajeError);
            fflush(stdin);
            gets(auxCad);
            while(!(validarGets(50, auxCad)))
            {
                printf("Error, reingrese un numero menor a 50 cifras");
                gets(auxCad);
            }
            auxInt = atoi(auxCad);
        }

        *resultado = auxInt;
        todoOk = 1;
    }
    return todoOk;
}

int pedirYValidarFloat(float* resultado, char mensaje[50], char mensajeError[50], float minimo, float maximo)
{
    int todoOk = 0;
    char auxCad[50];
    float auxFloat;


    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s", mensaje);
        gets(auxCad);
        while(!(validarGets(50, auxCad)))
        {
            printf("Error, reingrese un numero menor a 50 cifras");
            fflush(stdin);
            gets(auxCad);
        }
        auxFloat = atof(auxCad);

        while(auxFloat < minimo || auxFloat > maximo)
        {
            printf ("\n%s",mensajeError);
            fflush(stdin);
            gets(auxCad);
            while(!(validarGets(50, auxCad)))
            {
                printf("Error, reingrese un numero menor a 50 cifras");
                gets(auxCad);
            }
            auxFloat = atof(auxCad);
        }

        *resultado = auxFloat;
        todoOk = 1;
    }
    return todoOk;
}

int pedirYValidarChar(char* resultado, char mensaje[50], char mensajeError[50], char minimo, char maximo)
{
    int todoOk = 0;
    char buffer;

    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s", mensaje);
        fflush(stdin);
        scanf("%c", &buffer);

        if(buffer >= minimo && buffer <= maximo)
        {
            *resultado = buffer;
            todoOk = 1;
        }
        else
        {
            do
            {
                printf("\n%s", mensajeError);
                fflush(stdin);
                scanf("%c", &buffer);

                if(buffer >= minimo && buffer <= maximo)
                {
                    *resultado = buffer;
                    todoOk = 1;
                    break;
                }
            }
            while(1);
        }
    }
    return todoOk;
}

int pedirYValidarString(int maximo, char* cadena,  char mensaje[50], char mensajeError[50], int minimo)
{
    int todoOk = 0;
    char auxCad[maximo];

    if(cadena != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s", mensaje);
        fflush(stdin);
        gets(auxCad);
        while(!validarGets(maximo, auxCad))
        {
            printf("Error, reingrese un texto menor a %d car%ccteres: ", maximo-1, 160);
            gets(auxCad);
        }

        if(strlen(auxCad) >= minimo && strlen(auxCad) < maximo)
        {
            strcpy(cadena, auxCad);
            todoOk = 1;
        }
        else
        {
            do
            {
                printf("\n%s", mensajeError);
                gets(auxCad);
                while(!validarGets(maximo, auxCad))
                {
                    printf("Error, reingrese un texto menor a %d y menor a %d car%ccteres", maximo-1, minimo, 160);
                    fflush(stdin);
                    gets(auxCad);
                }
                if(strlen(auxCad) >= minimo && strlen(auxCad) < maximo)
                {
                    strcpy(cadena, auxCad);
                    todoOk = 1;
                    break;
                }
            }
            while(1);
        }

    }


    return todoOk;
}

int ll_buscarId(LinkedList* this, int id, int* index)
{
    int todoOk = 0;
    Passenger* auxPass;

    if(this != NULL && index != NULL && id > 0)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            auxPass = (Passenger*) ll_get(this, i);
            if(auxPass->id == id)
            {
                *index = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int subMenuModif(int* opcion)
{
    int todoOk = 0;

    if(opcion != NULL)
    {
        printf("Que desea modificar?\n1. Nombre\n2. Apellido\n3. Precio\n4. C%cdigo de vuelo\n5. Estado del vuelo\n6. Tipo de pasajero\n7. Salir\n", 162);
        pedirYValidarInt(opcion, "Ingrese un numero: ", "Error, ingrese un numero del 1 al 7: ", 1, 7);
        todoOk = 1;
    }

    return todoOk;
}

int subMenuOrdenar(int* opcion, int* orden)
{
    int todoOk = 0;

    if(opcion != NULL)
    {
        printf("Que desea ordenar?\n1. Id\n2. Nombre\n3. Apellido\n4. Precio\n5. C%cdigo de vuelo\n6. Estado del vuelo\n7. Tipo de pasajero\n8. Salir\n", 162);
        pedirYValidarInt(opcion, "Ingrese un numero: ", "Error, ingrese un numero del 1 al 8: ", 1, 8);
        if(*opcion != 8)
        {
            printf("Lo desea ordenar de manera ascendente (1) o descendente (0)?");
            pedirYValidarInt(orden, "Ingrese un numero: ", "Error, ingrese un numero del 0 al 1: ", 0, 1);
            todoOk = 1;
        }
    }

    return todoOk;
}

int sortPassengersById(void* type1, void* type2)
{
    int todoOk = 0;
    Passenger* auxPass1;
    Passenger* auxPass2;

    if(type1 != NULL && type2 != NULL)
    {
        auxPass1 = (Passenger*) type1;
        auxPass2 = (Passenger*) type2;

        if(auxPass1->id  > auxPass2->id)
        {
            todoOk = 1;
        }
        else if(auxPass1->id  < auxPass2->id)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int sortPassengersByName(void* type1, void* type2)
{

    int todoOk = 0;
    Passenger* auxPass1;
    Passenger* auxPass2;

    if(type1 != NULL && type2 != NULL)
    {
        auxPass1 = (Passenger*) type1;
        auxPass2 = (Passenger*) type2;

        todoOk = stricmp(auxPass1->nombre, auxPass2->nombre);
    }

    return todoOk;
}

int sortPassengersByLastName(void* type1, void* type2)
{

    int todoOk = 0;
    Passenger* auxPass1;
    Passenger* auxPass2;

    if(type1 != NULL && type2 != NULL)
    {
        auxPass1 = (Passenger*) type1;
        auxPass2 = (Passenger*) type2;

        todoOk = stricmp(auxPass1->apellido, auxPass2->apellido);
    }

    return todoOk;
}

int sortPassengersByPrice(void* type1, void* type2)
{
    int todoOk = 0;
    Passenger* auxPass1;
    Passenger* auxPass2;

    if(type1 != NULL && type2 != NULL)
    {
        auxPass1 = (Passenger*) type1;
        auxPass2 = (Passenger*) type2;

        if(auxPass1->precio  > auxPass2->precio)
        {
            todoOk = 1;
        }
        else if(auxPass1->precio  < auxPass2->precio)
        {
            todoOk = -1;
        }
    }

    return todoOk;
}

int sortPassengersByFlycode(void* type1, void* type2)
{

    int todoOk = 0;
    Passenger* auxPass1;
    Passenger* auxPass2;

    if(type1 != NULL && type2 != NULL)
    {
        auxPass1 = (Passenger*) type1;
        auxPass2 = (Passenger*) type2;

        todoOk = stricmp(auxPass1->codigoVuelo, auxPass2->codigoVuelo);
    }

    return todoOk;
}

int sortPassengersByStatusFlight(void* type1, void* type2)
{

    int todoOk = 0;
    Passenger* auxPass1;
    Passenger* auxPass2;

    if(type1 != NULL && type2 != NULL)
    {
        auxPass1 = (Passenger*) type1;
        auxPass2 = (Passenger*) type2;

        todoOk = stricmp(auxPass1->estadoDelVuelo, auxPass2->estadoDelVuelo);
    }

    return todoOk;
}

int sortPassengersByType(void* type1, void* type2)
{

    int todoOk = 0;
    Passenger* auxPass1;
    Passenger* auxPass2;

    if(type1 != NULL && type2 != NULL)
    {
        auxPass1 = (Passenger*) type1;
        auxPass2 = (Passenger*) type2;

        todoOk = stricmp(auxPass1->tipoPasajero, auxPass2->tipoPasajero);
    }

    return todoOk;
}
