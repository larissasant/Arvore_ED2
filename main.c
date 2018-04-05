#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
Arv_bin *arv = arv_cria(
                        arv_cria_no('a',
                            arv_cria_no('b',
                                        NULL,
                                    arv_cria_no('d', NULL, NULL)
                                        ),
                                    arv_cria_no('c',
                                        arv_cria_no('e', NULL,NULL),
                                                arv_cria_no('f', NULL,NULL)
                                    )
                                )
                        );
        printf("\n\t\t_________________ARVORE______________\n\n");

        printf("\n\n--Formato da Arvore: ");
        arv_imprime_formatado(arv);

        printf("\n\n--Pre ordem: ");
        arv_imprime_escolhendo_ordem(arv, 1);

        printf("\n\n--Infixa: ");
        arv_imprime_escolhendo_ordem(arv, 2);

        printf("\n\n--Pos Ordem: ");
        arv_imprime_escolhendo_ordem(arv, 3);

        printf("\n\n--Altura da arvore: %d ", arv_altura(arv));

        printf("\n\n--Numero de folhas: %d", numeros_folhas_no(arv->raiz));

        printf("\n\n--'a' esta na arvore? sim/nao : ");

        arv_pertence(arv, 'a') ? printf("sim"):printf("nao");

        printf("\n\n--Buscar 'b' na arvore: ");
        Nodo *n = arv_busca(arv, 'b');
         if (n!=NULL)
        printf("Letra encontrada: %c \n", n->info);

        printf("\n\n--Tamanho: %d", tamanho(arv->raiz));
        //largura(arv);
        //pre_ordem_iterativo(arv);
        //in_ordem_iterativo(arv->raiz);
        //pos_ordem_iterativo(arv->raiz);

       printf("\n\n--Arvore espelhada: ");
       espelho(arv->raiz);
       arv_imprime_formatado(arv);



 arv_libera(arv);


}


