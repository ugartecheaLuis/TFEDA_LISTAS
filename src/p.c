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
    
    /*Agregamos a l1
    agregar(l1,0,14);
    agregar(l1,1,32);
    agregar(l1,2,3);
    agregar(l1,3,6);
    agregar(l1,4,19);
    */

    printf ("\nPRUEBAS PARA AGREGAR\n");
    agregar (l2, 2, 21); //agrega en una lista lista vacia en una posicion diferente de 0
    agregar (l2, 0, 17); //agrega a una lista vacía
    agregar (l2, 0, 2);
    agregar (l2, 2, 41);
    agregar (l2, 2, 3);
    imprimir (l2);

    return 0;
}

