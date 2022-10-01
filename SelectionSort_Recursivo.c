#include <stdio.h>

int selectionSort (int a[], int n)
{
    int i, j, min, aux;

    for(i = 0; i < (n - 1); i++)
    {
        min = i;

        for(j = (i+1); j < n; j++){
            if(a[j] < a[min])
                min = j;
    	}
    	if (i != min){
    		aux = a[i];
    		a[i] = a[min];
    		a[min] = aux;
		}
	}
	return  selectionSort (a, n - 1);
}

int main()
{
	int selectionSort ();
	void mostrar ();
	
	int numeros[10] = {4, 9, 7, 6, 3, 1, 8, 9, 5, 2};
    int n = sizeof(numeros)/sizeof(numeros[0]);
    int i = 0;
    
	printf("Vetor Original: ");
	for(i = 0; i < n; i++)
		printf("\n");
	
    selectionSort(numeros, n);
    printf("Vetor Ordenado: ");
	    
    for(i = 0; i < n; i++){
    	printf("%d", (i > 0)?", ":"", numeros [i]);
		printf("\n");
	}

	getch();
    return 0;
}

