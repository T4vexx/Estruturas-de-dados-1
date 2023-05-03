//Arquivo de implementa��o

#include <stdlib.h>
#include <stdio.h>
#include "AB.h"

//EDs e tipos
//-------------------------------------------
//Tipo n�
struct no {
	char info;
	struct no *esq;
	struct no *dir;
};
//-------------------------------------------

//Opera��es
//-------------------------------------------
No *criavazia () {
	return NULL;
}

No *cria (char c, No *esq, No *dir) {
	
	No *aux = malloc(sizeof(No));
	aux->info = c;
	aux->esq = esq;
	aux->dir = dir;
	
	return (aux);
}

int vazia (No *t) {
	return t == NULL;
}

void imprime (No *t) {
	
	if (!vazia(t)) {
		printf("%c ", t->info); //Imp. ra�z
		imprime (t->esq); //Imp. esq. (funcao recursiva)
		imprime (t->dir); //Imp. dir. (funcao recursiva)
	}
		
}
	
No *libera (No *t) {
	
	if (vazia(t)){
		libera (t->esq);
		libera (t->dir);
		free (t);
	}
	
	return NULL;
}

int pertence (No *t, char c){
	
	if (vazia(t))
		return 0; //�rvore vazia
	else
		return t->info == c || pertence (t->esq,c) || pertence (t->dir,c);
}
