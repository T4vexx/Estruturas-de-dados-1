#include <stdbool.h>

typedef int tipo_dado;

typedef struct no {
    int chave;
    struct no *esq;
    struct no *dir;
} no;

void Definir(no *t);

no *criaRaiz(no *t, tipo_dado elem);

int numeroDeNos(no *t);

int Altura(no *t);

bool Vazia(no *t);

bool Balanceada(no *t);

bool perfeitamenteBalanceada(no *t);

bool insereDireita(no *t, tipo_dado elem);

bool insereEsquerda(no *t, tipo_dado elem);

void Visita (no *t);

void preOrdem (no *t);

void inOrdem (no *t);

void posOrdem (no *t);

void Imprime_arvore(no *raiz, int nivel, char tipo_conexa); 
//---------------------------------------------
//P/ ABB
//Fun��o (recursiva) de busca para ABB
no *Busca_r(no *t, tipo_dado valor);

//Fun��o para inserir um elem. c/ valor x em uma ABB, caso ele ainda
//n�o esteja l�. Retorna o ponteiro para o n� que cont�m o elem c/ x. 
no *Busca_insere(no *t, tipo_dado elem);

//Fun��o de remo��o dado um n� p, a ser removido.
//Retorna em p o ponteiro para o n� que o substituiu
void Remove_no(no **p);

//Encontra o descendente mais � esquerda da sub-arvore � direita de p. 
//� um n� terminal: seu conte�do � copiado em q e ele ser� removido
void Substitui_menor_a_direita(no **p, no **suc);

//Fun��o para buscar e remover um elem. c/ valor x.
//Retorna true se removeu o elem.; false se o elem. n�o estava na �rvore
bool Busca_remove(no **p_raiz, tipo_dado elem);