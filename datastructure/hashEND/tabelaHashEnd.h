#ifndef TABELAHASHEND_H
#define TABELHASHEND_H

#include "lista.h"

void inserirEND(int i , Lista* vet[] , int tam);
void buscarEND(int i , Lista* vet[] , int tam);
void removerEND(int i , Lista* vet[] , int tam);
void exibirTabelaEND(Lista* vet[] , int tam);

int funcHash(int chave ,  int tam);

#endif