#include <stdio.h>
#include <stdlib.h>
#include "LEstaticaSequencial.c"

int main (){

    struct lista L;

    InicializaLista(&L);
    Inserir(&L, 100, 0);
    Inserir(&L, 50, 1);
    Inserir(&L, 25, 2);
    Inserir(&L, 12, 3);
    Inserir(&L, 6, 4);
    Remover(&L, 3);
    ImprimirRecursivo(&L, 0);


    return;
}
