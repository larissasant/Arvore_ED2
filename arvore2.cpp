#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include "arvore.h"

using namespace std;
void largura(Arv_bin* arv);

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

void pre_ordem_iterativo(Arv_bin* arv){
    stack<Nodo *> pilha;
    Nodo *corr = NULL;

    pilha.push(arv->raiz);

    while(!pilha.empty()){
        corr = pilha.top();
        printf("%c\n", corr->info);
        pilha.pop();
        if (corr->direita != NULL)
            pilha.push(corr->direita);
        if (corr->esquerda != NULL)
            pilha.push(corr->esquerda);
    }
}

void in_ordem_iterativo(Nodo* raiz) {
	stack<Nodo *> pilha;

	while(!pilha.empty() || raiz != NULL) {
		if (raiz != NULL) {
			pilha.push(raiz);
			raiz = raiz->esquerda;
		}
		else {
			raiz = pilha.top();
			pilha.pop();
			printf("%c",raiz->info);
			raiz = raiz->direita;
		}
	}

}

void pos_ordem_iterativo(Nodo* raiz){
    stack<Nodo *> pilha1;

    pilha1.push(raiz);

    while (!pilha1.empty()){
        while (raiz != NULL){
            if(raiz->direita)
                pilha1.push(raiz->direita);
            pilha1.push(raiz);
            raiz = raiz->esquerda;
        }
        raiz = pilha1.top();
        pilha1.pop();

        if (raiz->direita && raiz->direita == pilha1.top()){
            pilha1.pop();
            pilha1.push(raiz);
            raiz = raiz->direita;
        }
        else{
            printf("%c", raiz->info);
            raiz = NULL;
        }
    }
}


void largura(Arv_bin* arv){
    queue<Nodo *> fila;
    Nodo *corr = NULL;

    fila.push(arv->raiz);

    while(!fila.empty()){
        corr = fila.front();
        printf("%c", corr->info);
        fila.pop();
        if (corr->direita != NULL)
            fila.push(corr->direita);
        if (corr->esquerda != NULL)
            fila.push(corr->esquerda);
    }
}
