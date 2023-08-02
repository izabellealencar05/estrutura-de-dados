#include <stdio.h>
#include <stdlib.h>


//Declaracao de variaveis
int vetor[10000];
int i = 0;
int troquei = 1;


//funcao principal
int main(){
    for (i = 0;i <10000; i++){
        vetor[i] = (rand() %10000);
    }

//impressao vetor
    for (i = 0; i < 10000; i++){
        printf("%d\n", vetor[i]);
    }


//ordenacao propriamente dita

    while (troquei){
        troquei = 0;

        for (i = 0; i < 9999; i++){
            if (vetor[i] > vetor[i + 1]){
                int temp = vetor [i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                troquei = 1;
            }
        }
    }

//impressao do vetor
    for (i = 0; i < 10000; i++){
        printf("%d\n", vetor[i]);
    }
}


