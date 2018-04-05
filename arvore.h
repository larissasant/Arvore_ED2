#ifndef _ARVOREBIN_H_
#define _ARVOREBIN_H_

typedef struct no {
	char info;
	struct no *esquerda;
	struct no *direita;
}Nodo;

typedef struct arv_bin {
	Nodo * raiz;
}Arv_bin;

Arv_bin* arv_cria(Nodo* raiz);
Nodo* arv_cria_no(char c, Nodo* esquerdo, Nodo* direito);

void arv_imprime(Arv_bin* arv);
void arv_imprime_no(Nodo* raiz);

void arv_imprime_formatado(Arv_bin* arv);
void arv_imprime_formatado_no(Nodo* raiz);

void arv_imprime_escolhendo_ordem(Arv_bin* arv, int ordem);

void arv_imprime_pre_ordem(Nodo* raiz);
void arv_imprime_infixa(Nodo* raiz);
void arv_imprime_pos_ordem(Nodo* raiz);

void arv_libera(Arv_bin* arv);
void arv_libera_no(Nodo* raiz);

int arv_pertence(Arv_bin* arv, char c);
int arv_pertence_no(Nodo* raiz, char c);

Nodo* arv_busca(Arv_bin* arv, char c);
Nodo* arv_busca_no(Nodo* raiz, char c);

int arv_altura(Arv_bin* arv);
int arv_altura_no(Nodo* raiz);

int tamanho_no(Nodo* raiz);
int soma_nos (Nodo* raiz);

int numeros_folhas_no(Nodo *raiz);

void espelho(Nodo* raiz);
void largura(Arv_bin* arv);
void pre_ordem_iterativo(Arv_bin* arv);
void in_ordem_iterativo(Nodo* raiz);
void pos_ordem_iterativo(Nodo* raiz);
int tamanho(Nodo* raiz) ;
#endif


