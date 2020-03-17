#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estacionamento.h"

void Consultar(carro *car, char *placa, int MAX){
    int aux =0;

    for (int i=0; i<MAX; i++){
        if (strcmp((car+i)->placa, placa) == 0){
            printf("\n\n\t Placa: %s ",car[i].placa);
            printf("\n\t Cor: %s",car[i].color);
            printf("\n\t Marca/Modelo: %s \n\n",car[i].MarcaModelo);
            aux = 1;
        }
    }
    if (aux ==0)
            printf("\n\n Carro Nao encontrado!!! \n");
    return 0;
}


int Pesquisa(carro *car, char *placa, int MAX){
    for (int i=0; i<MAX; i++){
        if (strcmp((car+i)->placa, placa)==0){
            return i;
        }
    }
    return -1;
}

void Insercao(carro *car, char *placa, int *MAX){

    int i= *MAX;
    char str[15];
    if (MAX == 200){
        printf("O Estacionamento esta cheio!!!");
        exit(0);
    }
    if (Pesquisa(car, placa, *MAX)!= -1){
        printf("Carro ja esta no estacionamento!!!");
        exit(0);
    }

    printf("Qual a cor do Automovel: ");
    scanf("%s", &car[i].color);
    printf("Qual a Marca do Automovel: ");
    scanf("%s", &car[i].MarcaModelo);
    printf("Qual o Modelo do Automovel: ");
    scanf("%s", &str);
    strcat(car[i].MarcaModelo, str);
    strcpy((car+i)->placa, placa);
    *MAX = *MAX + 1;

    return;
}

void Remocao(carro *car, char *placa, int *MAX){
    int i = Pesquisa(car, placa, *MAX);
    int j, k;
    if ( i == -1){
        printf("Carro não esta no estacionamento!!!");
        return;
    }
    do{
        printf("Placa: %s",car[i].placa);
        printf("Cor: %s",car[i].color);
        printf("Marca/Modelo: %s",car[i].MarcaModelo);
        printf("Deseja remover o Carro do Estacionamento? \n Sim[1] Nao[0]");
        getchar();
        scanf("%d", &j);
    }while (j!=1  && j!=0);

    k = *MAX-1;
    if (j==1){
        strcpy((car+i)->placa, (car+k)->placa);
        strcpy((car+i)->color, (car+k)->color);
        strcpy((car+i)->MarcaModelo, (car+k)->MarcaModelo);
        *MAX = *MAX-1;
        printf("Removido Com Sucesso.");
    }
    return;
}

