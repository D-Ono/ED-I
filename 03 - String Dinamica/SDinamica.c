#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    char elem;
    struct no *prox;
};

struct SDin{
    struct no *primElem;
};

void inicializaString (struct SDin *StrDin){
    StrDin->primElem = NULL;
    return;
}

void reiniciaString (struct SDin *StrDin){
    struct no *aux = StrDin->primElem;
    struct no *pro = StrDin->primElem;
    while(aux!=NULL){
        pro = pro->prox;
        free(aux);
        aux = pro;
    }
    StrDin->primElem = NULL;
    return;
}

void imprimirString(struct SDin StrDin){
    struct no *aux = StrDin.primElem;

    while (aux!= NULL){
        printf("%c", aux->elem);
        aux = aux->prox;
    }
    return;
}

int tamString(struct SDin *StrDin){
    struct no *aux = StrDin->primElem;
    int tam =0;

    while (aux!= NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

void insereChar (struct SDin *StrDin, char c){
    struct no *aux = StrDin->primElem;
    struct no *novoNo;

    novoNo = (struct no*)malloc(sizeof(struct no));
    if (aux == NULL){
        aux= novoNo;
        StrDin->primElem = novoNo;
    }
    else{
        while (aux->prox !=NULL){
            aux = aux->prox;
        }
        aux->prox = novoNo;
    }

    novoNo->prox = NULL;
    novoNo->elem=c;
    return;
}

void insereCharPos(struct SDin *str, char c, int start){
    struct no *aux = str->primElem;
    struct no *novoNo, *aux2;
    int cont=1;

    novoNo = (struct no*)malloc(sizeof(struct no));

    while(aux!= NULL && cont!=start){
        aux2 = aux;
        aux = aux->prox;
        cont++;
    }
    if (aux == NULL)
        printf("A %d posicao esta alem da String... ", start);

    aux2->prox = novoNo;
    novoNo->prox = aux;
    novoNo->elem = c;

    return;
}

void copiaString (struct SDin *StrDin, struct SDin *recebeCopy){
    struct no *aux = StrDin->primElem;

    while(aux!=NULL){
        insereChar(recebeCopy, aux->elem);
        aux = aux->prox;
    }

    return;
}

void concatenaString(struct SDin *s1,struct SDin *s2, struct SDin *s3){
    struct no *aux1= s1->primElem;
    struct no *aux2 = s2->primElem;

    while(aux1!=NULL && aux2!=NULL){
        insereChar(s3, aux1->elem);
        insereChar(s3, aux2->elem);
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    while(aux1!=NULL){
        insereChar(s3, aux1->elem);
        aux1 = aux1->prox;
    }
    while(aux2!=NULL){
        insereChar(s3, aux2->elem);
        aux2 = aux2->prox;
    }
    return;
}

int verificatam(struct SDin *str1, struct SDin *str2){
    int tam1, tam2, aux;

    tam1 = tamString(str1);
    tam2 = tamString(str2);

    aux = tam1 < tam2? 1 :0;
    return aux;
}

int stringIguais(struct SDin *s1, struct SDin *s2){
    struct no *aux= s1->primElem;
    struct no *aux1= s2->primElem;

    while(aux!=NULL && aux1!=NULL){
        if(aux1->elem != aux->elem)
            return 0;
        aux1= aux1->prox;
        aux= aux->prox;
    }
    if(aux1!=NULL || aux!=NULL)
        return 0;
    return 1;
}

void removeQuantChar(struct SDin *str, int num, int start){
    int cont =1;
    struct no *aux = str->primElem;
    struct no *aux1, *aux2;

    while(aux!= NULL && cont!=start){
        aux2 = aux;
        aux = aux->prox;
        cont++;
    }
    if (aux == NULL)
        printf("A %d posicao esta alem da String... ", start);
    cont=0;
    aux1 = aux;
    while(cont < num){
        aux1= aux1->prox;
        free(aux);
        aux = aux1;
        cont++;
    }
    aux2->prox = aux;
    return;
}

void insereSubString(struct SDin *str, char *v, int start){
    struct no *aux = str->primElem;
    int cont=1, i=0;

    while (*(v+i) != '\0'){
        insereCharPos(str, *(v+i), start);
        start++;
        i++;
    }

    return;
}

void procuraSubString (struct SDin *str, int *local, char *padrao){
    struct no *aux= str->primElem;
    int i=0, pos =1;
    *local =1;

    while (aux!=NULL && *(padrao+i) != '\0'){
        if(aux->elem == *(padrao+i)){
            if (i == 0){
                *local = pos;
            }
            i++;
            aux = aux->prox;
        }
        else{
            *local = 0;
            i=0;
            aux = aux->prox;
        }
        pos++;
    }

    return;
}

int main (){
    struct SDin str, str1, str2;
    char s[]="NoNI";
    char d[]="Nov";
    int loc;

    inicializaString(&str);
    inicializaString(&str1);
    inicializaString(&str2);
    insereChar(&str, 'D');
    insereChar(&str, 'a');
    insereChar(&str, 'v');
    insereChar(&str, 'i');
    insereChar(&str, 'D');
    insereSubString(&str, &s, 3);
    imprimirString(str);
    procuraSubString(&str, &loc, &d);
    if (loc == 0)
        printf("Padrao nao encontrado!!! ");
    else
        printf(" \n Padrao comeca no %d \n\n", loc);
    copiaString(&str, &str1);
    printf("\n");
    imprimirString(str1);
    printf("\n");
    if(stringIguais(&str, &str1))
        printf("Iguais \n\n\n");
    concatenaString(&str, &str1, &str2);
    removeQuantChar(&str2, 3, 2);
    imprimirString(str2);
    insereChar(&str1, 'a');
    if(verificatam(&str, &str1))
        printf("\n \n Ha");
    reiniciaString(&str);
    imprimirString(str);
    insereChar(&str, 'D');
    insereChar(&str, 'v');
    insereChar(&str, 'D');
    printf("\n\n");
    imprimirString(str);
    return;
}
