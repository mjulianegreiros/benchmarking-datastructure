#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int inserirT(int i , int* vet , int tam , int *colisoes){
    int count = 0;
    int posicao;
    do{
        posicao = funcHashAberta(i , count , tam);
        if(vet[posicao]==0){ // fazer função para o vetor iniciar com todas as posições igual a 0
            vet[posicao] = i;
            printf("Elemento inserido.\n");
            return 1;
        } else{
            count++;
            (*colisoes)++;
        }
    } while(vet[posicao]!=i && count<tam);

    if(count==tam){
        printf("A lista está completamente preenchida. Não foi possível inserir o elemento.\n");
        return 0;
    }
    
}

int buscarT(int i, int* vet , int tam){
    int posicao;
    int count=0;
    do{
        posicao = funcHashAberta(i , count , tam);
        if(vet[posicao]==i){
            printf("Chave encontrada na posição %d.\n" , posicao);
            return 1;
        } else{
            count++;
        }
    } while(vet[posicao]!=i && count<tam);
    
    if(count==tam){
        printf("Não foi possível encontrar o elemento.\n");
        return 0;
    }
    
}
void removerT(int i , int* vet , int tam){
    int posicao;
    int count=0;
    do{
        posicao = funcHashAberta(i , count , tam);
        if(vet[posicao]==i){
            printf("Chave removida da posição %d." , posicao);
            vet[posicao] = -1; //codigo para um elemento deletado
            return;
        } else{
            count++;
        }
    } while(vet[posicao]!=i && (int)count<tam);
    
    if(count==tam){
        printf("O elemento não pode ser removido pois não está na tabela.\n");
        return;
    }
}

void exibirTabela(int* vet , int tam){
    for(int i=0;i<tam;i++){
        printf("pos: %d-> %d\n" , i , vet[i]);
    }
}

int funcHashAberta(int chave , int tentativa , int tam){
    return (chave%tam + 3*tentativa*tentativa)%tam;
}
