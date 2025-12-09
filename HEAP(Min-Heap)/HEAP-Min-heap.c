#include <stdio.h>
#include <stdlib.h>

typedef struct{//struct do heap
    int *dados;
    int tamanho;
    int capacidade;
}heap;

heap* criarheap(int capacidade){ //alocação de memória do heap e do vetor
    heap *h = (heap*)malloc(sizeof(heap));
    h->dados = malloc(capacidade * sizeof(int));
    h->tamanho = 0;
    h->capacidade = capacidade;
    return h;
}

void trocar(int *a, int *b){//função para trocar indices e valores
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pai(int i){//definição da regra para pai
    return (i-1)/2;
}

int filhodir(int i){//definição da regra para filhos à direita
    return 2 *i+2;
}

int filhoesq(int i){//definição da regra para filhos à esquerda
    return 2 *i+1;
}

void subirheap(heap *h, int i){//sobe o dado se ele for menor que o pai
    while (i != 0 && h->dados[pai(i)] > h->dados[i]){
        trocar(&h->dados[pai(i)], &h->dados[i]);
        i = pai(i);
    }
}

 void inserir(heap *h,int valor){//função para inserir dados no heap
    if(h->tamanho == h->capacidade){
        printf("O Heap está cheio!\n");
        return;
    }
   
    int i = h->tamanho;
    h->dados[i] = valor;
    h->tamanho++;
    subirheap(h, i);
 }

 void descerheap(heap *h, int i) {//desce o dado se ele for maior

    int esq = filhoesq(i);
    int dir = filhodir(i);
    int menor = i;

    if (esq < h->tamanho && h->dados[esq] < h->dados[menor])
        menor = esq;

    if (dir < h->tamanho && h->dados[dir] < h->dados[menor])
        menor = dir;

    if (menor != i) {
        trocar(&h->dados[i], &h->dados[menor]);
        descerheap(h, menor);
    }
}

int removermin(heap *h){//remove o min-heap(raiz)
     if (h->tamanho == 0){
        printf("Heap vazio!\n");
        return -1;
    }
    int raiz = h->dados[0];
    h->dados[0] = h->dados[h->tamanho - 1];
    h->tamanho--;
    descerheap(h,0);

    return raiz;
}

void imprimirheap(heap *h){//imprime o heap
    for( int cont = 0;cont < h->tamanho;cont++){
        printf("%d:%d",cont,h->dados[cont]);
        printf("\n");
    }
}

int main(){
    int opcao, cap = 0,data;
    heap *h = NULL;

    do{
    
        printf("\n======================\n");
        printf("\n-------MIN-HEAP-------\n");
        printf("\n======================\n");
        printf("\n0 -Sair\n1 - Definir capacidade\n2 -Inserir\n3-Remover Min-heap\n4- Imprimir\n ");
        printf("\nEscolha uma opcao:\n");
        scanf("%d",&opcao);
        switch (opcao){
        case 0:
            system("clear");
            printf("\nSaindo...\n");
            break;
        case 1:
            system("clear");
            printf("Defina a capacidade do heap:\n");
            scanf("%d",&cap);
            h = criarheap(cap);
            break;
        case 2:
            if(h == NULL){
                printf("Insira a capacidade primeiro!\n");
                while (getchar() != '\n');
                break;
            }
            if(h->tamanho == h->capacidade){
                printf("Capacidade maxima atingida!\n");
                break;
            }
            printf("Insira um dado:\n");
            if (scanf("%d", &data) != 1) {
                while (getchar() != '\n');
                printf("Dado inválido.\n"); 
                break;
            }
            inserir(h,data);
            break;
        case 3:
            if(cap == 0 || h->tamanho == 0){
                printf("Heap vazio!\n");  
                while (getchar() != '\n');
                break;
            }
            printf("Removendo Min-Heap...\n");
            removermin(h);
            printf("Heap após remover: ");
            imprimirheap(h);
            break;
        case 4:
            
            if(cap == 0 || h->tamanho == 0){
                printf("Heap vazio!\n");  
                break;
            }
            printf("Heap atual:\n");
            imprimirheap(h);
            break;
        default:
            break;
        }
    }while(opcao!=0);
}
