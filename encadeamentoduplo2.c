#include <stdio.h>
#include <stdlib.h>

/// Declaração da estrutura do nó ///

struct no {
    int numero;
    struct no *proximo;
};

/// Declaração de variáveis ///

struct no *cabeca;

/// Função que insere um nó na lista ///

void inserir(int numero){
    /// Alocação de memória ///
    struct no *novoNo = (struct no *)malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = cabeca;

    if (cabeca == NULL){
        cabeca = novoNo;
        novoNo -> proximo = cabeca;
    } else {
        struct no *ponteiro = cabeca;

        while ((*ponteiro).proximo != cabeca){
            ponteiro = ponteiro->proximo;
        }
        ponteiro->proximo = novoNo;
    }
}

void imprimir(){
    struct no *ponteiro = cabeca;

    if (ponteiro != NULL){
        while(1){
            printf("%d\n", ponteiro->numero);
            ponteiro = ponteiro->proximo;

            if (ponteiro == cabeca){
                break;
            }
        }
    }
    printf("======================\n");
}

void remover(){

}

int main(){
    imprimir();

    inserir(1);
    imprimir();

    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    imprimir();
}
