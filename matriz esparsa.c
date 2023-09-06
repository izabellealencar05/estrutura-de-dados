#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///DECLARACAO DE CONSTANTES

const int MODULO = 3;

///DECLARACAO DE ESTRUTURAS

struct no {
    int numero;
    struct no *proximoNo;
};
struct diretor{
    int resto;
    struct no *proximoNo;
    struct diretor *proximoDiretor;
};

///DECLARACAO DE VARIAVEIS///

struct diretor *cabeca = NULL;

///FUNCAO QUE PROCURA O DIRETOR CERTO///

struct diretor *procurarDiretor(int resto){
    struct diretor *ponteiro = cabeca;

///VARRENDO A LISTA ATE ENCONTRAR O RESTO CERTO OU CHEGAR NO FINAL///

    while ((ponteiro != NULL) && (ponteiro -> resto != resto)){
        ponteiro = ponteiro -> proximoDiretor;
    }

  if (ponteiro == NULL){

///CRIAR UM DIRETOR NOVO///
        ponteiro = (struct diretor *) malloc(sizeof(struct diretor));
        ponteiro -> resto = resto;
        ponteiro -> proximoNo = NULL;
        ponteiro -> proximoDiretor = cabeca;

        cabeca = ponteiro;
    }
    return ponteiro;
};

///FUNCAO QUE INSERE UM NO NA MATRIZ ESPARSA///

void inserir(int numero){
    struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);

    struct no *novoNo = (struct no *) malloc(sizeof(struct no));

    novoNo -> numero = numero;
    novoNo -> proximoNo = ponteiroDiretor -> proximoNo;

    ponteiroDiretor -> proximoNo = novoNo;
}

///FUNCAO QUE IMPRIME A MATRIZ ESPARSA///

void imprimir(){
    struct diretor *ponteiroDiretor = cabeca;

    printf("=============MATRIZ ESPARSA==============\n");
    while(ponteiroDiretor != NULL){
        struct no *ponteiroNo = ponteiroDiretor -> proximoNo;

        printf("%d:\t", ponteiroDiretor -> resto);
        while (ponteiroNo != NULL){
            printf("%d\t", ponteiroNo -> numero);
            ponteiroNo = ponteiroNo -> proximoNo;
        }
        printf("\n");
        ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
    }
}

void remover (int numero){
    struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);

    if (ponteiroDiretor -> proximoNo != NULL){
        if(ponteiroDiretor -> proximoNo -> numero == numero){
///CASO FACIL, EXCLUIR O PRIMEIRO NO DA LISTA///
            struct no *ponteiroExcluir = ponteiroDiretor -> proximoNo;
            ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
            free(ponteiroExcluir);
    }
    else {
        struct no *ponteiroAnterior = ponteiroDiretor -> proximoNo;

        while((ponteiroAnterior -> proximoNo != NULL)&&
              (ponteiroAnterior -> proximoNo -> numero != numero)){
                ponteiroAnterior = ponteiroAnterior -> proximoNo;
              }
              if(ponteiroAnterior -> proximoNo != NULL){
                struct no *ponteiroExcluir = ponteiroAnterior -> proximoNo;
                ponteiroAnterior ->proximoNo = ponteiroExcluir ->proximoNo;
                free(ponteiroExcluir);
              }
    }
}
}
///FUNCAO PRINCIPAL DE EXECUCAO DO PROGRAMA///

int main(){
    int i = 0;
    time_t t;
    int numero;

    srand((unsigned)time(&t));

    for(i = 0; i < 10; i++){
        inserir(rand());
    }
    imprimir();
    while(numero != -1){
        printf("digite um numero para excluir: ");
        scanf("%d", &numero);


    remover(numero);

    system("pause");
    system("cls");
    imprimir();
    }
}
