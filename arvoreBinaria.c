/////////PROGRAMA QUE IMPLEMENTE UMA ARVORE BINARIA////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////DECLARACAO DE ESTRUTURAS////////
struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
};
///////// FUNCAO QUE INSERE UM NO NA ARVORE////////
struct no *inserir(struct no *raiz, int numero){
    if (raiz == NULL){
        raiz = (struct no *) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    } else{
        if ((rand() % 2)== 0){
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        } else{
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }

    return raiz;
};
/////////NAVEGACAO EM PRE-ORDEM///////////
void navegarPreordem(struct no *raiz){
    if(raiz != NULL){
        printf("%d\t", raiz -> numero);
        navegarPreordem(raiz -> esquerda);
        navegarPreordem(raiz -> direita);

    }
}
/////////NAVEGACAO EM ORDEM/////////
void navegarEmordem(struct no *raiz){
    if(raiz != NULL){
        navegarEmordem(raiz ->esquerda);
        printf("%d\t", raiz -> numero);
        navegarEmordem(raiz -> direita);
    }
}
//////////NAVEGACAO EM POS-ORDEM//////
void navegarPosordem(struct no *raiz){
    if(raiz != NULL){
        navegarPosordem(raiz -> esquerda);
        navegarPosordem(raiz -> direita);
        printf("%d\t", raiz -> numero);
    }
}
////////////FUNCAO PRINCIPAL///////
int main(){
///////DECLARACAO DE VARIAVEIS///////
    struct no *raiz = NULL;
///////INICIALIZACAO DE ALEATORIADADE/////
    time_t t;
    srand((unsigned)time(&t));
////////PREENCHIMENTO DA ARVORE////
    int i = 0;
    for (i = 0; i < 5; i++){
        raiz = inserir(raiz, i);
    }
/////NAVEGACAO/////
    printf("\n=================PRE-ORDEM==================\n");
    navegarPreordem(raiz);

    printf("\n=================EM-ORDEM===================\n");
    navegarEmordem(raiz);

    printf("\n=================POS-ORDEM==================\n");
    navegarPosordem(raiz);

}

