#include <stdio.h>
#include <stdlib.h>
#include "dadosx.h"

struct elemento{
  struct num dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

struct fila{
  struct elemento *inicio;
  struct elemento *fim;
  int qtd;
};

int main(void) {

  Fila *fi, *f2;
  int op;
  
  fi = cria();

  do{
    printf("1- inserir:\n");
    printf("2- negativo:\n");
    printf("3- imprimir:\n");
    scanf("%d", &op);

    switch(op){
      case 1:
        if(Fila_cheia(fi)==1){
          printf("fila cheia!\n");
        }else{
          struct num num;
          printf("Digite um valor:\n");
          scanf("%d", &num.num);
          insere_Fila(fi, num);
        }
      break;
      case 2:
      	if(Fila_vazia(fi)==1){
      		printf("fila vazia\n");
		  }else{
		  	excluir_negativo(fi);
		  }
      break;
      case 3:
    	if(Fila_vazia(fi)==1){
      		printf("fila vazia\n");
		}else{
			imprimir(fi);	  	
		}
      break;
    }    
    
  }while(op<=3);
  
  return 0;
}

Fila* cria(){
  Fila *fi = (Fila*) malloc(sizeof(Fila*));
  if(fi != NULL){
    fi->inicio = NULL;
    fi->fim = NULL;
    fi->qtd = 0;
  }
  return fi;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void libera_Fila(Fila* fi){
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

int insere_Fila(Fila* fi, struct num num){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
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
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->fim = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int excluir_negativo(Fila* fi){
	
	int i;
	if(fi==NULL){
		return 0;
	}
	Elem *no = fi->inicio;
	while(no != NULL){
		if(no->dados.num < 0){
			remove_fila(fi);
		}
		no = no->prox;
	}
	
}

void imprimir(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
    	printf("%d ", no->dados.num);
        no = no->prox;
    }
}
