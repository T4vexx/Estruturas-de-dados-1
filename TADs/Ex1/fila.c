#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct fila {
    int key;
    struct fila *prox;
}Tfila;

void insere(Tfila **fila,int n) {
    Tfila *aux,*antes;
    aux = (Tfila *)malloc(sizeof(Tfila));
    aux->key = n;
    aux->prox = NULL;

    if(!(*fila)) {
        (*fila) = aux;
        return;
    }

    antes=(*fila);
    while(antes->prox != NULL) {
        antes = antes->prox; 
    }

    if(antes->prox == NULL) {
        antes->prox = aux;
    }
}

int remover(Tfila **fila) {
    Tfila *aux;

    aux=*fila;
    *fila=(*fila)->prox;
    return aux->key;
}

void returnFila(Tfila *fila) {
    Tfila *aux=fila;

    if(!aux) {
        printf("\nVazio");
    }

    while(aux != NULL) {
        printf("[%d] ", aux->key);
        aux = aux->prox;
    } 

    return;
}

void liberarFila(Tfila **fila) {
    Tfila *aux;
    aux=*fila;
    while(aux != NULL) {
        aux=*fila;
        if(*fila) {
            (*fila) = (*fila)->prox;
        }
        *fila=NULL;
        free(aux);
    }

    return;
}