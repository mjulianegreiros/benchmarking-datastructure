#include <stdio.h>
#include <stdlib.h>
#include "hashEND/lista.h"
#include "hashEND/tabelaHashEnd.h"
#include "hash/tabelaHash.h"
#include "abb/arvore.h"
#include "avl/avl.h"
#include "../benchmark/benchmark.h"

#define TAM 50000 // aqui é o tamanho dos vetores das tabelas hashs
#define VAZIO 0
#define DEL -1

int main(){
    // Inicialização de atributos especificos de cada estrutura
    int colisoesHashEnd = 0, colisoesHashEnc = 0, rotacoesAvl = 0;


    // as variaveis abaixo devem fazer a soma do tempo das interações
    double tempoInsereABB=0 , tempoRemoveABB=0 , tempoBuscaABB=0;
    double tempoInsereAVL=0 , tempoRemoveAVL=0 , tempoBuscaAVL=0;
    double tempoInsereHash=0 , tempoRemoveHash=0 , tempoBuscaHash=0;
    double tempoInsereHashEND=0 , tempoRemoveHashEND=0 , tempoBuscaHashEND=0;


    int vetHashEnd[TAM];
    Lista *vetHashEnc[TAM];
    Arv *abb = criar_arv();
    Avl *avl = criar_avl();

    // Inicializando com 0 os valores da tabela hash por endereçamento aberto
    for(int i=0;i<TAM;i++){
        inserirT(VAZIO, vetHashEnd, TAM, &colisoesHashEnd);
    }

    // Inicializando as listas como NULL na tabela hash com encadeamento separado
    for(int i=0;i<TAM;i++){
        vetHashEnc[i] = NULL;
    }

    FILE *f = fopen("../dados/dados_aleatorio.txt", "r");
    if(f == NULL){
        printf("Erro ao abrir o arquivo!\n");
    }

    int num, i;
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);

        // calculo do tempo de inserção da tabela hash com endereçamendo aberto
        //tempoInsereHash += calcTempoInsereHash(vetHashEnd, num, TAM, &colisoesHashEnd);

        // calculo do tempo de inserção da tabela hash com encadeamento separado
        //tempoInsereHashEND += calcTempoInsereHashEND(num, vetHashEnc, TAM, &colisoesHashEnc);

        // Calculo do tempo de inserção da árvore binária de busca
        //tempoInsereABB += calcTempoInsereArvore(abb, num);

        // calculo do tempo de inserção da árvore avl
        //tempoInsereAVL += calcTempoInsereAVL(avl, num, &rotacoesAvl);
    }
    printf("Foram inseridos %d elementos!\n", i);
    //printf("tempo de insercao dos elementos na tabela hash por enderecamento aberto: %.5f\n", tempoInsereHash);

    //printf("tempo de insercao dos elementos na tabela hash por encadeamento separado: %.5f\n", tempoInsereHashEND);

    //printf("Tempo de insercao dos elementos na ABB: %.5f\n", tempoInsereABB);

    //printf("Quantidade de rotacoes realizadas: %d\n", rotacoesAvl);
    //printf("Tempo de insercao dos elementos na AVL: %.5f\n", tempoInsereAVL);


    // FILE *f = fopen("dados_aleatorio.txt", "r");

    // int x;
    // while(fscanf(f, "%d", &x) != EOF){
    //     inserir_avl(avl, x, &rotacoes);
    // }

    return 0;
}