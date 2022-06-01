#define MAX 100
struct num{
	int num;
};
typedef struct fila Fila;

Fila* cria_fila();
int fila_cheia(Fila *fi);
int fila_vazia(Fila *fi);
int insere_fila(Fila *fi, struct num num);
void imprime_Fila(Fila* fi);
int remove_fila(Fila *fi);
int insere(Fila *fi, Fila* f2);
int ordenar(Fila* fi);
