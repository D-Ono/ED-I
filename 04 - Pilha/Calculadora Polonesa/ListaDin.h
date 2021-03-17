struct nos {
    int elem;
    struct nos *prox;
};

struct Lista{
    struct nos *priElem;
    struct nos *ultElem;
};


void inicializaLista(struct Lista *list);
void insereNo(int elem, struct Lista *list);
void imprime(struct Lista *list);
short listaVazia(struct Lista *l);
int tamanho(struct Lista *l);
void EliminaPrimeiroNo(struct Lista *lis);
