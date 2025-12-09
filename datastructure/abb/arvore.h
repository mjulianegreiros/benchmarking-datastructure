#ifndef ARVORE_H
#define ARVORE_H

typedef struct no No;
typedef struct arv Arv;

Arv* criar_arv();
void inserir(Arv *a, int chave);
void remover(Arv *a, int chave);

No* inserir_no(No *raiz, int chave);
No* remover_no(No *raiz, int chave);
No* menor_dir(No *raiz);
int altura_no(No *raiz);

void buscar(Arv *a, int chave);
void buscar_arv(No *raiz, int chave);
void imprimir(Arv *a);
void imprimir_arv(No *raiz);

#endif