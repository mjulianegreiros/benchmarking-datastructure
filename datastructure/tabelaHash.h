#ifndef TABELA_H
#define TABELA_H


int inserir(int i , int* vet , int tam);
int buscar(int i , int* vet , int tam);
void remover(int i , int* vet , int tam);
void exibirTabela(int* vet , int tam);

int funcHash(int chave , int tentativa , int tam);

#endif

