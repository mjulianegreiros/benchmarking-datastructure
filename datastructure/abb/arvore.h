#ifndef ARVORE_H
#define ARVORE_H

typedef struct no No;
typedef struct arv Arv;

Arv* criar_arv();
void inserir_abb(Arv *a, int chave);
void remover_abb(Arv *a, int chave);

No* inserir_no_abb(No *raiz, int chave);
No* remover_no_abb(No *raiz, int chave);
No* menor_dir_abb(No *raiz);
int altura_abb(Arv *a);
int calc_altura_abb(No *raiz);

void buscar_abb(Arv *a, int chave);
void buscar_no_abb(No *raiz, int chave);
void imprimir_abb(Arv *a);
void imprimir_abb_recursivo(No *raiz);

#endif