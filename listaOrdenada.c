#include "listaOrdenada.h"

void insereOrdenado(ListaDuplamente *LD, int informacao){

    if(LD->inicio != NULL){
        if(informacao <= LD->inicio->chave){
            insereInicio(LD, informacao);
        }
        
        else if(informacao >= LD->fim->chave){
            insereFinal(LD, informacao);
        }
        
        else{
            No *novo = criaNo(informacao);

            if(informacao >= LD->auxiliar->chave){
                while(informacao >= LD->auxiliar->proximo->chave && LD->auxiliar->proximo != LD->fim){
                    LD->auxiliar = LD->auxiliar->proximo;
                }

                novo->proximo = LD->auxiliar->proximo;
                novo->anterior = LD->auxiliar;
                LD->auxiliar->proximo->anterior = novo;
                LD->auxiliar->proximo = novo;
            }
            
            else{
                while(informacao <= LD->auxiliar->anterior->chave && LD->auxiliar->anterior != LD->inicio){
                    LD->auxiliar = LD->auxiliar->anterior;
                }

                novo->proximo = LD->auxiliar;
                novo->anterior = LD->auxiliar->anterior;
                LD->auxiliar->anterior->proximo = novo;
                LD->auxiliar->anterior = novo;
            }
        }
    }
    
    else{
        insereInicio(LD, informacao);
    }
}

ListaDuplamente *juntarListas(ListaDuplamente *L1, ListaDuplamente *L2){

    ListaDuplamente *L3 = malloc(sizeof(ListaDuplamente));

    while(L1->inicio != NULL || L2->inicio != NULL){
        if(L1->inicio != NULL && L2->inicio != NULL){
            if(L1->inicio >= L2->inicio){
                insereNodeFinal(L3, L2->inicio);
            }
            
            else{
                insereNodeFinal(L3, L1->inicio);
                L1->inicio = L1->inicio->proximo;
            }
        }
        
        else{
            if(L3->inicio == NULL){
                free(L3);
                return NULL;
            }
            
            else{
                if(L1->inicio == NULL){
                    if(L2->inicio == NULL){
                        free(L3);
                        return NULL;
                    }
                    
                    free(L3);
                    return L2;
                }
                
                else{
                    if(L1->inicio == NULL){
                        free(L3);
                        return NULL;
                    }
                    
                    free(L3);
                    return L1;
                    }
            }       
        }   
    }
    return L3;
}   