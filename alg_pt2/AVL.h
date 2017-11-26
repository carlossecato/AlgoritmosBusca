//Trabalho 2 - Disciplina: Algoritmos e Estrutura de Dados
//Analise de Arvores e algoritmos de ordenacao
//Data: 26/11/2017
//Alberice Lucas de Araujo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include <stdio.h>
#include <stdlib.h>


//declaração do nó da árvore
typedef int elem;

typedef struct bloco_avl {
	elem info;
	int fb;
	struct bloco_avl *esq, *dir;
} no_avl;

typedef struct {
	no_avl *raiz_avl;
} AVL;


//protótipos das funções
void criar(AVL*);
void finalizarAVL(no_avl**);
void insercao_AVL( AVL *A, char *info);
void imprimirAVL(no_avl**);
int aux_insere(no_avl**, int*, int*);
int inserir_avl(no_avl**,int*);
int buscar(no_avl**,int*);
int nosFolhas_avl(no_avl*);
