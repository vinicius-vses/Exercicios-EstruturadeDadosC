/*Faça um programa que leia do usuário o tamanho de um vetor a ser lido e faça a  alocação dinâmica de memória. 
Em seguida, leia do usuário seus valores e mostre quantos dos números são pares e quantos são ímpares.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *p;
	int i, N, contImp=0, contPar=0;
	float res;
	
	printf ("Digite o n%cmero de elementos do vetor: ",163);
	scanf ("%d", &N);	
	p = (int *) (malloc(N*sizeof(int)));	
	if (p == NULL){
		printf ("Erro: M%cmoria Insuficiente.\n",130);
		getch ();
		exit (1);
	}
		for (i = 0; i < N; i++){
			printf("Digite o valor da posi%cao %d: ",135 ,i+1); 
			scanf ("%d", &p[i]);
		}
		for (i = 0; i < N; i++){
				res = p[i] % 2;
				if (res==0){
				contPar++;	
				}else{
				contImp++;					
				}
		}
	printf ("Pares: %d \n",contPar);
	printf ("Impares: %d \n",contImp);
	getch ();
    return 0;
}
