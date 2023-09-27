#include <stdio.h>
#include <stdlib.h>

//a busca binaria so funciona se estiver ordenada

//Declaracao de variaveis
int vetor[10000];
int i = 0;
int busca = 0;
int inicio = 0;
int fim = 9999;
int meio = 0;


//funcao principal
int main(){
    for (i = 0;i <10000; i++){
        vetor[i] = i;
    }

//Perguntar o parametro de busca
    printf("digite o valor a ser buscado: ");
    scanf("%d", &busca);


//busca propriamente dita
    while (fim >= inicio){
        meio = ((inicio + fim)/2);

        if(busca == vetor[meio]){
            printf("achei! na posicao %d\n", meio);
            return 0;
        } else if (busca > vetor[meio]){
            inicio = (meio + 1);
        } else{
            fim = (meio - 1);
        }
   }
   printf("nao existe");
}

