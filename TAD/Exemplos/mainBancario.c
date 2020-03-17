#include <stdio.h>
#include <stdlib.h>
#include "ContaBancaria.c"
#include <conio.h>


int main (void){
    ContaBancaria conta1;
    Inicializa(&conta1, 918556, 300.00);
    printf("\nAntes da movimentacao:\n ");
    Imprime(conta1);
    Deposito(&conta1, 50.00);
    Saque(&conta1, 70.00);
    printf("\nDepois da movimentacao:\n ");
    Imprime (conta1);
    getch();

    return;
}
