#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "miPasajero.h"

/****************************************************
    Menu:a
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main(void)
{
    setbuf(stdout, NULL);
    int nextId = 1;
    int saveStatus = 0; //Bandera de guardado
    int change = 0; //Bandera de cambios
    int menuLevel = 0; // Bandera menu
    cargarId(&nextId);
    char path[50];
    char confSalida = 'n';
    char conf;
    LinkedList* listaPasajeros = ll_newLinkedList();
    if(listaPasajeros == NULL)
    {
        printf("Ocurrio un error al crear el linked list\n");
        return 1;
    }

    do
    {
        system("cls");
        switch(option())
        {
        case 1:
            printf("Ha ingresado a la opcion cargar los datos del pasajero desde un archivo en modo texto\n\n");

            strcpy(path, "data.csv");
            confirma("La ruta por defecto es data.csv, desea cambiarla? ", &conf);

            if(conf == 's')
            {
                pedirPath(path);
            }

            if(path != NULL)
            {
                if(controller_loadFromText(path, listaPasajeros))
                {
                    cargarId(&nextId);
                    printf("Pasajeros cargados correctamente\n");
                    menuLevel = 1;
                }
                else
                {
                    printf("\nNo se pudo cargar el archivo");
                }
            }
            else
            {
                printf("Se ingres%c una ruta no valida\n", 162);
            }

            break;
        case 2:
            printf("Ha ingresado a la opcion cargar los datos del pasajero desde un archivo en modo binario\n\n");

            strcpy(path, "data.bin");
            confirma("La ruta por defecto es data.bin, desea cambiarla? ", &conf);

            if(conf == 's')
            {
                pedirPath(path);
            }

            if(path != NULL)
            {
                if(controller_loadFromBinary(path, listaPasajeros))
                {
                    cargarId(&nextId);
                    printf("Pasajeros cargados correctamente\n");
                    menuLevel = 1;
                }
                else
                {
                    printf("\nNo se pudo cargar el archivo");
                }
            }
            else
            {
                printf("Se ingres%c una ruta no valida\n", 162);
            }
            break;
        case 3:
            printf("Ha ingresado a la opcion Alta del pasajero\n\n");
            if(controller_addPassenger(listaPasajeros, &nextId))
            {
                printf("\n Pasajero agregado correctamente!\n\n");
                menuLevel = 1;
                change = 1;
            }
            else
            {
                printf("\n No se pudo agregar el pasajero!\n\n");
            }
            break;
        case 4:
            if(menuLevel == 1)
            {
                printf("Ha ingresado a la opci%cn Modificar pasajero\n\n", 162);
                if(controller_editPassenger(listaPasajeros, &nextId))
                {
                    printf("\n Edici%cn realizada correctamente!\n\n", 162);
                    change = 1;
                }
            }
            else
            {
                printf("Debe ingresar algun pasajero antes de poder modificarlo");
            }
            break;
        case 5:
            if(menuLevel == 1)
            {
                printf("Ha ingresado a la opci%cn Baja del pasajero\n\n", 162);
                if(controller_removePassenger(listaPasajeros, &nextId))
                {
                    printf("\n Pasajero eliminado correctamente!\n\n");
                    change = 1;
                }
            }
            else
            {
                printf("Debe ingresar algun pasajero antes de poder darle de baja");
            }
            break;
        case 6:
            if(menuLevel == 1)
            {
                printf("Ha ingresado a la opci%cn Listar pasajero\n\n", 162);
                controller_ListPassenger(listaPasajeros);
            }
            else
            {
                printf("Debe ingresar algun pasajero antes de poder listarlo");
            }
            break;
        case 7:
            if(menuLevel == 1)
            {
                printf("Ha ingresado a la opci%cn Ordenar pasajero\n\n", 162);
                if(!controller_sortPassenger(listaPasajeros))
                {
                    printf("\n No se pudo ordenar correctamente!\n\n");
                }
                else
                {
                    change = 1;
                }
            }
            else
            {
                printf("Debe ingresar algun pasajero antes de poder ordenarlo");
            }
            break;
        case 8:
            printf("Ha ingresado a la opci%cn guardar los datos del pasajero en el archivo, modo texto\n\n", 162);
            strcpy(path, "datazo.csv");
            confirma("La ruta por defecto es datazo.csv, desea cambiarla? ", &conf);

            if(conf == 's')
            {
                pedirPath(path);
            }

            if(path != NULL)
            {
                if(controller_saveAsText(path, listaPasajeros))
                {
                    mayorId(listaPasajeros, &nextId);
                    guardarId(nextId);
                    printf("\nPasajeros guardados correctamente\n");
                    saveStatus = 1;
                }
                else
                {
                    printf("\nNo se pudo guardar los pasajeros");
                }
            }
            else
            {
                printf("Se ingres%c una ruta no valida\n", 162);
            }


            break;
        case 9:
            printf("Ha ingresado a la opci%cn guardar los datos del pasajero en el archivo, modo binario\n\n", 162);
            strcpy(path, "datazo.bin");
            confirma("La ruta por defecto es datazo.bin, desea cambiarla? ", &conf);

            if(conf == 's')
            {
                pedirPath(path);
            }

            if(path != NULL)
            {
                if(controller_saveAsBinary(path, listaPasajeros))
                {
                    mayorId(listaPasajeros, &nextId);
                    guardarId(nextId);
                    printf("\nPasajeros guardados correctamente\n");
                    saveStatus = 1;
                }
                else
                {
                    printf("\nNo se pudo guardar los pasajeros");
                }
            }
            else
            {
                printf("Se ingres%c una ruta no valida\n", 162);
            }

            break;
        case 10:
            if(saveStatus == 0 && change == 1)
            {
                printf("Atenci%cn!! No se guardaron los cambios\n ", 162);
                confirma("Desea salir de todas formas? ", &conf);

                if(conf == 'n')
                {
                    break;
                }
            }
            controller_exit(listaPasajeros, &confSalida);

            break;
        }
        printf("\n\n");
        system("pause");
    }
    while(confSalida != 's');

    return 0;
}


