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

int calcTempoInsereAVL(){
    clock_t inicio = clock();
    // função de inserir na árvore AVL
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoBuscaAVL(){
    clock_t inicio = clock();
    // função de busca na árvore AVL
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoRemoveAVL(){
    clock_t inicio = clock();
    // função de remover na árvore AVL
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}

int calcTempoInsereHash(){
    clock_t inicio = clock();
    // função de inserir na tabela hash
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoBuscaHash(){
    clock_t inicio = clock();
    // função de buscar na tabela hash
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}
int calcTempoRemoveHash(){
    clock_t inicio = clock();
    // função de remover na tabela hash
    clock_t fim = clock();
    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    return tempo;
}