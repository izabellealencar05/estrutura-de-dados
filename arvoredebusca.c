#include <stdio.h>
#include <stdlib.h>
#include <time.h>

////DECLARACAO DE ESTRUTURAS//////

struct no{
    int numero;
    struct no *esquerda;
    struct no *direita;
};


///////FUNCAO QUE INSERE UM NO NA ARVORE/////

struct no *inserir(struct no *raiz, int numero){
        if (raiz == NULL){
            raiz = (struct no *) malloc(sizeof(struct no));
            raiz -> numero = numero;
            raiz -> esquerda = NULL;
            raiz -> direita = NULL;
        }else {
            if(numero < raiz -> numero){
                raiz -> esquerda = inserir(raiz -> esquerda, numero);
            } else if (numero > raiz -> numero){
                raiz -> direita = inserir(raiz -> direita, numero);
            }
        }
        return raiz;
};

///////FUNCAO QUE BUSCA UM NO NA ARVORE////////

void buscar(struct no *raiz, int numero){
    if(raiz == NULL){
        printf("nao achei!");
    } else if(raiz -> numero == numero){
        printf("achei!!!!");
    } else if(numero < raiz -> numero){
        buscar(raiz -> esquerda, numero);
    } else{
        buscar(raiz -> direita, numero);
    }
}

/////////FUNCAO QUE NAVEGA A ARVORA EM ORDEM///////

void navegar(struct no *raiz){
    if(raiz != NULL){
        navegar(raiz -> esquerda);
        printf("%d\t", raiz -> numero);
        navegar(raiz -> direita);
    }
}

////////FUNCAO QUE DESENHA UM MENU NA TELA////////

int menu(){
    int opcao;
    printf("\n");
    printf("========================================\n");
    printf("|                 MENU                 |\n");
    printf("========================================\n");
    printf("|    1 - inserir                       |\n");
    printf("|    2 - buscar                        |\n");
    printf("|    3 - navegar                       |\n");
    printf("|    4 - construir arvore               |\n");
    printf("|    5 - sair                           |\n");
    printf("========================================\n");
    printf("digite a opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

//////////FUNCAO PRINCIPAL DE EXECUCAO DO PROGRAMA//////

int main(){
    struct no *raiz = NULL;
    int opcao = 0;
    int numero = 0;
    int i = 0;

    /////INICIALIZACAO DE ALEATORIEDADE//////////
    time_t t;
    srand((unsigned) time(&t));

    while(opcao != 5){
        opcao = menu();

        switch (opcao){
            case 1:

                printf("digite um numero: ");
                scanf("%d", &numero);
                raiz = inserir(raiz, numero);
                break;

            case 2:

                printf("digite o numero: ");
                scanf("%d", &numero);
                buscar(raiz, numero);
                break;

            case 3:

                navegar(raiz);

                break;

            case 4:
                for(i = 0; i < 1000; i++){
                    raiz = inserir(raiz, rand());
                }
                break;
        }
    }
}
