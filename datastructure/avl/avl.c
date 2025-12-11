#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct no{
    int chave;
    No *esq;
    No *dir;
    int altura;
};

struct avl{
    No *raiz;
};

Avl* criar_avl(){
    Avl *avl = (Avl*) malloc(sizeof(Avl));
    if(avl == NULL){
        printf("Nao foi possivel criar a arvore!\n");
        return NULL;
    }

    avl->raiz = NULL;

    return avl;
}

void inserir(Avl *a, int chave){
    a->raiz = inserir_no(a->raiz, chave);

    printf("Valor %d inserido com sucesso!\n", chave);
    printf("Altura: %d\n\n", a->raiz->altura);
}

void remover(Avl *a, int chave){
    a->raiz = remover_no(a->raiz, chave);

    printf("Valor %d removido com sucesso!\n", chave);
    printf("Altura da arvore: %d\n\n", a->raiz->altura);
}

No* inserir_no(No *raiz, int chave){
    if(raiz == NULL){
        No *no = (No*) malloc(sizeof(No));
        if(no != NULL){
            no->chave = chave;
            no->dir = NULL;
            no->esq = NULL;
            no->altura = 0;
            return no;
        }return NULL;
    }

    if(chave < raiz->chave){
        raiz->esq = inserir_no(raiz->esq, chave);
    }else if(chave > raiz->chave){
        raiz->dir = inserir_no(raiz->dir, chave);
    }

    return raiz;
}

No* remover_no(No *raiz, int chave){
    if(raiz == NULL){
        printf("Arvore vazia!\n");
        return NULL;
    }

    if(chave > raiz->chave){
        raiz->dir = remover_no(raiz->dir, chave);
    }else if(chave < raiz->chave){
        raiz->esq = remover_no(raiz->esq, chave);
    }else{
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            return NULL;
        }

        else if(raiz->esq == NULL){
            No *temp = raiz->dir;
            free(raiz);
            return temp;
        }else if(raiz->dir == NULL){
            No *temp = raiz->esq;
            free(raiz);
            return temp;
        }

        else{
            No *sucessor = menor_dir(raiz->dir);
            raiz->chave = sucessor->chave;
            raiz->dir = remover_no(raiz->dir, sucessor->chave); 
        }
    }
    return raiz;
}

No* menor_dir(No *raiz){
    while(raiz->esq != NULL){
        raiz = raiz->esq;
    }
    return raiz;
}

void buscar(Avl *a, int chave){
    buscar_avl(a->raiz, chave);
}

void buscar_avl(No *raiz, int chave){
    if(raiz == NULL){
        printf("Valor %d nao encontrado na arvore!\n", chave);
        return;
    }

    if(chave > raiz->chave){
        buscar_avl(raiz->dir, chave);
    }else if(chave < raiz->chave){
        buscar_avl(raiz->esq, chave);
    }else{
        printf("%d encontrado na posicao %p!\n", chave, raiz);
    }
}

int altura_no(No *no){
    if(no == NULL){
        return 0;
    }else{
        return no->altura;
    }
}

int fb_no(No *no){
    if(no == NULL){
        return 0;
    }else{
        return altura_no(no->esq) - altura_no(no->dir);
    }
}

No* rotacao_esquerda(No *x){
    No *y = x->dir;
    No *z = y->esq;

    y->esq = x;
    x->dir = z;

    x->altura = 1 + max(altura(x->esq), altura(x->dir));
    y->altura = 1 + max(altura(y->esq), altura(y->dir));

    return y;
}


No* rotacao_direita(No *y){
    No *x = y->esq;
    No *z = x->dir;

    x->dir = y;
    y->esq = z;

    y->altura = 1 + max(altura(y->esq), altura(y->dir));
    x->altura = 1 + max(altura(x->esq), altura(x->dir));

    return x;
}

No* rotacao_dupla_esq(No *n){
    n->esq = rotacao_esquerda(n->esq);
    return rotacao_direita(n);
}


No* rotacao_dupla_dir(No *n){
    n->dir = rotacao_direita(n->dir);
    return rotacao_esquerda(n);
}

void imprimir(Avl *a){
    if(a == NULL){
        printf("Arvore vazia!\n");
    }else{
        printf("Valores da arvore: "); 
        imprimir_avl(a->raiz);
        printf("\n");
    }
}

void imprimir_avl(No *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->chave);
        imprimir_avl(raiz->esq);
        imprimir_avl(raiz->dir);
    }

}