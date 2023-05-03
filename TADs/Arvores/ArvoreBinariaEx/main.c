#include <stdlib.h>
#include <stdio.h>
#include "ab.c"

int main (){
	// 	   4
	//    /  \
	//   2    6
	//  / \  / \
	// 1  3  5  7
	//          /\
	//          8 9
  	
	  
	//prints 1 3 2 5 7 6 4
	no *t;
	Definir(t);
	
	t = criaRaiz(t, 4);
	
	//Filhos do 4
	insereEsquerda(t, 2);
	insereDireita(t, 6);
	
	//Filhos do 2
	insereEsquerda(t->esq, 1);
	insereDireita(t->esq, 3);
	
	//Filhos do 6
	insereEsquerda(t->dir, 5);
	insereDireita(t->dir, 7);

	//filhos de 7
	// insereEsquerda((t->dir)->esq, 8);
	// insereDireita((t->dir)->esq, 9);
	
	//Filho do 5
	//d.valor = 8;
	//insereDireita(t->dir->esq, d);
	
	printf("\n\n Pre Ordem \n");	
	preOrdem(t);
	
	printf("\n\n Em Ordem \n");	
	inOrdem(t);
	
	printf("\n\n P�s Ordem \n");	
	posOrdem(t);

	printf("\n\n P�s Ordem iterativo\n");	
	posOrdemIterativa(t);
	
	printf("É balanceada: %d",Balanceada(t));
	printf("É perfeitamente balanceada: %d",perfeitamenteBalanceada(t));

	printf("O maior é %d", maiorEmT(t));
	printf("total de nos folhas %d",totalNosFolhas(t));

	printf("A arvore é completamente binaria %d", isTreeComplete(t));

	return 0;
}
