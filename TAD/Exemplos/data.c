#include <stdio.h>
#include "data.h"

void inicializaData(data *d){
    printf("Escreva o Dia: ");
    scanf("%d",&d->dia);
    printf("Escreva o Mes: ");
    scanf("%d",&d->mes);
    printf("Escreva o Ano: ");
    scanf("%d",&d->ano);
}
