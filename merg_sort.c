#include <stdio.h>
#include <stdlib.h>


int *mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
	int i, j, k, metadeTamanho, *vetorTemp;



	if(posicaoInicio == posicaoFim) return NULL;

	// ordenacao recursiva das duas metades
	metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

	mergeSort(vetor, posicaoInicio, metadeTamanho);
	mergeSort(vetor, metadeTamanho + 1, posicaoFim);

	// intercalacao no vetor temporario t
	i = posicaoInicio;
	j = metadeTamanho + 1;
	k = 0;

	vetorTemp = (int*) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));
	if(vetorTemp == NULL){
		printf("Erro alocacao \n");
	}
	while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
		if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
			vetorTemp[k] = vetor[j];
			j++;
			k++;
		}
		else {
			if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
				vetorTemp[k] = vetor[i];
				i++;
				k++;
			}
			else {
				if (vetor[i] < vetor[j]) {
					vetorTemp[k] = vetor[i];
					i++;
					k++;
				}
				else {
					vetorTemp[k] = vetor[j];
					j++;
					k++;
				}
			}
		}

	}
	// copia vetor intercalado para o vetor original
	for(i = posicaoInicio; i <= posicaoFim; i++) {
		vetor[i] = vetorTemp[i - posicaoInicio];
	}
	free(vetorTemp);
	return vetor;
}


void imprime_merge (int *c, int tam, int opcao){
	int i;
	if(opcao==0){
		for(i=0;i<tam;i++){
			printf("%d ", c[i]);
		}
	}
	else{
		for (i = tam -1; i >= 0; i--)
		{
			printf("%d ", c[i]);
		}
	}
}

int *criavet(int tam){
	int *vetor;
	vetor=(int*)malloc(tam*sizeof(int));
	if(!vetor){
		printf("Erro na alocacao");
	}
	return vetor;
}	



