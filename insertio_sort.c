#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main ()
{
	int *p;
	int tam,i,j,aux;
	int opcao;
	
	//printf("Digite o tamanho do vetor: ");
	scanf("%d",&tam);
	p=(int*)calloc(tam,sizeof(int));
	scanf("%d",&opcao);
	

	for(i=0;i<tam;i++){
		scanf("%d",&p[i]);
	}
	
	for(j=1;j<tam;j++){
		aux=p[j];
		i=j-1;
		while (i>=0 && p[i]>aux){
			p[i+1]=p[i];
			i=i-1;
		}
			p[i+1]=aux;
	}
	
	if(opcao==0){
	for(i=0;i<tam;i++){
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
