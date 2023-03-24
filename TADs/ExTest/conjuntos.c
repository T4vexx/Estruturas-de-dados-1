#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"

typedef struct conjunto {
    int key;
    Con *prox;
} Con;

void ciraConjuntoVazio(Con **A) {
    *A = NULL;
    return;
}

void insere(int x, Con **A) {
    Con *aux,*antes;
    aux = (Con *)malloc(sizeof(Con));
    aux->key = x;

    if(!(*A)) {
        aux->prox = NULL;
        *A = aux;
    }
    
    antes=(*A);
    while(antes->prox != NULL) {
        antes = antes->prox; 
    }

    if(antes->prox == NULL) {
        antes->prox = aux;
        aux->prox = NULL;
    }

    return;
}

void append(Con** headRef, int newData) {
    if(membro(newData,*headRef)) 
        return;
    Con* newNode = (Con*)malloc(sizeof(Con));
    Con* last = *headRef;
    newNode->key = newData;
    newNode->prox = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (last->prox != NULL) {
        last = last->prox;
    }
    last->prox = newNode;
}

void uniao(Con *A,Con *B,Con **C) {
    Con *aux=NULL;
    while(A != NULL) {
        append(&aux,A->key);
        A = A->prox;
    }
    while(B != NULL) {
        append(&aux,B->key);
        B = B->prox;
    }
   (*C) = aux;
}

Con* copiarAemC(Con *A) {
    Con *aux=A,*new=NULL,*antes,*C;
    int count=0;

    while(aux != NULL) {
        antes=new;
        new = (Con *)malloc(sizeof(Con));
        new->key=aux->key;
        if(antes) {
            antes->prox=new;
        }
        aux = aux->prox;
        if(count == 0) {
            C = new;
            count++;
        }  
    }

    return C;
}

void interseccao(Con *A,Con *B, Con **C) {
    Con *auxa=A,*auxb=B,*auxc=NULL,*antes;
    int a,b,count=0;

    if(igual(A,B)) {
        (*C) = copiarAemC(A);
        return;
    }

    while(auxa!=NULL) {
        auxb = B;

        while(auxb!=NULL) {
            if(auxa->key == auxb->key) {
                
                antes=auxc;
                auxc = malloc(sizeof(Con));
                auxc->key = auxb->key;
                auxc->prox = NULL;
                if(antes) {
                    antes->prox=auxc;
                }
                if(count == 0) {
                    *C = auxc;
                    count++;
                }
            }

            auxb = auxb->prox;
        }

        auxa = auxa->prox;
    }
    return;
}

int membro(int x, Con *A) {
    Con *aux;

    if(A == NULL) {
        return 0;
    }

    aux=A;
    while(aux->key != x && aux->prox != NULL) {
        aux = aux->prox; 
    }

    if(aux->prox == NULL) {
        return 0;
    }

    if(aux->key == x) {
        return 1;
    }

    return 0;
}

int igual(Con *B, Con *A) {
    int a,b,i;
    Con *auxa=A, *auxb=B;
    a = count_list(A);
    b = count_list(B);

    if(a!=b) {
        return 0;
    }

    for(i=0;i<a;i++) {
        if(auxa->key != auxb->key) {
            return 0;
        }

        auxa = auxa->prox;
        auxb = auxb->prox;
    }

    return 1;
}

void returnFila(Con *fila) {
    Con *aux=fila;

    if(!aux) {
        printf("\nVazio");
    }

    while(aux != NULL) {
        printf("[%d] ", aux->key);
        aux = aux->prox;
    } 

    return;
}

int count_list(Con* head){
    int count = 0;
    while (head != NULL){
        count++;
        head = head->prox;
    }
    return count;
}

Con* split_list(Con* head, int n) {
    int count = 1;
    Con* ptr = head;
    while (count < n && ptr != NULL) {
        ptr = ptr->prox;
        count++;
    }
    if (ptr == NULL) return NULL;
    Con* prox = ptr->prox;
    ptr->prox = NULL;
    return prox;
}

Con* merge(Con* first, Con* second) {
    Con* result = NULL;

    // Base cases
    if (first == NULL)
        return second;
    else if (second == NULL)
        return first;

    // Recursive cases
    if (first->key <= second->key) {
        result = first;
        result->prox = merge(first->prox, second);
    } else {
        result = second;
        result->prox = merge(first, second->prox);
    }

    return result;
}

void merge_sort(Con **headRef) {
    Con *head = (*headRef);
    if (head == NULL || head->prox == NULL) {
        return;
    }
    int n = count_list(head);
    Con *head2 = split_list(head, n / 2);
    merge_sort(&head);
    merge_sort(&head2);
    (*headRef) = merge(head, head2);
}