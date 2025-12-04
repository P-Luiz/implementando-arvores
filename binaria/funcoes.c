#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

//função para pausar o programa e esperar o usuario digitar enter
void esperar(){
    system(green"read -p 'digite ENTER para continuar...'var"reset);
}

//função para imprimir a lista de contatos
no imprimir(no *aux,int *cont){
    if (aux -> left != NULL){
        imprimir(no *aux->left);
    }
    printf("%-7d %-11s %-9d",cont, aux->nome, aux->telefone);
    *cont ++;
    imprimir(aux->right);
}

//função para adicionar um contato
void adicionar(no *raiz,char nome[50], int telefone){
    no *novo = malloc(sizeof (no));
    if (novo==NULL){
        printf(red"erro na alocação!\n"reset);
    }
    novo -> left = NULL;
    novo -> right = NULL;
    strcpy(novo->nome,nome);
    novo -> telefone = telefone;
    if(raiz == NULL){
        raiz = novo;
        return;
    }
    else{
        no *aux = raiz;
        int num;
        while(1){
            num = strcmp(aux->nome,novo->nome);
            if(num < 0 ){
                if (aux -> left == NULL){
                    aux -> left = novo;
                    return;
                }
                else{
                    aux = aux ->left;
                }
            }
            else if(num > 0){
                if(aux -> right == NULL){
                    aux-> right = novo;
                    return;
                }
                else{
                    aux = aux->right;
                }
            }
            else{
                if (aux -> left == NULL){
                    aux -> left = novo;
                    return;
                }
                else{
                    aux = aux ->left;
                }
            }
        }
    }
}