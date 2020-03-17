#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "garcom.c"
#include "menu.h"


int Menu01(void) {
int opcao;

  system("CLS");		// limpeza da tela
  printf("1 - Pesquisar Candidato; \n");
  printf("2 - Inserir Candidato; \n");
  printf("3 - Remover Candidato; \n");
  printf("4 - Alterar Dados Do Candidato; \n");
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


void MenuPrincipal(void){
    garcom cand[200];
    char rg[15];
    int MAX=0, op;
 do {
	op = Menu01();
	system("cls");
    switch(op)  {
	case 1:
	    printf("Digite o RG que deseja Pesquisar: ");
        scanf("%s", &rg);
        Consultar(cand, &rg, MAX);
        system("Pause");
        break;

	case 2:
	    printf("Digite o RG do Candidato que deseja Inserir: ");
        scanf("%s", &rg);
        Insercao(cand, &rg, &MAX);
        system("pause");
        break;

	case 3:
	    printf("Digite o RG que deseja Remover: ");
        scanf("%s", &rg);
        Remocao(cand, &rg, &MAX);
		system("Pause");
		break;

	case 4:
	    printf("Digite o RG do Candidato que Deseja Alterar os Dados: ");
        scanf("%s", &rg);
        Alterar(cand, &rg, MAX);
        system("pause");
		break;
	case 5:
		 break;
	}	//switch

  } while ( Continua() );

    return;
}
