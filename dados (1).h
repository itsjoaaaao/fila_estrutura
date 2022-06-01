struct num{
  int numero;
};
typedef struct fila Fila;

Fila* cria_fila();
void libera_fila(Fila* fi);
int fila_cheia(Fila* fi);
int fila_vazia(Fila* fi);
int insere_fila(Fila* fi, struct num num);
int remove_fila(Fila* fi);
int consulta(Fila* fi, struct num *num);
int tamanho(Fila* fi);
int remover_inicio(Fila* fi);
void imprimir(Fila* fi);