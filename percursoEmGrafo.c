//PROGRAMA QUE IMPLEMENTA UM PERCURSO EM GRAFO//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//DECLARACAO DE CONSTANTES//
const int TAMANHO = 5;

//FUNCAO QUE CRIA O GRAFO//

void criar(int grafo[TAMANHO][TAMANHO], int aleatorio){
        int i = 0;
        int j = 0;
        int aresta = 0;
        //INCIALIZACAO DO GRAFO//

        for(i = 0; i < TAMANHO; i++){
            for(j = 0; j < TAMANHO; j++){
                grafo[i][j] = 0;
            }
        }

        //PREENCHIMENTO DO GRAFO//
        for(i = 0; i < (TAMANHO -1); i++){
            for(j = (i + 1); j < TAMANHO; j++){
                if(aleatorio){
                    aresta = (rand() % 2);
                } else{
                    printf("digite <1> se %d tem aresta com %d: ", i, j);
                    scanf("%d",&aresta);
                }
                grafo[i][j] = aresta;
                grafo[j][i] = aresta;
            }
        }
}
//FUNCAO QUE EXECUTA A DESCOBERTA DO CAMINHO//
int procurarPercursoRecursivo(int grafo[TAMANHO][TAMANHO],
                              int visitado[TAMANHO],
                              int inicio,
                              int fim){
    int vizinho = 0;
    int retorno = 0;

    if (inicio == fim){
        retorno = 1;
    } else {
        visitado[inicio] = 1;
        for (vizinho = 0; vizinho < TAMANHO; vizinho++){
            if((grafo[inicio][vizinho])&&(!visitado[vizinho])){
               if (procurarPercursoRecursivo(grafo, visitado, vizinho , fim)){
                    retorno = 1;
                    printf("%d <- ", vizinho);
                    break;
               }
            }
        }
    }
    return retorno;
}

int procurarPercurso(int grafo[TAMANHO][TAMANHO], int inicio, int fim){
    int i =0;
    int visitado[TAMANHO];
    int encontrei = 0;

    for(i = 0; i < TAMANHO; i++){
    visitado[i] = 0;
}
    encontrei = procurarPercursoRecursivo(grafo, visitado, inicio, fim);
    printf("%d\n", inicio);

    return encontrei;
}
//FUNCAO PRINCIPAL QUE EXECUTA O TAMANHO//
int main(){
    int grafo[TAMANHO][TAMANHO];
    int inicio =0;
    int fim = 0;

    criar(grafo, 0);

    printf("digite o vertice incial: ");
    scanf("%d", &inicio);

    printf("digiet o vertice final: ");
    scanf("%d", &fim);

    if(procurarPercurso(grafo, inicio, fim)){
        printf("ha um caminho!\n");
    } else{
        printf("nao ha um caminho!\n");
    }
}

