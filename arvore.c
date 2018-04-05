#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Arv_bin* arv_cria(Nodo* raiz){
     Arv_bin *arv = (Arv_bin*) malloc(sizeof(Arv_bin));
        arv->raiz = raiz;
    return arv;
}

Nodo* arv_cria_no(char c, Nodo* esquerda, Nodo* direita){
    Nodo *no = (Nodo*) malloc(sizeof(Nodo));

    no->esquerda = esquerda;
    no->direita = direita;
    no->info = c;

    return no;
}
void arv_imprime(Arv_bin* arv){
    return arv_imprime_no(arv->raiz);
}

void arv_imprime_no(Nodo* raiz){
    if(raiz!=NULL){
        arv_imprime_no(raiz->esquerda);
        printf("%c\n", raiz->info);
        arv_imprime_no(raiz->direita);
    }
}

void arv_imprime_escolhendo_ordem(Arv_bin* arv, int ordem){
    if(ordem == 1){
        arv_imprime_pre_ordem(arv->raiz);
    }
    else if(ordem == 2){
        arv_imprime_infixa(arv->raiz);
    }
    else if(ordem == 3){
        arv_imprime_pos_ordem(arv->raiz);
    }
    else{
        printf("Opcao invalida!");
    }
}

void arv_imprime_formatado(Arv_bin* arv){
    arv_imprime_formatado_no(arv->raiz);
    printf("\n");
}

void arv_imprime_formatado_no(Nodo* raiz){
    printf("<");
    if(raiz!=NULL){
        printf("%c", raiz->info);
        arv_imprime_formatado_no(raiz->esquerda);
        arv_imprime_formatado_no(raiz->direita);
    }
    printf(">");
}

void arv_imprime_pre_ordem(Nodo* raiz){
    if(raiz!=NULL){
        printf("%c", raiz-> info);
        arv_imprime_pre_ordem(raiz-> esquerda);
        arv_imprime_pre_ordem(raiz->direita);

    }
}

void arv_imprime_infixa(Nodo* raiz){
    if(raiz!=NULL){
        arv_imprime_infixa(raiz-> esquerda);
        printf("%c", raiz-> info);
        arv_imprime_infixa(raiz-> direita);

    }
}

void arv_imprime_pos_ordem(Nodo* raiz){
    if(raiz!=NULL){
        arv_imprime_pos_ordem(raiz-> esquerda);
        arv_imprime_pos_ordem(raiz-> direita);
        printf("%c", raiz-> info);

    }
}

void arv_libera_no(Nodo *raiz){
    if(raiz!=NULL){
        arv_libera_no(raiz->esquerda);
        arv_libera_no(raiz->direita);
        free(raiz);
        raiz = NULL;
    }
}

void arv_libera(Arv_bin* arv){
    if(arv!=NULL)
    arv_libera_no(arv->raiz);
    free(arv);
}

int arv_pertence(Arv_bin* arv, char c){
    return arv_pertence_no(arv->raiz,c);
 }
int arv_pertence_no(Nodo* raiz, char c){
    if(raiz == NULL){
        return 0;
    }
    if(raiz->info==c){
        return 1;
    }
    else if (arv_pertence_no(raiz->esquerda,c)){
        return 1;
    }
    else
    return arv_pertence_no(raiz->direita,c);

}

Nodo* arv_busca(Arv_bin* arv, char c){
    return arv_busca_no(arv->raiz,c);
}

Nodo* arv_busca_no(Nodo* raiz, char c){
    if(raiz==NULL){
        return 0;
    }
    else if(raiz->info == c){
        //printf("%c", c);
        return raiz;
    }else{

    Nodo *no = arv_busca_no(raiz->esquerda, c);
    if (no!= NULL)
        return no;
    else
        return arv_busca_no(raiz->direita, c);
    }
}

int arv_altura(Arv_bin* arv){
    return arv_altura_no(arv->raiz);

}
int max(int altura_direita, int altura_esquerda){
    return altura_direita> altura_esquerda ? altura_direita:altura_esquerda;
}

int arv_altura_no(Nodo* raiz){
    int altura_esquerda;
    int altura_direita;

    if(raiz==NULL){
        return 0;
    }
    altura_esquerda = 1 + arv_altura_no(raiz->direita);
    altura_direita =  1 + arv_altura_no(raiz->esquerda);
    return max(altura_direita, altura_esquerda);
}
/*void largura (Nodo *raiz){
    Nodo *aux, *vet[5];
    int fim, inicio;

  vet[0] = raiz;
  inicio = 0;
  fim = 1;
  while(inicio < fim){
    aux = vet[inicio];
    inicio++;

    printf("%c", aux->info);
    if(aux->esquerda!= NULL){
      vet[fim] = aux->esquerda;
      fim++;
    }
    if(aux->direita != NULL){
      vet[fim] = aux->direita;
      fim++;
    }
  }
}*/


void espelho(Nodo* raiz) {
	if(raiz == NULL)
		return;
	else {
		Nodo* aux;
		espelho(raiz->esquerda);
		espelho(raiz->direita);

		aux = raiz->esquerda;
		raiz->esquerda = raiz->direita;
		raiz->direita = aux;
	}

}



int numeros_folhas_no(Nodo *raiz){
    if (raiz==NULL){
        return 0;
    }
    else if (raiz->esquerda == NULL && raiz->direita==NULL){
        return 1;
    }
    return 0 + numeros_folhas_no(raiz->esquerda) + numeros_folhas_no(raiz->direita);
}
int tam = 0;
int tamanho(Nodo* raiz) {
	if(raiz != NULL) {
		tam++;
		tamanho(raiz->esquerda);
		tamanho(raiz->direita);
	}
	return tam;
}
