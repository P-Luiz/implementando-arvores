#ifndef funcoes_h
#define funcoes_h

typedef struct no{
    char nome[50];
    int telefone;
    struct no *left;
    struct no *right;
}no;

#define red "\033[31m" 
#define green "\033[32m"
#define blue "\033[34m"
#define magenta "\033[35m"
#define cyan    "\033[36m"
#define reset "\033[0m"

//função para pausar o programa e esperar o usuario digitar enter
void esperar();

//função para imprimir a lista de contatos
void imprimir(no *aux,int *cont);

//função para adicionar um contato
no *adicionar(no *raiz,char nome[50], int telefone);

//função para buscar um contato
int buscar (no *raiz,char nome[50]);

//função para mostrar a estrutura da arvore
void mostrar()

//função para trocar o nome do contato
no *trocar_nom(no* raiz,char nome[50],char nnome[50]);

//função para trocar o número do contato
no *trocar_num(no* raiz,char nome[50],int telefone);

//função para excluir um contato
no *excluir(no *raiz,char nome[50]);

//função para mostrar a estrutura da arvore
void mostrar(no*raiz, int camada);
#endif