#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX     5  
#define INVALIDO -1
#define false    -1  
#define true      1

typedef int TIPOCHAVE;

typedef struct   
{         
   TIPOCHAVE  chave;        
   char       nomeUsuario  [100+1];
   char       prontuario [10+1];
}REGISTRO;

typedef struct
{  
   REGISTRO reg;
   int      prox;
}ELEMENTO;

typedef struct 
{  
   ELEMENTO A[MAX];  
   int      inicio;  
   int      dispo;   
}LISTA;

void 	inicializarLista 		(LISTA *l);
int 	tamanho 				(LISTA *l);
void 	exibirLista 			(LISTA *l);
int 	buscaSequencialOrd 		(LISTA *l, TIPOCHAVE ch); 
int 	obterNo 				(LISTA *l);
void 	devolverNo 				(LISTA *l, int j);  
int 	excluirElemLista 		(LISTA *l, TIPOCHAVE ch); 
int 	inserirElemListaOrd 	(LISTA *l, REGISTRO reg);
void 	reinicializarLista 		(LISTA *l);


TIPOCHAVE  oqueBuscar  ();
TIPOCHAVE  oqueExcluir ();
REGISTRO   oqueInserir ();

void inicializarLista (LISTA *l) 
{  int i;
   for (i=0; i<MAX-1; i++)  
      l->A[i].prox = i + 1;
   l->A[MAX-1].prox=INVALIDO;
   l->inicio = INVALIDO;  
   l->dispo  = 0;
}

int tamanho (LISTA *l) 
{  
   int i   = l->inicio;  
   int tam = 0;
   while (i != INVALIDO) 
   {  
      tam++;
      i = l->A[i].prox;
   }
   return tam;
}

void exibirLista (LISTA *l)
{
    int i = l->inicio;  
    printf("\nLista: \" ");  
    while (i != INVALIDO) 
    {
       printf("[%i - %s - %s -> %i]", 
	   l->A[i].reg.chave, l->A[i].reg.nomeUsuario, l->A[i].reg.prontuario, l->A[i].prox);  
       i = l->A[i].prox;
    }
    printf("\"\n"); getch();
}

int buscaSequencialOrd (LISTA *l, TIPOCHAVE ch) 
{  
    int i = l->inicio;
    while (i != INVALIDO && l->A[i].reg.chave < ch)  
       i = l->A[i].prox;
    if (i != INVALIDO && l->A[i].reg.chave == ch)  
       return i;
    else
       return INVALIDO;
}

int obterNo (LISTA *l) 
{
   int resultado = l->dispo;  
   if (l->dispo != INVALIDO)
      l->dispo = l->A[l->dispo].prox;  
   return resultado;
}

void devolverNo (LISTA *l, int j)  
{  
   l->A[j].prox= l->dispo;  
   l->dispo = j; 
} 

int excluirElemLista (LISTA *l, TIPOCHAVE ch) 
{  
    int ant = INVALIDO;
    int i   = l->inicio;
    while ((i != INVALIDO) && (l->A[i].reg.chave<ch)) 
    {  
        ant = i;
        i = l->A[i].prox;
    }
    if (i==INVALIDO || l->A[i].reg.chave!=ch) 
        return false;  
    if (ant == INVALIDO) 
        l->inicio = l->A[i].prox;
    else 
        l->A[ant].prox = l->A[i].prox;  
    devolverNo(l,i);
    return true;
}

int inserirElemListaOrd (LISTA *l, REGISTRO reg) 
{  
   if (l->dispo == INVALIDO) 
   {  
   	  printf ("\nPosicao invalida ou lista cheia. Nao vai inserir [%i].",reg.chave); getch();
      return false;
   }
   int ant      = INVALIDO;  
   int i        = l->inicio;
   TIPOCHAVE ch = reg.chave; 
   
   while ((i != INVALIDO) && (l->A[i].reg.chave<ch)) 
   {  
        ant = i;
        i = l->A[i].prox;
   }
   if (i!=INVALIDO && l->A[i].reg.chave==ch) 
   {  
   	   printf ("\nChave a inserir [%i] ja esta na lista.",ch); getch();
       return false;
   }
   
   i = obterNo(l);
   l->A[i].reg = reg;
   if (ant == INVALIDO)
   { 
      printf ("\nChave a inserir [%i] sera a 1a. da lista.[%i]",ch, ant); getch();
      l->A[i].prox = l->inicio;  
      l->inicio = i;
   } 
   else 
   {
      l->A[i].prox = l->A[ant].prox; 
      l->A[ant].prox = i; 
   }
   return true;
}

void reinicializarLista (LISTA *l) 
{  
    inicializarLista(l);
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
	printf ("\nPRONTUARIO DO USUARIO : "); fflush (stdin); gets(r.prontuario);
	return r;
}

int main ()
{
   LISTA lis;
   int *ant;
   char opc;
   
   inicializarLista (&lis);
   do
   {
   		system ("cls");
   		printf ("\n   TESTE COM LISTA ESTATICA E METODOS   	     ");
   		printf ("\n----------------------------------------------");
   		printf ("\n 1. Inicializar Lista          		  	     ");
   		printf ("\n 2. Retorna a quantidade de elementos da Lista");
   		printf ("\n 3. Exibir Lista       		        		 ");
   		printf ("\n 4. Fazer busca na Lista  		  			 ");
   		printf ("\n 5. Inserir elemento na Lista  		  	     ");
   		printf ("\n 6. Excluir elemento na Lista       		  	 ");
   		printf ("\n 7. Reinicializar Lista   		  			 ");
   		printf ("\n----------------------------------------------");
   		printf ("\n    Escolha: "); fflush (stdin); opc = getche();
   		
		switch (opc)
   	    {
   	    	case '1': inicializarLista (&lis);                              break;
   	    	case '2': printf("\nRetorno da lista = %i", tamanho(&lis) ); 	break;
   	    	case '3': exibirLista(&lis);
   	    	case '4': if ( buscaSequencialOrd (&lis, oqueBuscar())  != false ) 
			               printf("\nAchou"); 
					  else printf ("\nNao achou");                          break;
   	    	case '5': if ( inserirElemListaOrd (&lis, oqueInserir())  != false ) 
			               printf("\nElemento incluido"); 
					  else printf ("\nNao incluiu elemento");	            break;
			case '6': if ( excluirElemLista(&lis, oqueExcluir()) != false )
			               printf("\nElemento excluido"); 
					  else printf ("\nNao excluiu");			            break;
			case '7': reinicializarLista (&lis);                            break;                        
		}

		printf ("\n\nNovo teste? [n/N = NEGATIVO]"); fflush (stdin); opc = getche();
   }
   while ( opc != 'n' && opc != 'N');
   return 0;
}
