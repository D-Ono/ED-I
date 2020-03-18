#include <stdio.h>
#include <stdlib.h>
#include "Exercicio02.h"

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

void ImprimiLista(LISTA l){
    if(l.prim == -1){
        printf("Nenhum Funcionario Inscrito");
        return;
    }
    int i = l.prim;
    printf("Nome: %s \n", l.A[i].nome);
    printf("Matricula: %d \n", l.A[i].matricula);
    printf("Departamento: %s \n", l.A[i].departamento);
    printf("Salario: %.2f \n", l.A[i].salario);
    while (l.A[i].prox != -1){
        i = l.A[i].prox;
        printf("\n\n");
        printf("Nome: %s \n", l.A[i].nome);
        printf("Matricula: %d \n", l.A[i].matricula);
        printf("Departamento: %s \n", l.A[i].departamento);
        printf("Salario: %.2f \n", l.A[i].salario);
    }
}

void Retira(LISTA *l, int pos, int *flag){
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
    *flag = 1;
    return;
}

void Insere(LISTA *l, int *flag){
    int i=l->prim;

    if (l->disp == -1){     ///LISTA CHEIA
        *flag = 0;
        return;
    }

    if (i == -1)            ///PRIMEIRO ELEMENTO
        l->prim = l->disp;
    else{
        while(l->A[i].prox != -1)
            i= l->A[i].prox;
        l->A[i].prox = l->disp;
    }
    i = l->disp;
    l->disp = l->A[i].prox;
    printf("Qual o Nome do Funcionario: ");
    scanf("%s", &l->A[i].nome);
    printf("Qual a Matricula do Funcionario: ");
    scanf("%d", &l->A[i].matricula);
    printf("Qual o Salario do Funcionario: ");
    scanf("%f", &l->A[i].salario);
    printf("Qual o Departamento do Funcionario: ");
    scanf("%s", &l->A[i].departamento);
    l->A[i].prox = -1;
    *flag = 1;
    return;
}

int Pesquisa(LISTA l){
    int op, matr;
    int i=l.prim;
    char nome[15];

    if ( i == -1)
        return -1;
    system("CLS");		// limpeza da tela
    printf("1 - Remover por Nome; \n");
    printf("2 - Remover por Matricula; \n");

    printf("\n\n Escolha a opcao desejada : ");
    scanf("%d", &op);

    system("CLS");
    switch(op)  {
	case 1:
        printf("\n\n\t Digite o Nome do Funcionario a ser Removido: ");
        scanf("%s", &nome);
        while(strcmp(nome, l.A[i].nome)!=0)
            i= l.A[i].prox;
        if (l.A[i].prox == -1)
            return -1;
        return i;

	case 2:
        printf("\n\n\t Digite a Matricula do Funcionario a ser Removido: ");
        scanf("%d", &matr);
        while(matr != l.A[i].matricula)
            i= l.A[i].prox;
        if (l.A[i].prox == -1)
            return -1;
        return i;
    }
}
