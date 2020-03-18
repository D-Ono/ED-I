#define MAX 100

struct reg{
    int elem;
    int prox;
};

typedef struct lista{
    int disp, prim;
    struct reg A[MAX];
}LISTA;

void FLVazia(LISTA *l);
void Vazia (LISTA l, int *flag);
void ImprimiLista(LISTA l);
void Retira(LISTA *l, int *elem, int pos, int *flag);
void Insere(LISTA *l, int elem, int *flag);
