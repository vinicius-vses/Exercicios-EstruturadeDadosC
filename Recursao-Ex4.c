/*Faça uma função recursiva que receba um número inteiro positivo par N 
e imprima todos os números pares de 0 até N em ordem crescente.*/

#include <stdio.h>
#include <stdlib.h>

int par (int n, int c){
	if (n % 2 != 0){
		return 0;
	}else 
		for (c = 0; c <= n; c++){
			if(n % 2 == 0){
			n++;
			}
		}
		return n * par (n - 1, c + 0);
}

int main (){

	int n = 0, c;

	printf ("Digite um n%cmero inteiro positivo par: ",163);
	scanf ("%d", &n);
	printf ("%d\n", par(n, c));	
	getchar;

	return 0;
}

//Nao consegui fazer com que os numeros pares apare�am ):
