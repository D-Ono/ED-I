#include <stdio.h>
#include <stdlib.h>
#include "Exercicio02.c"

int Menu01(void) {
int opcao;

  system("CLS");		// limpeza da tela
  printf("1 - Inserir Um Funcionario; \n");
  printf("2 - Remover Um Funcionario; \n");
  printf("3 - Exibir Todos os Funcionarios; \n");
  printf("4 - Sair; ");

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

int main (){
    LISTA l;
    int flag=0, elem, pos;
    FLVazia(&l);
    int op;
 do {
	op = Menu01();
	system("cls");
    switch(op)  {
	case 1:
        Insere(&l, &flag);
        if (flag == 1){
            printf(" \n\n\t Funcionario Inserido com Sucesso \n\n");
        }
        system("Pause");
        break;

	case 2:
	    pos = Pesquisa(l);
        Retira(&l, pos, &flag);
        if (flag == 1){
            printf(" \n\n\t Funcionario Retirado com Sucesso \n\n");
        }
        system("pause");
        break;

	case 3:
        ImprimiLista(l);
		system("Pause");
		break;

    case 4:
        break;
	}	//switch

  } while ( Continua() );

    return;
}
