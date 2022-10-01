/*Escreva um programa que contenha duas variáveis inteiras. 
Compare seus endereços e exiba o maior endereço.*/

#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int A = 1, *endA = &A;
	int B = 2, *endB = &B;
	
	if(*&A > *&B){
		
		printf ("Endereco de A %c o maior.\n" ,130 );
		
	}else{
		printf ("Endereco de B %c o maior.\n" ,130);
	}
	
	getch ();
	
	return 0;	
}
