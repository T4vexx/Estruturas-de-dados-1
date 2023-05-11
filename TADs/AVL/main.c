#include <stdio.h>
#include "AVL.c"

int main() {
    no *raiz=NULL;

    //insere raiz
    raiz = inserirEBalancear(&raiz,15);

    inserirEBalancear(&raiz,10);
    inserirEBalancear(&raiz,20);

    //printa preOrdem
    preOrdem(raiz);

    return 0;
}