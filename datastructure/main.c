#include <stdio.h>
#include <stdlib.h>
#include "hashEND/lista.h"
#include "hashEND/tabelaHashEnd.h"
#include "avl/avl.h"


int main(){
    Lista *tabela[10];

    for (int i = 0; i < 10; i++){
        tabela[i] = criarLista();
    }
    
    inserirEND(10 , tabela , 10);
    inserirEND(20 , tabela , 10);
    inserirEND(15 , tabela , 10);
    exibirTabelaEND(tabela , 10);

    Avl *a = criar_avl();
    inserir_avl(a, 3);
    inserir_avl(a, 1);
    inserir_avl(a, 2);
}