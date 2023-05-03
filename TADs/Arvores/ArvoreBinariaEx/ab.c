#include <stdio.h>
#include <math.h>
#include "ab.h"


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

bool *libera_no(no *t) {
    no *aux;

    if(t == NULL) {
        return false;
    }
    aux = t;
    free(t);
    return aux;
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
    //     } ese {l
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
    } else if(t->esq == NULL && t->dir == NULL ) {
        return true;
    } else if(t->esq != NULL && t->dir != NULL) {
        return (perfeitamenteBalanceada(t->esq) && perfeitamenteBalanceada(t->dir));
    } else if(t->esq != NULL) {
        return (numeroDeNos(t->esq) == 1);
    } else {
        return (numeroDeNos(t->dir) == 1);
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

bool insereEsquerda(no *t, tipo_dado elem) {
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

int maiorEmT(no *t) {
    int maior = 0;
    if(t != NULL) {
		int esq = maiorEmT(t->esq);
		int dir = maiorEmT(t->dir);
        if(esq > dir) {
            maior = esq;
        } else {
            maior = dir;
        }
        if(t->chave > maior) {
            maior = t->chave;
            return maior;
        } 

        return maior;
	}
}

int totalNosFolhas(no *t) {
    int esq=0,dir=0;
    if(t != NULL){
		esq = totalNosFolhas(t->esq);
		dir = totalNosFolhas(t->dir);
		if(t->dir == NULL && t->esq == NULL) {
            return (esq + dir + 1);
        }
        return esq + dir;
	}
}

bool isTreeCompleteRule(no *t) {
    if(t == NULL) {
        return true;
    } else if(t->dir == NULL && t->esq == NULL) {
        return true;
    } else if(t->dir != NULL && t->esq != NULL) {
        return (isTreeCompleteRule(t->dir) && isTreeCompleteRule(t->esq));
    } else if(t->dir != NULL) {
        return false;
    } else {
        return false;
    }
}

bool isTreeComplete(no *t) {
    bool rule,nosCheck;
    int nosFolhas,altura;

    rule = isTreeCompleteRule(t);
    nosFolhas = totalNosFolhas(t);
    altura = Altura(t);
    if(nosFolhas != pow(2,altura-1)) {
        nosCheck = false;
    } else {
        nosCheck = true;
    }

    return(rule && nosCheck);
}

//------------------------------ Ex 8
typedef struct no_pilha {
    no *valor;
    struct no_pilha *proximo;
} no_pilha;

typedef struct {
    no_pilha *topo;
} pilha;

pilha *criar_pilha() {
    pilha *nova_pilha = malloc(sizeof(pilha));
    nova_pilha->topo = NULL;
    return nova_pilha;
}

void empilhar(pilha *p, no *valor) {
    no_pilha *novo_no = malloc(sizeof(no_pilha));
    novo_no->valor = valor;
    novo_no->proximo = p->topo;
    p->topo = novo_no;
}

no *topo(pilha *p) {
    return p->topo->valor;
}

no *desempilhar(pilha *p) {
    no_pilha *no_a_remover = p->topo;
    no *valor = no_a_remover->valor;
    p->topo = no_a_remover->proximo;
    free(no_a_remover);
    return valor;
}

int contem(pilha *p, no *valor) {
    no_pilha *no_atual = p->topo;
    while (no_atual != NULL) {
        if (no_atual->valor == valor) {
            return 1;
        }
        no_atual = no_atual->proximo;
    }
    return 0;
}

int esta_vazia(pilha *p) {
    return p->topo == NULL;
}

void liberar_pilha(pilha *p) {
    while (!esta_vazia(p)) {
        desempilhar(p);
    }
    free(p);
}

// void posOrdemIterativa (no *t) {
//     if (t == NULL) {
//         return;
//     }
//     pilha *pilha_arvore = criar_pilha();
//     pilha *pilha_visitados = criar_pilha();
//     empilhar(pilha_arvore, t);
//     while (!esta_vazia(pilha_arvore)) {
//         no *no_atual = topo(pilha_arvore);
//         if (contem(pilha_visitados, no_atual)) {
//             printf("Dado impresso: %d\n", no_atual->chave);
//             desempilhar(pilha_arvore);
//         } else {
//             empilhar(pilha_visitados, no_atual);
//             if (no_atual->dir != NULL) {
//                 empilhar(pilha_arvore, no_atual->dir);
//             }
//             if (no_atual->esq != NULL) {
//                 empilhar(pilha_arvore, no_atual->esq);
//             }
//         }
//     }
//     liberar_pilha(pilha_arvore);
//     liberar_pilha(pilha_visitados);
// }
void posOrdemIterativa(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    pilha *p = criar_pilha();
    no *anterior = NULL;

    while (!esta_vazia(p) || raiz != NULL) {
        if (raiz != NULL) {
            empilhar(p, raiz);
            raiz = raiz->esq;
        } else {
            no *top = topo(p);
            if (top->dir != NULL && top->dir != anterior) {
                raiz = top->dir;
            } else {
                printf("Dado impresso: %d\n", top->chave);
                desempilhar(p);
                anterior = top;
            }
        }
    }

    liberar_pilha(p);
}

//------------------------ex9
