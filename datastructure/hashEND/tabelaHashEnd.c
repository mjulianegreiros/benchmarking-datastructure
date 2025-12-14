#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tabelaHashEnd.h"

#define CONST_A 0.6180339887 // número de ouro

void inserirEND(int i , Lista* vet[] , int tam , int *colisoesEND){
    int posicao = funcHashEnd(i , tam);
    if(vet[posicao] == NULL){
        vet[posicao] = criarLista();
    }else{
        (*colisoesEND)++;
        // printf("\ncolision... :(");
    }
    insereLista(vet[posicao] , i);
}
void buscarEND(int i , Lista* vet[] , int tam){
    int posicao = funcHashEnd(i , tam);
    if(vet[posicao] == NULL){
        printf("Nao existe lista na posicao %d!\n", posicao);
        return;
    }else{
        buscaLista(vet[posicao] , i);
    }
}
void removerEND(int i , Lista* vet[] , int tam){
    int posicao = funcHashEnd(i ,tam);
    if(vet[posicao] == NULL){
        printf("Nao existe lista na posicao %d!\n", posicao);
    }else{
        removeLista(vet[posicao] , i);
    }
}
void exibirTabelaEND(Lista* vet[] , int tam){
    for(int i=0; i<tam; i++){
        printf("\npos: %d -> " , i);
        if(vet[i] == NULL){
            printf("Nao existe lista nesta posicao!\n");
        }else{
            exibirLista(vet[i]);
        }
    }
}

int funcHashEnd(int chave , int tam){
    double mult = (double)chave * CONST_A;
    double parteFrac =  mult - floor(mult);
    double posicao = (double)tam * parteFrac;

    return (int)posicao;
}