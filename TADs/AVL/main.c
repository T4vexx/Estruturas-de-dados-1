//Otavio Augusto Teixeira - Arvore AVL
#include <stdio.h>
#include "AVL.c"

int main() {
    //Definição da ávore vazia
    no *raiz=NULL;

    //Exemplo de inserções na árvore avl
    inserirEBalancear(&raiz,15);
    inserirEBalancear(&raiz,10);
    inserirEBalancear(&raiz,20);
    inserirEBalancear(&raiz,7);
    inserirEBalancear(&raiz,6);
    inserirEBalancear(&raiz,5);
    inserirEBalancear(&raiz,8);
    inserirEBalancear(&raiz,30);
    inserirEBalancear(&raiz,2);
    inserirEBalancear(&raiz,16);
    inserirEBalancear(&raiz,9);
    inserirEBalancear(&raiz,4);
    inserirEBalancear(&raiz,3);
    inserirEBalancear(&raiz,35);
    inserirEBalancear(&raiz,33);
    inserirEBalancear(&raiz,25);


    //Exemplo da função de romoção na árvore
    removerEBalancear(&raiz,15);
    removerEBalancear(&raiz,7);
    removerEBalancear(&raiz,20);
    removerEBalancear(&raiz,30);
    removerEBalancear(&raiz,2);

    //Exemplo de print em ordem da ávore
    inOrdem(raiz);

    return 0;
}