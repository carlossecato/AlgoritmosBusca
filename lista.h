//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

#define TamLista 100
#define TamListaLivro 100

typedef struct {
	char nome[50];
	char nusp[10];
	char tel[10];
	char email[30];
}eleml;



typedef struct {
	int qtd;
	eleml dados[TamLista];
}Lista;

typedef struct {
	char titulo[50];
	char autor[50];
	char ISBN[10];
	char editora[30];
	int ano;
	int exemplar;
	char edicao[10];
	int disponivel;
	Fila F;
}elemLivro;

typedef struct {
	int qtd;
	elemLivro dados[TamListaLivro];
}ListaLivros;



void cria(Lista*);

void cria_livros(ListaLivros*);

void libera_lista(Lista* L);

void liberaLivros(ListaLivros*);

int consulta_lista_pos(Lista* L, int pos, eleml *X);

int consulta_lista_mat(Lista* L, int mat, eleml *X);

int insere_lista(Lista* L, eleml *X);

int insereListaLivros(ListaLivros*, elemLivro*);

int remove_lista(Lista* L, char*);

int removeListaLivro(ListaLivros*, char*, int*);

int tamanho_lista(Lista* L);

int lista_cheia(Lista* L);

int listaLivro_cheia(ListaLivros *LL);

int lista_vazia(Lista* L);


