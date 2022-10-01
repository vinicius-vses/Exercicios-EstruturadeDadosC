/*Faça um programa que leia do usuário o tamanho de um vetor a ser lido e faça a alocação dinâmica em memória. 
Em seguida, leia do usuário seus valores e imprima o vetor lido.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *p;
	int i, N;

	printf ("Digite o n%cmero de elementos do vetor: ",163);
	scanf ("%d", &N);	
	p = (int *) (malloc(N*sizeof(int)));	
	if (p == NULL){
		printf ("Erro: M%cmoria Insuficiente.\n",130);
		getch ();
		exit (1);
	}
	
	for (i=0; i <N; i++){
		printf("Digite os valores do vetor: ");
		scanf ("%d", &p[i]);
	}
	
	for (i=0; i <N; i++){
	printf("\n%d", p[i]);
	}
	
	getch ();
    return 0;
}
