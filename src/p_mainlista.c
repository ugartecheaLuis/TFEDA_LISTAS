#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"
#include <stdbool.h>

int main(){

    lista *l, *l1, *l2;
    l = lista_vacia ();
    l1 = lista_vacia (); //lista modificable
    l2 = lista_vacia (); //lista modificable
    bool b;
    int e, p;
    
    //Agregamos a l1
    agregar(l1,0,14);
    agregar(l1,1,32);
    agregar(l1,2,3);
    agregar(l1,3,6);
    agregar(l1,4,19);

    printf ("PRUEBAS PARA ES_VACIA\n");
    b = es_vacia (l);
    printf ("Para una lista vacia: %i\n", b);
    b = es_vacia (l1);
    printf ("Para una lista con elementos: %i\n", b);
    imprimir (l1);

    printf ("\nPRUEBAS PARA AGREGAR\n");
    agregar (l2, 2, 21); //agrega en una lista lista vacia en una posicion diferente de 0
    agregar (l2, 0, 17); //agrega a una lista vacía
    agregar (l2, 0, 9); //agrega por el principio
    agregar (l2, 2, 42); //agrega por el finak
    agregar (l2, 1, 15); //agrega por el medio
    agregar (l2, 2, 5); //agrega por el medio
    agregar (l2, 10, 18); //agrega en una posición inválida
    imprimir (l2); // resultado esperado: [9 15 5 17 42]

    printf ("\nPRUBEAS PARA ELIMINAR\n");
    eliminar (l, 0); //elimnar en una lista vacia
    eliminar (l2, 0); //eliminar por el principio
    eliminar (l2, 3); //eliminar por el final
    eliminar (l2, 1); //eliminar por el medio
    eliminar (l2, 5); //eliminar en una posicion no valida
    imprimir (l2); //resultado esperado: [15 17]

    //Agregamos en diferentes posiciones el mismo elemento para poder probar eliminar1
    agregar (l1, 2, 0);
    agregar (l1, 5, 0);
    agregar (l1, 7, 0);
    agregar (l1, 0, 0);
    agregar (l1, 8, 0);

    printf("\nPRUEBAS DE BUSCAR\n");
    printf ("Para una lista vacia:\n");
    p = buscar (l, 1);
    printf ("Para la lista 1: ");
    imprimir (l1);
    p = buscar (l1, 3);
    printf ("El elemento 3 se encuentra en la posicion %d\n", p);
    p = buscar (l1, 17);

    printf ("\nPRUEBAS PARA LOCALIZAR\n");
    printf ("Para una lista vacia:\n");
    e = localizar (l, 3);
    printf ("Para la lista 1: ");
    imprimir (l1);
    e = localizar (l1, 2);
    printf ("En la posicion 2 es el %d\n", e);
    e = localizar (l1, 7);

    printf ("\nPRUEBAS PARA VACIAR\n");
    printf ("Para una lista vacia\n");
    vaciar (l);
    printf ("Para la lista 1: ");
    imprimir (l1);
    vaciar (l1);
    imprimir (l1);
    
    return 0;
}