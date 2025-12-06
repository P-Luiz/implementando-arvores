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
                    printf(red"A lista de contatos esta vazia!\n"reset);
                    esperar();
                    break;
                }
                cont = 1;
                aux = raiz;
                printf("-------------------\n");
                printf("= C O N T A T O S =\n");
                printf("-------------------\n\n");
                printf("-----------------------------\n");
                printf("ORDEM |   NOME   |   NÚMERO\n");
                imprimir(aux,&cont);
                printf("-----------------------------\n\n");
                esperar()
                break;
            case 2:
                printf("Digite o nome do novo contato: \n");
                scanf(" %49[^\n]", nome);
                printf("Digite o telefone do novo contato: \n");
                scanf("%d",&telefone);
                raiz = adicionar(raiz,nome,telefone);
                printf("%s foi adicionado a lista de contatos\n",nome);
                esperar();
                break;
            case 3:
                if (raiz == NULL){
                    printf(red"Nenhum contato foi registrado!\n"reset);
                    break;
                }
                printf("digite o nome do contato que quer procurar: \n");
                scanf(" %49[^\n]", nome);
                cont = buscar(raiz,nome);
                esperar()
                break;
            case 4:
                if(raiz == NULL){
                    printf(red"não tem contatos pra editar!\n"reset);
                }
                aux = raiz;
                cont = 1;
                while(1){
                    system("clear");
                    imprimir(aux,&cont);
                    printf("Digite o nome do contato que quer editar: \n");
                    scanf(" %49[^\n]", nome);
                    cont = buscar(raiz,nome);
                    if (cont == 1 ){
                        break;
                    }
                }
                while(escolha != 4){
                    printf("---------------\n");
                    printf("= E D I T A R =\n");
                    printf("---------------\n\n");
                    printf("1 - Editar nome\n");
                    printf("2 - Editar Número\n");
                    printf("3 - Excluir contato\n");
                    printf("4 - Sair\n");
                    printf("Escolha: \n");
                    scanf("%d",&escolha);
                        system("clear");
                    switch(escolha){
                        case 1:
                            char nnome[50];
                            printf("digite o novo nome: \n");
                            scanf(" %49[^\n]", nnome);
                            raiz = trocar_nom(raiz,nome,nnome);
                            printf(green"Nome trocado com sucesso!\n"reset);
                            esperar()
                            break;
                        case 2:
                            printf("digite o novo número: \n");
                            scanf("%d",&telefone);
                            raiz = trocar_num(raiz,nome,telefone);
                            printf(green"Número trocado com sucesso!\n"reset);
                            esperar()
                            break;
                        case 3:
                            raiz = excluir(raiz,nome);
                            printf(green"Contato excluido!\n"reset)
                            esperar()
                            break;
                        case 4:
                            break;
                        default:
                            printf(red"selecione uma opção válida\n"reset);
                    }
                }
                break;
            case 5:
                if(raiz == NULL){
                    printf(red"Lista vazia!\n"reset);
                    break;
                }
                cont = 0;
                mostrar(raiz,cont);
                break;
            case 6:
                break;
            default:
                printf(red"Escolha Inválida!\n" reset);
                break;
        }
    }
    return 0;
}