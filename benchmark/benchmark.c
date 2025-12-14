#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "benchmark.h"

double calcTempoInsereArvore(Arv *a , int elemento){
    clock_t inicio = clock();
    inserir_abb(a , elemento);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
double calcTempoBuscaArvore(Arv *a , int elemento){
    clock_t inicio = clock();
    buscar_abb(a , elemento);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
double calcTempoRemoveArvore(Arv *a , int elemento){
    clock_t inicio = clock();
    remover_abb(a , elemento);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}

double calcTempoInsereAVL(Avl *a , int chave, int *rotacoes){
    clock_t inicio = clock();
    inserir_avl(a , chave, rotacoes);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
double calcTempoBuscaAVL(Avl *a , int chave){
    clock_t inicio = clock();
    buscar_avl(a , chave);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
double calcTempoRemoveAVL(Avl *a , int chave, int *rotacoes){
    clock_t inicio = clock();
    remover_avl(a , chave, rotacoes);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}

double calcTempoInsereHash(int *vet , int chave , int tam , int *colisoes){
    clock_t inicio = clock();
    inserirT(chave , vet , tam , colisoes);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
double calcTempoBuscaHash(int *vet , int chave , int tam){
    clock_t inicio = clock();
    buscarT(chave , vet , tam);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
double calcTempoRemoveHash(int *vet , int chave , int tam){
    clock_t inicio = clock();
    removerT(chave , vet ,tam);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}

double calcTempoInsereHashEND(int i , Lista *vet[] , int tam , int *colisoes){
    clock_t inicio = clock();
    inserirEND(i , vet , tam , colisoes);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
double calcTempoBuscaHashEND(int i , Lista *vet[] , int tam){
    clock_t inicio = clock();
    buscarEND(i , vet , tam);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
double calcTempoRemoveHashEND(int i , Lista *vet[] , int tam){
    clock_t inicio = clock();
    removerEND(i , vet , tam);
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}