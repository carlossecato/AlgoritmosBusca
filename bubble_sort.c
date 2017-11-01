#include <stdio.h>
#include <stdlib.h>

int *geravet(int tam);
void bubbleSort(int *p, int tam);
void imprime(int *p, int tam, int opcao);


void bubbleSort(int *p, int tam){
	int i, j, aux; 
	
	for(i=tam-1; i >= 1; i--){  
        for(j=0; j < i ; j++){
        	
            if(p[j]>p[j+1]){
            	
                aux = p[j];
                p[j] = p[j+1];
                p[j+1] = aux;
                
            }
        }
    }
} 

void imprime_bubble(int *p, int tam, int opcao){
    int i;

    if(opcao==0){
    for(i=0; i<tam; i++){
            printf("%d ",p[i]);
    }
}   
    else{
        for (i = tam -1; i >= 0; i--)
        {
           printf("%d ", p[i]);
        }
    }

}

int *geravet(int tam){
        int *p;

        p=(int*)calloc(tam,sizeof(int));
        if(!p){
            printf("Erro ao alocar\n");
        }

        return p;
}   


