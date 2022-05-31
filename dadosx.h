struct num{
 int num;
};
typedef struct fila Fila;

Fila* cria();
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
int insere_Fila(Fila* fi, struct num num);
void imprimir(Fila* fi);
int remove_fila(Fila* fi);
int excluir_negativo(Fila* fi);
