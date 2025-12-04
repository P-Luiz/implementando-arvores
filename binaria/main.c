#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(){
    no *raiz;
    raiz = NULL;
    no *aux;
    int escolha,cont,telefone;
    char nome[50];
    while(escolha != 6){
        system ("clear");
        printf("------------------------------\n");
        printf("= M E N U  P R I N C I P A L =\n");
        printf("------------------------------\n");
        printf("1 - Listar Contatos(A-Z)\n");
        printf("2 - Adicionar Contato\n");
        printf("3 - Buscar Contato\n");
        printf("4 - Editar Contato\n");
        printf("5 - Mostrar Estrutura\n");
        printf("6 - Sair\n\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        system("clear");
        switch(escolha){
            case 1:
                if(raiz == NULL){
                    printf(red"A lista de contatos esta vazia!"reset);
                    esperar();
                    break;
                }
                cont = 1;
                aux = raiz;
                printf("-------------------\n");
                printf("= C O N T A T O S =\n");
                printf("-------------------\n\n");
                printf("-----------------------------");
                printf("ORDEM |   NOME   |   NÚMERO\n");
                imprimir(aux,&cont);
                printf("-----------------------------");
                break;
            case 2:
                printf("Digite o nome do novo contato: \n");
                scanf("%s",&nome);
                printf("Digite o telefone do novo contato: \n");
                scanf("%d",&telefone);
                adicionar(raiz,nome,telefone);
                printf("%s foi adicionado a lista de contatos",nome);
                esperar();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf(red"Escolha Inválida!\n" reset);
                break;
        }
    }
    return 0;
}