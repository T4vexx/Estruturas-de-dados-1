#include <stdlib.h>     //Para usar malloc, free, exit ...
#include <stdio.h>      //Para usar printf ,... 
#include "ABB.h"

//Opera��es
//------------------------------------------------------
//Cria uma �rvore bin�ria vazia
void Definir (tree t) 
{
   t = NULL;
}

//Verifica se a AB � uma �rvore vazia
bool Vazia (tree t)
{ 
   if (t == NULL)
		return (true);
	return (false);
}
 
//Define n� raiz
tree Criar_raiz (tree t, tipo_dado elem)
{
   t = malloc(sizeof(no));
   if (!t)
   {
      printf( "Memoria insuficiente!\n" );
      exit(1);
   }
   
   t->esq = NULL;
   t->dir = NULL;
   t->info = elem;
   
   return(t);
}

//Retorna a altura (profundidade) da AB
int Altura (tree t)
{	
	if (Vazia(t)) {
		//printf("Vazio\n");
		return 0;
	}

   int altE = Altura (t->esq);
   int altD = Altura (t->dir);
   
   if (altE > altD) {
      return (altE + 1);
   }
   return(altD + 1); 
   //altura = max(altE,altD) + 1
}

//Fun��o recursiva para verificar se uma AB � balanceada
bool Balanceada (tree t)
{
	if (Vazia (t)) 
		return true;
	else if (t->esq == NULL && t->dir == NULL) // se n�o tem filhos
		return true;	
	else if (t->esq != NULL && t->dir != NULL) //se tem duas sub-�rvores
		return (Balanceada (t->esq) && Balanceada (t->dir));	
	else if (t->esq != NULL) //Se tem um unico filho na esquerda
		return (Altura (t->esq) == 1);	
	else return (Altura (t->dir) == 1);//Se tem um unico filho na direita
}

//Fun��o (recursida) para calcular o n�mero de n�s da AB
int Numero_nos (tree t)
{
   if (Vazia (t))
      return 0;
   
   int nE = Numero_nos (t->esq);
   int nD = Numero_nos (t->dir);
   
   return(nE + nD + 1);
}

//Fun��o (recursiva) para verificar se 
//uma AB � perfeitamente balanceada
bool Perf_balanceada (tree t)
{
   if (Vazia (t)) 
   	  return true;
   else if (t->esq == NULL && t->dir == NULL)  //t n�o tem filhos
      return true;
   else if(t->esq != NULL && t->dir != NULL)  //t tem ambas sub�rvores n�o-nulas
 	  return (Perf_balanceada(t->esq) && Perf_balanceada(t->dir)); //recurs�o
   else if(t->esq != NULL)                 //t tem um �nico filho � na  esquerda 
      return (Numero_nos(t->esq) == 1);
   else                                      //t tem um �nico filho � na direita
      return (Numero_nos(t->dir) == 1);
}

//Fun��o p/ adicionar um filho � direita de um n�, cujo ponteiro � dado (pai). 
//Se o n� n�o possui filho � direita, ent�o cria esse filho com conte�do "elem"
bool Insere_dir (tree pai, tipo_dado elem)
{
   	if (Vazia (pai)){
		return false;
	}
	
   if (pai->dir != NULL)
   {
      printf("Ja tem filho a direita\n");
      return false;
   }

 	pai->dir = malloc(sizeof(no));
	pai->dir->info = elem;
	pai->dir->dir = NULL;
	pai->dir->esq = NULL;

   //Alternativa #2
   //Criar_raiz(pai->dir, elem);
    
   return true;
}

//Fun��o p/ adicionar um filho � esquerda de um n�, cujo ponteiro � dado (pai). 
//Se o n� n�o possui filho � esquerda, ent�o cria esse filho com conte�do "elem"
bool Insere_esq (tree pai, tipo_dado elem)
{
	if (Vazia (pai)) {
		return false;
	}
   
   if (pai->esq != NULL)
   {
      printf("Ja tem filho a esquerda\n");
      return false;
   }

   pai->esq = malloc(sizeof(no));
   pai->esq->info = elem;
   pai->esq->dir = NULL;
   pai->esq->esq = NULL;
   
   //Alternativa #2
   //Criar_raiz(pai->esq, elem);
   
   return true;
}

//Fun��o "Visita" na forma de impress�o de dado
void Visita (tree t)
{
   printf("Valor: %d\n", t->info.valor);
}

//Percorre a �rvore em pr�-ordem
void Pre_ordem (tree t)
{
   if(t != NULL)
   {
      Visita(t);
      Pre_ordem(t->esq);
      Pre_ordem(t->dir);
   }
}

//Percorre a �rvore no esquema in-ordem
void In_ordem(tree t)
{
   if(t != NULL) 
   {
      In_ordem(t->esq);
      Visita(t);
      In_ordem(t->dir);
   }
}

//Percorre a �rvore em p�s-ordem
void Pos_ordem(tree t)
{
   if(t != NULL)
   {
      Pos_ordem(t->esq);
	  Pos_ordem(t->dir);
      Visita(t);
   }
}

