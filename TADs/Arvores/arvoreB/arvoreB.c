#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

//Implementa��es
//---------------------------------------

//Cria AB vazia
void Definir (tree t){
	t = NULL;
}

//Verifica se a AB est� vazia
bool Vazia (tree t){
	if(t == NULL){
		return (true);
	}
	return (false);
}

//Define o n� raiz
tree criaRaiz (tree t, tipo_dado elem){
	t = malloc (sizeof (no));
	
	if(!t){
		printf("Nao foi possivel criar o no raiz.\n");
		return;
	}
	
	t->info = elem;
	t->dir = NULL;
	t->esq = NULL;
	
	return(t);		

}

//Retorna a altura (profundidade) da AB
int Altura (tree t){
	
	if (Vazia(t)){
		return 0;
	}
	
	int altE = Altura (t->esq);
	int altD = Altura (t->dir);
	
	if (altE > altD){
		return (altE + 1); 
	}
	return (altD + 1); 
	//altura = max(altE, altD) + 1
}

bool Balanceada (tree t){
	// if (Vazia (t)) return true;
	
	// else if (t->esq == NULL && t->dir == NULL) // se n�o tem filhos
	// 	return true;
	// else if (t->esq != NULL && t->dir != NULL) //se tem duas sub-�rvores
	// 	return (Balanceada (t->esq) && Balanceada (t->dir));
	// else if (t->esq != NULL) //Se tem um unico filho na esquerda
	// 	return (Altura (t->esq) == 1);
	// else 
	// 	return (Altura (t->dir) == 1);//Se tem um unico filho na direita
	if(Vazia(t)) {
		return true;
	} else {
		int esq = Altura(t->esq);
		int dir = Altura(t->dir);
		int difAlturas = esq - dir;
		if(difAlturas > 1 || difAlturas < -1) {
			return false;
		} else {
			return (Balanceada(t->esq) && Balanceada(t->dir));
		}
	}
}

int numeroNos (tree t){
	if (Vazia (t)) return 0;
	
	int nDir = numeroNos (t->dir);
	int nEsq = numeroNos (t->esq);
	
	return (nDir + nEsq + 1);
}


bool perfeitamenteBalanceada (tree t){
	if (Vazia (t)) return true;
	
	else if (t->esq == NULL && t->dir == NULL)
		return true;
	else if (t->esq != NULL && t->dir != NULL)
		return (perfeitamenteBalanceada (t->esq) && perfeitamenteBalanceada (t->dir));
		//para ser perfeitamente balanceada o n�mero de n�s pode diferir em, no m�ximo, 1
	else if (t->esq != NULL)  
		return (numeroNos (t->esq) == 1);
	else return (numeroNos (t->dir) == 1);
}

bool insereDireita (tree pai, tipo_dado elem){
	if (Vazia (pai)){
		return false;
	}
	if (pai->dir != NULL){
		printf("Ja possui filho a direita. \n");
		return false;
	}
	pai->dir = malloc (sizeof (struct no));
	if(!pai->dir){
		printf("Nao foi possivel criar o no.\n");
		return;
	}
	pai->dir->info = elem;
	pai->dir->dir = NULL;
	pai->dir->esq = NULL;

	return true;
}

bool insereEsquerda (tree pai, tipo_dado elem){
	if (Vazia (pai)){
		return false;
	}
	if (pai->esq != NULL){
		printf("Ja possui filho a esquerda. \n");
		return false;
	}
	
	pai->esq = malloc (sizeof (struct no));
	if(!pai->esq){
		printf("Nao foi possivel criar o no.\n");
		return;
	}
	pai->esq->info = elem;
	pai->esq->dir = NULL;
	pai->esq->esq = NULL;
	return (true);
}

void Visita (tree t){
	printf("Valor: %d\n", t->info.valor);
}

void preOrdem (tree t){
	if(t != NULL){
		Visita (t);
		preOrdem (t->esq);
		preOrdem (t->dir);
	}	
}

void inOrdem (tree t){
	if(t != NULL){
		inOrdem (t->esq);
		Visita (t);
		inOrdem (t->dir);
	}	
}

void posOrdem (tree t){
	if(t != NULL){
		posOrdem (t->esq);
		posOrdem (t->dir);
		Visita (t);
	}

}
//---------------------------------------


