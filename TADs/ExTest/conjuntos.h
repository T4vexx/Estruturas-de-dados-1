typedef struct conjunto Con;

void ciraConjuntoVazio(Con **A);

void uniao(Con *A,Con *B,Con **C);

void interseccao(Con *A,Con *B, Con **C);

int membro(int x, Con *A);

void insere(int x, Con **A);

int igual(Con *B, Con *A);

void merge_sort(Con **headRef);

void returnFila(Con *fila);