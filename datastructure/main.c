#include <stdio.h>
#include <stdlib.h>
#include "hashEND/lista.h"
#include "hashEND/tabelaHashEnd.h"


int main(){
    Lista *tabela[10];

    for (int i = 0; i < 10; i++){
        tabela[i] = criarLista();
    }
    
    inserirEND(10 , tabela , 10);
    inserirEND(20 , tabela , 10);
    inserirEND(15 , tabela , 10);
    inserirEND(38 , tabela , 10);
    inserirEND(35 , tabela , 10);
    inserirEND(12 , tabela , 10);
    inserirEND(1 , tabela , 10);
    inserirEND(5 , tabela , 10);
    inserirEND(9 , tabela , 10);
    inserirEND(100 , tabela , 10);
    inserirEND(107 , tabela , 10);
    exibirTabelaEND(tabela , 10);
}