void Imprime_arvore(tree raiz, int nivel, char tipo_conexao) 
{
    int i;
	if (raiz != NULL) 
	{
        Imprime_arvore(raiz->dir, nivel + 1, '/');
        
		for (i = 1; i < nivel; i++) 
		    printf("   ");
        
		printf("%c-%d\n", tipo_conexao, raiz->info.valor);
        //printf("%c-%p\n", tipo_conexao, &raiz->info.valor);
		Imprime_arvore(raiz->esq, nivel + 1, '\\');
    }
}
//---------------------------------------------

//---------------------------------------------
//P/ ABB
//Fun��o (recursiva) de busca para ABB
tree Busca_r (tree raiz, tipo_dado elem)
{
   if (raiz == NULL)
      return NULL;

   if (elem.valor == raiz->info.valor)
      return raiz;

   if (elem.valor < raiz->info.valor)
      return Busca_r(raiz->esq, elem);
   else
      return Busca_r(raiz->dir, elem);
}

//Fun��o (n�o-recursiva) de busca para ABB
tree Busca_nr (tree raiz, tipo_dado elem)
{
   tree p = raiz;
   
   while (p != NULL)
   {
      if (p->info.valor == elem.valor) 
         return p;
      else if (elem.valor > p->info.valor) 
         p = p->dir;
      else 
         p = p->esq;
   }
   
   return p;
}

//Fun��o (recursiva) para inserir um elemento com um 
//valor x em uma ABB, caso ele ainda n�o esteja l�. 
//Retorna o ponteiro para o n� que cont�m o elem. c/ valor x 
tree Busca_insere (tree raiz, tipo_dado elem)
{
   //Inserir elem. a partir de um n� desalocado
   if (raiz == NULL)
   {
      raiz = malloc(sizeof(no));
      raiz->info = elem;
      raiz->esq = NULL;
      raiz->dir = NULL;

      return raiz;
   }

   if (elem.valor < raiz->info.valor)
      raiz->esq = Busca_insere(raiz->esq, elem);

   if (elem.valor > raiz->info.valor)
      raiz->dir = Busca_insere(raiz->dir, elem);
 
   return raiz;
}

//Fun��o de remo��o dado o ponteiro do n� p (a ser removido)
void Remove_no (tree *p)
{
   tree q;
   
   //Caso tenha filho �nico � direita ou � n� folha
   if ((*p)->esq == NULL)
   {
      //Substitui pelo filho � direita
      q = *p; 
	  *p = (*p)->dir; 
	  free(q);	  
   } 
   else if ((*p)->dir == NULL) //Caso tenha filho �nico � esquerda
   {
      //Substitui pelo filho � esquerda
      q = *p; 
	  *p = (*p)->esq; 
	  free(q);
   } 
   else //Caso tenha dois filhos: aplica algum crit�rio de ajuste
      Substitui_menor_a_direita(p, &(*p)->dir);
      //Alternativamente: Substituir_maior_a_esquerda(p, p->esq)
}

//Encontra o sucessor de p, isto �, o descendente mais 
//� esquerda da sub-arvore � direita de p.
void Substitui_menor_a_direita(tree *p, tree *suc)
{
   tree q;
   
   if ((*suc)->esq == NULL)
   {
      (*p)->info = (*suc)->info;
      
	  //Remover sucessor
      q = *suc;
      *suc = (*suc)->dir;
      free(q);
      
      //Atualizar o ponteiro p na �rvore (nao necessario p essa proposta)
      //*p = *suc;
   } 
   else
      Substitui_menor_a_direita(p, &(*suc)->esq);
}

//Fun��o (recursiva) para buscar e remover um elemento com um
//valor x. Retorna true se removeu o elemento; false, se o 
//elemento de valor x n�o estava na �rvore
bool Busca_remove(tree *p_raiz, tipo_dado elem)
{
   
   tree raiz = *p_raiz;
   
   //�rvore vazia; x n�o est� na �rvore
   if (raiz == NULL)
      return false;
   
   //Encontrou exatamente x: eliminar
   if (raiz->info.valor == elem.valor) 
   { 
      Remove_no(p_raiz);
      //Caso altere a raiz no procedimento, altera aqui
      return true;
   }
   
   if (elem.valor < raiz->info.valor)
   {
	  //Buscar e remover na sub-�rvore esquerda
      return Busca_remove(&(raiz->esq), elem);
   }
   else
   {
	  //Buscar e remover na sub-�rvore direita
      return Busca_remove((&raiz->dir), elem);
   }
}

no *rotacaoEsquerda(no *p) {
   no *aux;
   int aux2;
   if(!(p->dir != NULL && (p->dir)->dir != NULL)) {
      printf("Rotação a esquerda impossivel");
      return NULL;
   } 

   aux2 = p->info.valor;
   p->info.valor = (p->dir)->info.valor;
   (p->dir)->info.valor = aux2;
   aux = p->dir;
   p->dir = (p->dir)->dir;
   p->esq = aux;
   aux->dir = NULL;
   if((p->esq)->esq != NULL) {
      aux = (p->esq)->esq;
      (p->esq)->esq = NULL;
      (p->esq)->dir = aux;
   }
   
   return p;
}
