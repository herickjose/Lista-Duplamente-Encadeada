#include "listaDuplamente.h"

ListaDuplamente *criaLista(){

    ListaDuplamente *LD = malloc(sizeof(ListaDuplamente));

    LD->inicio = NULL;
    LD->fim = NULL;
    LD->auxiliar = NULL;
    LD->tamanho = 0;

    return LD;
}

void insereNodeInicio(ListaDuplamente *LD, No *node){

    node->proximo = LD->inicio;

    if(LD->inicio == NULL){
        LD->inicio = node;
        LD->fim = node;
    }
    
    else{
        LD->inicio->anterior = node;
        LD->inicio = node;
    }
}

void insereNodeFinal(ListaDuplamente *LD, No *node){

    node->anterior = LD->fim;

    if(LD->inicio == NULL){
        LD->inicio = node;
        LD->fim = node;
    }
    
    else{
        LD->fim->proximo = node;
        LD->fim = node;
    }
}

void insereInicio(ListaDuplamente *LD, int informacao){

    No *novo = criaNo(informacao);
    novo->proximo = LD->inicio;

    if(LD->inicio == NULL){
        LD->inicio = novo;
        LD->fim = novo;
        LD->auxiliar = novo;
    }
    
    else{
        LD->inicio->anterior = novo;
        LD->inicio = novo;
    }
}

void insereFinal(ListaDuplamente *LD, int informacao){

    No *novo = criaNo(informacao);
    novo->anterior = LD->fim;

    if(LD->inicio == NULL){
        LD->inicio = novo;
        LD->fim = novo;
        LD->auxiliar = novo;
    }
    
    else{
        LD->fim->proximo = novo;
        LD->fim = novo;
    }
}

No *buscaChave(ListaDuplamente *LD, int informacao){

    No *atual = LD->inicio;

    while(atual != NULL){
        if(atual->chave == informacao){
            break;
        }
        else if(atual->chave != informacao){
            atual = atual->proximo;
        }
    }
    return atual;
}

void excluiInicio(ListaDuplamente *LD){

    if(LD != NULL){
        No *atual = LD->inicio;
        LD->inicio = atual->proximo;

        if(LD->inicio != NULL){
            LD->inicio->anterior = NULL;
        }

        free(atual);
    }
}

void excluiFinal(ListaDuplamente *LD){

    No *atual = LD->inicio;

    if(atual->proximo != NULL){
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual = atual->anterior;
        free(atual->proximo);
        atual->proximo = NULL;
    }
    
    else{
        free(LD->inicio);
        LD->inicio = NULL;
    }
}

void imprimeLista(ListaDuplamente *LD){

    int contador = 0;
    No *atual = LD->inicio;

    if(atual != NULL){
        printf("\n------------------ CONTEUDO DA LISTA ------------------\n");
        while(atual != NULL){
            printf("Posicao: %i\t Valor: %i\n", contador, atual->chave);
            atual = atual->proximo;
            contador++;
        }

        printf("-------------------------------------------------------\n");
    }
    
    else{
        printf("\n---------------------- LISTA VAZIA ---------------------\n");
    }
}

void limpaLista(ListaDuplamente *LD){

    No *atual = LD->inicio;
    int contador = 0;

    printf("\n---------------------- EXCLUINDO ---------------------\n");

    while(atual != NULL){
        No *temporario = atual;
        printf("Excluindo posicao: %i\t Valor: %i \t... OK!\n", contador, atual->chave);
        atual = atual->proximo;
        free(temporario);
        contador++;
    }
    
    printf("\n---------------------- LISTA LIMPA ---------------------\n");
    LD->inicio = NULL;
    LD->fim = NULL;
}

ListaDuplamente *deletaLista(ListaDuplamente *LD){

    limpaLista(LD);
    free(LD);
    printf("\n---------------------- LISTA DELETADA ---------------------\n");

    return NULL;
}