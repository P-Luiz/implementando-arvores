#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

//função para pausar o programa e esperar o usuario digitar enter
void esperar(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf(green "Digite ENTER para continuar..." reset);
    getchar();
}

//função para imprimir a lista de contatos
void imprimir(no *aux,int *cont){
    if(aux == NULL){
        return;
    }
    imprimir(aux->left,cont);
    printf("%d%-6s|%-10s|%-9lld\n",*cont,"º", aux->nome, aux->telefone);
    (*cont) ++;
    imprimir(aux->right,cont);
}

//função para adicionar um contato
no* adicionar(no *raiz,char nome[50], long long int telefone){
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

//função para buscar um contato
int buscar (no *raiz,char nome[50]){
    int comp;
    while (1){
        comp = strcmp(raiz->nome,nome);
        if(comp == 0){
            printf("Contato encontrado:\nNOME:%s\nTELEFONE:%lld\n",nome,raiz->telefone);
            return 1;
        }
        else if(comp < 0 ){
            if(raiz->right == NULL){
                printf(red"Esse contato não existe na lista!\n"reset);
                return 0;
            }
            raiz = raiz -> right;
        }
        else if(comp > 0 ){
            if(raiz->left == NULL){
                printf(red"Esse contato não existe na lista!\n"reset);
                return 0;
            }
            raiz = raiz -> left;
        }
    }
}

//função para trocar o nome do contato
no *trocar_nom(no* raiz,char nome[50],char nnome[50]){
    no *aux = raiz;
    while(1){
        int comp = strcmp(aux->nome,nome);
        if(comp == 0){
            raiz = adicionar(raiz,nnome,aux->telefone);
            raiz = excluir(raiz,nome);
            return raiz;
        }
        else if(comp < 0 ){
            aux = aux -> right;
        }
        else{
            aux = aux -> left;
        }
    }
}

//função para trocar o número do contato
no *trocar_num(no* raiz,char nome[50],long long int telefone){
    int comp;
    no* aux = raiz;
    while(1){
        comp = strcmp(aux -> nome,nome);
        if (comp == 0){
            aux ->telefone = telefone;
            break;
        }
        else if(comp < 0){
            aux = aux ->right;
        }
        else if(comp > 0){
            aux = aux -> left;
        }
    }
    return raiz;
}

//função para excluir um contato
no *excluir(no *raiz,char nome[50]){
    if (strcmp(raiz->nome , nome) == 0){
        if(raiz -> left == NULL){
            no *aux = raiz ->right;
            free(raiz);
            return aux;
        }
        if(raiz -> right == NULL){
            no *aux = raiz ->left;
            free(raiz);
            return aux;
        }
        else if(raiz->right != NULL && raiz ->left != NULL){
            no*aux = raiz -> left;
            while (aux->right != NULL){
                aux = aux ->right;
            }
            strcpy(raiz->nome,aux->nome);
            raiz->telefone = aux->telefone;
            raiz ->left = excluir(raiz ->left,aux->nome);
        }
    }
    else if(strcmp(raiz->nome , nome) < 0){
        raiz -> right = excluir(raiz->right,nome);
    }
    else if(strcmp(raiz->nome , nome) > 0){
        raiz -> left  = excluir(raiz->left,nome);
    }
    return raiz;
}   

//função para mostrar a estrutura da arvore
void mostrar(no*raiz, int camada){
    if(raiz == NULL){
        return;
    }
    mostrar(raiz->right,camada+1);
    printf("\n");
    for (int i = 0;i < camada;i++){
        printf("\t");
    }
    printf("%s\n",raiz->nome);
    mostrar(raiz->left,camada+1);
}