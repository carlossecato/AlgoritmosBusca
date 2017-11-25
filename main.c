#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista_dim.h"
#include "bubble.h"
#include "insertion.h"
#include "merge.h"

elem *geraListaOrdCres(Lista *L, int N){
	int erro, i;
	elem *p;
	p = (elem*)calloc(N,sizeof(elem));
	for(i=0;i<N;i++){
		p[i]=10*i;
		inserir(L,&p[i],&erro);

	}	
	return	p;
}


elem *geraListaOrdDecr(Lista *L, int N){
	int erro, i, j=0;
	elem *p;
	p = (elem*)calloc(N,sizeof(elem));
	for(i=N;i>0;i--){

		p[j++]= N*i;
		inserir(L,&p[i],&erro);

	}	
	return	p;
}


elem *geraListaAleatoria(Lista *L, int N){
	int erro, i;
	elem *p;
	p = (elem*)calloc(N,sizeof(elem));
	for(i=0;i<N;i++){
		p[i]=0+rand()%1000;//%(R-0+1);
		inserir(L,&p[i],&erro);

	}	
	return	p;
}

void imprime(Lista *L){
	no *aux;

	aux = L->inicio;
	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}

}
void calculaAleatorio (Lista *L, int *p, int N, int R){
	clock_t init,end; 
	clock_t *tempoMerge, *tempoInsertion, *tempoBubble;
	int aux,i; 
	double somaMerge, somaInsertion, somaBubble;

	printf("\n   \t\t>>> Dados Aleatorios <<<   \n\n");

	tempoMerge = (clock_t*)calloc(R,sizeof(clock_t));
	tempoInsertion = (clock_t*)calloc(R,sizeof(clock_t));
	tempoBubble = (clock_t*)calloc(R,sizeof(clock_t));

	aux =N-1;
	for(i=0; i<R; i++){
		p = geraListaAleatoria(L,N);
		init = clock();
		mergeSort(p,0,aux);
		end = clock();
		tempoMerge[i] = (end-init);///CLOCKS_PER_SEC;


		p = geraListaAleatoria(L,N);
		init = clock();
		insertion_sort(p,N);
		end = clock();
		tempoInsertion[i] = (end-init);///CLOCKS_PER_SEC;


		p = geraListaAleatoria(L,N);
		init = clock();
		bubbleSort(p,N);
		end = clock();
		tempoBubble[i] = (end-init);//CLOCKS_PER_SEC;

	}

	for(i=0;i<R;i++){
		somaMerge += tempoMerge[i];
		somaInsertion += tempoInsertion[i];
		somaBubble += tempoBubble[i];
	}	

	somaMerge = somaMerge/R; 
	somaInsertion = somaInsertion/R;
	somaBubble = somaBubble/R;


	printf("Merge:  \t%.2lf milisegundos  \t%.2lf segundos\n",somaMerge,somaMerge/CLOCKS_PER_SEC);
	printf("Insertion: \t%.2lf milisegundos \t%.2lf segundos\n",somaInsertion, somaInsertion/CLOCKS_PER_SEC);
	printf("Bubble: \t%.2lf milisegundos \t%.2lf segundos\n",somaBubble, somaBubble/CLOCKS_PER_SEC);

	free(tempoMerge);
	free(tempoInsertion);
	free(tempoBubble);
}

