#include "L_Est_Encadeada.c"

int main (){
    LISTA l;
    int flag=0, elemretirado;

    FLVazia(&l);
    Insere(&l, 10, &flag);
    Insere(&l, 15, &flag);
    Insere(&l, 20, &flag);
    ImprimiLista(l);
    Retira(&l, &elemretirado, 1, &flag);
    ImprimiLista(l);

    return;
}
