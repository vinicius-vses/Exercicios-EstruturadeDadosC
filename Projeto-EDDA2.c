/*
Instituto Federal de Educação, Ciência e Tecnologia de São Paulo
Projeto semestral para a disciplina de Estrutura de Dados do segundo semestre
Curso de Tecnologia em Análise e Desenvolvimento de Sistemas
Docente:  Guilherme Werneck de Oliveira
Discente: Vinicius Souza do Espírito Santo Prontuário: SP3068901
Projeto entregue até 27/01/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#define  true  1
#define  false 0

typedef int bool;

typedef struct
{  
	int			chave;
	int 		atend;
	char		Nnorm[1+1];
	char		Npriori[1+1];
	char		tipoatend[1+1];
}REGISTRO;

typedef struct aux
{  
	REGISTRO 	reg;
	struct 		aux * PROX;
	int			Nnorm;
	int			Npriori;			
}ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
	PONT 		inicio;
	PONT 		fim;
	int  		tam;
	int			Nnorm;
	int			Npriori;
}FILA;

void 		inicializarfila 		(FILA * f);
int 		tamanho 				(FILA * f);
void 		exibirfila 				(FILA * f, REGISTRO  reg);
bool 		estaVazia				(FILA * f);
int 		inserirAtend			(FILA * f, REGISTRO  reg);
bool 		inserirNaFila 			(FILA * f, REGISTRO  reg);
PONT 		naPosic 				(FILA * f, int indice);
void 		inserirSenha 			(FILA * f, REGISTRO * reg, int indice);
int			indice					(FILA * f, PONT aux);
//void		ordenaElem				(FILA * f, REGISTRO  reg);
bool 		excluirDaFila			(FILA * f, REGISTRO *reg);
void 		reinicializarFila		(FILA * f);
void     	msgErro	 				(void);

void inicializarfila (FILA * f)
{
  f->inicio = NULL;
  f->fim    = NULL;
}

int tamanho (FILA * f)
{  
	PONT    end = f->inicio;
	int     tam = 0;
	while (end != NULL)
	{
  		tam++;
  		end = end->PROX;
	}
	return tam;
}

bool estaVazia (FILA * f)
{
   if (f->inicio == NULL)
    return true;
   return false;
}

bool excluirDaFila (FILA * f, REGISTRO *reg)
{  
   if (f->inicio==NULL)
   	  return false;
   *reg = f->inicio->reg;
   PONT apagar = f->inicio;
   f->inicio = f->inicio->PROX; 
   free(apagar);
   if (f->inicio == NULL)
      f->fim = NULL;
   return true;
}

void reinicializarFila (FILA * f)
{  
   PONT end = f->inicio;
   PONT apagar;
   while (end != NULL)
   {
      apagar = end;
	  end = end->PROX;
	  free(apagar);
   }
   f->inicio = NULL;
   f->fim = NULL;
}

void msgErro (void)
{
	printf ("\nOpção inválida!\n");
	getch  ();
	system ("cls");
}

int inserirAtend (FILA * f, REGISTRO reg)
{
	printf ("Quantos atendentes estão diponíveis? ");
	scanf  ("%i", &reg.atend);
}

PONT naPosic (FILA * f, int indice)
{
	if (indice >= 0 && indice < f->tam){
		PONT aux = f->fim;
		int i;
		for (i = 0; i < indice; i++)
			aux = aux->PROX;
		return aux;
	}
	return NULL;
}

void exibirfila (FILA * f, REGISTRO  reg)
{  
   PONT end = f->inicio;
   system ("cls");
   if (end == NULL)
   	printf ("LISTA VAZIA!");
   else{	
   	printf("Número de atendente(s) %i:  Senha: ", reg.atend);
   		while (end != NULL)
   		{
		printf ("%s%i ",end->reg.tipoatend, end->reg.chave);
		end = end->PROX;
   		}
	}
}

bool inserirNaFila (FILA * f, REGISTRO reg)
{
	REGISTRO		 elem;
	PONT end  = f->inicio;
	char      		  opc;
	
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	
	if ( novo == NULL )
	{
		printf ("\nErro ao alocar nova senha.");
		getch();
		return;
   	}else{
   			while (opc != 's')
			{
				printf ("Pressione 'N/n' para Atendimento Normal\n");
				printf ("Pressione 'P/p' para Atendimento Prioritário\n");
				printf ("Pressione 'S/s' para voltar ao menu");
				printf ("\n Escolha: "); fflush (stdin); opc = getche(); opc = tolower(opc);
   					switch (opc)
   					{
						case 'n' : printf ("\nDigite 'N/n' novamente para confirmar: ");
						fflush (stdin); gets(elem.Nnorm);
						return true;				break;
						case 'p' : printf ("\nDigite 'P/p' novamente para confirmar: ");
						fflush (stdin); gets(elem.Npriori);
						return false;				break;
    					case 's' :  main    (); 	break;
						default  :  msgErro ();		break;
					}
			}
		}
}

void inserirSenha (FILA * f, REGISTRO  * reg, int indice)
{
	REGISTRO	elem;
	
	if (indice == 0)
		inserirNaFila (f, *reg);
	else {
		PONT atual = naPosic(f, indice);
		
		PONT novo = (PONT) malloc(sizeof(ELEMENTO));
		
		if (inserirNaFila (f, *reg) == true){
			PONT ant  = naPosic (f, indice - 1);
			novo->reg = *reg;
			ant ->PROX = novo;
			novo->PROX = atual;
			f->tam++;
			f->Nnorm++;
			printf ("\nSenha [%s%i] requisitada com sucesso.",elem.tipoatend, f->fim->Nnorm);
		}
			else{
				(inserirNaFila (f, *reg) == false);
				PONT ant  = naPosic (f, indice - 1);
				novo->reg = *reg;
				ant ->PROX = novo;
				novo->PROX = atual;
   				f->tam++;
				f->Npriori++;
				printf ("\nSenha [%s%i] requisitada com sucesso.",elem.tipoatend, f->fim->Npriori);
			}
	}
}

int indice (FILA * f, PONT aux)
{
	if (aux != NULL){
		PONT fim = f->inicio;
		int indice = 0;
		while (fim != aux && fim != NULL){
			fim = fim->PROX;
			indice++;				
		}
		if (fim != NULL)
			return indice;
	}
	printf ("Senha não está na Fila!\n");
	return -1;
}

/*void ordenaElem (FILA * f, REGISTRO   reg)
{
	REGISTRO	elem;
	
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	if (novo){
		novo->PROX = reg;
		novo->PROX = NULL;
		if (*f == NULL)
			*f = novo;
		else{
			if (elem.tipoatend  == 'p'){
				if ((*f)->chave != 'p'){
					novo->PROX *f;
					*f = novo;
				}
				else{
					PONT = *f;
					while (PONT->PROX && aux->PROX->elem.tipoatend)
						aux = aux->PROX;
					novo->PROX = aux->PROX;
					aux->PROX = novo;
				}	
			}
			else{
				PONT = *f;
				while(aux->PROX)
					aux = aux->PROX;
				aux->PROX = novo;
			}			
		}
	}
	else
		printf ("Malloc devolveu NULL!\n");
}*/

