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

//Tipo nó
typedef struct no
{
   tipo_dado info;
   struct no *esq;
   struct no *dir;
} no;

//Tipo árvore binária (AB): ponteiro p/ nó
typedef struct no *tree;
//------------------------------------------------------


//Declarações de funções/operações
//------------------------------------------------------
//Cria uma árvore binária variza
void Definir (tree t);

//Verifica se a AB é vazia
bool Vazia (tree t);

//Define nó raiz
tree Criar_raiz (tree t, tipo_dado elem);

//Retorna a altura (profundidade) da AB
int Altura (tree t);

//Função para verificar se uma AB é balanceada
bool Balanceada (tree t);

//Função para calcular o número de nós da AB
int Numero_nos (tree t);

//Função para verificar se uma AB é perfeitamente balanceada
bool Perf_balanceada (tree t);

//Função p/ adicionar um filho à direita de um nó, cujo ponteiro é dado (pai). 
//Se o nó não possui filho à direita, então cria esse filho com conteúdo "elem"
bool Insere_dir (tree pai, tipo_dado elem);

//Função p/ adicionar um filho à esquerda de um nó, cujo ponteiro é dado (pai). 
//Se o nó não possui filho à esquerda, então cria esse filho com conteúdo "elem"
bool Insere_esq (tree pai, tipo_dado elem);

//Função "Visita" na forma de impressão de dado
void Visita (tree t);

//Percorre a árvore em pré-ordem
void Pre_ordem (tree t);

//Percorre a árvore no esquema in-ordem
void In_ordem (tree t);

//Percorre a árvore em pós-ordem
void Pos_ordem (tree t);

//Imprime árvore de forma gráfica
void Imprime_arvore (tree t, int espaco, char tipo_conexao);

//---------------------------------------------
//P/ ABB
//Função (recursiva) de busca para ABB
tree Busca_r (tree raiz, tipo_dado valor);

//Função (não-recursiva) de busca para ABB
tree Busca_nr (tree raiz, tipo_dado valor);

//Função para inserir um elem. c/ valor x em uma ABB, caso ele ainda
//não esteja lá. Retorna o ponteiro para o nó que contém o elem c/ x. 
tree Busca_insere (tree raiz, tipo_dado elem);

//Função de remoção dado um nó p, a ser removido.
//Retorna em p o ponteiro para o nó que o substituiu
void Remove_no (tree *p);

//Encontra o descendente mais à esquerda da sub-arvore à direita de p. 
//É um nó terminal: seu conteúdo é copiado em q e ele será removido
void Substitui_menor_a_direita (tree *p, tree *suc);

//Função para buscar e remover um elem. c/ valor x.
//Retorna true se removeu o elem.; false se o elem. não estava na árvore
bool Busca_remove (tree *p_raiz, tipo_dado elem);
//------------------------------------------------------

