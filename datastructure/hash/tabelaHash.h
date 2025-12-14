#ifndef TABELA_H
#define TABELA_H

int inserirT(int i , int* vet , int tam , int *colisoes);
int buscarT(int i , int* vet , int tam);
void removerT(int i , int* vet , int tam);
void exibirTabela(int* vet , int tam);

int funcHashAberta(int chave , int tentativa , int tam);

#endif

