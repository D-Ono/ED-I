#include "L_Est_Encadeada.c"
#include <stdio.h>
#include <stdlib.h>


int Menu01(void) {
int opcao;

  system("CLS");		// limpeza da tela
  printf("1 - Inserir Um Elemento; \n");
  printf("2 - Remover Um Elemento; \n");
  printf("3 - Imprimir a Lista; \n");
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

int main (){
    LISTA l;
    int flag=0, elemretirado, elem, pos;
    FLVazia(&l);
    int op;
 do {
	op = Menu01();
	system("cls");
    switch(op)  {
	case 1:
	    printf("Digite o elemento que deseja Inserir: ");
        scanf("%d", &elem);
        Insere(&l, elem, &flag);

        if (flag == 1){
            printf(" \n\n\t Elemento Inserido com Sucesso \n\n");
        }
        system("Pause");
        break;

	case 2:
	    printf("Digite a posicao do elemento que deseja retirar: ");
        scanf("%d", &pos);
        Retira(&l, &elemretirado, pos, &flag);
        if (flag == 1){
            printf(" \n\n\t Elemento Retirado com Sucesso \n\n");
        }
        system("pause");
        break;

	case 3:
        ImprimiLista(l);
		system("Pause");
		break;

	case 5:
		 break;
	}	//switch

  } while ( Continua() );

    return;
}
