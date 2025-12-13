#include <stdio.h>
#include <stdlib.h>
#include "hashEND/lista.h"
#include "hashEND/tabelaHashEnd.h"
#include "avl/avl.h"

#define TAM 50000


int main(){
    // int *colisoes;
    // int *colisoesEND;
    // *colisoes = 0; *colisoesEND = 0;

    // int tempoInsereABB=0 , tempoRemoveABB=0 , tempoBuscaABB=0;
    // int tempoInsereAVL=0 , tempoRemoveAVL=0 , tempoBuscaAVL=0;
    // int tempoInsereHash=0 , tempoRemoveHash=0 , tempoBuscaHash=0;
    // int tempoInsereHashEND=0 , tempoRemoveHashEND=0 , tempoBuscaHashEND=0;

    int rotacoes = 0;
    Avl *a = criar_avl();
    inserir_avl(a, 3, &rotacoes);
    inserir_avl(a, 1, &rotacoes);
    inserir_avl(a, 2, &rotacoes);
    printf("%d\n", rotacoes);

    return 0;
}