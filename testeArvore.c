#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* init (void){
    return NULL;
}

int vazia(Arv* a){
    if(a == NULL){
        printf("vazio");
    }


}

void imprime (Arv* a){
    if (a != NULL) {
        imprime(a->esq);
        printf("%d\n",a->info);
        imprime(a->dir);
    }
}

Arv* busca (Arv* r, int v){
    if (r == NULL) return NULL;
    else if (r->info > v) return busca (r->esq, v);
    else if (r->info < v) return busca (r->dir, v);
    else return r;
}

Arv* insere (Arv* a, int v){
    if (a==NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info)
        a->esq = insere(a->esq,v);
    else /* v < a->info */
        a->dir = insere(a->dir,v);
    return a;
}

main(){




return 0;
}
