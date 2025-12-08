#ifndef TABELA_H
#define TABELA_H

typedef int chave;

int inserir(chave i , chave* vet);
int buscar(chave i , chave* vet);
void remover(chave i , int tent, chave* vet);
void exibirTabela(chave* vet);

int funcHash(chave chave , int tentativa , int tam);

