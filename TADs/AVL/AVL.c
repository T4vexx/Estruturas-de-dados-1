#include <stdlib.h>     //Para usar malloc, free, exit ...
#include <stdio.h>      //Para usar printf ,... 
#include "AVL.h"

//Operações
//------------------------------------------------------
//Verifica se a AB é vazia
bool Vazia (no *t) {
    if(t == NULL) {
        return true;
    }
    return false;
}


//Retorna a altura (profundidade) da AB
int Altura (no *t)
{	
	if (Vazia(t)) {
		printf("Vazio\n");
		return 0;
	}

   int altE = Altura (t->esq);
   int altD = Altura (t->dir);
   
   if (altE > altD) {
      return (altE + 1);
   }
   return(altD + 1); 
}

//Define nó raiz
no *criarRaiz (int info) {
    no *t;
    t = malloc(sizeof(no));
    if(!t) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    t->esq = NULL;
    t->dir = NULL;
    t->info = info;
    return t;
}

//Função que verifica os fatores de balanceamento de cada no
void balancear(no *t) {
    int esq=0,dir=0;
    if(t != NULL) {
        esq = Altura(t->esq);
        dir = Altura(t->dir);
        t->balance = dir - esq;

        balancear(t->esq);
        balancear(t->dir);
    }
}

//Função que rotaciona um no a esquerda
no *rotacaoSimplesEsquerda(no *p) {
    no *aux,*aux2;
    aux = p;
    p=p->dir;
    aux2 = p->esq;
    p->esq = aux;
    aux->dir = aux2;

    return p;
}

//Função que rotaciona um no a direita
no *rotacaoSimplesDireita(no *p) {
    no *aux,*aux2;
    aux = p;
    p=p->esq;
    aux2 = p->dir;
    p->dir = aux;
    aux->esq = aux2;

    return p;
}

//Função que rotaciona duplamente um no a direita
no *rotacaoDuplaDireita(no *t) {
    t = rotacaoSimplesEsquerda(t);
    t = rotacaoSimplesDireita(t);
}

//Função que rotaciona duplamente um no a esquerda
no *rotacaoDuplaEsquerda(no *t) {
    t = rotacaoSimplesDireita(t);
    t = rotacaoSimplesEsquerda(t);
}

//Função que realiza as rotações
void rotacionar(no *t) {
    no *aux;

    if(t != NULL) {
        if(t->balance > 1) {
            if(t->dir->balance < 0) {
                aux = rotacaoDuplaEsquerda(t->esq);
                t->esq = aux;
            } else {
                aux = rotacaoSimplesEsquerda(t->esq);
                t->esq = aux;
            }
        } else if(t->balance < -1) {
            if(t->esq->balance > 0) {
                aux = rotacaoDuplaDireita(t->dir);
                t->dir = aux;
            } else {
                aux = rotacaoSimplesDireita(t->dir);
                t->dir = aux;
            }
        }
    }
}

//Função que primeiro insere o valor e depois checa se esta balanceado, caso nao esteja promove as rotações
no *inserirEBalancear(no **t,int info) {
    inserir(*t,info);
    balancear(t);
    rotacionar(t);
}

//Função que busca e insere o elemento
no *inserir(no **t,int info) {
    if((*t) == NULL) {
        (*t) = criarRaiz(info);
        return (*t);
    }

    if (info < (*t)->info) {
        (*t)->esq = inserir((*t)->esq, info);
        return NULL;
    }
    if (info > (*t)->info) {
        (*t)->dir = inserir((*t)->dir, info);
        return NULL;
    }
}

//Função que printa a arvore em pre-ordem
void preOrdem(no *t) {
    if(t != NULL) {
      printf("[%d]\n");
      preOrdem(t->esq);
      preOrdem(t->dir);
    }
}