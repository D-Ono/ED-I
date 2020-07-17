#include <stdio.h>
#include "LEstaticaSequencial.h"

void InicializaLista(struct lista *L){

    for (int i=0; i< MAX; i++){
        L->elem[i] =   0;
    }
    L->qelem =0;
}

void Inserir(struct lista *L, int elem, int i){     /// INSERE ELEMENTO NA POSIÇÂO i
    L->elem[i] = elem;
    L->qelem = L->qelem +1;
    return;
}

void InserirFinal(struct lista *L, int elem){     /// INSERE ELEMENTO NO FINAL DA LISTA
    L->elem[L->qelem] = elem;
    L->qelem = L->qelem +1;
    return;
}

void Remover(struct lista *L, int pos){             /// REMOVE ELEMENTO NA POSICAO pos
    int i;
    for (i=pos; i<= L->qelem; i++){
        L->elem[i] = L->elem[i+1];
    }
    L->qelem = L->qelem-1;
    return;
}

void RemoverFinal(struct lista *L){             /// REMOVE ELEMENTO NO FINAL DA LISTA
    int elem = L->elem[--(L->qelem)];
    return elem;
}

int ImprimirRecursivo(struct lista *L, int i){
        printf("%d \n", L->elem[i] );
        if (i==(L->qelem-1)){
            return 0;
        }
        else {
            return  ImprimirRecursivo(L, i+1);
        }
}




