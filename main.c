#include "listaDuplamente.h"

int main(void){

    printf("INICIANDO O CODIGO: \n");

    ListaDuplamente *LD = criaLista();

    int opcao, valor;

    No *removido;

    do{
        printf("\n\t0 - SAIR\n\t1 - INSERIR NO INICIO\n\t2 - INSERIR NO FINAL\n\t3 - INSERIR ORDENADO\n\t4 - EXCLUIR INICIO\n\t5 - EXCLUIR FINAL\n\t6 - BUSCAR CHAVE\n\t7 - IMPRIMIR LISTA\n");

        printf("\nESCOLHA UMA OPCAO: ");
        scanf("%i", &opcao);

        switch(opcao){
            
            case 1:
                printf("\nDigite um valor: ");
                scanf("%i", &valor);
                insereInicio(LD, valor);
                break;
            
            case 2:
                printf("\nDigite um valor: ");
                scanf("%i", &valor);
                insereFinal(LD, valor);
                break;
            
            case 3:
                printf("\nDigite um valor: ");
                scanf("%i", &valor);
                insereOrdenado(LD, valor);
                break;
            
            case 4:
                printf("\nEXCLUINDO INICIO... \n");
                excluiInicio(LD);
                break;
            
            case 5:
                printf("\nEXCLUINDO FINAL... \n");
                excluiFinal(LD);
                break;
            
            case 6:
                printf("\nDigite um valor: ");
                scanf("%i", &valor);
                //buscaChave(LD, valor);
                removido = buscaChave(LD, valor);
                if(removido){
                    printf("\nVALOR ENCONTRADO: %i\n", removido->chave);
                }
                else{
                    printf("\nVALOR NAO ENCONTRADO!\n");
                }
                break;
            
            case 7:
                printf("\nIMPRIMINDO A LISTA... \n");
                imprimeLista(LD);
                break;
            
            default:
                if(opcao != 0){
                    printf("\nOPCAO INVALIDA!\n");
                }
        }
    }
    while(opcao != 0);

    return 0;
}