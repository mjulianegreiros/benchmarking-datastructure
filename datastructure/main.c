#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int main(){

    int vet[10];

    for(int i=0;i<10;i++){
        vet[i] = 0;
    }


    inserir(10 , vet , 10);
    inserir(15 , vet , 10);
    inserir(326 , vet , 10);
    inserir(516 , vet , 10);

    exibirTabela(vet , 10);

    buscar(516,  vet , 10);

    remover(150 , vet , 10);
    printf("\n\n");
    exibirTabela(vet , 10);


}