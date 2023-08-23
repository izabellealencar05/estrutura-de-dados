//PROGRAMA QUE IMPLEMNTA UMA LISTA DE DUPLO ENCADEAMENTO//
#include <stdio.h>
#include <stdlib.h>

//DECLARACAO DA ESTRUTURA DO NO//

struct no{
    int numero;
    struct no *anterior;
    struct no *proximo;
};

//DECLARACAO DE VARIAVEIS//

struct no *cabeca = NULL;

//FUNCAO QUE INSERE UM NO NA LISTA//

void inserir(int numero){
    //ALOCACAO DA MEMORIA//
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> anterior = NULL;
    novoNo -> proximo = NULL;

    if (cabeca == NULL){
        //caso facil a lista esta vazia//
        cabeca = novoNo;
    } else {
        //caso dificil a lista nao esta vazia
        struct no *ponteiro = cabeca;
        while (ponteiro -> proximo != NULL){
            ponteiro = ponteiro -> proximo;
        }
        //EXECUTA OS APONTAMENTOS//
        ponteiro -> proximo = novoNo;
        novoNo -> anterior = ponteiro;
    }
}
//FUNCAO QUE IMPRIME A LISTA//

void imprimir(){
    struct no *ponteiro = cabeca;
    while (ponteiro != NULL){
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }
    printf("=================\n");
}
//FUNCAO QUE REMOVE O NO DA LISTA//

void remover(int numero){
    struct no *ponteiro = cabeca;

    while (ponteiro != NULL){
        if (ponteiro -> numero == numero){
            if (ponteiro -> anterior == NULL){
                //EXCLUIR O PRIMEIRO NO DA LISTA
                cabeca = cabeca -> proximo;
                if (cabeca != NULL){
                    cabeca -> anterior = NULL;
                }
                free(ponteiro);
                ponteiro = cabeca;
            } else if (ponteiro -> proximo == NULL){
                struct no *temp = ponteiro;
                ponteiro = ponteiro -> anterior;
                ponteiro -> proximo = NULL;
                free(temp);
            } else {
            //EXCLUIR UM NO DO MEIO DA LISTA//
            struct no *temp = ponteiro;
            ponteiro = ponteiro -> anterior;
            temp -> anterior -> proximo = temp -> proximo;
            temp -> proximo -> anterior = temp -> anterior;
            free(temp);
            }
        }
        if (ponteiro != NULL){
            ponteiro = ponteiro -> proximo;
        }
    }
}

//FUNCAO PRINCIPAL DE EXECUCAO DO PROGRAMA//
int main(){
    remover(1);
    imprimir();

    inserir(1);
    remover(1);
    imprimir();

    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    remover(1);
    remover(5);
    remover(3);
    imprimir();
}
