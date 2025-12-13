#include <stdio.h>
#include <stdlib.h>
#include "hashEND/lista.h"
#include "hashEND/tabelaHashEnd.h"
#include "hash/tabelaHash.h"
#include "abb/arvore.h"
#include "avl/avl.h"
#include "benchmark/benchmark.h"

#define TAM 50000 // aqui é o tamanho dos vetores das tabelas hashs
#define VAZIO 0;
#define DEL -1;


int main(){
    int colisoes;
    int colisoesEND;


    // as variaveis abaixo devem fazer a soma do tempo das interações
    int tempoInsereABB=0 , tempoRemoveABB=0 , tempoBuscaABB=0;
    int tempoInsereAVL=0 , tempoRemoveAVL=0 , tempoBuscaAVL=0;
    int tempoInsereHash=0 , tempoRemoveHash=0 , tempoBuscaHash=0;
    int tempoInsereHashEND=0 , tempoRemoveHashEND=0 , tempoBuscaHashEND=0;

    /*int rotacoes = 0;
    Avl *a = criar_avl();
    inserir_avl(a, 3, &rotacoes);
    inserir_avl(a, 1, &rotacoes);
    inserir_avl(a, 2, &rotacoes);
    printf("%d\n", rotacoes);*/

    // aqui deve ter um menu para escolher qual amostra deve ser inserida.
    // são necessarios 3 arquivos, um pra cada amostra
    // exemplo: tabela hash
    // abre o arquivo, e para a inserção:
    int vet[TAM];
    for(int i=0;i<TAM;i++){
        tempoInsereHash += calcTempoInsereHash(num , vet , TAM , &colisoes);
        // num é o valor lido pelo arquivo e vet é o vetor criado
    }
    

    return 0;
}