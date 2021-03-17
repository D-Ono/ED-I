#include <stdio.h>
#include <stdlib.h>
#include "ListaDin.h"

void inicializaLista(struct Lista *l){
    l->priElem = NULL;
    l->ultElem = NULL;
}

void insereNo(int elem, struct Lista *list){
    struct nos *novoNo;
    novoNo = (struct nos*)malloc(sizeof(struct nos));
    novoNo->elem = elem;
    novoNo->prox = NULL;
    if (list->priElem == NULL){
        list->ultElem = novoNo;
    }
    else novoNo->prox = list->priElem;
        list->priElem = novoNo;
}

void imprime(struct Lista *list){
    struct nos *aux;

    aux = list->priElem;
    while(aux != NULL){
        printf("\n Elemento = %d", aux->elem);
        aux = aux->prox; //vai para o próximo
    }
}

short listaVazia(struct Lista *list){
    if (list->priElem == NULL)
        return 1;
    return 0;
}

int tamanho(struct Lista *list){
    struct nos *p= list->priElem;
    int tam =0;

    while(p!=NULL){
        tam++;
        p =p->prox;
    }
    return(tam);
}


void EliminaPrimeiroNo(struct Lista *l){
    struct nos *aux;
    aux = l->priElem;
    l->priElem = aux->prox;
    free(aux);
    return;
}

