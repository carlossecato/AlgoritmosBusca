//Trabalho 2 - Disciplina: Algoritmos e Estrutura de Dados
//Analise de Arvores e algoritmos de ordenacao
//Data: 26/11/2017
//Alberice Lucas de Araujo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890


#include <stdio.h>
#include <stdlib.h>

#define TamFila 100


//estrutura da arvore binaria
typedef int elem;
typedef struct bloco {
	elem info;
	struct bloco *esq, *dir;
} no;

typedef struct {
	no *raiz;
} Arvore;



//estrutura da fila
typedef struct {
	int inicio, fim, total;
	no *itens[TamFila];
} Fila;


void EntraFila(Fila *F, no *X, int *erro) ;
void SaiFila(Fila *F, no **X, int *erro) ;
void CriaFila(Fila *F) ;
void EsvaziaFila(Fila *F) ;

void cria(Arvore*);
int IsEmpty(Arvore*);
no* busca(no*,elem*);
no* busca_pai(no*,elem*);
void inserir_esq(Arvore*,elem*,elem*,int*);
void inserir_dir(Arvore*,elem*,elem*,int*);
void imprimir(no*);
int altura(no*);
int nosFolhas(no*);
void finaliza(no*);
void remover(Arvore*,elem*,int*);
int espelho_similares(no*,no*);






//função responsavel por inserir uma string em camadas por uma arvore
void inserirLarguraRecursivo(no** n, int raiz, char * str);

//função para verificar se uma arvore esta cheia
int EstaArvoreCheia(no* );

//função para verificar se uma arvore é do tipo ABB
int IsABB(no*);

//função para verificar se subarvore atende o requisito preordem
int is_percurso_pre0_ordem(no *);

//função para verificar se subarvore atende o requisito em ordem
int is_percurso_em_ordem(no *);

//função para verificar se subarvore atende o requisito posordem
int is_percurso_pos_ordem(no *);


