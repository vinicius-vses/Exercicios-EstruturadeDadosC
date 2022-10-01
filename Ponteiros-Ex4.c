/*Crie um programa que contenha um array de int contendo 10 elementos. 
Imprima o endereço de cada posição desse array.*/

#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int i;
	int vet[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p;	
	p = vet;
	
	for (i = 0; i < 10; i++)
	printf ("%i\n", *(p+i));

	getch ();
	
	return 0;	
}
