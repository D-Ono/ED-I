#include <stdio.h>
#include <stdlib.h>

struct No{
    int Elemento;
    struct No *Ant;
    struct No *Prox;
};

struct Lista{
    struct No *priElem;
    struct No *ultElem;
};

void inicializaLista(struct Lista *list){
    list->priElem = NULL;
    list->ultElem = NULL;
}


/// inserção de um novo elemento no início da lista
void insereNo(int elem, struct Lista *List){
    struct No *novoNo;
    novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->Elemento = elem;
    novoNo->Prox = novoNo->Ant = NULL;
    if (List->priElem == NULL){
        List->ultElem = novoNo;
    }
    else{//configura o atributo Ant do priElem para referenciar o novoNo, somente se o mesmo existir (lista não vazia)
        novoNo->Prox = List->priElem;
        List->priElem->Ant = novoNo;
    }
    List->priElem = novoNo;
}

void insereNoFinal(int elem, struct Lista *List){
    struct No *novoNo;

    novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->Elemento = elem;
    novoNo->Prox = novoNo->Ant = NULL;
    if (List->priElem == NULL){
        List->ultElem = novoNo;
    }
    else{
        novoNo->Ant = List->ultElem;
        List->ultElem->Prox = novoNo;
    }
    List->ultElem = novoNo;
}

void removeNo(int elem, struct Lista *List){
    struct No *p = List->priElem;

    while (p!=NULL && p->Elemento !=elem){
        p = p->Prox;
    }

    if(p==NULL)
        return 0;

    if (p->Ant == NULL){
        List->priElem = p->Prox;
        List->priElem->Ant = NULL;
    }
    else if (p == List->ultElem){
            List->ultElem= p->Ant;
            List->ultElem->Prox =NULL;
        }
        else{
            p->Ant->Prox = p->Prox;
            p->Prox->Ant = p->Ant;
        }
    free(p);

    return;
}

//Imprime os valores dos elementos contidos na lista ao contrário
void imprimeListaInverso(struct Lista *List){
    struct No *p;
    for (p = List->ultElem; p!=NULL; p=p->Ant)
        printf("\n Elemento = %d", p->Elemento);
}

void imprimeLista(struct Lista l){
    struct No *aux;
    for (aux=l.priElem; aux !=NULL; aux = aux->Prox)
        printf("\n %d ", aux->Elemento);
}

int main (){
    struct Lista l;

    inicializaLista(&l);
    insereNo(10, &l);
    insereNo(12, &l);
    insereNo(14, &l);
    insereNo(16, &l);
    imprimeListaInverso(&l);
    printf("\n\n");
    imprimeLista(l);
    return;
}
