#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct no{
    No *esq;
    No *dir;
    int chave;
};

struct arv{
    No *raiz;
    int altura;
};

Arv* criar_arv(){
    Arv *arv = (Arv*) malloc(sizeof(Arv));
    if(arv == NULL){
        printf("Nao foi possivel criar a arvore!\n");
        return NULL;
    }

    arv->raiz = NULL;
    arv->altura = 0;

    return arv;
}

void inserir_abb(Arv *a, int chave){
    a->raiz = inserir_no_abb(a->raiz, chave);
    a->altura = calc_altura_abb(a->raiz);

    printf("Valor %d inserido com sucesso!\n", chave);
    printf("Altura: %d\n\n", a->altura);
}

void remover_abb(Arv *a, int chave){
    a->raiz = remover_no_abb(a->raiz, chave);
    a->altura = calc_altura_abb(a->raiz);

    printf("Valor %d removido com sucesso!\n", chave);
    printf("Altura da arvore: %d\n\n", a->altura);
}

No* inserir_no_abb(No *raiz, int chave){
    if(raiz == NULL){
        No *no = (No*) malloc(sizeof(No));
        if(no != NULL){
            no->chave = chave;
            no->dir = NULL;
            no->esq = NULL;
            return no;
        }return NULL;
    }

    if(chave < raiz->chave){
        raiz->esq = inserir_no_abb(raiz->esq, chave);
    }else if(chave > raiz->chave){
        raiz->dir = inserir_no_abb(raiz->dir, chave);
    }

    calc_altura_abb(raiz);
    return raiz;
}

No* remover_no_abb(No *raiz, int chave){
    if(raiz == NULL){
        printf("Arvore vazia!\n");
        return NULL;
    }

    if(chave > raiz->chave){
        raiz->dir = remover_no_abb(raiz->dir, chave);
    }else if(chave < raiz->chave){
        raiz->esq = remover_no_abb(raiz->esq, chave);
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
            No *sucessor = menor_dir_abb(raiz->dir);
            raiz->chave = sucessor->chave;
            raiz->dir = remover_no_abb(raiz->dir, sucessor->chave); 
        }
    }
    calc_altura_abb(raiz);
    return raiz;
}

No* menor_dir_abb(No *raiz){
    while(raiz->esq != NULL){
        raiz = raiz->esq;
    }
    return raiz;
}

void buscar_abb(Arv *a, int chave){
    buscar_no_abb(a->raiz, chave);
}

void buscar_no_abb(No *raiz, int chave){
    if(raiz == NULL){
        printf("Valor %d nao encontrado na arvore!\n", chave);
        return;
    }

    if(chave > raiz->chave){
        buscar_no_abb(raiz->dir, chave);
    }else if(chave < raiz->chave){
        buscar_no_abb(raiz->esq, chave);
    }else{
        printf("%d encontrado na posicao %p!\n", chave, raiz);
    }
}

int calc_altura_abb(No *raiz){
    if(raiz == NULL){
        return 0;
    }

    int alt_esq = calc_altura_abb(raiz->esq);
    int alt_dir = calc_altura_abb(raiz->dir);

    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}

void imprimir_abb(Arv *a){
    if(a == NULL){
        printf("Arvore vazia!\n");
    }else{
        printf("Valores da arvore: "); 
        imprimir_abb_recursivo(a->raiz);
        printf("\n");
    }
}

void imprimir_abb_recursivo(No *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->chave);
        imprimir_abb_recursivo(raiz->esq);
        imprimir_abb_recursivo(raiz->dir);
    }

}

int altura_abb(Arv *a){
    return a->altura;
}