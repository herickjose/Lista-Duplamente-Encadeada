#include "no.h"

No *criaNo(int info){

    No *novo = malloc(sizeof(No));
    
    if(novo == NULL){
        perror("ERRO NO MALLOC!\n");
        exit(1);
    }
    
    else{
        novo->chave = info;
        novo->proximo = NULL;
        novo->anterior = NULL;

        return novo;
    }
}