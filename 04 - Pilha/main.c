#include "TAD_Pilha.c"

int main(void){
    struct pilha P1;
    inicializaPilha(&P1);
    push(&P1, 10);
    push(&P1, 3);
    push(&P1, 8);
    push(&P1, 10);
    push(&P1, 5);
    imprimePilha(P1);
return;
}
