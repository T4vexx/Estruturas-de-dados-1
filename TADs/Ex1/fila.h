typedef struct fila Tfila;

//função que insere um valor n em uma fila Tfila fila no final da fila
void insere(Tfila **fila,int n);

//função que remove o primeiro da fila e devolve o valor do mesmo
int remover(Tfila **fila);

//função que printa a fila em ordem
void returnFila(Tfila *fila);

//função que libera a memoria da fila
void liberarFila(Tfila **fila);