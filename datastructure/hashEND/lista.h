#ifndef LISTA_H
#define LISTA_H

struct no{
    int elemento;
    struct no *prox;
};
struct lista{
    struct no *inicio;
};

typedef struct no No;
typedef struct lista Lista;

Lista* criarLista();
void insereLista(Lista* lista , int elemento);
void buscaLista(Lista* lista , int elemento);
void removeLista(Lista* lista , int elemento);
void exibirLista(Lista* lista);


#endif