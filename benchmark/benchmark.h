#ifndef BENCHMARK_H
#define BENCHMARK_H

int calcTempoInsereArvore(Arv *a , int elemento);
int calcTempoBuscaArvore(Arv *a , int elemento);
int calcTempoRemoveArvore(Arv *a , int elemento);

int calcTempoInsereAVL();
int calcTempoBuscaAVL();
int calcTempoRemoveAVL();

int calcTempoInsereHash();
int calcTempoBuscaHash();
int calcTempoRemoveHash();


#endif