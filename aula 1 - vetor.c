#include <stdio.h>
//declaração de var
int vetor[10];
int i = 0;

//função principal

int main(){
    //inicialização da memória
    for (i = 0 ; i < 10; i++){
            vetor[i] = 0;
    }
    //preenchimemto do vetor
    for (i = 0; i < 10 ; i++){
        printf("digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }
    //impressão do vetor
    for (i = 0 ; i < 10 ; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
}

