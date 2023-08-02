#include <stdio.h>
#include <stdlib.h>
//Declaracao de variaveis

int vetor[10000];
int i = 0;
int j = 0;

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
    for (i = 0; i < 9999; i++){ //do primeiro ao penultimo
        for (j = (i + 1); j < 10000; j++){ //do proximo ao ultimo
            if (vetor [i] > vetor [j]) {
                int temp = vetor[i]; //pra trocar as variaveis, deve criar uma var temporaria
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
//impressao do vetor
    for (i = 0; i < 10000; i++){
        printf("%d\n", vetor[i]);
    }
}
