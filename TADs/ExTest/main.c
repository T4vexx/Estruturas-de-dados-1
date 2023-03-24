#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conjuntos.c"

int main() {
    Con *nuns1,*nuns2,*nuns3;
    ciraConjuntoVazio(&nuns1);
    ciraConjuntoVazio(&nuns2);
    ciraConjuntoVazio(&nuns3);

    insere(3,&nuns1);
    insere(6,&nuns1);
    insere(10,&nuns1);
    insere(11,&nuns1);
    insere(4,&nuns1);
    insere(25,&nuns1);
    insere(8,&nuns1);

    insere(3,&nuns2);
    insere(11,&nuns2);
    insere(10,&nuns2);
    insere(5,&nuns2);
    insere(14,&nuns2);
    insere(15,&nuns2);
    insere(4,&nuns2);
    insere(8,&nuns2);

    merge_sort(&nuns1);
    merge_sort(&nuns2);

    interseccao(nuns1,nuns2,&nuns3);
    merge_sort(&nuns3);
    printf("\n");
    returnFila(nuns3);
}   