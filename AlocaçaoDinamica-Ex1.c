/*Crie um programa que:
Aloque dinamicamente um array de 5 números inteiros;
Peça para o usuário digitar os 5 números no espaço alocado;
Mostre na tela os 5 números; 
Libere a memória alocada.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *p;
	int i;
	p = (int *) (malloc(5*sizeof(int)));	
	if (p == NULL){
		printf ("Erro: M%cmoria Insuficiente.\n",130);
		getch ();
		exit (1);
	}
	
	for (i=0; i<5; i++){
		printf ("Digite o valor da posi%cao %d: ",135 ,i);
		scanf ("%d", &p[i]);
	}
	
	for (i=0; i<5; i++){
		printf ("\n %d", p[i]);	
	}	
	
	free (p);
	getch ();
    return 0;
}
