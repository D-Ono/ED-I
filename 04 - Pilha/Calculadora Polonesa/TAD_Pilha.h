struct no {
    int elem;
    struct no *prox;
};

struct pilha {
    struct no *topo;
};


void inicializaPilha(struct pilha *P);
short pilhaVazia(struct pilha *P);
void push(struct pilha *P, int elem);
short pop(struct pilha *P);
void imprimePilha(struct pilha P);
