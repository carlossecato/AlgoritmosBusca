#include "lista_dim.h"

void cria(Lista *L){
	L->inicio = NULL;
	L->fim = NULL;
}

void inserir(Lista *L, elem *X, int *erro){
	
	no *p;
	
	p = (no*)malloc(sizeof(no));
	if(p==NULL){
		*erro = 1;
		return;
	} else *erro = 0;
	
	p->info = *X;
	p->prox = NULL;
	
	if(L->inicio == NULL)
		L->inicio = p;
	else L->fim->prox = p;

	L->fim = p;
	
}

void finaliza(Lista *L){

	no *p;
	
	p=L->inicio;	
	
	while(p!=NULL){
		L->inicio = L->inicio->prox;
		free(p);
		p=L->inicio;
	}
	
	L->fim = p;
}

int tamanho_rec(no *p){
	
	if(p==NULL)
		return 0;
	else return(1+tamanho_rec(p->prox));
	
}

int tamanho_rec_lista(Lista *L){
	return tamanho_rec(L->inicio);
}

int tamanho(Lista *L){
	
	no *p;
	int count = 0;
	
	p=L->inicio;
	
	while(p!=NULL){
		count++;
		p=p->prox;		
	}
	
	return count;
}

int esta_na_lista(Lista *L, elem *X){
	
	no *p;
	p=L->inicio;
	
	while((p != NULL)&&(p->info != *X)){
		p=p->prox;
	}
	
	if(p==NULL)
		return 0;
	else return 1;
	
}

int esta_na_lista_rec(no *p, elem *X){
	
	if(p == NULL)
		return 0;
	else if (p->info==*X)
		return 1;
	else 
		return esta_na_lista_rec(p->prox,X);

}

int eliminar(Lista *L, elem *X){
	
	no *p, *aux;
	int teste = 0;

	p = L->inicio;
	while ((p!=NULL) && (!teste)) {
		if (p->info == *X) {
			if (p == L->inicio)
				L->inicio = L->inicio->prox;
			else if (p == L->fim) {	
				L->fim = aux;
				L->fim->prox = NULL;

			}
			else aux->prox = p->prox;
			free(p);
			teste = 1;
			return 1;
		}
		else {
			aux = p;
			p = p->prox;
		}

	}
	return 0;     
}
