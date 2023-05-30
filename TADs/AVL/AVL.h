//Otavio Augusto Teixeira - Arvore AVL
#include <stdbool.h> //Para usar true or false

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
//------------------------------- Funções auxiliares -------------------------------
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
void rotacionar(no **t);

//------------------------------- Inserção -------------------------------
//Função que primeiro insere o valor e depois checa se esta balanceado, caso nao esteja promove as rotações
void inserirEBalancear(no **t,int info);

//Função que busca e insere o elemento
void inserir(no **t,int info);

//------------------------------- Remoção -------------------------------
//Função para remover um no pelo info e balancear a arvore após isso
bool removerEBalancear(no **raiz, int info);

//Função que remove um nó
bool remover(no **raiz, int info);

//Função que substitui o no com 2 filhos pelo menor a direita
void substituiPeloMenorADireita(no **p, no **suc);

//Função que remove um no em especifico
void removeNo(no **raiz);

//------------------------------- Prints -------------------------------
//Função que printa a arvore em pre-ordem
void inOrdem(no *t);