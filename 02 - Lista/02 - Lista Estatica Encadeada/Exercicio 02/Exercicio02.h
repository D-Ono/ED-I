#define MAX 100

struct reg{
    char nome[15];
    int matricula;
    char departamento[10];
    float salario;
    int prox;
};

typedef struct lista{
    int disp, prim;
    struct reg A[MAX];
}LISTA;

void FLVazia(LISTA *l);
void ImprimiLista(LISTA l);
void Retira(LISTA *l, int pos, int *flag);
void Insere(LISTA *l, int *flag);
int Pesquisa(LISTA l);
