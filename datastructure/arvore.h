#ifndef ABINARIA_H
#define ABINARIA_H

typedef struct no No;
typedef struct arv Arv;

Arv* criar_arv();
Arv* inserir(Arv *a, int chave);
No* remover(Arv *a, int chave);
No* menor_dir(No *raiz);
void buscar(No *raiz, int chave);

#endif