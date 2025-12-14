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

void dadosOrdenados();
void dadosAleatorios();
void dadosQuaseOrdenados();

int main(){
    int op;
    do{
        printf("\n\n\t\tBem-vindo ao programa de Benchmark de Estruturas de Dados Avançadas!\n\n");
        printf(" Selecione qual conjunto de dados deseja analisar:\n");
        printf(" [1] Dados aleatórios.\n [2] Dados ordenados.\n [3] Dados quase ordenados.\n >> ");
        scanf("%d" , &op);
        switch (op)
        {
        case 0:
            printf("\nSaindo...");
            break;
        case 1:
            printf("\nIniciando análise com dados aleatórios...\n\n");
            dadosAleatorios();
            printf(" [1] Continuar.\n [0] Sair.\n >> ");
            scanf("%d", &op);
            break;
        case 2:
            printf("\nIniciando análise com dados ordenados...\n\n");
            dadosOrdenados();
            printf(" [1] Continuar.\n [0] Sair.\n >> ");
            scanf("%d", &op);
            break;
        case 3:
            printf("\nIniciando análise com os dados quase ordenados...\n\n");
            dadosQuaseOrdenados();
            printf(" [1] Continuar.\n [0] Sair.\n >> ");
            scanf("%d", &op);
            break;
        default:
            break;
        }
    }while(op!=0 && (op==1 || op==2 || op==3));
    
    return 0;
}

