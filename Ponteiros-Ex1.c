/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real e char. 
Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando os ponteiros. 
Imprima os valores das variáveis antes e após a modificação.*/

#include <stdio.h>
#include <stdlib.h>

int main (){
	
	//Declaracao Integer/Inteiro
	int i = 9;
	int *pontInt = &i;
	
	//Declaracao Floating-Point/Real
	float f = 0.9;
	float *pontFloat = &f;
	
	//Declaracao Character
	char c = 'v';
	char *pontChar = &c;
	
	//Type Cast
	*pontInt = 10;
	*pontFloat = 0.7;
	*pontChar = 's';
	
	//Imprimindo Valores	
	printf("Numero inteiro: %i\n", *pontInt);	
	printf("Numero real: %f\n", *pontFloat);
	printf("Letra: %c", *pontChar);
	
	getch ();
	
	return 0;	
}
