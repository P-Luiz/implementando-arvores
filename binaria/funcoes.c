#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

//função para pausar o programa e esperar o usuario digitar enter
void esperar(){
    system(green"read -p 'digite ENTER para continuar...'var"reset);
}

//função para imprimir a lista de contatos
void imprimir(no *aux,int *cont){
    if (aux -> left != NULL){
        imprimir(aux->left,cont);
    }
    printf("%-7d %-11s %-9d",cont, aux->nome, aux->telefone);
    (*cont) ++;
    imprimir(aux->right,cont);
}

//função para adicionar um contato
no* adicionar(no *raiz,char nome[50], int telefone){
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
        return raiz;
    }
    else{
        no *aux = raiz;
        int num;
        while(1){
            num = strcmp(aux->nome,novo->nome);
            if(num < 0 ){
                if (aux -> right == NULL){
                    aux -> right = novo;
                    break;
                }
                else{
                    aux = aux ->right;
                }
            }
            else if(num > 0){
                if(aux -> left == NULL){
                    aux-> left = novo;
                    break;
                }
                else{
                    aux = aux->left;
                }
            }
            else{
                if (aux -> left == NULL){
                    aux -> left = novo;
                    break;
                }
                else{
                    aux = aux ->left;
                }
            }
        }
        return raiz;
    }
}