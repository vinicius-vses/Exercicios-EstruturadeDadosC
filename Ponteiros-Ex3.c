/*Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado. 
Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main (){
	
	int A, B;
	int *endA = &A;
	int *endB = &B;
	
	printf ("Digite um numero: ");
	scanf ("%d", &A);
		
	printf ("Digite mais um numero: ");
	scanf ("%d", &B);	
	
	if(*&A > *&B){
		
	printf ("Conteudo em A: %i\n" ,*endA);
		
	}else{
		printf ("Conteudo em B: %i\n" ,*endB);
	}
			
	getch ();
	
	return 0;
}
