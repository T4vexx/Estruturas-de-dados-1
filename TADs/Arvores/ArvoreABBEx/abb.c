#include <stdio.h>
#include "abb.h"

void Definir(no *t) {
    t = NULL;
}

no *criaRaiz(no *t, tipo_dado elem) {
    t = malloc(sizeof(no));
    if(!t) {
       printf("Nao foi possivel criar o no raiz"); 
    }
    t->chave = elem;
    t->dir = NULL;
    t->esq = NULL;

    return t;
}

void Imprime_arvore(no *raiz, int nivel, char tipo_conexao) 
{
    int i;
	if (raiz != NULL) 
	{
        Imprime_arvore(raiz->dir, nivel + 1, '/');
        
		for (i = 1; i < nivel; i++) 
		    printf("   ");
        
		printf("%c-%d\n", tipo_conexao, raiz->chave);
        //printf("%c-%p\n", tipo_conexao, &raiz->info.valor);
		Imprime_arvore(raiz->esq, nivel + 1, '\\');
    }
}

int numeroDeNos(no *t) {
    if(Vazia(t)) {
        return 0;
    }

    int esq = numeroDeNos(t->esq);
    int dir = numeroDeNos(t->dir);

    return (esq + dir + 1);
}

int Altura(no *t) {
    if(Vazia(t)) {
        return 0;
    }

    int esq = Altura(t->esq); 
    int dir = Altura(t->dir);

    if(esq > dir) {
        return esq + 1;
    } else {
        return dir + 1;
    }

}

bool Vazia (no *t) {
    if(t == NULL) {
        return true;
    } else {
        return false;
    }
}

bool Balanceada(no *t) {
    // if(Vazia(t)) {
    //     return true;
    // } else {
    //     int esq = Altura(t->esq);
    //     int dir = Altura(t->dir);
    //     int difAltura = esq - dir;
    //     if(difAltura > 1 || difAltura < -1) {
    //         return false;
    //     } else {
    //         return Balanceada(t->esq) && Balanceada(t->dir);
    //     }
    // }
    if(Vazia(t)) {
        return true;
    } else if(Vazia(t->esq) && Vazia(t->dir)) {
        return true;
    } else if((!Vazia(t->esq)) && (!Vazia(t->dir))) {
        return Balanceada(t->dir) && Balanceada(t->esq);
    } else if(!Vazia(t->esq)) {
        return Altura(t->esq) == 1;
    } else {
        return Altura(t->dir) == 1;
    }
}

bool perfeitamenteBalanceada(no *t) {
    if(Vazia(t)) {
        return true;
    } else if(Vazia(t->esq) && Vazia(t->dir)) {
        return true;
    } else if((!Vazia(t->esq)) && (!Vazia(t->dir))) {
        return perfeitamenteBalanceada(t->esq) && perfeitamenteBalanceada(t->dir);
    } else if(Vazia(t->esq)) {
        return numeroDeNos(t->esq) == 1;
    } else {
        return numeroDeNos(t->dir) == 1;
    }
}

bool insereDireita(no *t, tipo_dado elem) {
    no *aux;
    if(Vazia(t)) {
        return false;
    }

    if(t->dir != NULL) {
        printf("Ja possui filho a direita");
    }
    aux = criaRaiz(aux, elem);
    t->dir = aux;
    if(!t->dir){
		printf("Nao foi possivel criar o no.\n");
		return;
	}
    return true;
}

bool insereDireita(no *t, tipo_dado elem) {
    no *aux;
    if(Vazia(t)) {
        return false;
    }

    if(t->esq != NULL) {
        printf("Ja possui filho a esquerda");
    }
    aux = criaRaiz(aux, elem);
    t->esq = aux;
    if(!t->esq){
		printf("Nao foi possivel criar o no.\n");
		return;
	}
    return true;
}

void Visita (no *t){
	printf("Valor: %d\n", t->chave);
}

void preOrdem (no *t){
	if(t != NULL){
		Visita (t);
		preOrdem (t->esq);
		preOrdem (t->dir);
	}	
}

void inOrdem (no *t){
	if(t != NULL){
		inOrdem (t->esq);
		Visita (t);
		inOrdem (t->dir);
	}	
}

void posOrdem (no *t){
	if(t != NULL){
		posOrdem (t->esq);
		posOrdem (t->dir);
		Visita (t);
	}

}

no *Busca_r(no *t, tipo_dado valor) {
    if(Vazia(t)) {
        return NULL;
    }

    if(t->chave == valor) {
        return t;
    }

    if(valor < t->chave) {
        return Busca_r(t->esq, valor);
    } else {
        return Busca_r(t->dir, valor);
    }
}

no *Busca_insere(no *t, tipo_dado elem) {
    no *aux;
    if(Vazia(t)) {
        aux = malloc(sizeof(no));
        aux->chave = elem;
        aux->esq = NULL;
        aux->dir = NULL;
        t = aux;
    }

    if(elem < t->chave) {
        t->esq = Busca_insere(t->esq, elem);
    }
    if(elem > t->chave) {
        t->dir = Busca_insere(t->dir, elem);
    }

    return t;
}

void Remove_no(no **p) {
    no *aux;
    if((*p)->esq == NULL) {
        aux = *p;
        *p = (*p)->dir;
        free(aux);
    } else if((*p)->dir == NULL) {
        aux = *p;
        *p = (*p)->esq;
        free(aux);
    } else {
        Substitui_menor_a_direita(*p, &(*p)->dir);
    }
}

void Substitui_menor_a_direita(no **p, no **suc) {
    no *aux;
    if((*suc)->esq == NULL) {
        (*p)->chave = (*suc)->chave;
        aux = *suc;
        *suc = (*suc)->dir;
        free(aux);
    } else {
        Substitui_menor_a_direita(*p,&(*suc)->dir);
    }
}

bool Busca_remove(no **p_raiz, tipo_dado elem) {
    no *aux = *p_raiz;
    if(aux == NULL) {
        return false;
    }

    if(aux->chave == elem) {
        Remove_no(p_raiz);
        return true;
    }

    if(elem > aux->chave) {
        return Busca_remove(&(aux->esq),elem);
    } else {
        return Busca_remove(&(aux->dir),elem);
    }
}