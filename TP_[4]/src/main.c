#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char* nombre[50];
} ePersona;


int main(void)
{
    LinkedList* lista = ll_newLinkedList();
    LinkedList* lista2 = ll_newLinkedList();
    LinkedList* lista3;
    LinkedList* lista4;
    ePersona* prueba = NULL;
    ePersona* prueba2 = NULL;
    ePersona* prueba3 = NULL;
    ePersona* prueba4 = NULL;
    void* punteroGet = NULL;
    void* punteroGet2 = NULL;
    void* punteroGet3 = NULL;

    printf("Creo el linked list, por lo que tiene que dar tamanio 0,\nTamanio ll_len: %d\n", ll_len(lista));

    ll_add(lista, prueba);
    ll_add(lista, prueba2);
    ll_add(lista, prueba3);
    ll_add(lista, prueba4);
    printf("Agrego cuatro elementos, por lo que el tamanio tiene que dar 4,\nTamanio ll_len: %d\n",  ll_len(lista));

    punteroGet = ll_get(lista, 2);
    punteroGet2 = ll_get(lista, 1);
    punteroGet3 = ll_get(lista, 3);

    ll_add(lista2, punteroGet);
    ll_add(lista2, punteroGet2);
    ll_add(lista2, punteroGet3);

    printf("Guardar la persona en la posicion 2, si se guardo bien da 0\n Devuelve: %d\n", ll_set(lista, 2, prueba2));
    printf("El indice de donde aparece la persona de prueba 1: %d\n", ll_indexOf(lista, punteroGet2));

    printf("La lista contiene la persona de prueba 1?\nDevuelve %d\n", ll_contains(lista, punteroGet));

    printf("Dentro de la lista1 estan los elementos de la lista 2?\n Devuelve %d\n",ll_containsAll(lista, lista2));


    //clono la lista 1 con el ll clone
    lista3 = ll_clone(lista);

    printf("Dentro de la lista1 estan los elementos de la lista 2?\nDevuelve %d\n",ll_containsAll(lista, lista2));
    lista4 = ll_subList(lista3, 1, 2);
    printf("Dentro de la lista4 estan los elementos de la lista 3?\n Devuelve %d\n",ll_containsAll(lista4, lista3));

    printf("El linkedlist esta vacio? %d\n", ll_isEmpty(lista));
    ll_clear(lista);
    printf("Is empty? %d\n", ll_isEmpty(lista));
    ll_deleteLinkedList(lista);

    printf("La lista 2 tiene %d elementos\n", ll_len(lista2));
    ll_remove(lista2, 1);
    printf("Se elimino un elemento de la lista 2, actualmente tiene %d elementos\n", ll_len(lista2));

    printf("El tamanio de la lista 2 es de %d\n", ll_len(lista2));
    ll_pop(lista2, 1);
    printf("El tamanio de la lista 2 es de %d\n", ll_len(lista2));

    ll_push(lista2, 1, punteroGet2);
    printf("El tamanio de la lista 2 es de %d\n", ll_len(lista2));


    	startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
    	startTesting(3);  // getNode - test_getNode
    	startTesting(4);  // addNode - test_addNode
    	startTesting(5);  // ll_add
    	startTesting(6);  // ll_get
    	startTesting(7);  // ll_set
    	startTesting(8);  // ll_remove
    	startTesting(9);  // ll_clear
    	startTesting(10); // ll_deleteLinkedList
    	startTesting(11); // ll_indexOf
    	startTesting(12); // ll_isEmpty
    	startTesting(13); // ll_push
    	startTesting(14); // ll_pop
    	startTesting(15); // ll_contains
    	startTesting(16); // ll_containsAll
    	startTesting(17); // ll_subList
    	startTesting(18); // ll_clone
    	startTesting(19); // ll_sort

    return 0;
}
