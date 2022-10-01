/*Faça uma função recursiva que receba um número inteiro positivo N 
e imprima todos os números naturais de 0 até N em ordem crescente.*/

#include <stdio.h>
#include <stdlib.h>

int nat (int n, int c){
	if (n == 0){
		return 0;
	}else{
		printf ("%d\n", c);
		return n * nat (n - 1, c + 1);
	}
}

int main (){

	int n = 0, c;

	printf ("Digite um n%cmero inteiro positivo: ",163);
	scanf ("%d", &n);
	nat(n, c + 1);
	
	getchar();

	return 0;
}
