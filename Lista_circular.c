#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX       2 
#define INVALIDO -1
#define false    -1  
#define true      1

typedef int 	bool;

typedef int TIPOCHAVE;

typedef struct   
{         
   TIPOCHAVE  chave;       
   char       nomeUsuario[100+1];
   char       prontuario [10+1];
}REGISTRO;

typedef struct aux
{  
	REGISTRO 	reg;
	struct 		aux	* prox;
}ELEMENTO;

typedef ELEMENTO * PONT;  

typedef struct 
{
	PONT cabeca;
}LISTA;

void inicializarLista 	(LISTA* l);
int tamanho 			(LISTA* l);
void exibirLista 		(LISTA* l);
PONT buscaSeqOrd 		(LISTA* l, TIPOCHAVE ch);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
PONT buscaSequencialExc (LISTA* l, TIPOCHAVE ch, PONT* ant);
bool excluirElemLista 	(LISTA* l, TIPOCHAVE ch);
void reinicializarLista (LISTA* l);

TIPOCHAVE  	oqueBuscar 		(void);
void 		pesquisaLista 	(LISTA* l);
REGISTRO 	oqueInserir 	(void);
void 		insereNaLista 	(LISTA* l);
TIPOCHAVE  	oqueExcluir 	(void);
void 		excluiDaLista 	(LISTA* l);

void inicializarLista(LISTA* l)
{
  l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
  l->cabeca->prox = l->cabeca;
}

int tamanho(LISTA* l) 
{  
	PONT end = l->cabeca->prox;  
	int  tam = 0;
	while (end != l->cabeca) {  
		tam++;
		end = end->prox;
	}
	return tam;
}

void exibirLista(LISTA* l) 
{  
   PONT end = l->cabeca->prox;  
   system ("cls");
   printf("Lista: [ ");  
   while (end != l->cabeca) {
		printf("\n%i - %s - %s", end->reg.chave, end->reg.nomeUsuario, end->reg.prontuario);  
		end = end->prox;
   }
   printf("]\n");
}

PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch) 
{
	PONT pos = l->cabeca->prox;
	l->cabeca->reg.chave = ch;                      
	while (pos->reg.chave != ch)
		pos = pos->prox;                       
	if (pos != l->cabeca)   
		return pos;                            
	return NULL;                               
}
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) 
{  
	TIPOCHAVE ch = reg.chave;
	PONT ant, i;
	i = buscaSequencialExc(l,ch,&ant);  
	if (i != NULL)	
		return false;
	i = (PONT) malloc(sizeof(ELEMENTO));  
	i->reg = reg;                        
	i->prox = ant->prox;
	ant->prox = i;                   
	return true;
}

PONT buscaSequencialExc (LISTA* l, TIPOCHAVE ch, PONT* ant)
{ 
	*ant = l->cabeca;
	PONT atual = l->cabeca->prox;
	l->cabeca->reg.chave = ch;
	while (atual->reg.chave<ch){                                                
		*ant  = atual;                              
		atual = atual->prox;                         
	}
	if ((atual != l->cabeca && atual->reg.chave == ch)) 
		return atual;                                
	return NULL;                                    
}

bool excluirElemLista (LISTA* l, TIPOCHAVE ch) 
{  
	PONT ant, i;
	i = buscaSequencialExc(l,ch,&ant);  
	if (i == NULL)           
		return false;                         
	ant->prox = i->prox; 
	free(i);                 
	return true;            
}

void reinicializarLista(LISTA* l) 
{  
    PONT apagar;
	PONT end = l->cabeca->prox;   
	while (end != l->cabeca){  
		apagar 	= end;    
		end 	= end->prox;  
		free(apagar);        
	}                        
	l->cabeca->prox = l->cabeca;        
}

TIPOCHAVE  oqueBuscar ()
{   TIPOCHAVE nbusca;
	printf ("\nDigite o elemento para busca: ");
	fflush (stdin);
	scanf ("%i", &nbusca);
	return nbusca;
}

void pesquisaLista(LISTA* l)
{
    PONT ender;
    TIPOCHAVE elem;
	elem  = oqueBuscar();	
	ender = buscaSeqOrd(l, elem);
	if (ender == NULL)
	   printf ("\nChave [%i] nao encontrada.", elem);
	else
	   printf ("\nChave [%i] encontrada em [%p]", elem, ender);
}

REGISTRO oqueInserir ()
{	REGISTRO r;
	printf ("\nTIPOCHAVE            : "); fflush (stdin); scanf("%i", &r.chave);
	printf ("\nNOME DO USUARIO      : "); fflush (stdin); gets(r.nomeUsuario);
	printf ("\nPRONTUARIO DO USUARIO: "); fflush (stdin); gets(r.prontuario);
	return r;
}

void insereNaLista(LISTA* l)
{
	REGISTRO	elem;
	elem  = oqueInserir();
	if ( inserirElemListaOrd(l, elem) == true )
	   printf ("\nChave [%i] inserida.", elem.chave );
	else
	   printf ("\nChave [%i] nao inserida", elem.chave );
}

TIPOCHAVE  oqueExcluir ()
{   TIPOCHAVE nexclui;
	printf ("\nDigite o elemento para excluir: ");
	fflush (stdin);
	scanf ("%i", &nexclui);
	return nexclui;
}

void excluiDaLista(LISTA* l)
{	TIPOCHAVE chave;
 	chave = oqueExcluir();
	if ( excluirElemLista(l, chave) == true )
	   printf ("\nChave [%i] excluida.", chave );
	else
	   printf ("\nChave [%i] nao excluida", chave );
}

int main ()
{
   LISTA lis; 
   int *ant;
   char opc;
   do
   {    
   		system ("cls");
   		printf ("\n TESTE COM LISTA DINAMICA E METODOS           ");
   		printf ("\n----------------------------------------------");
   		printf ("\n 1. Inicializar Lista                		 ");
   		printf ("\n 2. Retorna a quantidade de elementos da Lista");
   		printf ("\n 3. Exibir Lista            		  			 ");
   		printf ("\n 4. Fazer busca na Lista    		  			 ");
   		printf ("\n 5. Inserir elemento na Lista  	  			 ");
   		printf ("\n 6. Excluir elemento da Lista  	  			 ");
   		printf ("\n 7. Reinicializa Lista  			             ");
   		printf ("\n----------------------------------------------");
   		printf ("\n    Escolha: "); fflush (stdin); opc = getche();
   		
		switch (opc)
   	    {
   	    	case '1': inicializarLista(&lis); 								break;
   	    	case '2': printf("\nRetorno da lista = %i", tamanho(&lis) ); 	break;
   	    	case '3': exibirLista (&lis);									break;			
   	    	case '4': pesquisaLista (&lis);						            break;
   	    	case '5': insereNaLista (&lis);									break;
   	    	case '6': excluiDaLista (&lis);									break;
   	    	case '7': reinicializarLista (&lis);							break;
		}

		printf ("\n\nNovo teste? [n/N = NEGATIVO]"); fflush (stdin); opc = getche();
   }
   while ( opc != 'n' && opc != 'N');
   return 0;
}
