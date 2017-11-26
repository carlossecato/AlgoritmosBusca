//Trabalho 2 - Disciplina: Algoritmos e Estrutura de Dados
//Analise de Arvores e algoritmos de ordenacao
//Data: 26/11/2017
//Alberice Lucas de Araujo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

//função para criar/inicializar a AVL
void criar(AVL *A) {
	A->raiz_avl=NULL;
}

//função para finalizar a AVL; deve começar com p=raiz
void finalizarAVL(no_avl **p) {
	if (*p!=NULL) {
		finalizarAVL(&(*p)->esq);
		finalizarAVL(&(*p)->dir);
		free(*p);
	}     
}

//imprime os elementos da árvore
void imprimirAVL(no_avl **p) {
	if (*p!=NULL) {
		printf("%c/%d(",(*p)->info,(*p)->fb);
		imprimirAVL(&(*p)->esq);
		printf(",");
		imprimirAVL(&(*p)->dir);
		printf(")");
	}
	else printf("=");
}

//função de busca de um elemento na AVL; deve começar com p=raiz
int buscar(no_avl **p, int *x) {
	if (*p==NULL)
		return 0;
	else if (*x<(*p)->info)
		return(buscar(&(*p)->esq,x));
	else if (*x>(*p)->info)
		return(buscar(&(*p)->dir,x));
	else return 1;
}

int nosFolhas_avl(no_avl *p){
	if(p == NULL){
		return 0;
	}
	if((p->esq == NULL) && (p->dir == NULL)){
		return 1;
	}
	return (nosFolhas_avl(p->esq) + nosFolhas_avl (p->dir));
}


//funções para inserção de um elemento na AVL
//a variável "cresceu" indica se a árvore cresceu após a inserção
void EE(no_avl **r) {
	no_avl *pai=*r;
	no_avl *filho=pai->esq;
	pai->esq=filho->dir;
	filho->dir=pai;
	pai->fb=0;
	filho->fb=0;
	*r=filho;
}

void DD(no_avl **r) {
	no_avl *pai=*r;
	no_avl *filho=pai->dir;
	pai->dir=filho->esq;
	filho->esq=pai;
	pai->fb=0;
	filho->fb=0;
	*r=filho;
}

void ED(no_avl **r) {
	no_avl *pai=*r;
	no_avl *filho=pai->esq;
	no_avl *neto=filho->dir;
	pai->esq=neto->dir;
	filho->dir=neto->esq;
	neto->esq=filho;
	neto->dir=pai;
	switch (neto->fb) {
		case -1:
			pai->fb=1;
			filho->fb=0;
			break;
		case 0:
			pai->fb=0;
			filho->fb=0;
			break;
		case 1:
			pai->fb=0;
			filho->fb=-1;
			break;
	}
	neto->fb=0;
	*r=neto;
}

void DE(no_avl **r) {
	no_avl *pai=*r;
	no_avl *filho=pai->dir;
	no_avl *neto=filho->esq;
	filho->esq=neto->dir;
	pai->dir=neto->esq;
	neto->esq=pai;
	neto->dir=filho;
	switch (neto->fb) {
		case -1:
			pai->fb=0;
			filho->fb=1;
			break;
		case 0:
			pai->fb=0;
			filho->fb=0;
			break;
		case 1:
			pai->fb=-1;
			filho->fb=0;
			break;
	}
	neto->fb=0;
	*r=neto;
}

void insercao_AVL( AVL *A, char *info){
	int i, erro;
	int c;
	while( info[i] != '\0'){
		//printf("inserindo %c\n", info[i]); // usada para realizar testes da insercao avl
		while(info[i] == 32){
			i ++;}
		c = info[i];
		erro = inserir_avl(&A->raiz_avl, &c);
		i++;
	}

}

int aux_insere(no_avl **p, int *x, int *cresceu) {
	if (*p==NULL) {
		*p=(no_avl*) malloc(sizeof(no_avl));
		(*p)->info=*x;
		(*p)->fb=0;
		(*p)->esq=NULL;
		(*p)->dir=NULL;
		*cresceu=1;
		return 1;
	}
	else if (*x==(*p)->info)
		return 0;
	else if (*x<(*p)->info) {
		if (aux_insere(&(*p)->esq,x,cresceu)) {
			if (*cresceu) {
				switch ((*p)->fb) {
					case -1:
						if ((*p)->esq->fb==-1)
							EE(p);
						else ED(p);
						*cresceu=0;
						break;
					case 0:
						(*p)->fb=-1;
						*cresceu=1;
						break;
					case 1:
						(*p)->fb=0;
						*cresceu=0;
						break;
				}
			}
			return 1;
		}
		else return 0;
	}
	else {
		if (aux_insere(&(*p)->dir,x,cresceu)) {
			if (*cresceu) {
				switch ((*p)->fb) {
					case -1:
						(*p)->fb=0;
						*cresceu=0;
						break;
					case 0:
						(*p)->fb=1;
						*cresceu=1;
						break;
					case 1:
						if ((*p)->dir->fb==1)
							DD(p);
						else DE(p);
						*cresceu=0;
						break;
				}
			}
			return 1;
		}
		else return 0;
	}
}

int inserir_avl(no_avl **p, int *x) {
	int cresceu;
	return aux_insere(p, x, &cresceu);
}




