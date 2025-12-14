#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "../datastructure/abb/arvore.h"
#include "../datastructure/avl/avl.h"
#include "../datastructure/hash/tabelaHash.h"
#include "../datastructure/hashEND/tabelaHashEnd.h"
#include "benchmark.h"

double calcTempoInsereArvore(Arv *a , int elemento);
double calcTempoBuscaArvore(Arv *a , int elemento);
double calcTempoRemoveArvore(Arv *a , int elemento);

double calcTempoInsereAVL(Avl *a , int chave, int *rotacoes);
double calcTempoBuscaAVL(Avl *a , int chave);
double calcTempoRemoveAVL(Avl *a , int chave, int *rotacoes);

double calcTempoInsereHash(int *vet , int chave , int tam , int *colisoes);
double calcTempoBuscaHash(int *vet , int chave , int tam);
double calcTempoRemoveHash(int *vet , int chave , int tam);

double calcTempoInsereHashEND(int i , Lista* vet[] , int tam , int *colisoesEND);
double calcTempoBuscaHashEND(int i , Lista* vet[] , int tam);
double calcTempoRemoveHashEND(int i , Lista* vet[] , int tam);


#endif