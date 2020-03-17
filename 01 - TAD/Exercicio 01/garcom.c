#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "garcom.h"

void Consultar(garcom *cand, char *rg, int MAX){
    int aux =0;

    for (int i=0; i<MAX; i++){
        if (strcmp((cand+i)->rg, rg) == 0){
            printf("\n\n\t Nome: %s \n",cand[i].nome);
            printf("\t Endereco: %s \n",cand[i].ende);
            printf("\t Telefone: %s \n",cand[i].tele);
            printf("\t RG: %s \n\n",cand[i].rg);
            aux = 1;
        }
    }
    if (aux ==0)
            printf("\n\n Candidato Nao encontrado!!! \n");
    return 0;
}


int Pesquisa(garcom *cand, char *rg, int MAX){

    for (int i=0; i<MAX; i++){
        if (strcmp((cand+i)->rg, rg) == 0){
            return i;
        }
    }
    return -1;
}

void Insercao(garcom *cand, char *rg, int *MAX){

    int i= *MAX;
    if (i == 200){
        printf("O numero de candidatos esta cheio!!!");
        return;
    }
    if (Pesquisa(cand, rg, *MAX)!= -1){
        printf("Candidato ja inscrito!!!");
        return;
    }

    printf("Qual o nome do Candidato: ");
    scanf("%s", &cand[i].nome);
    printf("Qual o endereco do Candidato: ");
    scanf("%s", &cand[i].ende);
    printf("Qual o Telefone do Candidato: ");
    scanf("%s", &cand[i].tele);
    strcpy((cand+i)->rg, rg);
    *MAX = *MAX + 1;

    return;
}

void Remocao(garcom *cand, char *rg, int *MAX){
    int i = Pesquisa(cand, rg, *MAX);
    int j, k;
    if ( i == -1){
        printf("Candidato não inscrito!!!");
        return;
    }
    do{
        printf("\n\n\t Nome: %s \n",cand[i].nome);
        printf("\t Endereco: %s \n",cand[i].ende);
        printf("\t Telefone: %s \n",cand[i].tele);
        printf("\t RG: %s \n",cand[i].rg);
        printf("\n\t\t Deseja remover o Candidato? \n Sim[1] Nao[0]");
        getchar();
        scanf("%d", &j);
    }while (j!=1  && j!=0);

    k = *MAX-1;
    if (j==1){
        strcpy((cand+i)->ende, (cand+k)->ende);
        strcpy((cand+i)->nome, (cand+k)->nome);
        strcpy((cand+i)->rg, (cand+k)->rg);
        strcpy((cand+i)->tele, (cand+k)->tele);

        *MAX = *MAX-1;
        printf("Removido Com Sucesso.");
    }
    return;
}

void Alterar(garcom *cand, char *rg, int MAX){
    int i = Pesquisa(cand, rg, MAX);
    int j;
    if ( i == -1){
        printf("Candidato não inscrito!!!");
       return;
    }

    printf("Nome: %s \n", (*(cand+i)).nome);      /// (*(p+1)).nome = (p+1)->nome.
    printf("Endereco: %s \n",(cand+i)->ende);
    printf("Telefone: %s \n",(cand+i)->tele);
    printf("RG: %s \n",(cand+i)->rg);


    do{
        printf("\n Deseja alterar o nome do Candidato? \n Sim[1] Nao[0]: ");
        getchar();
        scanf("%d", &j);
    }while (j!=1  && j!=0);
    if (j==1){
        printf("Novo Nome: ");
        scanf("%s", &cand[i].nome);
        printf(" \n Alterado com sucesso!!! \n\n");
    }
        do{
        printf("Deseja alterar o endereco do Candidato? \n Sim[1] Nao[0]: ");
        getchar();
        scanf("%d", &j);
    }while (j!=1  && j!=0);
    if (j==1){
        printf("Novo Endereco: ");
        scanf("%s", &cand[i].ende);
        printf(" \n Alterado com sucesso!!! \n\n");
    }
        do{
        printf("Deseja alterar o telefone do Candidato? \n Sim[1] Nao[0]: ");
        getchar();
        scanf("%d", &j);
    }while (j!=1  && j!=0);
    if (j==1){
        printf("Novo Telefone: ");
        scanf("%s", &cand[i].tele);
        printf(" \n Alterado com sucesso!!! \n\n");
    }
    return;
}
