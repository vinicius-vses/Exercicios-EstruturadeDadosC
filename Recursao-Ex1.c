/*Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a N*/

#include <stdio.h>
#include <conio.h>

int soma (int valor){
	
	if (valor == 0)
		return 0;
	else
		return valor + soma (valor - 1);
}

int main (){
	
	int num, i=0, r=0;
	
	printf ("Digite um n%cmero: ", 163);
	scanf ("%d", &num);
	
	r = soma(num);
	printf ("Somat%cria dos n%cmeros anteriores at%c %d : %d\n",162,163,130,num,r);
	
	getchar();

	return 0;
}




