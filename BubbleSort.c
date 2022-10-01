#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int main()
{
    int numeros [TAM]; 	
	int i, aux, cont;
	
	printf ("Digite os numeros a serem ordenados:\n");
    for (i = 0; i < TAM; i++){
		scanf ("%d", &numeros[i]);
	}
	
    for (cont = 1; cont < TAM; cont++) {
    	for (i = 0; i < TAM - 1; i++){
      		if (numeros[i] > numeros[i + 1]) {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
            }
        }
    }
    
	printf ("\nVetor Ordenado:\n");
		
    for (i = 0; i < TAM; i++){
    	printf ("%d\n", numeros[i]);
    }
    
    getch();
	return 0;
}
