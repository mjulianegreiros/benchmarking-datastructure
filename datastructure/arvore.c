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

Arv* inserir(Arv *a, int chave){
    No *aux = a->raiz;
    if(aux == NULL){
        No *no = (No*) malloc(sizeof(No));
        if(no != NULL){
            no->chave = chave;
            no->dir = NULL;
            no->esq = NULL;
            return no;
        }return NULL;
    }

    if(chave < aux->chave){
        aux->esq = inserir(aux->esq, chave);
    }else if(chave > aux->chave){
        aux->dir = inserir(aux->dir, chave);
    }else{
        printf("Valor ja existe na arvore!\n");
    }

    return aux;
}

void buscar(No *raiz, int chave){
    if(raiz == NULL){
        printf("Arvore vazia!\n");
        return;
    }

    if(chave > raiz->chave){
        buscar(raiz->dir, chave);
    }else if(chave < raiz->chave){
        buscar(raiz->esq, chave);
    }else{
        print("%d encontrado na posicao %p!\n", chave, raiz);
    }
}

No* remover(Arv *a, int chave){
    No *aux = a->raiz;
    if(aux == NULL){
        printf("Arvore vazia!\n");
        return;
    }

    if(chave > aux->chave){
        aux->dir = remover(aux->dir, chave);
    }else if(chave < aux->chave){
        aux->esq = remover(aux->esq, chave);
    }else{
        if(aux->esq == NULL && aux->dir == NULL){
            free(aux);
            printf("Valor removido\n!");
            return NULL;
        }

        else if(aux->esq == NULL){
            No *temp = aux->dir;
            free(aux);
            return temp;
        }else if(aux->dir == NULL){
            No *temp = aux->esq;
            free(aux);
            return temp;
        }

        else{

        }
    }
}

No* menor_dir(No *raiz){
    while(raiz->esq != NULL){
        
    }
}