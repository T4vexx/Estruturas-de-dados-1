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

bool *libera_no(no *t);

void Visita (no *t);

void preOrdem (no *t);

void inOrdem (no *t);

void posOrdem (no *t);