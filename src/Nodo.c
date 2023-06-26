#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"

nodo *crear_nodo(int dato){
    nodo *n;
    n=(nodo *)malloc(sizeof(nodo));
    n->dato = dato;
    n->sig=NULL;
    return n;
}

void borrar_nodo(nodo *n){
    if(n->sig == NULL){
        free(n);
        n=NULL;
    }
}

