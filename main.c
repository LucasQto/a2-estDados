#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esquerda, *direita;
} Arv;

void inserirArv(Arv **raiz, int numero){
    if(*raiz == NULL){
        *raiz = (Arv *) malloc(sizeof(Arv));
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        (*raiz)->valor = numero;
    }else{
        if(numero < (*raiz)->valor)
            inserirArv(&(*raiz)->esquerda, numero);
        if(numero > (*raiz)->valor)
            inserirArv(&(*raiz)->direita, numero);
    }
}

void preOrdem(Arv *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(Arv *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void intraOrdem(Arv *raiz) {
    if (raiz != NULL) {
        intraOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        intraOrdem(raiz->direita);
    }
}

void liberarArvore(Arv *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    Arv* raiz = NULL;
    int valores[10];
    int opcao;

    printf("Digite 10 numeros:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
        inserirArv(&raiz, valores[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1 - Pre-ordem\n");
        printf("2 - Pos-ordem\n");
        printf("3 - Intraordem\n");
        printf("9 - Sair\n");
        printf("Digite a opção que deseja: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Pre-ordem:\n");
                preOrdem(raiz);
                printf("\n");
                break;
            case 2:
                printf("Pos-ordem:\n");
                posOrdem(raiz);
                printf("\n");
                break;
            case 3:
                printf("Intraordem:\n");
                intraOrdem(raiz);
                printf("\n");
                break;
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 9);

    liberarArvore(raiz);
    return 0;
}
