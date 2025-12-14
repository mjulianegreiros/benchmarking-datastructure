#ifndef TABELAHASHEND_H
#define TABELAHASHEND_H

#include "lista.h"

void inserirEND(int i , Lista* vet[] , int tam , int *colisoesEND);
void buscarEND(int i , Lista* vet[] , int tam);
void removerEND(int i , Lista* vet[] , int tam);
void exibirTabelaEND(Lista* vet[] , int tam);

int funcHashEnd(int chave ,  int tam);

#endif