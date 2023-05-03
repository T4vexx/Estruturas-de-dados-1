#include <stdbool.h> //Tipo booleano

//Estruturas e tipos
//-------------------------------------------
//Tipo registro
typedef struct
{
   int valor;
   //char nome[30];
   //... (caso tenha outros campos)
} tipo_dado;

//Tipo n�
typedef struct no
{
   tipo_dado info;
   struct no *esq;
   struct no *dir;
} no;

//Tipo �rvore bin�ria (AB): ponteiro p/ n�
typedef struct no *tree;
//------------------------------------------------------


//Declara��es de fun��es/opera��es
//------------------------------------------------------
//Cria uma �rvore bin�ria variza
void Definir (tree t);

//Verifica se a AB � vazia
bool Vazia (tree t);

//Define n� raiz
tree Criar_raiz (tree t, tipo_dado elem);

//Retorna a altura (profundidade) da AB
int Altura (tree t);

//Fun��o para verificar se uma AB � balanceada
bool Balanceada (tree t);

//Fun��o para calcular o n�mero de n�s da AB
int Numero_nos (tree t);

//Fun��o para verificar se uma AB � perfeitamente balanceada
bool Perf_balanceada (tree t);

//Fun��o p/ adicionar um filho � direita de um n�, cujo ponteiro � dado (pai). 
//Se o n� n�o possui filho � direita, ent�o cria esse filho com conte�do "elem"
bool Insere_dir (tree pai, tipo_dado elem);

//Fun��o p/ adicionar um filho � esquerda de um n�, cujo ponteiro � dado (pai). 
//Se o n� n�o possui filho � esquerda, ent�o cria esse filho com conte�do "elem"
bool Insere_esq (tree pai, tipo_dado elem);

//Fun��o "Visita" na forma de impress�o de dado
void Visita (tree t);

//Percorre a �rvore em pr�-ordem
void Pre_ordem (tree t);

//Percorre a �rvore no esquema in-ordem
void In_ordem (tree t);

//Percorre a �rvore em p�s-ordem
void Pos_ordem (tree t);

//Imprime �rvore de forma gr�fica
void Imprime_arvore (tree t, int espaco, char tipo_conexao);

//---------------------------------------------
//P/ ABB
//Fun��o (recursiva) de busca para ABB
tree Busca_r (tree raiz, tipo_dado valor);

//Fun��o (n�o-recursiva) de busca para ABB
tree Busca_nr (tree raiz, tipo_dado valor);

//Fun��o para inserir um elem. c/ valor x em uma ABB, caso ele ainda
//n�o esteja l�. Retorna o ponteiro para o n� que cont�m o elem c/ x. 
tree Busca_insere (tree raiz, tipo_dado elem);

//Fun��o de remo��o dado um n� p, a ser removido.
//Retorna em p o ponteiro para o n� que o substituiu
void Remove_no (tree *p);

//Encontra o descendente mais � esquerda da sub-arvore � direita de p. 
//� um n� terminal: seu conte�do � copiado em q e ele ser� removido
void Substitui_menor_a_direita (tree *p, tree *suc);

//Fun��o para buscar e remover um elem. c/ valor x.
//Retorna true se removeu o elem.; false se o elem. n�o estava na �rvore
bool Busca_remove (tree *p_raiz, tipo_dado elem);
//------------------------------------------------------

