#include "TAD_Pilha.c"
#include "ListaDin.c"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct prec{
    char elem;
    int ordem;
};

bool precedencia(){
    struct prec op[7];
    op[0].elem = ')';
    op[0].ordem = 1;
    op[1].elem = '(';
    op[1].ordem = 2;
    op[2].elem = '+';
    op[2].ordem = 3;
    op[3].elem = '-';
    op[3].ordem = 3;
    op[4].elem = '*';
    op[4].ordem = 4;
    op[5].elem = '/';
    op[5].ordem = 4;
    op[6].elem = '^'
    op[6].ordem = 5;

}

void TrasnformaEmPosFixada(struct Lista *L, char *s){
    int tam = strlen(s), i= 0;
    char op;

    while(i<tam){
        if(isspace(*(s+i))){
            i++;
            continue;
        }
        if ((isdigit(*(s+i))) || isalpha(*(s+i))){
            ///LISTA RECEBE *(s+i)
        }
        else{
            op = *(s+i);
            while(precedencia()){
                ///POP
                ///LISTA RECEBE Pop
            }
        }
        i++;
    }

}

int main(void){
    struct pilha P1;



return;
}
