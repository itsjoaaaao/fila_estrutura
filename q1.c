#include<stdio.h>
#include<stdlib.h>
#include"q1dados.h"

struct fila{
	int inicio, fim, qtd;
	struct num dados[MAX];
};

int main(){
	
	Fila *fi, *f2;
	struct num num;
	int i;
	
	fi = cria_fila();
	//f2 = cria_fila();
	
	for(i=0; i<3; i++){
		printf("Digite um valor:\n");
		scanf("%d", &num.num);
		insere_fila(fi, num);
	}
	
	/*for(i=0; i<3; i++){
		remove_fila(fi);
		ordenar(fi);
	}*/
	
	imprime_Fila(fi);
	
	
	return 0;
}

Fila* cria_fila(){
  Fila *fi;
  fi = (Fila *) malloc(sizeof(Fila));
  if(fi != NULL){
    fi->inicio = 0;
    fi->fim = 0;
    fi->qtd = 0;
  }
}

int fila_cheia(Fila *fi){
  if(fi == NULL){
    return -1;
  }
  if(fi->qtd == MAX)
    return 1;
  else
    return 0;
}

int fila_vazia(Fila *fi){
  if(fi == NULL){
    return -1;
  }
  if(fi->qtd == 0)
    return 1;
  else
    return 0;
}

int insere_fila(Fila *fi, struct num num){
  if(fi == NULL){
    return 0;
  }
  if(fila_cheia(fi)){
    return 0;
  }
  fi->dados[fi->fim] = num;
  fi->fim = (fi->fim+1)%MAX;
  fi->qtd++;
  return 1;
}

int remove_fila(Fila *fi){
  if(fi == NULL || fila_vazia(fi))
    return 0;
  fi->inicio = (fi->inicio+1)%MAX;
  fi->qtd--;
  return 1;
}

/*int ordenar(Fila* fi){
	
	int maior;
	Fila* f2;
	struct num num;
	
	if(fi == NULL){
		return 0;
	}
	if(fi->dados[fi->inicio] > fi->dados[fi->fim]){
		//maior = fi->inicio;
		insere_fila(f2, num);
	}
	
}*/

void imprime_Fila(Fila* fi){
	
    if(fi == NULL)
        return;
    int j, aux;
    int i = fi->inicio;
    
    for(i=fi->inicio; i<3; i++){
    	for(j=i+1; j<3; j++){
    		if(fi->dados[i].num > fi->dados[j].num){
    			aux = fi->dados[i].num;
    			fi->dados[i].num = fi->dados[j].num;
    			fi->dados[j].num = aux;
			}
		}
	}
	
	for(i=fi->inicio; i<3; i++){
		printf("%d ", fi->dados[i].num);
	}
	
    /*while(i != fi->fim){
        i = (i + 1) % MAX;
        printf("%d ", fi->dados[i].num);
    }*/
}
