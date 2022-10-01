#include <stdio.h>

void insertionSort(int v[], int n)
	int i, n, aux;
 
	if(n>1){
	insertionSort(v, n-1);

	i = n-1;
		while((i>0) && (v[i-1]>v[i])){
			aux = v[i-1];
			v[i-1] = v[i];
			v[i] = aux;
			i--;
		}
	}
} 
