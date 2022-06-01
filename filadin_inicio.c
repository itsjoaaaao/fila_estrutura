#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

struct fila{
  struct elemento *inicio;
  struct elemento *fim;
  int qtd;
};

struct elemento{
  struct num dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

int main(void) {

  Fila *fi;
  int op;
  struct num num;

  fi = cria_fila();

  do{
    printf("1-inserir\n");
    printf("2- remover inicio\n");
    printf("3- imprimir\n");
    scanf("%d", &op);

    switch(op){
      case 1:
        //struct num num;
        printf("Digite um valor:\n");
        scanf("%d", &num.numero);
        insere_fila(fi,num);
      break;
      case 2:
        remover_inicio(fi);
      break;
      case 3:
        imprimir(fi);
      break;
    }
    
  }while(op<=3);
  
  return 0;
}

Fila* cria_fila(){
  Fila *fi;
  fi = (Fila*) malloc(sizeof(Fila));
  if(fi !=  NULL){
    fi->inicio = NULL;
    fi->fim = NULL;
  }
  return fi;
}

void libera_fila(Fila* fi){
  if(fi != NULL){
    Elem* no;
    while(fi->inicio != NULL){
      no = fi->inicio;
      fi->inicio = fi->inicio->prox;
      free(no);
    }
    free(fi);
  }
}

int fila_cheia(Fila* fi){
  return 0;
}

int fila_vazia(Fila* fi){
  if(fi == NULL) return 1;
  if(fi->inicio == 0) return 1;
  return 0;
}

int insere_fila(Fila* fi, struct num num){
  if(fi == NULL) return 0;
  //if(fila_cheia(fi)) return 0;
  Elem *no;
  no = (Elem*) malloc(sizeof(Elem));
  if(no == NULL) return 0;
  no->dados = num;
  no->prox = NULL;
  if(fi->fim == NULL)
    fi->inicio = no;
  else
    fi->fim->prox = no;
  fi->fim = no;
  fi->qtd++;
  return 1;
}

int remove_fila(Fila* fi){
  if(fi == NULL) return 0;
  if(fila_vazia(fi)) return 0;
  Elem* no = fi->inicio;
  fi->inicio = fi->inicio->prox;
  if(fi->inicio==NULL) fi->fim = NULL;
  free(no);
  fi->qtd--;
  return 1;
}

int consulta(Fila* fi, struct num *num){
  if(fi == NULL || fila_vazia(fi)) return 0;
  *num = fi->inicio->dados;
  return 1;
}

int tamanho(Fila* fi){
  if(fi == NULL) return 0;
  int cont = 0;
  Elem* no = fi->inicio;
  while(no != NULL){
    cont++;
    no = no->prox;
  }
  return cont; //ou fi->qtd somente
}

int remover_inicio(Fila* fi){
  if(fi == NULL) return 0;
  Elem* no = fi->inicio;
  printf("inicio: %d\n", no->dados.numero);
  free(no);
}

void imprimir(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
    	  printf("%d ", no->dados.numero);
        no = no->prox;
    }
}