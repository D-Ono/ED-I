#include "TAD_Pilha.h"
#include <stdio.h>
#include <stdlib.h>

//Inicializa a pilha
void inicializaPilha(struct pilha *P){
    P->topo=NULL;
}

//Verifica se a pilha está vazia
short pilhaVazia(struct pilha *P){
    if (P->topo == NULL)
        return(1); //Está vazia
    return(0); //Não está vazia
}

//Insere o elemento no topo da pilha
void push(struct pilha *P, int elem){
    struct no *novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->elem = elem;
    novoNo->prox = P->topo;
    P->topo = novoNo;
    return;
}

//Remove o elemento no topo da pilha
short pop(struct pilha *P){
    struct no *ptr = P->topo;
    if(pilhaVazia(P)) //Pilha vazia
        return(0);
    ptr = P->topo;
    P->topo = ptr->prox;
    free(ptr);
    return(1); //Removeu com sucesso
}

//Imprime os valores dos elementos contidos na pilha
void imprimePilha(struct pilha P){
    struct no *ptr; // variável auxiliar para percorrer a lista
    printf("Valores dentro da Pilha\n");
    printf("Topo -> ");
    for(ptr = P.topo; ptr!=NULL ; ptr = ptr->prox)
        printf("%d ", ptr->elem);
    return;
}
