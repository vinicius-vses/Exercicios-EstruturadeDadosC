#include <stdio.h>
#include <stdlib.h>

int buscaSequencial(int *V [2] [2], int N, int elem) {
    int i, j;
    for(i = 0; i < N; i++) {
    	for(j = 0; j < N; j++) {
        	if(elem == V [i][j])
            	return 1; 
    		}
    }
    return -1; 
}

int main()
{
	int buscaSequencial(int *V [2] [2], int N, int elem);
    
	int *V[2][2] = {42, 10, 3, 43};

    return 0;
}
