#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "datastructure/arvore.h"
#include "datastructure/tabelaHash.h"
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

int calcTempoInsereAVL();
int calcTempoBuscaAVL();
int calcTempoRemoveAVL();

int calcTempoInsereHash();
int calcTempoBuscaHash();
int calcTempoRemoveHash();