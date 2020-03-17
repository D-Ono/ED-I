typedef struct estacionamento{
    char placa[8];
    char MarcaModelo[30];
    char color[20];
}carro;

void Consultar(carro *car, char *placa, int MAX);
int Pesquisa(carro *car, char *placa, int MAX);
void Insercao(carro *car, char *placa, int *MAX);
void Remocao(carro *car, char *placa, int *MAX);
void Alterar(carro *car, char *placa, int MAX);

