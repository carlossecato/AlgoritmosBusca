#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista_dim.h"
#include "bubble.h"
#include "insertion.h"
#include "merge.h"


int main ()
{
		int N, R,i, erro;
		int *p;

		no *px;

		Lista L;

		cria(&L);

		srand((9292890));

		printf("Digite um numero inteiro: \n");
		scanf("%d",&N);
		p = (int*)calloc(N,sizeof(int));
		printf("Digite o numero de repeticoes desejada: \n");
		scanf("%d", &R);

		for(i=0;i<N;i++){
		p[i]=0+rand()%(R-0+1);
		inserir(&L,&p[i],&erro);

	}	

	px = L.inicio;
	while(px != NULL )	{
				printf("%d ",px->info );
		px = px->prox;	
		}


		printf("\n");
		mergeSort(p,0,N);
		for(i=0;i<N;i++){
		printf("%d\n",p[i] );
	}

	
}

