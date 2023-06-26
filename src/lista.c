#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Nodo.h"
#include "lista.h"

lista* lista_vacia(){
    lista* l;
    l=(lista*)malloc(sizeof(lista));
    l->len = 0;
    l->head = l->tail = NULL;
    return l;
}

bool es_vacia (lista* l){
    bool b;
    if(l->len==0){
        b = true;
    }else{
        b = false;
    }
    return b;
}

void agregar (lista* l, int p, int e){
    nodo *nuevo = NULL;
    nuevo = crear_nodo (e);
    if (l->len == 0){
        if(p != 0){
            printf("no se puede agregar en una posicion diferente de 0 cuando la lista esta vacia\n");
            return;
        }else{
            l->head = l->tail = nuevo;
            l->tail->sig = NULL;
            l->len++;
        }
    }else{
        if (p == 0){
            nuevo->sig = l->head;
            l->head = nuevo;
        }
        if (p == l->len){
            l->tail->sig = nuevo;
            l->tail = l->tail->sig;
            l->tail->sig = NULL;
        }
        if (p > 0 && p < l->len){
            nodo* temp = l->head;
            for (int pos = 0; pos = (p-1); pos++){
                temp = temp->sig;
            }
            nuevo->sig = temp->sig;
            temp->sig = nuevo;
        }
        l->len ++;
    }
    return;
}

void eliminar (lista* l, int p){
    if (l->len == 0 || p < 0 || p >= l->len){
        if (p < 0 || p >= l->len){
            if (l->len == 0){
                printf ("La lista esta vacia\n");
                return;
            }else{
                printf ("No existe la posicion en la lista\n");
                return;
            }
        }
        printf ("La lista esta vacia\n");
        return;
    }else{
        nodo* temp = NULL;
        if (p == 0){
            temp = l->head;
            l->head = l->head->sig;
            temp->sig = NULL;
            free(temp);
            temp = NULL;
        }
        if (p > 0 && p < l->len){
            nodo *temp1 = NULL;
            temp = l->head;
            for (int i = 0; i < (p-1); i++){
                temp = temp->sig;
            }
            temp1 = temp->sig;
            temp->sig = temp1->sig;
            temp1->sig = NULL;
            free (temp1);
            temp1 = NULL;
        }
        l->len--;
        return;
    }
}

int buscar (lista* l, int e){
    if (l->len == 0){
        return -1;
    }else{
        nodo* temp = l->head;
        for (int pos = 0; pos < l->len; pos++){
            if (e == temp->dato){
                return pos;
            }
            temp = temp->sig;
        }
    }
    printf ("El elemento no exite en la lista\n");
}

int localizar (lista* l, int p){
    if (l->len == 0 || p < 0 || p > l->len){
        if (p < 0 || p >= l->len){
            if (l->len == 0){
                printf ("La lista esta vacia\n");
            }else{
                printf ("No existe la posicion en la lista\n");
            }
        }
        return -1;
    }else{
        nodo* temp = l->head;
        for (int pos = 0; pos < p; pos++){
            temp = temp->sig;
        }
        return temp->dato;
    }
}

void vaciar (lista *l){
    int tp = l->len;
    if (es_vacia(l) == 1){
        printf ("La lista ya estaba vacia\n");
    }else{
        while (es_vacia (l) != 1){
            eliminar (l, 0);
        }
        printf ("La lista fue vaciada\n");
    }
    return;
}

void imprimir(lista* l){
    if(es_vacia(l) == 0){
        nodo* temp=l->head;
        printf("[  ");
        for(int i = 0; i<l->len; i++){
            printf("%i  ",temp->dato);
            temp = temp->sig;
        }
        printf("]\n");
    }else{
        printf("La lista esta vacia\n");
        return;
    }
}