void calculaCresc (Lista *L, int *p, int N, int R){
	clock_t init,end; 
	clock_t *tempoMergeCresc, *tempoInsertionCresc, *tempoBubbleCresc;
	int aux,i; 
	double somaMergeCresc, somaInsertionCresc, somaBubbleCresc;

	printf("\n   \t>>> Dados em Ordem Crescente <<<   \n\n");

	tempoMergeCresc = (clock_t*)calloc(R,sizeof(clock_t));
	tempoInsertionCresc = (clock_t*)calloc(R,sizeof(clock_t));
	tempoBubbleCresc = (clock_t*)calloc(R,sizeof(clock_t));

	aux =N-1;
	for(i=0; i<R; i++){
		p = geraListaOrdCres(L,N);
		
		init = clock();
		mergeSort(p,0,aux);
		end = clock();
		tempoMergeCresc[i] = (end-init);///CLOCKS_PER_SEC;


		p = geraListaOrdCres(L,N);
		init = clock();
		insertion_sort(p,N);
		end = clock();
		tempoInsertionCresc[i] = (end-init);///CLOCKS_PER_SEC;


		p = geraListaOrdCres(L,N);
		init = clock();
		bubbleSort(p,N);
		end = clock();
		tempoBubbleCresc[i] = (end-init);///CLOCKS_PER_SEC;

	}

	for(i=0;i<R;i++){
		somaMergeCresc += tempoMergeCresc[i];
		somaInsertionCresc += tempoInsertionCresc[i];
		somaBubbleCresc += tempoBubbleCresc[i];
	}	

	somaMergeCresc = somaMergeCresc/R; 
	somaInsertionCresc = somaInsertionCresc/R;
	somaBubbleCresc = somaBubbleCresc/R;


	printf("Merge:  \t%.2lf milisegundos  \t%.2lf segundos\n",somaMergeCresc, somaMergeCresc/CLOCKS_PER_SEC);
	printf("Insertion: \t%.2lf milisegundos \t%.2lf segundos\n",somaInsertionCresc, somaInsertionCresc/CLOCKS_PER_SEC);
	printf("Bubble: \t%.2lf milisegundos \t%.2lf segundos\n",somaBubbleCresc, somaBubbleCresc/CLOCKS_PER_SEC);

	free(tempoMergeCresc);
	free(tempoInsertionCresc);
	free(tempoBubbleCresc);
}

void calculaDecres (Lista *L, int *p, int N, int R){
	clock_t init,end; 
	clock_t *tempoMerge, *tempoInsertion, *tempoBubble;
	int aux,i; 
	double somaMerge, somaInsertion, somaBubble;

	printf("\n   \t>>> Dados em Ordem Decrescente <<<   \n\n");

	tempoMerge = (clock_t*)calloc(R,sizeof(clock_t));
	tempoInsertion = (clock_t*)calloc(R,sizeof(clock_t));
	tempoBubble = (clock_t*)calloc(R,sizeof(clock_t));

	aux =N-1;
	for(i=0; i<R; i++){
		p = geraListaOrdDecr(L,N);
		init = clock();
		mergeSort(p,0,aux);
		end = clock();
		tempoMerge[i] = (end-init);//CLOCKS_PER_SEC;


		p = geraListaOrdDecr(L,N);
		init = clock();
		insertion_sort(p,N);
		end = clock();
		tempoInsertion[i] = (end-init);//CLOCKS_PER_SEC;


		p = geraListaOrdDecr(L,N);
		init = clock();
		bubbleSort(p,N);
		end = clock();
		tempoBubble[i] = (end-init);//CLOCKS_PER_SEC;

	}

	for(i=0;i<R;i++){
		somaMerge += tempoMerge[i];
		somaInsertion += tempoInsertion[i];
		somaBubble += tempoBubble[i];
	}	

	somaMerge = somaMerge/R; 
	somaInsertion = somaInsertion/R;
	somaBubble = somaBubble/R;


	printf("Merge:  \t%.2lf milisegundos  \t%.2lf segundos\n",somaMerge, somaMerge/CLOCKS_PER_SEC);
	printf("Insertion: \t%.2lf milisegundos \t%.2lf segundos\n",somaInsertion, somaInsertion/CLOCKS_PER_SEC);
	printf("Bubble: \t%.2lf milisegundos \t%.2lf segundos\n",somaBubble, somaBubble/CLOCKS_PER_SEC);

	free(tempoMerge);
	free(tempoInsertion);
	free(tempoBubble);

}

int main ()
{
	int N, R,i, erro, aux;
	elem *p, *q, *r;
	clock_t init,end, tempo;

	no *px;
	no *anterior;
	no *atual;

	Lista L;

	cria(&L);

	srand((9292890));

	printf("Digite um numero inteiro: \n");
	scanf("%d",&N);
	
	printf("Digite o numero de repeticoes desejada: \n");
	scanf("%d", &R);	

	printf("\n\n");
	/*p=geraListaOrdDecr(&L,N);
	for (int i = 0; i < N; i++)
	{
		printf("%d ",p[i] );
	}*/
	calculaAleatorio(&L,p, N,R);
	calculaCresc(&L, q, N,R);
	calculaDecres(&L, r, N,R);
	/*
	for(i=0;i<N;i++){
		inserir(&L,&p[i],&erro);
		eliminar(&L, &p[i]);
	}
*/
	//imprime(&L);

	
}

