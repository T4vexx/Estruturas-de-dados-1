#include <stdio.h>
#include <stdlib.h>
#include "abb.c"

//Exemplo
int main (){
	no* t;
	Definir(t);
	
	//Cria n� ra�z = 4
	
	t = criaRaiz(t, 4);
	
	//Filhos do 4
	insereDireita(t, 2);
	insereDireita(t, 6);
	
	//Filhos do 2
	insereDireita(t->esq, 1);
	insereDireita(t->esq, 3);
	
	//Filhos do 6

	insereDireita(t->dir, 5);
	insereDireita(t->dir, 7);
	
	//Filho do 5 direita
	//d.valor = 8;
	//Insere_dir(t->dir->esq, d);
    //Filho do 8 esquerda
	//d.valor = 10;
	//Insere_esq(t->dir->esq->dir, d);
	
	printf("Altura: %d\n", Altura(t));
	printf("Nro nos: %d\n", numeroDeNos(t));

	//no* teste;
	//d.valor = 6;
	//teste = Busca_r (t, d);
	//printf("Valor encontrado: %d\n",teste->info.valor);
	//teste = Busca_nr (t, d);
	//printf("Valor encontrado: %d\n",teste->info.valor);
	
	//d.valor = 8;
	//no* teste = Busca_insere(t, d);
	//d.valor = 90;
	//teste = Busca_insere(t, d);
	Imprime_arvore(t,1,' ');
	//	
	//printf("\n\n");
	//d.valor = 7;
	//Busca_remove (&t,d);
	//Imprime_arvore(t,1,' ');
		
	//printf("\n\n Pre Ordem \n");	
	//Pre_ordem(t);
	
	//printf("\n\n Em Ordem \n");	
	//In_ordem(t);
	
	//printf("\n\n P�s Ordem \n");	
	//Pos_ordem(t);
	
	//if (Balanceada(t))
	//	printf("Eh balanceada");
	//else
	//	printf("Nao � balanceada");
			
	return 0;
}
