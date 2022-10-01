/*Crie uma função recursiva que receba dois inteiros positivos k e n e calcule k elevado a n*/

#include <stdio.h>

int pot (int k, int n){
	
	if (n == 0)
		return 1;
	else
		return k * pot (k, n - 1);
}

int main (){
	
	int k, n;

	printf ("Digite o n%cmero base: ", 163);
	scanf ("%d", &k);
	printf ("Digite o expoente: ");
	scanf ("%d", &n);
	
	printf ("Resultado de %d elevado a %d: %d ", k, n, pot(k, n));
	
	getchar();

	return 0;
}

