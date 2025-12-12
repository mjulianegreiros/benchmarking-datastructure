#ifndef ARVORE_H
#define ARVORE_H

typedef struct no No;
typedef struct avl Avl;

Avl* criar_avl();
void inserir_avl(Avl *a, int chave);
void remover_avl(Avl *a, int chave);

No* inserir_no(No *raiz, int chave);
No* remover_no(No *raiz, int chave);
No* menor_dir(No *raiz);
int altura_no(No *no);
int fb_no(No *no);
No* rotacao_esquerda(No *x);
No* rotacao_direita(No *y);
No* rotacao_dupla_esq(No *n);
No* rotacao_dupla_dir(No *n);
int max(int x, int y);

void buscar(Avl *a, int chave);
void buscar_avl(No *raiz, int chave);
void imprimir(Avl *a);
void imprimir_arv(No *raiz);

#endif