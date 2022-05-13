#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "pasajero.h"
#include "arrayPassenger.h"

int menu()
{
    int opcion;

    printf(" ______________________________________ \n");
    printf("|                                      |\n");
    printf("|       *** Menu Principal ***         |\n");
    printf("|______________________________________| \n");
    printf("| 1) Darle de alta al pasajero         |\n");
    printf("| 2) Modificar pasajero                |\n");
    printf("| 3) Darle de baja al pasajero         |\n");
    printf("| 4) Carga forzada de pasajeros        |\n");
    printf("| 5) Informar                          |\n");
    printf("| 6) Salir                             |\n");
    printf("|______________________________________|\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 6 || isalpha(opcion))
    {
        fflush(stdin);      //Limpio el buff de entrada para que en el caso de que arriba ingresen una letra no se rompa el prorgama
        printf("Se ingreso una opcion erronea, ingrese la opcion nuevamente: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int subMenuModificar()
{
    int opcion;
    printf(" ______________________________________ \n");
    printf("|      *** Modificar pasajero ***      |\n");
    printf("|______________________________________| \n");
    printf("| Que desea modificar?                 |\n");
    printf("|--------------------------------------| \n");
    printf("| 1) Nombre                            |\n");
    printf("| 2) Apellido                          |\n");
    printf("| 3) Precio                            |\n");
    printf("| 4) Codigo de vuelo                   |\n");
    printf("| 5) Clase del pasajero                |\n");
    printf("| 6) Estado del vuelo                  |\n");
    printf("| 7) Salir                             |\n");
    printf("|______________________________________|\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 7 || isalpha(opcion))
    {
        fflush(stdin);
        printf("Se ingreso una opcion erronea, ingrese la opcion nuevamente: ");
        scanf("%d", &opcion);
    }
    system("cls");

    return opcion;
}

int subMenuInformar(int* criterio)
{
    int opcion;
    printf(" _________________________________________________________________________________________________\n");
    printf("|                                            *** Informar ***                                     |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("| 1) Informar listado de pasajeros por tipo y apellido                                            |\n");
    printf("| 2) Total y promedio de los precios del pasaje y cantidad de pasajeros que superan el promedio   |\n");
    printf("| 3) Listado de pasajeros por codigo de vuelo y estado de vuelo \"Activo\"                          |\n");
    printf("| 4) Salir                                                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 4 || isalpha(opcion))
    {
        fflush(stdin);
        printf("Se ingreso una opcion erronea, ingrese la opcion nuevamente: ");
        scanf("%d", &opcion);
    }

    if(opcion == 1 || opcion == 3)
    {
        printf("Ingrese la manera en que lo quiera ordenar\n 0) Descendente (Z - A)\n 1) Ascendente (A - Z)\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", criterio);

        while(*(criterio) < 0 || *(criterio) > 1 || isalpha(*(criterio)))
        {
            fflush(stdin);
            printf("Se ingreso una opcion erronea, ingrese la opcion nuevamente: ");
            scanf("%d", criterio);
        }
    }

    return opcion;
}



int ingresoPasajero(ePasajero* vec, int* pId)
{
    int todoOk = 0;
    char auxCadena[100];
    float auxPrecio;
    int auxTipoDePasajero;
    int auxEstadoDelVuelo;
    ePasajero aux;

    //validaciones
    if(vec &&pId)
    {
        aux.id = *(pId);
        *pId = *pId + 1;

        printf("\nIngrese el nombre del pasajero (maximo 50 caracteres): ");
        fflush(stdin);
        gets(auxCadena);
        while(!(validarGets(51, auxCadena)))
        {
            printf("Reingrese el nombre del pasajero: ");
            gets(auxCadena);
        }
        strcpy(aux.nombre, auxCadena);

        printf("\nIngrese el apellido del pasajero (maximo 50 caracteres): ");
        fflush(stdin);
        gets(auxCadena);
        while(!(validarGets(51, auxCadena)))
        {
            printf("Reingrese el apellido del pasajero: ");
            gets(auxCadena);
        }
        strcpy(aux.apellido, auxCadena);

        printf("\nIngrese el precio del vuelo: $");
        scanf("%f", &auxPrecio);
        while(auxPrecio < 0 || auxPrecio > 999999)
        {
            fflush(stdin);
            printf("Reingrese un precio valido (menor a 1millon): $");
            scanf("%f", &auxPrecio);
        }
        aux.precio = auxPrecio;

        printf("\nIngrese el codigo del vuelo (alfanumerico de maximo 9 digitos): ");
        fflush(stdin);
        gets(auxCadena);

        while(!(validarGets(10, auxCadena)) || strlen(auxCadena) > 9)
        {
            printf("Reingrese el codigo de vuelo: ");
            gets(auxCadena);
        }
        strcpy(aux.codigoDeVuelo, auxCadena);

        printf("\nIngrese el tipo de pasajero \n\"1\" para Primera Clase, \"2\" para Clase Ejecutiva y \"3\" para Clase Economica: ");
        scanf("%d", &auxTipoDePasajero);
        while(auxTipoDePasajero < 1 || auxTipoDePasajero > 3 || isalpha(auxTipoDePasajero))
        {
            fflush(stdin);
            printf("Reingrese un tipo de pasajero valido: ");
            scanf("%d", &auxTipoDePasajero);
        }
        aux.tipoDePasajero = auxTipoDePasajero;

        printf("\nIngrese el estado del pasajero \n1) para \"Activo\", 2) \"Inactivo\": ");
        scanf("%d", &auxEstadoDelVuelo);
        while(auxEstadoDelVuelo < 1 || auxEstadoDelVuelo > 2 || isalpha(auxEstadoDelVuelo))
        {
            fflush(stdin);
            printf("Reingrese un estado del pasajero valido: ");
            scanf("%d", &auxEstadoDelVuelo);
        }
        aux.estadoDelVuelo = auxEstadoDelVuelo;

        todoOk = 1;
        *vec = aux;
    }
    else
    {
        printf("Ocurrio un error al ingresar pasajeros\n");
    }
    return todoOk;
}

int harcodearPasajeros(ePasajero* vec, int tam, int rep, int* id)
{
    int todoOk = 0;
    int i;
    int contEspacio;

    if(vec && tam > 0 && rep <= tam)
    {

        buscarPosicionesDisponibles(vec, tam, &contEspacio);
        if(rep<=contEspacio)
        {
            for(int in=0; in<rep; in++)
            {
                if(buscarPosicionLibre(vec, tam, &i))
                {
                    if(in==8 || !(in%9))
                    {
                        vec[i].id = *(id);
                        *id = *(id) + 1;
                        strcpy(vec[i].nombre, "Sofia");
                        strcpy(vec[i].apellido, "Heimenger");
                        vec[i].precio = 53740.14;
                        strcpy(vec[i].codigoDeVuelo, "hzG851Df0");
                        vec[i].tipoDePasajero = 3;
                        vec[i].estadoDelVuelo = 1;
                        vec[i].isEmpty = 0;
                        todoOk = 1;
                    }
                    else if(in==7 || !(in%8))
                    {
                        vec[i].id = *(id);
                        *id = *(id) + 1;
                        strcpy(vec[i].nombre, "Julieta");
                        strcpy(vec[i].apellido, "Rainaldi");
                        vec[i].precio = 173150.36;
                        strcpy(vec[i].codigoDeVuelo, "HBx741Df0");
                        vec[i].tipoDePasajero = 1;
                        vec[i].estadoDelVuelo = 2;
                        vec[i].isEmpty = 0;
                        todoOk = 1;
                    }
                    else if(in==6 || !(in%7))
                    {
                        vec[i].id = *(id);
                        *id = *(id) + 1;
                        strcpy(vec[i].nombre, "Santiago");
                        strcpy(vec[i].apellido, "Del Sur");
                        vec[i].precio = 148303.79;
                        strcpy(vec[i].codigoDeVuelo, "lOx850Df0");
                        vec[i].tipoDePasajero = 2;
                        vec[i].estadoDelVuelo = 1;
                        vec[i].isEmpty = 0;
                        todoOk = 1;
                    }
                    else if(in==5 || !(in%6))
                    {
                        vec[i].id = *(id);
                        *id = *(id) + 1;
                        strcpy(vec[i].nombre, "Guillermo");
                        strcpy(vec[i].apellido, "De los Andes");
                        vec[i].precio = 193800.82;
                        strcpy(vec[i].codigoDeVuelo, "zBx741Df0");
                        vec[i].tipoDePasajero = 1;
                        vec[i].estadoDelVuelo = 1;
                        vec[i].isEmpty = 0;
                        todoOk = 1;
                    }
                    else if(in==4 || !(in%5))
                    {
                        vec[i].id = *(id);
                        *id = *(id) + 1;
                        strcpy(vec[i].nombre, "Estanislao");
                        strcpy(vec[i].apellido, "Mendoza");
                        vec[i].precio = 55400.00;
                        strcpy(vec[i].codigoDeVuelo, "ABx741Df0");
                        vec[i].tipoDePasajero = 2;
                        vec[i].estadoDelVuelo = 1;
                        vec[i].isEmpty = 0;
                        todoOk = 1;
                    }
                    else if(in==3 || !(in%4))
                    {
                        vec[i].id = *(id);
                        *id = *(id) + 1;
                        strcpy(vec[i].nombre, "Jorge");
                        strcpy(vec[i].apellido, "Lopez");
                        vec[i].precio = 28090.00;
                        strcpy(vec[i].codigoDeVuelo, "ACx499Da3");
                        vec[i].tipoDePasajero = 3;
                        vec[i].estadoDelVuelo = 2;
                        vec[i].isEmpty = 0;
                        todoOk = 1;
                    }
                    else if(in==2 || !(in%3))
                    {
                        vec[i].id = *(id);
                        *id = *(id) + 1;
                        strcpy(vec[i].nombre, "Atilio");
                        strcpy(vec[i].apellido, "Perez");
                        vec[i].precio = 233000.00;
                        strcpy(vec[i].codigoDeVuelo, "zFx125Dd1");
                        vec[i].tipoDePasajero = 1;
                        vec[i].estadoDelVuelo = 2;
                        vec[i].isEmpty = 0;
                        todoOk = 1;
                    }
                    else if(in==0 || !(in%2))
                    {
                        vec[i].id = *(id);
                        *id = *(id) + 1;
                        strcpy(vec[i].nombre, "Carlos");
                        strcpy(vec[i].apellido, "Maradona");
                        vec[i].precio = 50000.00;
                        strcpy(vec[i].codigoDeVuelo, "AFx489Dd0");
                        vec[i].tipoDePasajero = 3;
                        vec[i].estadoDelVuelo = 1;
                        vec[i].isEmpty = 0;
                        todoOk = 1;
                    }
                    else if(in==1 || (in%2))
                    {
                        vec[i].id = *(id);
                        *id = *(id) + 1;
                        strcpy(vec[i].nombre, "Julian");
                        strcpy(vec[i].apellido, "Alvarez");
                        vec[i].precio = 26950.00;
                        strcpy(vec[i].codigoDeVuelo, "CBx652Id0");
                        vec[i].tipoDePasajero = 2;
                        vec[i].estadoDelVuelo = 1;
                        vec[i].isEmpty = 0;
                        todoOk = 1;
                    }
                }
            }
        }
    }
    return todoOk;
}


int buscarDescripcionTipoPasajero(eTipoDePasajero* tipoPasajero, int tam, int num, char* descTipPasaj)
{
    int todoOk = 0;

    if(tipoPasajero && tam>0 && num>0 && descTipPasaj)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipoPasajero[i].num == num)
            {
                strcpy(descTipPasaj, tipoPasajero[i].descripcion);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarDescripcionEstadoDeVuelo(eEstadoDeVuelo* estadoDeVuelo, int tam, int num, char* descTipPasaj)
{
    int todoOk = 0;

    if(estadoDeVuelo && tam>0 && num>0 && descTipPasaj)
    {
        for(int i=0; i<tam; i++)
        {
            if(estadoDeVuelo[i].num == num)
            {
                strcpy(descTipPasaj, estadoDeVuelo[i].descripcion);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarPasajeros(int tam, ePasajero* lista, eEstadoDeVuelo* estado, int tamEst, eTipoDePasajero* tipo, int tamTipo)
{
    int todoOk = 0;
    char descEstVuelo[10];
    char descTipoDePasajero[16];

    if(tam>0 && lista && estado && tamEst>0 && tipo && tamTipo>0)
    {
        printf(" _____________________________________________________________________________________________________________________________________________________________________\n");
        printf("|  Id  |                Nombre                              |               Apellido                             |   Precio  | Codigo    | Clase del vuelo |  Estado  |\n" );
        printf("|------|----------------------------------------------------|----------------------------------------------------|-----------|-----------|-----------------|----------|\n");
        for(int i=0; i<tam; i++)
        {
            if(!(lista[i].isEmpty))
            {
                buscarDescripcionEstadoDeVuelo(estado, tamEst, lista[i].estadoDelVuelo, descEstVuelo);
                buscarDescripcionTipoPasajero(tipo, tamTipo, lista[i].tipoDePasajero, descTipoDePasajero);
                printf("| %4d | %50s | %50s | %9.2f | %9s | %15s | %8s |\n",  lista[i].id, lista[i].nombre, lista[i].apellido, lista[i].precio, lista[i].codigoDeVuelo, descTipoDePasajero, descEstVuelo);
            }
        }
        printf("|______|____________________________________________________|____________________________________________________|___________|___________|_________________|__________|\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int listarUnPasajero(int i, ePasajero* lista, eEstadoDeVuelo* estado, int tamEst, eTipoDePasajero* tipo, int tamTipo)
{
    int todoOk = 0;
    char descEstVuelo[10];
    char descTipoDePasajero[16];

    if(i>=0 && lista && estado && tamEst>0 && tipo && tamTipo>0)
    {
        printf(" _____________________________________________________________________________________________________________________________________________________________________\n");
        printf("|  Id  |                Nombre                              |               Apellido                             |   Precio  | Codigo    | Clase del vuelo |  Estado  |\n" );
        printf("|------|----------------------------------------------------|----------------------------------------------------|-----------|-----------|-----------------|----------|\n");

        if(!(lista[i].isEmpty))
        {
            buscarDescripcionEstadoDeVuelo(estado, tamEst, lista[i].estadoDelVuelo, descEstVuelo);
            buscarDescripcionTipoPasajero(tipo, tamTipo, lista[i].tipoDePasajero, descTipoDePasajero);
            printf("| %4d | %50s | %50s | %9.2f | %9s | %15s | %8s |\n",  lista[i].id, lista[i].nombre, lista[i].apellido, lista[i].precio, lista[i].codigoDeVuelo, descTipoDePasajero, descEstVuelo);
        }
        printf("|______|____________________________________________________|____________________________________________________|___________|___________|_________________|__________|\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int buscarPosicionLibre(ePasajero* vec, int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec && pIndex && tam>0 )
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int buscarPosicionesDisponibles(ePasajero* vec, int tam, int* pCont)
{
    int todoOk = 0;
    int cont = 0;

    if(vec && pCont && tam>0 )
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty)
            {
                cont++;
            }
        }
        todoOk = 1;
        *pCont = cont;
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

int modificacionPasajero(ePasajero* vec, int indice, int modif)
{
    int todoOk = 0;
    char auxCadena[100] ;
    float auxPrecio;
    int auxTipoDePasajero;
    int auxEstadoDelVuelo;

    if(vec && indice >= 0 && modif >0)
    {
        switch(modif)
        {
        case 1:
            printf("Ingrese el nuevo nombre (maximo 50 caracteres): ");
            fflush(stdin);
            gets(auxCadena);
            while(!(validarGets(51, auxCadena)))
            {
                printf("Reingrese el nuevo nombre del pasajero: ");
                gets(auxCadena);
            }
            strcpy(vec[indice].nombre, auxCadena);
            break;
        case 2:
            printf("Ingrese el nuevo apellido (maximo 50 caracteres): ");
            fflush(stdin);
            gets(auxCadena);
            while(!(validarGets(51, auxCadena)))
            {
                printf("Reingrese el apellido del pasajero: ");
                gets(auxCadena);
            }
            strcpy(vec[indice].apellido, auxCadena);
            break;
        case 3:
            printf("\nIngrese el nuevo precio del vuelo: $");
            scanf("%f", &auxPrecio);
            while(auxPrecio < 0 || auxPrecio > 999999)
            {
                fflush(stdin);
                printf("Reingrese un precio valido (menor a 1millon): $");
                scanf("%f", &auxPrecio);
            }
            vec[indice].precio = auxPrecio;
            break;
        case 4:
            printf("\nIngrese el nuevo codigo del vuelo (alfanumerico de maximo 9 digitos): ");
            fflush(stdin);
            gets(auxCadena);
            while(!(validarGets(10, auxCadena)) || strlen(auxCadena) > 9)
            {
                printf("Reingrese el codigo de vuelo: ");
                gets(auxCadena);
            }
            strcpy(vec[indice].codigoDeVuelo, auxCadena);
            break;
        case 5:
            printf("\nIngrese el nuevo tipo de pasajero \n\"1\" para Primera Clase, \"2\" para Clase Ejecutiva y \"3\" para Clase Economica: ");
            scanf("%d", &auxTipoDePasajero);
            while(auxTipoDePasajero < 1 || auxTipoDePasajero > 3 || isalpha(auxTipoDePasajero))
            {
                fflush(stdin);
                printf("Reingrese un tipo de pasajero valido: ");
                scanf("%d", &auxTipoDePasajero);
            }
            vec[indice].tipoDePasajero = auxTipoDePasajero;
            break;
        case 6:
            printf("\nIngrese el estado del pasajero \n1) para \"Activo\", 2) \"Inactivo\": ");
            scanf("%d", &auxEstadoDelVuelo);
            while(auxEstadoDelVuelo < 1 || auxEstadoDelVuelo > 2 || isalpha(auxEstadoDelVuelo))
            {
                fflush(stdin);
                printf("Reingrese un estado del pasajero valido: ");
                scanf("%d", &auxEstadoDelVuelo);
            }
            vec[indice].estadoDelVuelo = auxEstadoDelVuelo;
            break;

        }
    }


    return todoOk;
}

int totalYPromedio(ePasajero* vec, int tam, float* suma, float* prom, int* contPasajeros)
{
    int todoOk = 0;
    float acumPrecios = 0;
    float promedioDePrecios;
    int contadorPasajeros = 0;
    int contadorMayorQueProm = 0;

    if(vec && tam>0 && suma && prom && contPasajeros)
    {
        for(int i=0; i<tam; i++)
        {
            if(!(vec[i].isEmpty))
            {
                acumPrecios+= vec[i].precio;
                contadorPasajeros++;
            }
        }
        if(contadorPasajeros != 0)
        {
            promedioDePrecios = acumPrecios / contadorPasajeros;
        }

        for(int i=0; i<tam; i++)
        {
            if(!(vec[i].isEmpty) && vec[i].precio > promedioDePrecios)
            {
                contadorMayorQueProm++;
            }
        }

        *suma = acumPrecios;
        *prom = promedioDePrecios;
        *contPasajeros = contadorMayorQueProm;
        todoOk = 1;
    }
    return todoOk;
}

int informarPasajero(ePasajero* vec, int tam, eEstadoDeVuelo* estado, int tamEst, eTipoDePasajero* tipo, int tamTipo, int opcion, int criterio)
{
    int todoOk = 0;
    float suma;
    float promedio;
    int contMayorQueProm = 0;

    if(vec && tam>0 && opcion>0 && criterio >=0 && criterio<=1)
    {
        switch(opcion)
        {
        case 1:
            printf("Ingreso a listar pasajeros por tipo y por apellido\n");
            sortPassengers(vec, tam, criterio);
            listarPasajeros(tam, vec, estado, tamEst, tipo, tamTipo);
            break;
        case 2:
            printf("Mostrar precio total, promedio de los pasajes y cantidad de pasajeros que superan el promedio\n");
            totalYPromedio(vec, tam, &suma, &promedio, &contMayorQueProm);
            if(contMayorQueProm == 1)
            {
                printf("\nEl precio total es: %10.2f\nEl promedio de los precios es: %10.2f\nEn este vuelo hay un solo pasajero que supera el promedio de precio\n\n", suma, promedio);
            }
            else
            {
                printf("\nEl precio total es: %10.2f\nEl promedio de los precios es: %10.2f\nEn este vuelo la cantidad de pasajeros que superan el promedio de precio son: %4d\n\n", suma, promedio, contMayorQueProm);
            }
            break;
        case 3:
            printf("Ingreso a listar los pasajeros por codigo de vuelo y estado de vuelo \"Activo\"\n");
            sortPassengersByCode(vec, tam, criterio);
            listarPasajerosActivos(tam, vec, estado, tamEst, tipo, tamTipo);
            break;

        }
    }
    return todoOk;
}

int listarPasajerosActivos(int tam, ePasajero* lista, eEstadoDeVuelo* estado, int tamEst, eTipoDePasajero* tipo, int tamTipo)
{
    int todoOk = 0;
    char descEstVuelo[10];
    char descTipoDePasajero[16];

    if(tam>0 && lista && estado && tamEst>0 && tipo && tamTipo>0)
    {
        printf(" _____________________________________________________________________________________________________________________________________________________________________\n");
        printf("|  Id  |                Nombre                              |               Apellido                             |   Precio  | Codigo    | Clase del vuelo |  Estado  |\n" );
        printf("|------|----------------------------------------------------|----------------------------------------------------|-----------|-----------|-----------------|----------|\n");
        for(int i=0; i<tam; i++)
        {
            if((lista[i].estadoDelVuelo == 1) && !(lista[i].isEmpty))
            {
                buscarDescripcionEstadoDeVuelo(estado, tamEst, lista[i].estadoDelVuelo, descEstVuelo);
                buscarDescripcionTipoPasajero(tipo, tamTipo, lista[i].tipoDePasajero, descTipoDePasajero);
                printf("| %4d | %50s | %50s | %9.2f | %9s | %15s | %8s |\n",  lista[i].id, lista[i].nombre, lista[i].apellido, lista[i].precio, lista[i].codigoDeVuelo, descTipoDePasajero, descEstVuelo);
            }
        }
        printf("|______|____________________________________________________|____________________________________________________|___________|___________|_________________|__________|\n\n");
        todoOk = 1;
    }
    return todoOk;
}

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
        auxSalida = toupper(auxSalida);
        while(!isalpha(auxSalida))
        {
            printf("Reingrese una letra, \"s\" para si: ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = toupper(auxSalida);
        }

        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}

int confirmaIngreso(char* eleccion, char* mensaje)
{
    int todoOk = 0;
    char auxSalida;

    if(eleccion)
    {
        system("cls");
        printf("\nEsta seguro que desea ingresar a \"%s\" ?\n", mensaje);
        printf("Ingrese una letra, \"s\" para si: ");
        fflush(stdin);
        scanf("%c", &auxSalida);
        auxSalida = toupper(auxSalida);
        while(!isalpha(auxSalida))
        {
            printf("Reingrese una letra, \"s\" para si: ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = toupper(auxSalida);
        }

        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}

int confirma(char* eleccion)
{
    int todoOk = 0;
    char auxSalida;

    if(eleccion)
    {
        printf("Ingrese una letra, \"s\" para si: ");
        fflush(stdin);
        scanf("%c", &auxSalida);
        auxSalida = toupper(auxSalida);
        while(!isalpha(auxSalida))
        {
            printf("Reingrese una letra, \"s\" para si: ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = toupper(auxSalida);
        }

        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}




