struct ​no {
    int elem;
    struct no *prox; ​//auto-referência
};

struct ​Lista​ ​{
    struct ​no *priElem;
    struct ​no​ ​*ultElem;
};

void inicializaLista(struct Lista *list);
void insereNo(int elem, struct Lista *list);
void imprime(struct Lista *list);
short ​listaVazia (struct Lista *list);
int ​tamanho(struct Lista *list);
void EliminaPrimeiroNo(struct Lista *l);
