#include <stdio.h>
#include <stdlib.h>


long long int *mergeSort(long long int *vetor, long long int posicaoInicio, long long int posicaoFim);
void imprime (long long int *c, long long int tam, int opcao);
long long int *criavet(long long int tam);


long long int *mergeSort(long long int *vetor, long long int posicaoInicio, long long int posicaoFim) {
   long long int i, j, k, metadeTamanho, *vetorTemp;
    
    //printf("entrei no merg\n");

    if(posicaoInicio == posicaoFim) return NULL;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    //printf("dividi o veto\n");
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;

    vetorTemp = (long long int*) malloc(sizeof(long long int) * (posicaoFim - posicaoInicio + 1));
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


void imprime (long long int *c, long long int tam, int opcao){
	long long int i;
	if(opcao==0){
	for(i=0;i<tam;i++){
		printf("%llu ", c[i]);
	}
    }
    else{
        for (i = tam -1; i >= 0; i--)
        {
           printf("%llu ", c[i]);
        }
    }
}
	
long long int *criavet(long long int tam){
        long long int *vetor;
    vetor=(long long int*)malloc(tam*sizeof(long long int));
        if(!vetor){
            printf("Erro na alocacao");
    }
    return vetor;
}	



int main ()
{
    long long int *vetor,*c=NULL;    
    long long int tam, posicaoInicio, posicaoFim;
    long long int i;
    int opcao;
    
    
    //printf("Digite o tamanho do vetor: ");
    scanf("%llu",&tam);
    vetor = criavet(tam);
    scanf("%d", &opcao);

    for (i = 0; i < tam; i++ ) {
        scanf("%llu", &vetor[i]);
    }

    posicaoInicio=0;
    posicaoFim = tam-1;

    
    c=mergeSort(vetor, posicaoInicio, posicaoFim);
    imprime(c, tam, opcao);
}