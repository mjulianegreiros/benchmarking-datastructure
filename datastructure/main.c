#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    Arv *a = criar_arv();

    inserir(a, 5);
    inserir(a, 2);
    inserir(a, 8);
    inserir(a, 7);
    inserir(a, 3);
    inserir(a, 9);
    inserir(a, 1);
    imprimir(a);

    remover(a, 8);
    imprimir(a);

    remover(a, 1);
    imprimir(a);

    remover(a, 5);
    imprimir(a);

    remover(a, 2);
    imprimir(a);

    buscar(a, 3);
    buscar(a, 5);
    buscar(a, 2);
}