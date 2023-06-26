#ifndef __LISTA_H__
#define __LISTA_H__
#include "Nodo.h"
#include <stdbool.h>

struct _lista{
    nodo* head;
    nodo* tail;
    int len;
};

typedef struct _lista lista;

lista* lista_vacia();
bool es_vacia (lista*);
void agregar (lista*, int, int);
void eliminar (lista*, int);
int buscar (lista*, int);
int localizar (lista*, int);
void vaciar (lista*);
void imprimir (lista*);

#endif

