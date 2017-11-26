//Trabalho 2 - Disciplina: Algoritmos e Estrutura de Dados
//Analise de Arvores e algoritmos de ordenacao
//Data: 27/11/2017
//Alberice Lucas de Araujo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arvore.h"
#include "AVL.h"


// PROTOTIPO DAS FUNÇÕES USADAS
void menu(void);

int main(){
	// DECLARA A ARVORE ENTRADA , A  ARVORE AVL A E  ALGUMAS VARIAVEIS INTEIRAS
	Arvore Entrada;	
	AVL A;
	int i, erro, alt, folha;
	char info[50];
	for (i=0; i<51; i++){ // inicializa todos os elementos do array como 200 para futura verificação
		info[i] = 200;
	}
	i =0;
	// CHAMA O MENU DO  PROGRAMA
	menu();

	scanf(" %[^\n]s",info);

	printf("\n Os elementos a serem organizados na arvore sao os seguintes:\n");
	printf("\n%s\n\n", info);



	// CRIA A ARVORE E INSERE OS ELEMENTOS EM LARGURA
	cria(&Entrada);

	inserirLarguraRecursivo(&Entrada.raiz, 1, info);

	printf("\n \t\t>>> Analise Arvore Binaria <<<\n\n");



	// CARACTERIZA A ARVORE INFORMANDO  O QUE FOI PEDIDO PELA ESPECIFICAÇÃO DO TRABALHO  

	// IMPRIME A ARVORE NO FORMATO DISCUTIDO EM AULA 
	imprimir(Entrada.raiz);

	// MOSTRA A ALTURA DA ARVORE
	alt = altura(Entrada.raiz);
	printf("\nA altura da arvore eh: %d\n", alt);

	//calcula o numero de nos folha
	folha = nosFolhas(Entrada.raiz);
	printf("A qde de no folha eh: %d\n", folha);
	// VERIFICA SE A A ARVORE É AVL E INFORMA AO USUARIO 


	// VERIFICA SE A ARVORE É CHEIA E INFORMA AO USUARIO 
	printf("A arvore esta cheia? \n");  
	if (EstaArvoreCheia(Entrada.raiz) ==1){
		printf("Sim\n");
	}else{
		printf("Nao\n");
	}

	// VERIFICA SE A ARVORE É ABB E INFORMA AO USUARIO 
	printf("A arvore e ABB? \n");
	if (IsABB(Entrada.raiz) ==1){
		printf("Sim\n");
	}else{
		printf("Nao\n");
	}


	// VERIFICA SE OS ELEMENTOS FICAM ORDENADOS EM PRE-ORDEM
	printf("Os elementos ficam ordenados em Pre-ordem?  ");
	if (is_percurso_pre_ordem(Entrada.raiz) ==1){
		printf("Sim\n");
	}else{
		printf("Nao\n");
	}

	// VERIFICA SE OS ELEMENTOS FICAM ORDENADOS EM ORDEM  
	printf("Os elementos ficam ordenados em Ordem?  ");
	if (is_percurso_em_ordem(Entrada.raiz) ==1){
		printf("Sim\n");
	}else{
		printf("Nao\n");
	}
	// VERIFICA SE OS ELEMENTOS FICAM ORDENADOS EM POS-ORDEM     
	printf("Os elementos ficam ordenados em Pos-ordem?  ");
	if (is_percurso_pos_ordem(Entrada.raiz) ==1){
		printf("Sim\n");
	}else{
		printf("Nao\n");
	}


	//FAZ A INSERCAO DOS ELEMENTOS MONTANDO A AVL 
	criar(&A);
	insercao_AVL( &A, info);


	printf("\n \t\t>>> Analise Arvore AVL <<<\n\n");
	// CARACTERIZA A AVL INFORMANDO  O QUE FOI PEDIDO PELA ESPECIFICAÇÃO DO TRABALHO  

	// IMPRIME A ARVORE NO FORMATO DISCUTIDO EM AULA 
	imprimirAVL(&A.raiz_avl);

	// MOSTRA A ALTURA DA ARVORE
	//	alt = altura(A.raiz_avl);
	printf("\nA altura da arvore eh: %d", alt);
	//calcula o numero de nos folha
	folha = nosFolhas_avl(A.raiz_avl);
	printf("\nA qde de no folha eh: %d\n", folha);

	// NÃO É NECESSARIO VERIFICAR , A ARVORE É AVL 
	printf("A arvore eh uma AVL?\nSim");


	// VERIFICA SE A ARVORE É CHEIA E INFORMA AO USUARIO 
	printf("\nA arvore esta cheia? \n");
	if (EstaArvoreCheia(A.raiz_avl) ==1){
		printf("Sim\n");
	}else{
		printf("Nao\n");
	}

	// TODA AVL É UMA ABB 
	printf("A arvore e ABB? \n");
	printf("Sim\n");

	// VERIFICA SE OS ELEMENTOS FICAM ORDENADOS EM PRE-ORDEM
	printf("Os elementos ficam ordenados em Pre-ordem?  ");
	if (is_percurso_pre_ordem(A.raiz_avl) ==1){
		printf("Sim\n");
	}else{
		printf("Nao\n");
	}

	// VERIFICA SE OS ELEMENTOS FICAM ORDENADOS EM ORDEM  
	printf("Os elementos ficam ordenados em Ordem?  ");
	if (is_percurso_em_ordem(A.raiz_avl) ==1){
		printf("Sim\n");
	}else{
		printf("Nao\n");
	}
	// VERIFICA SE OS ELEMENTOS FICAM ORDENADOS EM POS-ORDEM     
	printf("Os elementos ficam ordenados em Pos-ordem?  ");
	if (is_percurso_pos_ordem(A.raiz_avl) ==1){
		printf("Sim\n");
	}else{
		printf("Nao\n");
	}

	getchar();

}


//FUNÇÃO MENU
void menu(void){

	printf("\n    >>>> Analisa Arvore <<<<    \n\n");
	printf("\nDigite os caracteres a serem inseridos: \n");
	printf("Obs: espacos indicam ausencia de no. \n");

}




