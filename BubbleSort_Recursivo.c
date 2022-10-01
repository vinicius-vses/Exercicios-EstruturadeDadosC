#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int bubbleSort (int numeros [TAM], int i)
{ 	
	int aux, cont;
	
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
    return (numeros);    
    }
    bubbleSort * (int numeros [TAM], int i);
}
