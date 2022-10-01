#include <stdio.h>

int main()
{
    int numeros[] = {90, 50, 20, 72}; 	
	int i, j, tam, valor;
	
	for (i = 1; i < 4 ; i++){
		valor = numeros [i];
		
		for (j = i - 1; j >= 0 && numeros[j] > valor; j--){
			numeros[j+1] = numeros[j];
		}
		numeros [j+1] = valor;
	}

	for (j = 0; j < 4; j++){
    printf ("%d\n", numeros[j]);
    }
    
	getch();
    return 0;
}
