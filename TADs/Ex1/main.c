#include <stdio.h>
#include "fila.c"

int main() {
    Tfila *fila=NULL;

    insere(fila,3);
    returnFila(fila);

    return 0;
}