void dadosOrdenados(){
    // Inicialização de atributos especificos de cada estrutura
    int colisoesHashEnd = 0, colisoesHashEnc = 0, rotacoesAvl = 0, alturaInsercaoAbb = 0, alturaRemocaoAbb = 0, alturaInsercaoAvl = 0, alturaRemocaoAvl;


    // as variaveis abaixo devem fazer a soma do tempo das interações
    double tempoInsereABB=0 , tempoRemoveABB=0 , tempoBuscaABB=0;
    double tempoInsereAVL=0 , tempoRemoveAVL=0 , tempoBuscaAVL=0;
    double tempoInsereHash=0 , tempoRemoveHash=0 , tempoBuscaHash=0;
    double tempoInsereHashEND=0 , tempoRemoveHashEND=0 , tempoBuscaHashEND=0;


    int vetHashEnd[TAM];
    Lista *vetHashEnc[TAM];
    Arv *abb = criar_arv();
    Avl *avl = criar_avl();

    
    FILE *f = fopen("../dados/dados_ordenado.txt", "r");
    if(f == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Inicializando com 0 os valores da tabela hash por endereçamento aberto
    for(int i=0;i<TAM;i++){
        inserirT(VAZIO, vetHashEnd, TAM, &colisoesHashEnd);
    }

    // Inicializando as listas como NULL na tabela hash com encadeamento separado
    for(int i=0;i<TAM;i++){
        vetHashEnc[i] = NULL;
    }
    

    int num, i;
    // calculo do tempo de inserção da tabela hash com endereçamendo aberto
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);
        
        tempoInsereHash += calcTempoInsereHash(vetHashEnd, num, TAM, &colisoesHashEnd);
    }
    rewind(f);

    // calculo do tempo de inserção da tabela hash com encadeamento separado
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);
        
        tempoInsereHashEND += calcTempoInsereHashEND(num, vetHashEnc, TAM, &colisoesHashEnc);
    }
    rewind(f);

    // Calculo do tempo de inserção da árvore binária de busca
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);
        
        tempoInsereABB += calcTempoInsereArvore(abb, num);
    }
    alturaInsercaoAbb = altura_abb(abb);
    rewind(f);

    // calculo do tempo de inserção da árvore avl
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);
        
        tempoInsereAVL += calcTempoInsereAVL(avl, num, &rotacoesAvl);
    }
    alturaInsercaoAvl = altura_avl(avl);
    rewind(f);


    //Busca tabela hash por endereçamento aberto
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaHash += calcTempoBuscaHash(vetHashEnd, num, TAM);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaHash += calcTempoBuscaHash(vetHashEnd, x, TAM);
    }
    rewind(f);

    //Busca tabela hash por encadeamento separado
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaHashEND += calcTempoBuscaHashEND(num, vetHashEnc, TAM);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaHashEND += calcTempoBuscaHashEND(x, vetHashEnc, TAM);
    }
    rewind(f);


    //Busca na ABB
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaABB += calcTempoBuscaArvore(abb, num);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaABB += calcTempoBuscaArvore(abb, x);
    }
    rewind(f);

    //Busca na AVL
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaAVL += calcTempoBuscaAVL(avl, num);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaAVL += calcTempoBuscaAVL(avl, x);
    }
    rewind(f);


    //Remoção 10% tabela hash por endereçamento aberto
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveHash += calcTempoRemoveHash(vetHashEnd, num, TAM);
    }
    rewind(f);

    //Remoção 10% tabela hash por encadeamento separado
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveHashEND += calcTempoRemoveHashEND(num, vetHashEnc, TAM);
    }
    rewind(f);

    //Remoção 10% ABB
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveABB += calcTempoRemoveArvore(abb, num);
    }
    alturaRemocaoAbb = altura_abb(abb);
    rewind(f);

    //Remoção 10% AVL
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveAVL += calcTempoRemoveAVL(avl, num, &rotacoesAvl);
    }
    alturaRemocaoAvl = altura_avl(avl);
    rewind(f);

    printf("\t\tForam inseridos %d elementos!\n\n", TAM);
    printf("TEMPO TOTAL DE INSERCOES:\n");
    printf("Tempo de insercao dos elementos na tabela hash por enderecamento aberto: %.5f\n", tempoInsereHash);
    printf("Tempo de insercao dos elementos na tabela hash por encadeamento separado: %.5f\n", tempoInsereHashEND);
    printf("Tempo de insercao dos elementos na ABB: %.5f\n", tempoInsereABB);
    printf("Tempo de insercao dos elementos na AVL: %.5f\n\n", tempoInsereAVL);

    printf("TEMPO MEDIO DE INSERCOES:\n");
    printf("Tempo de insercao dos elementos na tabela hash por enderecamento aberto: %.5f\n", tempoInsereHash/50000);
    printf("Tempo de insercao dos elementos na tabela hash por encadeamento separado: %.5f\n", tempoInsereHashEND/50000);
    printf("Tempo de insercao dos elementos na ABB: %.5f\n", tempoInsereABB/50000);
    printf("Tempo de insercao dos elementos na AVL: %.5f\n\n", tempoInsereAVL/50000);
    
    printf("QUANTIDADE DE COLISOES/ROTACOES REALIZADAS NA INSERCAO:\n");
    printf("Tabela hash de enderecamento aberto: %d colisoes\n" , colisoesHashEnd);
    printf("Tabela hash de encadeamento separado: %d colisoes\n" , colisoesHashEnc);
    printf("Arvore AVL: %d rotacoes\n\n", rotacoesAvl);

    printf("TEMPO TOTAL DE BUSCA:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoBuscaHash);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoBuscaHashEND);
    printf("Arvore ABB: %.5f\n", tempoBuscaABB);
    printf("Arvore AVL: %.5f\n\n", tempoBuscaAVL);

    printf("TEMPO MEDIO DE BUSCA:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoBuscaHash/50000);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoBuscaHashEND/50000);
    printf("Arvore ABB: %.5f\n", tempoBuscaABB/50000);
    printf("Arvore AVL: %.5f\n\n", tempoBuscaAVL/50000);

    printf("TEMPO TOTAL DE REMOCAO:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoRemoveHash);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoRemoveHashEND);
    printf("Arvore ABB: %.5f\n", tempoRemoveABB);
    printf("Arvore AVL: %.5f\n\n", tempoRemoveAVL);

    printf("TEMPO MEDIO DE REMOCAO:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoRemoveHash/50000);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoRemoveHashEND/50000);
    printf("Arvore ABB: %.5f\n", tempoRemoveABB/50000);
    printf("Arvore AVL: %.5f\n", tempoRemoveAVL/50000);

    printf("Rotacoes realizadas na remocao: %d\n\n", rotacoesAvl);

    printf("ALTURAS FINAIS DAS ARVORES:\n");
    printf("ABB apos as insercoes: %d\n", alturaInsercaoAbb);
    printf("ABB apos as remocoes: %d\n", alturaRemocaoAbb);
    printf("AVL apos as insercoes: %d\n", alturaInsercaoAvl);
    printf("AVL apos as remocoes: %d\n", alturaRemocaoAvl);
}

void dadosAleatorios(){
    FILE *f = fopen("../dados/dados_aleatorio.txt", "r");
    if(f == NULL){
        printf("Erro ao abrir o arquivo!\n");
    }

    // Inicialização de atributos especificos de cada estrutura
    int colisoesHashEnd = 0, colisoesHashEnc = 0, rotacoesAvl = 0, alturaInsercaoAbb = 0, alturaRemocaoAbb = 0, alturaInsercaoAvl = 0, alturaRemocaoAvl;


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
    
    // calculo do tempo de inserção da tabela hash com endereçamendo aberto
    int num, i;
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);

        tempoInsereHash += calcTempoInsereHash(vetHashEnd, num, TAM, &colisoesHashEnd);
    }
    rewind(f);

    // calculo do tempo de inserção da tabela hash com encadeamento separado
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);

        tempoInsereHashEND += calcTempoInsereHashEND(num, vetHashEnc, TAM, &colisoesHashEnc);
    }
    rewind(f);

    // Calculo do tempo de inserção da árvore binária de busca
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);

        tempoInsereABB += calcTempoInsereArvore(abb, num);
    }
    alturaInsercaoAbb = altura_abb(abb);
    rewind(f);

    // calculo do tempo de inserção da árvore avl
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);

        tempoInsereAVL += calcTempoInsereAVL(avl, num, &rotacoesAvl);
    }
    alturaInsercaoAvl = altura_avl(avl);
    rewind(f);


    //Busca tabela hash por endereçamento aberto
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaHash += calcTempoBuscaHash(vetHashEnd, num, TAM);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaHash += calcTempoBuscaHash(vetHashEnd, x, TAM);
    }
    rewind(f);

    //Busca tabela hash por encadeamento separado
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaHashEND += calcTempoBuscaHashEND(num, vetHashEnc, TAM);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaHashEND += calcTempoBuscaHashEND(x, vetHashEnc, TAM);
    }
    rewind(f);

    //Busca na ABB
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaABB += calcTempoBuscaArvore(abb, num);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaABB += calcTempoBuscaArvore(abb, x);
    }
    rewind(f);

    //Busca na AVL
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaAVL += calcTempoBuscaAVL(avl, num);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaAVL += calcTempoBuscaAVL(avl, x);
    }
    rewind(f);


    //Remoção 10% tabela hash por endereçamento aberto
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveHash += calcTempoRemoveHash(vetHashEnd, num, TAM);
    }
    rewind(f);

    //Remoção 10% tabela hash por encadeamento separado
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveHashEND += calcTempoRemoveHashEND(num, vetHashEnc, TAM);
    }
    rewind(f);

    //Remoção 10% ABB
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveABB += calcTempoRemoveArvore(abb, num);
    }
    alturaRemocaoAbb = altura_abb(abb);
    rewind(f);

    //Remoção 10% AVL
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveAVL += calcTempoRemoveAVL(avl, num, &rotacoesAvl);
    }
    alturaRemocaoAvl = altura_avl(avl);
    rewind(f);

    printf("\t\tForam inseridos %d elementos!\n\n", TAM);
    printf("TEMPO TOTAL DE INSERCOES:\n");
    printf("Tempo de insercao dos elementos na tabela hash por enderecamento aberto: %.5f\n", tempoInsereHash);
    printf("Tempo de insercao dos elementos na tabela hash por encadeamento separado: %.5f\n", tempoInsereHashEND);
    printf("Tempo de insercao dos elementos na ABB: %.5f\n", tempoInsereABB);
    printf("Tempo de insercao dos elementos na AVL: %.5f\n\n", tempoInsereAVL);

    printf("TEMPO MEDIO DE INSERCOES:\n");
    printf("Tempo de insercao dos elementos na tabela hash por enderecamento aberto: %.5f\n", tempoInsereHash/50000);
    printf("Tempo de insercao dos elementos na tabela hash por encadeamento separado: %.5f\n", tempoInsereHashEND/50000);
    printf("Tempo de insercao dos elementos na ABB: %.5f\n", tempoInsereABB/50000);
    printf("Tempo de insercao dos elementos na AVL: %.5f\n\n", tempoInsereAVL/50000);
    
    printf("Quantidade de colisoes/rotacoes realizadas na insercao:\n");
    printf("Tabela hash de enderecamento aberto: %d colisoes\n" , colisoesHashEnd);
    printf("Tabela hash de encadeamento separado: %d colisoes\n" , colisoesHashEnc);
    printf("Arvore AVL: %d rotacoes\n\n", rotacoesAvl);

    printf("TEMPO TOTAL DE BUSCA:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoBuscaHash);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoBuscaHashEND);
    printf("Arvore ABB: %.5f\n", tempoBuscaABB);
    printf("Arvore AVL: %.5f\n\n", tempoBuscaAVL);

    printf("TEMPO MEDIO DE BUSCA:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoBuscaHash/50000);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoBuscaHashEND/50000);
    printf("Arvore ABB: %.5f\n", tempoBuscaABB/50000);
    printf("Arvore AVL: %.5f\n\n", tempoBuscaAVL/50000);

    printf("TEMPO TOTAL DE REMOCAO:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoRemoveHash);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoRemoveHashEND);
    printf("Arvore ABB: %.5f\n", tempoRemoveABB);
    printf("Arvore AVL: %.5f\n\n", tempoRemoveAVL);

    printf("TEMPO MEDIO DE REMOCAO:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoRemoveHash/50000);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoRemoveHashEND/50000);
    printf("Arvore ABB: %.5f\n", tempoRemoveABB/50000);
    printf("Arvore AVL: %.5f\n", tempoRemoveAVL/50000);

    printf("Rotacoes realizadas na remocao: %d\n\n", rotacoesAvl);

    printf("ALTURAS FINAIS DAS ARVORES:\n");
    printf("ABB apos as insercoes: %d\n", alturaInsercaoAbb);
    printf("ABB apos as remocoes: %d\n", alturaRemocaoAbb);
    printf("AVL apos as insercoes: %d\n", alturaInsercaoAvl);
    printf("AVL apos as remocoes: %d\n", alturaRemocaoAvl);
}

void dadosQuaseOrdenados(){
    // Inicialização de atributos especificos de cada estrutura
    int colisoesHashEnd = 0, colisoesHashEnc = 0, rotacoesAvl = 0, alturaInsercaoAbb = 0, alturaRemocaoAbb = 0, alturaInsercaoAvl = 0, alturaRemocaoAvl;


    // as variaveis abaixo devem fazer a soma do tempo das interações
    double tempoInsereABB=0 , tempoRemoveABB=0 , tempoBuscaABB=0;
    double tempoInsereAVL=0 , tempoRemoveAVL=0 , tempoBuscaAVL=0;
    double tempoInsereHash=0 , tempoRemoveHash=0 , tempoBuscaHash=0;
    double tempoInsereHashEND=0 , tempoRemoveHashEND=0 , tempoBuscaHashEND=0;


    int vetHashEnd[TAM];
    Lista *vetHashEnc[TAM];
    Arv *abb = criar_arv();
    Avl *avl = criar_avl();

    
    FILE *f = fopen("../dados/dados_quase_ordenado.txt", "r");
    if(f == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Inicializando com 0 os valores da tabela hash por endereçamento aberto
    for(int i=0;i<TAM;i++){
        inserirT(VAZIO, vetHashEnd, TAM, &colisoesHashEnd);
    }

    // Inicializando as listas como NULL na tabela hash com encadeamento separado
    for(int i=0;i<TAM;i++){
        vetHashEnc[i] = NULL;
    }

    int num, i;
    // calculo do tempo de inserção da tabela hash com endereçamendo aberto
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);
        
        tempoInsereHash += calcTempoInsereHash(vetHashEnd, num, TAM, &colisoesHashEnd);
    }
    rewind(f);

    // calculo do tempo de inserção da tabela hash com encadeamento separado
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);
        
        tempoInsereHashEND += calcTempoInsereHashEND(num, vetHashEnc, TAM, &colisoesHashEnc);
    }
    rewind(f);

    // Calculo do tempo de inserção da árvore binária de busca
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);
        
        tempoInsereABB += calcTempoInsereArvore(abb, num);
    }
    alturaInsercaoAbb = altura_abb(abb);
    rewind(f);

    // calculo do tempo de inserção da árvore avl
    for(i=0;i<TAM;i++){
        fscanf(f, "%d", &num);
        
        tempoInsereAVL += calcTempoInsereAVL(avl, num, &rotacoesAvl);
    }
    alturaInsercaoAvl = altura_avl(avl);
    rewind(f);


    //Busca tabela hash por endereçamento aberto
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaHash += calcTempoBuscaHash(vetHashEnd, num, TAM);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaHash += calcTempoBuscaHash(vetHashEnd, x, TAM);
    }
    rewind(f);

    //Busca tabela hash por encadeamento separado
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaHashEND += calcTempoBuscaHashEND(num, vetHashEnc, TAM);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaHashEND += calcTempoBuscaHashEND(x, vetHashEnc, TAM);
    }
    rewind(f);

    //Busca na ABB
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaABB += calcTempoBuscaArvore(abb, num);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaABB += calcTempoBuscaArvore(abb, x);
    }
    rewind(f);

    //Busca na AVL
    for(i=0;i<TAM/2;i++){
        fscanf(f, "%d", &num);
        tempoBuscaAVL += calcTempoBuscaAVL(avl, num);
    }
    for(i=0;i<TAM/2;i++){
        int x = 1000000001 + i;
        tempoBuscaAVL += calcTempoBuscaAVL(avl, x);
    }
    rewind(f);


    //Remoção 10% tabela hash por endereçamento aberto
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveHash += calcTempoRemoveHash(vetHashEnd, num, TAM);
    }
    rewind(f);

    //Remoção 10% tabela hash por encadeamento separado
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveHashEND += calcTempoRemoveHashEND(num, vetHashEnc, TAM);
    }
    rewind(f);

    //Remoção 10% ABB
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveABB += calcTempoRemoveArvore(abb, num);
    }
    alturaRemocaoAbb = altura_abb(abb);
    rewind(f);

    //Remoção 10% AVL
    for(i=0;i<5000;i++){
        fscanf(f, "%d", &num);
        tempoRemoveAVL += calcTempoRemoveAVL(avl, num, &rotacoesAvl);
    }
    alturaRemocaoAvl = altura_avl(avl);
    rewind(f);

    printf("\t\tForam inseridos %d elementos!\n\n", TAM);
    printf("TEMPO TOTAL DE INSERCOES:\n");
    printf("Tempo de insercao dos elementos na tabela hash por enderecamento aberto: %.5f\n", tempoInsereHash);
    printf("Tempo de insercao dos elementos na tabela hash por encadeamento separado: %.5f\n", tempoInsereHashEND);
    printf("Tempo de insercao dos elementos na ABB: %.5f\n", tempoInsereABB);
    printf("Tempo de insercao dos elementos na AVL: %.5f\n\n", tempoInsereAVL);

    printf("TEMPO MEDIO DE INSERCOES:\n");
    printf("Tempo de insercao dos elementos na tabela hash por enderecamento aberto: %.5f\n", tempoInsereHash/50000);
    printf("Tempo de insercao dos elementos na tabela hash por encadeamento separado: %.5f\n", tempoInsereHashEND/50000);
    printf("Tempo de insercao dos elementos na ABB: %.5f\n", tempoInsereABB/50000);
    printf("Tempo de insercao dos elementos na AVL: %.5f\n\n", tempoInsereAVL/50000);
    
    printf("QUANTIDADE DE COLISOES/ROTACOES REALIZADAS NA INSERCAO:\n");
    printf("Tabela hash de enderecamento aberto: %d colisoes\n" , colisoesHashEnd);
    printf("Tabela hash de encadeamento separado: %d colisoes\n" , colisoesHashEnc);
    printf("Arvore AVL: %d rotacoes\n\n", rotacoesAvl);

    printf("TEMPO TOTAL DE BUSCA:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoBuscaHash);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoBuscaHashEND);
    printf("Arvore ABB: %.5f\n", tempoBuscaABB);
    printf("Arvore AVL: %.5f\n\n", tempoBuscaAVL);

    printf("TEMPO MEDIO DE BUSCA:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoBuscaHash/50000);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoBuscaHashEND/50000);
    printf("Arvore ABB: %.5f\n", tempoBuscaABB/50000);
    printf("Arvore AVL: %.5f\n\n", tempoBuscaAVL/50000);

    printf("TEMPO TOTAL DE REMOCAO:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoRemoveHash);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoRemoveHashEND);
    printf("Arvore ABB: %.5f\n", tempoRemoveABB);
    printf("Arvore AVL: %.5f\n\n", tempoRemoveAVL);

    printf("TEMPO MEDIO DE REMOCAO:\n");
    printf("Tabela hash com enderecamento aberto: %.5f\n", tempoRemoveHash/50000);
    printf("Tabela hash com encadeamento separado: %.5f\n", tempoRemoveHashEND/50000);
    printf("Arvore ABB: %.5f\n", tempoRemoveABB/50000);
    printf("Arvore AVL: %.5f\n", tempoRemoveAVL/50000);

    printf("Rotacoes realizadas na remocao: %d\n\n", rotacoesAvl);

    printf("ALTURAS FINAIS DAS ARVORES:\n");
    printf("ABB apos as insercoes: %d\n", alturaInsercaoAbb);
    printf("ABB apos as remocoes: %d\n", alturaRemocaoAbb);
    printf("AVL apos as insercoes: %d\n", alturaInsercaoAvl);
    printf("AVL apos as remocoes: %d\n", alturaRemocaoAvl);
}