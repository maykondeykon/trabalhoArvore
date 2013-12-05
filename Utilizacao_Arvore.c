#include <stdio.h>

#include <stdlib.h>
#include <string.h>

typedef char elemento[30];

#include "TAD_Arvore.c"

arv arv1;


void incluir() {
	char nome[30];
    char pai[30];


	printf("Digite um nome para incluir ");
   gets(nome);
   if (vazia(arv1))
        cria_Raiz(&arv1,nome);
	else {
         printf("Em qual posicao vc deseja incluir (Pai)? ");
         gets(pai);

        if(insere(arv1,pai,nome))
               printf("Elemento incluido com sucesso");
        else
               printf("item já possui subárvore direita ");

        getchar();
        }
}


main() {
   cria_Arvore(&arv1);
	do {
     	//clrscr();
		incluir();
        //printf("altura da arvore = %d\n",altura(arv1));
        //impressaoPrefixa(arv1,0);
        printf("filhos = %d\n",contarFilhos(arv1));

	} while (1);
	
	
}


