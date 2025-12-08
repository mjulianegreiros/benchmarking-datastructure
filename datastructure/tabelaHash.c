#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int inserir(chave i , chave* vet){
    int count = 0;
    int posicao;
    do{
        posicao = funcHash(i , count , (sizeof(vet)/sizeof(chave)));
        if(vet[posicao]==0){ // fazer função para o vetor iniciar com todas as posições igual a 0
            vet[posicao] = i;
            printf("Elemento inserido.");
            return 1;
        } else{
            count++;
        }
    } while(vet[posicao]!=i && count<(sizeof(vet)/sizeof(chave)));

    if(count==(sizeof(vet)/sizeof(chave))){
        printf("A lista está completamente preenchida. Não foi possível inserir o elemento.");
        return 0;
    }
    
}

int buscar(chave i, chave* vet){
    int posicao;
    int count;
    do{
        posicao - funcHash(i , count , (sizeof(vet)/sizeof(chave)));
        if(vet[posicao]==i){
            printf("Chave encontrada na posição %d." , posicao);
            return 1;
        } else{
            count++;
        }
    } while (vet[posicao]!=i && count<(sizeof(vet)/sizeof(chave)));
    
    if(count==(sizeof(vet)/sizeof(chave))){
        printf("Não foi possível encontrar o elemento.");
        return 0;
    }
    
}
void remover(chave i , int tent, chave* vet);

void exibirTabela(chave* vet){
    for(i=0;i<(sizeof(vet)/sizeof(chave));i++){
        printf("%d\n" , vet[i]);
    }
}

int funcHash(chave chave , int tentativa , int tam){
    return chave%tam + 3*tentativa*tentativa;
}
