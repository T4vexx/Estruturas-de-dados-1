#include <stdio.h>
#include <stdlib.h>
#include "AB.c"

int main() {
	
	//Exemplo
	//     a 
	//   /   \
	//  b     c
	//   \   / \
	//   d  e   f 
	
	//sub-�rvore 'd'
	No *t1 = cria ('d', criavazia(), criavazia());
	//sub-�rvore 'b'
	No *t2 = cria ('b', criavazia(), t1);
	
	//sub-�rvore 'e'
	No *t3 = cria ('e', criavazia(), criavazia());
	//sub-�rvore 'f'
	No *t4 = cria ('f', criavazia(), criavazia());
	//sub-�rvore 'c'
	No *t5 = cria ('c', t3, t4);
	
	//�rvore 'a'
	No *t = cria ('a', t2, t5);
	
	//imprime
	imprime(t);

	printf("pertence %d", pertence(t2,'d'));
	
	return 0;
}
