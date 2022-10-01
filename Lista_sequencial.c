#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX    5
#define false -1
#define true   1

typedef int TIPOCHAVE;

typedef struct 
{
	TIPOCHAVE chave;
	char nomeUsuario  [100+1];
	char prontUsuario [10+1];
}REGISTRO;

typedef struct
{
	REGISTRO A[MAX];
	int 	numElem;
}LISTA;

void 	inicializarLista (LISTA *l);
int 	retornarLista (LISTA *l);
void 	exibirLista (LISTA *l);
int 	buscaSequencial (LISTA *l, TIPOCHAVE ch);
int 	inserirElemLista (LISTA *l, REGISTRO reg, int posic);
int 	excluirElemLista (TIPOCHAVE ch, LISTA *l);
void 	reinicializarLista (LISTA *l);

void inicializarLista (LISTA *l)
{
	l->numElem = 0;
}

int retornarLista (LISTA *l)
{
	return l->numElem;
}

void exibirLista (LISTA *l)
{
	int i;
	printf ("\nLista:\n");
	for (i = 0; i < l -> numElem; i++)
		printf ("%i-%s-%s\n");
		l->A[i].chave, l->A[i].nomeUsuario, l->A[i].prontUsuario;
	printf ("\n");
	getch (); 
}

int buscaSequencial (LISTA *l, TIPOCHAVE ch)
{
	int i = 0;
	while (i < l-> numElem)
	{
		if (ch==l->A[i].chave)
			return i;
		else 
			i++;
	}
	return false;
} 

int inserirElemLista (LISTA *l, REGISTRO reg, int posic)
{
	int j;
	if ( (l->numElem==MAX) || (posic<0) || (posic>l->numElem) ){
		printf ("Posicao invalida ou lista cheia.\n");
		return false;
	}
		
	else {
		for (j = l->numElem; j>posic; j--) {
			l->A[j] = l->A[j-1];
		}
		l->A[posic] = reg;
		l->numElem++;
	}
	return true;
}

int excluirElemLista (TIPOCHAVE ch, LISTA *l)
{
	int pos, j;
	pos = buscaSequencial (l, ch);
	
	if (pos == -1){
		printf ("Registro nao encontrado.\n");
		return false;
	}
	else {
		for (j = pos; j <l->numElem-1; j++){
			l->A[j] = l->A[j+1];
		}
		l->numElem--;
	}
	return true;
}

void reinicializarLista (LISTA *l)
{
	l->numElem = 0;
}
TIPOCHAVE  oqueBuscar ()
{   TIPOCHAVE nbusca;
	printf ("\nDigite o elemento para busca: ");
	fflush (stdin);
	scanf ("%i", &nbusca);
	return nbusca;
}

TIPOCHAVE  oqueExcluir ()
{   TIPOCHAVE nexclui;
	printf ("\nDigite o elemento para excluir: ");
	fflush (stdin);
	scanf ("%i", &nexclui);
	return nexclui;
}

REGISTRO oqueInserir ()
{	REGISTRO r;
	printf ("\nTIPOCHAVE             : "); fflush (stdin); scanf("%i", &r.chave);
	printf ("\nNOME DO USUARIO       : "); fflush (stdin); gets(r.nomeUsuario);
	printf ("\nPRONTUARIO DO USUARIO : "); fflush (stdin); gets(r.prontUsuario);
	return r;
}

int main ()
{
	LISTA l;
	REGISTRO reg;
	TIPOCHAVE chave;
	int posic; 
	char opc, ch;
   
   inicializarLista (&l);
   do
   {
   		system ("cls");
   		printf ("\n    TESTE COM LISTA SEQUENCIAL E METODOS");
   		printf ("\n-------------------------------------------------");
   		printf ("\n 1. Inicializar Lista          					");
   		printf ("\n 2. Retorna a quantidade de elementos da Lista 	");
   		printf ("\n 3. Exibir Lista           						");
   		printf ("\n 4. Fazer busca na Lista       					");
   		printf ("\n 5. Inserir elemento da Lista  					");
   		printf ("\n 6. Excluir elemento na Lista  					");
   		printf ("\n 7. Reinicializar Lista        					");
   		printf ("\n-------------------------------------------------");
   		printf ("\n    Escolha: "); fflush (stdin); opc = getche();
   		
		switch (opc)
   	    {
   	    	case '1': inicializarLista (&l);
			case '2': printf("\nRetorno da lista = %i", (&l) );   			break;                        
   	    	case '3': exibirLista(&l); 										break;
   	    	case '4': if ( buscaSequencial (&l, ch)  != false ) 
			               printf ("\nAchou"); 
					  else printf ("\nNao achou");                      	break;
   	    	case '5': if ( inserirElemLista(&l, reg, posic ) != false )
			               printf ("\nElemento incluido"); 
					  else printf ("\nNao incluiu");			            break;
   	    	case '6': if ( excluirElemLista (ch, &l)  != false ) 
			               printf ("\nElemento excluido"); 
					  else printf ("\nNao excluiu elemento");	            break;
			case '7': reinicializarLista (&l);                           	break;	
		}

		printf ("\n\nNovo teste? [n/N = NEGATIVO]"); fflush (stdin); opc = getche();
   }
   while ( opc != 'n' && opc != 'N');
   return 0;
}
