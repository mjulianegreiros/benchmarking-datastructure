#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tabelaHashEnd.h>
#define CONST_A 0.6180339887 // número de ouro

struct no{
    int elemento;
    struct no *prox;
};
struct list{
    struct no *inicio;
};

int inserirEND(int i , List* vet , int tam);
int buscarEND(int i , List* vet , int tam);
void removerEND(int i , List* vet , int tam);
void exibirTabelaEND(List* vet , int tam){
    for(int i=0; i < tam; i++){
        printf("pos: %d -> " , i);
        if(vet->inicio != NULL){
            No *aux = vet[i]->inicio;
            while(aux!=NULL){
                printf("%d " , aux->prox);
                aux
            }
        }
    }
}

int funcHash(int chave , int tam){
    double mult = (double)chave * CONST_A;
    double parteFrac =  mult - floor(mult);
    double posicao = (double)tam * parteFrac;

    return (int)posicao;
}