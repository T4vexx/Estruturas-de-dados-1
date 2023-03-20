#include <stdio.h>
#include "fila.c"

int main() {
    Tfila *fila=NULL;
    int test;

    insere(&fila,3);
    insere(&fila,4);
    insere(&fila,5);
    returnFila(fila);

    test = remover(&fila);
    printf("\n -%d- \n",test);

    returnFila(fila);

    liberarFila(&fila);

    returnFila(fila);
    return 0;
}