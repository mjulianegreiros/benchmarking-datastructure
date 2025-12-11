#ifndef TABELAHASHEND_H
#define TABELHASHEND_H

typedef struct no{
    int elemento;
    struct no *prox;
}No;
typedef struct list{
    No *inicio;
}List;

int inserirEND(int i , List* vet , int tam);
int buscarEND(int i , List* vet , int tam);
void removerEND(int i , List* vet , int tam);
void exibirTabelaEND(List* vet , int tam);

int funcHash(int chave ,  int tam);

#endif