//Otavio Augusto Teixeira - Arvore AVL
#include <stdlib.h>     //Para usar malloc, free, exit ...
#include <stdio.h>      //Para usar printf ,... 
#include "AVL.h"

//Operações
//------------------------------- Funções auxiliares -------------------------------
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
		//printf("Vazio\n");
		return 0;
	}

   int altE = Altura(t->esq);
   int altD = Altura (t->dir);
   
   if (altE > altD) {
      return (altE + 1);
   }
   return(altD + 1); 
}

//Define nó raiz
no *criarRaiz(int info) {
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
    t->esq = rotacaoSimplesEsquerda(t->esq);
    t = rotacaoSimplesDireita(t);
}

//Função que rotaciona duplamente um no a esquerda
no *rotacaoDuplaEsquerda(no *t) {
    t->dir = rotacaoSimplesDireita(t->dir);
    t = rotacaoSimplesEsquerda(t);
}

//Função que realiza as rotações
void rotacionar(no **t) {
    no *aux;
    if(*t != NULL) {
        rotacionar(&(*t)->esq);
        rotacionar(&(*t)->dir);
        balancear(*t);
        if((*t)->balance > 1) {
            if(((*t)->dir)->balance < 0) {
                aux = rotacaoDuplaEsquerda(*t);
                (*t) = aux;
                return;
            } else {
                aux = rotacaoSimplesEsquerda(*t);
                (*t) = aux;
                return;
            }
        } else if((*t)->balance < -1) {
            if(((*t)->esq)->balance > 0) {
                aux = rotacaoDuplaDireita(*t);
                (*t) = aux;
                return;
            } else {
                aux = rotacaoSimplesDireita(*t);
                (*t) = aux;
                return;
            }
        }
        return;
    }
}

//------------------------------- Inserção -------------------------------
//Função que primeiro insere o valor e depois checa se esta balanceado, caso nao esteja promove as rotações
void inserirEBalancear(no **t,int info) {
    inserir(t,info);
    balancear(*t);
    rotacionar(t);
}

//Função que busca e insere o elemento
void inserir(no **t,int info) {
    if((*t) == NULL) {
        (*t) = criarRaiz(info);
        return;
    }

    if (info < (*t)->info) {
        inserir(&(*t)->esq, info);
    }
    if (info > (*t)->info) {
        inserir(&(*t)->dir, info);
    }
}

//------------------------------- Remoção -------------------------------
//Função para remover um no pelo info e balancear a arvore após a remoção
bool removerEBalancear(no **raiz, int info) {
    bool resp;
    resp = remover(raiz,info);
    balancear(*raiz);
    rotacionar(raiz);
    return resp;
}

//Função que remove um nó
void removeNo(no **raiz) {
    no *aux;
    if((*raiz)->esq == NULL) {
        aux = *raiz;
        *raiz = (*raiz)->dir;
        free(aux);
    } else if((*raiz)->dir == NULL) {
        aux = *raiz;
        *raiz = (*raiz)->esq;
        free(aux);
    } else {
        substituiPeloMenorADireita(raiz,&(*raiz)->dir);
    }
}

//Função que substitui o no com 2 filhos pelo menor a direita
void substituiPeloMenorADireita(no **p, no **suc) {
    no *aux;
    if((*suc)->esq == NULL) {
        (*p)->info = (*suc)->info;
        aux = *suc;
        *suc = (*suc)->dir;
        free(aux);
    } else {
        substituiPeloMenorADireita(p,&(*suc)->esq);
    }
}

//Função que remove um no em especifico
bool remover(no **raiz, int info) {
    if((*raiz) == NULL) {
        return false;
    }
    if((*raiz)->info == info) {
        removeNo(raiz);
        return true;
    }
    if((*raiz)->info > info) {
        return remover(&((*raiz)->esq), info);
    } else {
        return remover(&((*raiz)->dir), info);  
    }
}

//------------------------------- Prints -------------------------------
//Função que printa a arvore em pre-ordem
void inOrdem(no *t) {
    if(t != NULL) {
      inOrdem(t->esq);
      printf("[%d]\n",t->info);
      inOrdem(t->dir);
    }
}