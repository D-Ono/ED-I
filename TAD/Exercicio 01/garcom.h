typedef struct candidatos{
    char rg[15];
    char nome[50];
    char tele[14];
    char ende[60];
}garcom;

int Pesquisa(garcom *cand, char *rg, int MAX);
void Consultar(garcom *cand, char *rg, int MAX);
void Insercao(garcom *cand, char *rg, int *MAX);
void Remocao(garcom *cand, char *rg, int *MAX);
void Alterar(garcom *cand, char *rg, int MAX);
