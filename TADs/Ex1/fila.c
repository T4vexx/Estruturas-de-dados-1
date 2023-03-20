#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct fila {
    int key;
    Tfila *prox;
}Tfila;

void insere(Tfila *fila,int n) {
    Tfila *aux,*antes;
    aux = malloc(sizeof(Tfila));
    aux->key = n;
    aux->prox = NULL;

    if(!fila) {
        fila->prox = aux;
    }

    antes=fila;
    while(antes->prox != NULL) {
        antes = antes->prox; 
    }

    if(antes->prox == NULL) {
        antes->prox = aux;
    }
}

void returnFila(Tfila *fila) {
    Tfila *aux;
    aux=fila;

    while(aux != NULL) {
        printf("[%d]", aux->key);
        aux = aux->prox;
    }

    return;
}