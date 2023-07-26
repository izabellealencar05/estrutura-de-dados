#include <stdio.h>

int vetorOriginal[10];
int vetorInvertido[10];
int i = 0;

//funcao principal

int main(){
    //limpeza da memoria
    for (i = 0 ; i < 10; i++){
        vetorOriginal[i] = 0;
        vetorInvertido[i] = 0;
    }
    //preenchimento do vetor
    for (i = 0; i < 10 ; i++){
        printf("digite o valoor da posicao %d do vetor: ", i);
        scanf("%d", &vetorOriginal[i]);
    }
    //inversao do vetor
    for(i = 9; i >= 0 ; i--){
        vetorInvertido[9-i] = vetorOriginal[i];
    }
    //impressaqo dos vetores
    for (i = 0; i < 10; i++){
        printf("vetorOriginal[%d] = %d\n", i, vetorOriginal[i]);
    }
    printf("\n");
    for (i = 0; i < 10; i++){
        printf("vetorInvertido[%d] = %d\n", i, vetorInvertido[i]);
    }

}

