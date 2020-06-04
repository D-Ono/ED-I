#include <stdio.h>
#include <stdlib.h>
#include "ListaDin.h"


void inicializaLista(struct Lista *list){ ​//Inicialização da Lista
    list->priElem = ​NULL​;
    list->ultElem = ​NULL​;
}

void insereNo(int elem, struct Lista *list){
    struct no *novoNo;
    novoNo = (struct no*) malloc (​sizeof​(struct no));
    novoNo->elem = elem;
    novoNo->prox = NULL;
    if (list->priElem == NULL){
        list->ultElem = novoNo;​
    }
    else novoNo->prox = list->priElem;
        list->priElem = novoNo;
}

void imprime(struct Lista *list){
    struct no *aux; ​// variável auxiliar para percorrer a lista
    aux = list->priElem;
    while(aux != NULL){
        printf(​"\n Elemento = %d"​, aux->elem);
        aux = aux->prox; //vai para o próximo
    }
}

short ​listaVazia (struct Lista *list){
    ​if​ (list->priElem == ​NULL​)
        return​ 1; //verdadeiro
    ​return​ 0; //falso
}

int ​tamanho(struct Lista *list){
    struct ​no *p = list->priElem;
    int ​tam=0;
    while ​(p!=​NULL​){
        tam++;
        p=p->prox;
    }
    return(tam);
}


void EliminaPrimeiroNo(struct Lista *l){
    struct no *aux;
    aux = l->priElem;
    l->priElem = aux->prox;
    free(aux);
    return;
}

