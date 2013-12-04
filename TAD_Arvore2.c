#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[10];
}elemento;


typedef struct nodo *ptrNodo;

struct nodo {
    elemento info;
    ptrNodo filho;
    ptrNodo irmao;
};

typedef ptrNodo arv;

void cria_Arvore(arv *arvore) {
    *arvore = NULL;
}

int vazia(arv t) {
    return (t == NULL);
}

void cria_Raiz(arv *arvore, elemento e) {
    arv no;
    no = (ptrNodo) malloc(sizeof (struct nodo));
    no->filho = NULL;
    no->irmao = NULL;
    no->info, e;
    *arvore = no;
}

ptrNodo localiza(arv t, elemento item) {
    ptrNodo locfilho, locirmao;
    locfilho = NULL;
    locirmao = NULL;
    if (strcmp(t->info, item) != 0) {
        if (t->filho != NULL)
            locfilho = localiza(t->filho, item);
        if (locfilho == NULL) {
            if (t->irmao != NULL)
                locirmao = localiza(t->irmao, item);
            if (locirmao == NULL)
                return NULL;
            else
                return locirmao;
        } else
            return locfilho;
    } else
        return t;
}

int insere(arv arvore, elemento elem_pai, elemento e) {
    arv no, pai;
    pai = localiza(arvore, elem_pai);
    printf("\n%s\n\n", pai->info);
    no = (ptrNodo) malloc(sizeof (struct nodo));
    if (no == NULL)
        return 0;
    else {
        if (pai->filho == NULL) {
            pai->filho = no;
            no->filho = NULL;
            no->irmao = NULL;
            printf("\nElse 1\n");
        } else {
            no->irmao = pai->filho->irmao;
            pai->filho->irmao = no;
            no->filho = NULL;
            printf("\nElse 2\n");
        }
        strcpy(no->info, e);
        return 1;
    }

}

/*int pesquisa(arv arvore, elemento e){

    arv p;
    if (arvore->info==e)
        return 1;
    else {
        for (p=arvore->filho; p!=NULL; p=p->irmao) {
            if (pesquisa(p,e))
        return 1;
       }
    }
   return 0;
}*/

void imprime(arv arvore) {

//    arv p;
//    printf("%c\n", arvore->info);
//    for (p = arvore->filho; p != NULL; p = p->irmao)
//        imprime(p);
}

