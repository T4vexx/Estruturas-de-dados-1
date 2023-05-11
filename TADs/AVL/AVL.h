#include <stdbool.h>

//Estruturas e tipos
//-------------------------------------------
//Tipo registro
typedef struct no {
   int info;
   int balance;
   struct no *esq;
   struct no *dir;
} no;

//Declarações de funções/operações
//------------------------------------------------------
//Verifica se a AB é vazia
bool Vazia (no *t);

//Define nó raiz
no *criarRaiz (int info);

//Retorna a altura (profundidade) da AB
int Altura (no *t);

//Função que verifica os fatores de balanceamento de cada no
void balancear(no *t);

//Função que rotaciona um no a direita
no *rotacaoSimplesDireita(no *t);

//Função que rotaciona um no a esquerda
no *rotacaoSimplesEsquerda(no *t);

//Função que rotaciona duplamente um no a direita
no *rotacaoDuplaDireita(no *t);

//Função que rotaciona duplamente um no a esquerda
no *rotacaoDuplaEsquerda(no *t);

//Função que realiza as rotações
void rotacionar(no *t);

//Função que primeiro insere o valor e depois checa se esta balanceado, caso nao esteja promove as rotações
no *inserirEBalancear(no **t,int info);

//Função que busca e insere o elemento
no *inserir(no **t,int info);

//Função que printa a arvore em pre-ordem
void preOrdem(no *t);