int main (){
	
	FILA      * F;
	REGISTRO 	r;
	char      opc;
  	
	setlocale (LC_ALL, "portuguese");
	
	F = (FILA *) malloc (sizeof (FILA));
    if (F == NULL){
    	printf ("Malloc devolveu NULL!\n");
    	getch();
    exit (EXIT_FAILURE);
    }        

  inicializarfila (F);
	
  while (opc != '8')
  {
  	printf ("\n=====================================");
  	printf ("\n       ATENDIMENTO AO PÚBLICO   		");
  	printf ("\n=====================================");
  	printf ("\n 1 = Definir Número de Atendentes	");
  	printf ("\n 2 = Senha Atendimento				");
  	printf ("\n 3 = Chamar o Próximo da Fila		");
  	printf ("\n 4 = Mostrar Fila   		    		");
  	printf ("\n 5 = Ordem de Atendimento			");
  	printf ("\n 6 = Tamanho da Fila 				");
  	printf ("\n 7 = Reinicializar Fila	    		");
  	printf ("\n 8 = Sair         	  	    		");
  	printf ("\n=====================================");
  	printf ("\n Escolha: "); fflush (stdin); opc = getche();
  	system ("cls");
   	switch (opc) 
	{
		case '1' : inserirAtend		(F, r);						break;
		case '2' : inserirNaFila   	(F, r);						break;
		case '3' : 	
		  system ("cls");
		  if (excluirDaFila			(F, &r) == true)
      		printf ("\nSenha chamada: [%i]", r.chave);
      	  else
      	  	printf ("\nNão foi possível chamar a senha.");  	break;
   		case '4' : exibirfila		(F, r);						break;
//   		case '5' : ordenaElem    (F, r);					break;
   		case '6' : if (estaVazia(F) == false)
	               	  	printf ("\n\nTamanho da fila = %i",tamanho(F));
	               else printf ("\n\nFILA VAZIA!");				break;
   		case '7' : reinicializarFila(F);
		   				printf ("\n\nFILA REINICIALIZADA!");	break;
     	case '8' : exit(0); 									break;
		default  : msgErro();									break;
    }
	getch();
  }
  return (0);
}
