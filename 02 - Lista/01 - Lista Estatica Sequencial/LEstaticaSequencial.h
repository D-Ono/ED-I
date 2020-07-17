#define MAX 100

struct lista {
    int elem[MAX];
    int qelem;  ///Quantidade de Elementos
};

void InicializaLista(struct lista *L);
void Inserir(struct lista *l, int elem, int i);
void Remover(struct lista *l, int pos);
int ImprimirRecursivo(struct lista *l, int i);
void InserirFinal(struct lista *l, int elem);
void RemoverFinal(struct lista *l);
