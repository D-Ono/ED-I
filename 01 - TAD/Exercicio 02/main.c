#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estacionamento.c"

int Menu01(void) {
int opcao;

  system("CLS");		// limpeza da tela
  printf("1 - Pesquisar Carro; \n");
  printf("2 - Inserir Carro no Estacionamento; \n");
  printf("3 - Remover Carro do Estacionamento; \n");
  printf("5 - Sair; ");

  printf("\n\n Escolha a opcao desejada : ");
  scanf("%d", &opcao);

  return(opcao);
}


short Continua(void) {
int ch;

  do {
		system("cls");
        printf("\n\n\n      Voce deseja executar outra funcao? [S,N] : ");
		ch = getchar();
		ch= toupper(ch);
  }
  while( (ch != 'S') && (ch != 'N') );

  if(ch == 'S') return(1);
  else return(0);
}


int main(void){
    carro car[200];
    char placa[8];
    int MAX=0, op;
 do {
	op = Menu01();
	system("cls");
    switch(op)  {
	case 1:
	    printf("Digite a Placa que deseja Pesquisar: ");
        scanf("%s", &placa);
        Consultar(car, &placa, MAX);
        system("Pause");
        break;

	case 2:
	    printf("Digite a Placa do Carro que deseja Inserir: ");
        scanf("%s", &placa);
        Insercao(car, &placa, &MAX);
        system("pause");
        break;

	case 3:
	    printf("Digite a Placa que deseja Remover: ");
        scanf("%s", &placa);
        Remocao(car, &placa, &MAX);
		system("Pause");
		break;
	case 5:
		 break;
	}	//switch

  } while ( Continua() );

    return;
}

