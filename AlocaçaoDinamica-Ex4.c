/*Faça um programa que leia uma quantidade qualquer de números armazenando-os na memória e pare a leitura quando o usuário entrar um número negativo. 
Em seguida, imprima o vetor lido. Use a função REALLOC.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *p;
	int i;
	
	p = (int *) malloc(5*sizeof(int));
	
	if (p == NULL){
	printf ("Erro: M%cmoria Insuficiente.\n",130);
	getch ();
	exit (1);
	}
					
		for (i = 0; i < 5; i++){
			printf ("Digite qualquer n%cmero: ", 163 );
			scanf ("%d", &p[i]);		
			
			if (p[i] < 0){
				printf ("N%cmero negativo!\n",163);
				break;
			}	
		}
				p = realloc(p, 3*sizeof(int));	
				for (i = 0; i < 6 ; i++){
					printf("%d\n", p[i]);
				}
	getch ();
    return 0;
}
