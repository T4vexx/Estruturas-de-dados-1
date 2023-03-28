/*
  Lista linear sequencial
  Otávio Augusto Teixeira
  Exemplos mostrando criação, e varias usos das funções que já tinha e das que a gente implementou,
  inserção, remoção, buscar na lista, impressão da lista e outros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h" // trocar para .h

//Função para ler e ja adicionar um intem na lista ordenada
void criar(tipo_elem testElem, lista *test) {
  printf("Digite o numero de matricula: ");
  scanf("%d", &testElem.chave);
  printf("Digite nome: \n");
  scanf("%s", testElem.info.nome);
  printf("Digite idade: \n");
  scanf("%d", &testElem.info.idade);
  printf("Digite a media final: \n");
  scanf("%f", &testElem.info.media_final);
  Inserir_ord(testElem,test);
}

int main() {
  int opt,chave,ind;
  tipo_elem testElem;
  lista *test;
  opt  = 0;
  test = malloc(sizeof(lista));
  Definir(test);

  printf("========Usos das funções de lista.h========\n");
  printf("1 - Inserir (Ordenada): \n");
  printf("2 - Remover (Ordenada): \n");
  printf("3 - Buscar por chave (Ordenada): \n");
  printf("4 - Imprimir Lista: \n");
  printf("(-1) - Sair: \n");

  do {
    scanf("%d",&opt);

    switch (opt) {
      case 1:
        criar(testElem,test);
        break;
      case 2:
        printf("Digite a chave do elemento que deseja remover: ");
        scanf("%d",&chave);
        Remover_ch(chave,test);
        break;
      case 3:
        printf("Digite a chave do elemento que deseja buscar: ");
        scanf("%d",&chave);
        if(Buscar_ord(chave,test,&ind)) {
          printf("O elemento esta na posicao %d\n", ind);
        };
        break;
      case 4:
        Imprimir(test);
        break;
      default:
        break;
    }
    
    printf("\nDigite a opção: ");
  } while(opt != -1);

  printf("\n");

  printf("========Usos das funções de lista.h========\n");
  printf("1 - Cheia: %s\n",Cheia(test) ? "Cheia" : "Nao está cheia");
  printf("2 - Vazia: %s\n",Vazia(test) ? "Vazia" : "Nao está vazia");
  testElem.chave = 10;
  testElem.info.idade = 18;
  strcpy(testElem.info.nome, "Otávio Test");
  testElem.info.media_final = 10;
  printf("3 - imprimir elemento: \n");
  Impr_elem(testElem);
  printf("4 - Tamanho da lista: %d\n",Tamanho(test));

  system("PAUSE");
  return 0;
}

