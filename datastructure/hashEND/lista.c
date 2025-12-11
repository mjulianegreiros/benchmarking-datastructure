#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



Lista* criarLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}
void insereLista(Lista* lista , int elemento){
    No *no = (No*)malloc(sizeof(No));
    no->prox = lista->inicio;
    lista->inicio = no;
    no->elemento = elemento;
}
void buscaLista(Lista* lista , int elemento){
    No *aux = lista->inicio;
    if(lista->inicio==NULL){
        printf("Lista vazia.\n");
        return;
    }
    while(aux!=NULL && aux->elemento != elemento){
        aux = aux->prox;
    }
    if(aux==NULL){
        printf("Valor não encontrado.\n");
    } else{
        printf("\n%d" , aux->elemento);
    }
}
void removeLista(Lista* lista , int elemento){
    No *deletar = lista->inicio;
    if(lista->inicio==NULL){
        printf("Lista vazia.\n");
    }
    No *ant;
    while(deletar!=NULL && deletar->elemento != elemento){
        ant=deletar;
        deletar = deletar->prox;
    }
    if(deletar==NULL){
        printf("Valor nãao encontrado\n.");
        return;
    } else{
        ant->prox = deletar->prox;
        free(deletar);
        return;
    }

}
void exibirLista(Lista* lista){
    No *aux;
    if(aux==NULL){
        printf("Lista vazia.");
        return;
    }
    while(aux!=NULL){
        printf("%d " , aux->elemento);
        aux->prox;
    }
}