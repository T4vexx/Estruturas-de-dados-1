#include <stdio.h>
#include <stdlib.h>
#include "ABB.c"

//Exemplo
int main (){
	// 	   4
	//    /  \
	//   2    6
	//  / \  / \
	// 1  3  5  7
	// 
	tree t;
	Definir(t);

	tipo_dado d;
	
	//Cria n� ra�z = 4
	d.valor = 4;
	t = Criar_raiz(t, d);
	
	//Filhos do 4
	// d.valor = 2;
	// Insere_esq(t, d);
	d.valor = 6;
	Insere_dir(t, d);
	
	//Filhos do 2
	// d.valor = 1;
	// Insere_esq(t->esq, d);
	// d.valor = 3;
	// Insere_dir(t->esq, d);
	
	//Filhos do 6
	d.valor = 5;
	Insere_esq(t->dir, d);
	d.valor = 7;
	Insere_dir(t->dir, d);
	
	//Filho do 5 direita
	//d.valor = 8;
	//Insere_dir(t->dir->esq, d);
    //Filho do 8 esquerda
	//d.valor = 10;
	//Insere_esq(t->dir->esq->dir, d);
	
	// printf("Altura: %d\n", Altura(t));
	// printf("Nro nos: %d\n", Numero_nos(t));

	//tree teste;
	//d.valor = 6;
	//teste = Busca_r (t, d);
	//printf("Valor encontrado: %d\n",teste->info.valor);
	//teste = Busca_nr (t, d);
	//printf("Valor encontrado: %d\n",teste->info.valor);
	
	//d.valor = 8;
	//tree teste = Busca_insere(t, d);
	//d.valor = 90;
	//teste = Busca_insere(t, d);
	//Imprime_arvore(t,1,' ');
	//	
	//printf("\n\n");
	//d.valor = 7;
	//Busca_remove (&t,d);
	//Imprime_arvore(t,1,' ');
		
	printf("\n\n Pre Ordem \n");	
	Pre_ordem(t);
	
	printf("\n\n Pre Ordem  2\n");	
	Pre_ordem(rotacaoEsquerda(t));
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
