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
void esperar()

//função para imprimir a lista de contatos
void imprimir(no *aux,int *cont)

//função para adicionar um contato
void adicionar(no *raiz,char nome[50], int telefone)

#endif