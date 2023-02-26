#ifndef LISTADUPLAMENTE_H
#define LISTADUPLAMENTE_H

#include "no.h"

typedef struct listaDuplamente{

    int tamanho;
    No *inicio;
    No *fim;
    No *auxiliar;

}ListaDuplamente;

ListaDuplamente *criaLista();
void insereInicio(ListaDuplamente *LD, int informacao);
void insereNodeInicio(ListaDuplamente *LD, No *node);
void insereFinal(ListaDuplamente *LD, int informacao);
void insereNodeFinal(ListaDuplamente *LD, No *node);
void insereOrdenado(ListaDuplamente *LD, int informacao);
No *buscaChave(ListaDuplamente *LD, int informacao);
void excluiInicio(ListaDuplamente *LD);
void excluiFinal(ListaDuplamente *LD);
void imprimeLista(ListaDuplamente *LD);
void limpaLista(ListaDuplamente *LD);
ListaDuplamente *deletaLista(ListaDuplamente *LD);

#endif