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
    int altura;
};

Avl* criar_avl(){
    Avl *avl = (Avl*) malloc(sizeof(Avl));
    if(avl == NULL){
        printf("Nao foi possivel criar a arvore!\n");
        return NULL;
    }

    avl->raiz = NULL;
    avl->altura = 0;

    return avl;
}

void inserir(Avl *a, int chave){
    a->raiz = inserir_no(a->raiz, chave);
    a->altura = altura_no(a->raiz);

    printf("Valor %d inserido com sucesso!\n", chave);
    printf("Altura: %d\n\n", a->altura);
}

void remover(Avl *a, int chave){
    a->raiz = remover_no(a->raiz, chave);
    a->altura = altura_no(a->raiz);

    printf("Valor %d removido com sucesso!\n", chave);
    printf("Altura da arvore: %d\n\n", a->altura);
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

    altura_no(raiz);
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
    altura_no(raiz);
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

int altura_no(No *raiz){
    if(raiz == NULL){
        return 0;
    }

    int alt_esq = altura_no(raiz->esq);
    int alt_dir = altura_no(raiz->dir);

    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
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