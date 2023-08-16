////PROGRAMA DE LISTA DE ENCADEAMENTO SIMPLES////
 #include <stdio.h> 
 #include <stdlib.h>

////DECLARACAO DA ESTRUTURA DO NO////

 struct no{
 	int numero;
 	struct no *proximo;
 };
 
////DECLARACAO DE VARIAVEIS////
 struct no *cabeca = NULL;
 
////FUNCAO QUE INSERE UM NO NA LISTA////
 void inserir(int numero){
 	
////ALOCACAO DO ESPACO DE MEMORIA////
	struct no *NovoNo = (struct no *) malloc(sizeof(struct no));
	NovoNo -> numero = numero;
	NovoNo -> proximo = NULL;
	
	if (cabeca == NULL){
////CASO FACIL, A LISTA ESTA VAZIA////
		cabeca = NovoNo;
	} else{
////CASO DIFICIL, A LISTA NAO ESTA VAZIA////
		struct no *ponteiro = cabeca;
		
		while (ponteiro -> proximo != NULL){
			ponteiro = ponteiro -> proximo;
		}
		ponteiro -> proximo = NovoNo;
		}
}
////FUNCAO QUE IMPRIME OS NOS DA LISTA////
void imprimir(){
	printf("===============================\n");
	struct no *ponteiro = cabeca;
	while (ponteiro != NULL){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
} 
////FUNCAO QUE EXCLUI O NO DA LISTA///
void remover (int numero){
	if (cabeca != NULL){
		if (cabeca -> numero == numero){
////CASO FACIL, EXCLUIR O PRIMEIRO NO DA LISTA////
			struct no *ponteiroExcluir = cabeca;
			cabeca = cabeca -> proximo;
			free(ponteiroExcluir);
		} else{
////CASO DIFICIL, EXCLUIR ALGUM NO NO MEIO DA LISTA////
			struct no *ponteiroAnterior = cabeca;
			
			while ((ponteiroAnterior -> proximo != NULL) &&	(ponteiroAnterior -> proximo -> numero != numero)){
			
			ponteiroAnterior = ponteiroAnterior -> proximo;
		}
		if (ponteiroAnterior -> proximo != NULL){
			struct no *ponteiroExcluir = ponteiroAnterior -> proximo;
			ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
			free(ponteiroExcluir);
		}
		}
	}
}
////FUNCAO PRINCIPAL DO PROGRAMA////
int main(int argc, char *argv[]){
	int opcao = 0;
	int numero = 0;
	
	while(opcao != 4){
		printf("+================+\n");
		printf("| Menu de opcoes |\n");
		printf("+================+\n");
		printf("| 1 - inserir    |\n");
		printf("| 2 - remover    |\n");
		printf("| 3 - imprimir   |\n");
		printf("| 4 - sair       |\n");
		printf("+================+\n");
		printf("|Digite a opcao: |\n");
		scanf("%d", &opcao);
		
		switch (opcao){
		case 1: 
			printf("digite o numero: ");
			scanf("%d", &numero);
			inserir(numero);
			break;
		case 2:
			printf("digite o numero: ");
			scanf("%d", &numero);
			remover(numero);
			break;
		case 3:
			imprimir();
			break;
		}
	}
}
