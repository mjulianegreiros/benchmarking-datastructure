#ifndef ARVORE_H
#define ARVORE_H

typedef struct no No;
typedef struct avl Avl;

Avl* criar_avl();
void inserir(Avl *a, int chave);
void remover(Avl *a, int chave);

No* inserir_no(No *raiz, int chave);
No* remover_no(No *raiz, int chave);
No* menor_dir(No *raiz);
int altura_no(No *raiz);

void buscar(Avl *a, int chave);
void buscar_avl(No *raiz, int chave);
void imprimir(Avl *a);
void imprimir_arv(No *raiz);

#endif