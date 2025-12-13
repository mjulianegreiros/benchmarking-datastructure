#ifndef BENCHMARK_H
#define BENCHMARK_H

int calcTempoInsereArvore(Arv *a , int elemento);
int calcTempoBuscaArvore(Arv *a , int elemento);
int calcTempoRemoveArvore(Arv *a , int elemento);

int calcTempoInsereAVL(Avl *a , int chave);
int calcTempoBuscaAVL(Avl *a , int chave);
int calcTempoRemoveAVL(Avl *a , int chave);

int calcTempoInsereHash(int *vet , int chave , int tam , int *colisoes);
int calcTempoBuscaHash(int *vet , int chave , int tam);
int calcTempoRemoveHash(int *vet , int chave , int tam);

int calcTempoInsereHashEND(int i , Lista* vet[] , int tam , int *colisoesEND);
int calcTempoBuscaHashEND(int i , Lista* vet[] , int tam);
int calcTempoRemoveHashEND(int i , Lista* vet[] , int tam);


#endif