#include <stdio.h>
#include <stdlib.h>
#include "L_Est_Encadeada.h"

void FLVazia(LISTA *l){

    int i = 0;
    if (l != NULL){
        l->disp = 0;
        l->prim = -1;
        for(i=0 ; i<MAX-1 ; i++) //Inicializando o prox de cada elemento
            l->A[i].prox=i+1;
        l->A[i].prox= -1;
    }
    return;
}

void Vazia (LISTA l, int *flag){
    if (l.prim == -1)
        *flag = 1;
    else
        *flag = 0;

    return;
}

void ImprimiLista(LISTA l){
    if(l.prim == -1){
        printf("Lista Vazia");
        return;
    }
    int i = l.prim;
    printf("%d \n", l.A[i].elem);
    while (l.A[i].prox != -1){
        i = l.A[i].prox;
        printf("%d \n", l.A[i].elem);
    }
}

void Retira(LISTA *l, int *elem, int pos, int *flag){
    int i=l->prim, k;
    if ( i == -1){
        *flag = 0;
        return;
    }
    while(l->A[i].prox != pos)
        i= l->A[i].prox;
    k =l->A[i].prox;
    l->A[i].prox =l->A[k].prox;
    l->A[k].prox = l->disp;
    l->disp = k;
    *elem = l->A[k].elem;
    *flag = 1;
    return;
}

void Insere(LISTA *l, int elem, int *flag){
    int i=l->prim;

    if (l->disp == -1){
        *flag = 0;
        return;
    }

    if (i == -1){
        l->prim = l->disp;
        }
    else{
        while(l->A[i].prox != -1)
            i= l->A[i].prox;
        l->A[i].prox = l->disp;
    }

    i = l->disp;
    l->disp = l->A[i].prox;
    l->A[i].elem = elem;
    l->A[i].prox = -1;
    *flag = 1;
    return;
}
