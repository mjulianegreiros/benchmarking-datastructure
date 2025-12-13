#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "datastructure/abb/arvore.h"
#include "datastructure/avl/avl.h"
#include "datastructure/hash/tabelaHash.h"
#include "datastructure/hashEND/tabelaHashEnd.h"
#include "benchmark.h"

int calcTempoInsereArvore(Arv *a , int elemento){
    clock_t inicio = clock();
    inserir(a , elemento);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoBuscaArvore(Arv *a , int elemento){
    clock_t inicio = clock();
    buscar(a , elemento);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoRemoveArvore(Arv *a , int elemento){
    clock_t inicio = clock();
    remover(a , elemento);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}

int calcTempoInsereAVL(Avl *a , int chave){
    clock_t inicio = clock();
    inserir_avl(a , chave);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoBuscaAVL(Avl *a , int chave){
    clock_t inicio = clock();
    buscar_avl(a , chave);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoRemoveAVL(Avl *a , int chave){
    clock_t inicio = clock();
    remover_avl(a , chave);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}

int calcTempoInsereHash(int *vet , int chave , int tam , int *colisoes){
    clock_t inicio = clock();
    inserirT(chave , vet , tam , colisoes);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoBuscaHash(int *vet , int chave , int tam){
    clock_t inicio = clock();
    buscarT(chave , vet , tam);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoRemoveHash(int *vet , int chave , int tam){
    clock_t inicio = clock();
    removerT(chave , vet ,tam);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}

int calcTempoInsereHashEND(int i , Lista *vet[] , int tam , int *colisoes){
    clock_t inicio = clock();
    inserirEND(i , vet , tam , colisoes);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoBuscaHashEND(int i , Lista *vet[] , int tam){
    clock_t inicio = clock();
    buscarEND(i , vet , tam);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoRemoveHashEND(int i , Lista *vet[] , int tam){
    clock_t inicio = clock();
    removerEND(i , vet , tam);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}