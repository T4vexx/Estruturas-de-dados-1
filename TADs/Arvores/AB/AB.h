//Arquivo de interface (cabe�alho)

//Tipo No
typedef struct no No;
//----------------------------------


//Prot�tipo das fun��es (opera��es)
//----------------------------------
No *criavazia (void);

No *cria (char c, No *esq, No *dir);

No *libera (No *t);

int vazia (No *t);

int pertence (No *t, char c);

void imprime (No *t);
//----------------------------------

