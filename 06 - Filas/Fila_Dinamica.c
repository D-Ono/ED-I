#include <stdio.h>
#include <stdlib.h>

//tipoelem = int
struct noFila 
{
	int elemento;
	struct noFila *prox;
};

// Descritor
typedef struct 
{
	struct noFila *inicio;
	struct noFila *fim;
} Fila;

void inicializacao(Fila *fila)
{
	fila->inicio = NULL;  
	fila->fim = NULL; 
}

short vazia(Fila *fila) {	// verifica se a fila est� vazia
	if (fila->inicio == NULL) 
		return 1;
	else 
		return 0;
}

//o c�digo da fun��o fila cheia pode ser inserido na fun��o inserir
short cheia(Fila *fila) {     // a fila estar� cheia quando n�o houver mem�ria para ser alocada 
	struct noFila *novoNo;
	novoNo = malloc(sizeof(struct noFila)); 
	//malloc retorna null quando n�o houver mem�ria dispon�vel para aloca��o ou quando ocorrer algum erro durante a aloca��o - execu��o do malloc
   	if (novoNo == NULL) 
	   return 1; 
	else 
		return 0;
}

void inserir(Fila *fila,  int elemento) {
	struct noFila *novoNo;
	novoNo = malloc(sizeof(struct noFila)); 
	if (novoNo == NULL)  
	printf("Fila Cheia!!!");
	else {
		novoNo->elemento = elemento;
		novoNo->prox = NULL;
		if (vazia(fila))
			fila->inicio = novoNo;
		else 
		fila->fim->prox = novoNo;
	fila->fim = novoNo;
	}
}

void remover(Fila *fila, int *elemento)
{
  	struct noFila  *aux;
	if (vazia(fila)) 
		 printf("Fila Vazia - N�o h� elementos para remover!!!");	
	else{
		aux = fila->inicio;
		*elemento = aux->elemento; 
		fila->inicio = fila->inicio->prox;
		free(aux);
	}
}

void obterIncioFila(Fila *fila, int *elemento)
{
	if (vazia(fila)) 
		printf("Fila Vazia - N�o h� elementos na fila!!!");	
	else 
		*elemento = fila->inicio->elemento;
}
// Retorna o elemento que est� no inicio da fila


int main(void)
{
	int elemIni, elemRem;
	struct noFila *i = NULL;
	Fila F1;
	inicializacao(&F1);
	if(vazia(&F1))
		printf("\nFila vazia!");
		
	//Inserindo valores na fila
	inserir(&F1, 1);
	inserir(&F1, 1);
	inserir(&F1, 2);
	inserir(&F1, 3);
	inserir(&F1, 5);
	inserir(&F1, 8);
	inserir(&F1, 13);
	inserir(&F1, 21);
	inserir(&F1, 34);
	inserir(&F1, 55);
	printf("\nInseri 10 elementos!");
	
	//Imprimindo a fila
	printf("\nInicio (valor elem): %d", F1.inicio->elemento);
	printf("\nFim (valor elem): %d\n", F1.fim->elemento);
	for(i=F1.inicio ; i!=NULL ; i=i->prox)
		printf("%d ", i->elemento);
		
	obterIncioFila(&F1, &elemIni);
	printf("\nElemento do inicio: %d", elemIni);
	
	remover(&F1, &elemRem);
	printf("\nRemovi o elemento: %d", elemRem);
	remover(&F1, &elemRem);
	printf("\nRemovi o elemento: %d", elemRem);
	remover(&F1, &elemRem);
	printf("\nRemovi o elemento: %d", elemRem);
	remover(&F1, &elemRem);
	printf("\nRemovi o elemento: %d", elemRem);
	
	inserir(&F1, 89);
	
	//Imprimindo a fila
	printf("\nInicio (valor elem): %d", F1.inicio->elemento);
	printf("\nFim (valor elem): %d\n", F1.fim->elemento);
	for(i=F1.inicio ; i!=NULL ; i=i->prox)
		printf("%d ", i->elemento);
	
	return(0);
}
