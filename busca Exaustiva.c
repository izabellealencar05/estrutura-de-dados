#include <stdio.h>
#include <stdlib.h>

//Declaracao de variaveis
int vetor[10000];
int i = 0;
int busca = 0;
int achei = 0;


//funcao principal
int main(){
    for (i = 0;i <10000; i++){
        vetor[i] = (rand() %10000);
    }
//Perguntar o parametro de busca
    printf("digite o valor a ser buscado: ");
    scanf("%d", &busca);
//busca propriamente dita
    achei = -1;
    for(i = 0; i < 10000; i++){
        if(vetor[i] == busca){
            achei = i;
        }
    }
    if (achei == -1){
        printf("nao existe!");
    } else{
        printf("achei na posicao %d\n", achei);
    }
}
