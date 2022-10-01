/*Crie um programa que contenha um array de int contendo 5 elementos. 
Utilizando apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido.*/

#include <stdio.h>
#include <stdlib.h>

int main (){

	int i;
	int vet[5];		
	int *p;	
	p = vet;
	
	for (i = 0; i < 5; i++){
		printf ("Digite o %i%c valor: \n" ,1+i ,248);
		scanf ("%i", &vet[i]);		
	}
	
		for (i = 0; i < 5; i++)
		printf ("O dobro do %i%c valores: %i\n" ,1+i ,248 ,(vet[i]+vet[i]));
			
	getch ();

	return 0;
}
